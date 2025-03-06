#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/fs.h"
#include "../include/dir_ops.h"

void test_create_directory() {
    Directory *root = create_directory("root", NULL);
    if (!root || strcmp(root->name, "root") != 0 || root->parent != NULL) {
        printf("❌ test_create_directory FAILED\n");
        exit(1);
    }
    free_directory(root);
    printf("✅ test_create_directory PASSED\n");
}

void test_create_subdirectory() {
    Directory *root = create_directory("root", NULL);
    create_subdirectory(root, "sub1");

    if (!root->subdirs || strcmp(root->subdirs->name, "sub1") != 0) {
        printf("❌ test_create_subdirectory FAILED\n");
        exit(1);
    }

    free_directory(root);
    printf("✅ test_create_subdirectory PASSED\n");
}

void test_file_system_init_and_free() {
    FileSystem *fs = init_file_system();
    if (!fs || strcmp(fs->root->name, "/") != 0) {
        printf("❌ test_file_system_init_and_free FAILED\n");
        exit(1);
    }

    free_file_system(fs);
    printf("✅ test_file_system_init_and_free PASSED\n");
}

void test_change_directory() {
    FileSystem *fs = init_file_system();
    create_subdirectory(fs->root, "subdir");
    
    change_directory(fs, "subdir");
    if (strcmp(fs->current->name, "subdir") != 0) {
        printf("❌ test_change_directory FAILED\n");
        exit(1);
    }

    change_directory(fs, "..");
    if (strcmp(fs->current->name, "/") != 0) {
        printf("❌ test_change_directory (..) FAILED\n");
        exit(1);
    }

    free_file_system(fs);
    printf("✅ test_change_directory PASSED\n");
}

int main() {
    printf("Running tests...\n");
    test_create_directory();
    test_create_subdirectory();
    test_file_system_init_and_free();
    test_change_directory();
    printf("🎉 All test passed");
    return 0;
}
