#include "../include/fs.h"

FileSystem *init_file_system() {
    FileSystem *fs = (FileSystem *)malloc(sizeof(FileSystem));
    if (!fs) {
        perror("Failed to allocate memory for file system");
        exit(EXIT_FAILURE);
    }
    fs->root = create_directory("/", NULL);
    fs->current = fs->root;
    return fs;
}

void free_file_system(FileSystem *fs) {
    if (!fs) return;

    free_directory(fs->root);
    fs->root = NULL;
    fs->current = NULL;

    free(fs);
}

void change_directory(FileSystem *fs, const char *path) {
    if (strcmp(path, "..") == 0) {
        if (fs->current->parent) {
            fs->current = fs->current->parent;
        }
    } else {
        Directory *subdir = fs->current->subdirs;
        while (subdir) {
            if (strcmp(subdir->name, path) == 0) {
                fs->current = subdir;
                return;
            }
            subdir = subdir->next;
        }
        printf("cd: No such directory: %s\n", path);
    }
}

void print_directory_structure(Directory *dir, int depth) {
    if (!dir) return;

    for (int i = 0; i < depth; i++) printf("  ");
    printf("|-- %s\n", dir->name);

    Directory *subdir = dir->subdirs;
    while (subdir) {
        print_directory_structure(subdir, depth + 1);
        subdir = subdir->next;
    }
}
