#include "../include/dir_ops.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Directory *create_directory(const char *name, Directory *parent) {
    Directory *dir = (Directory *)malloc(sizeof(Directory));
    if (!dir) {
        perror("Failed to allocate memory for directory");
        exit(EXIT_FAILURE);
    }

    strncpy(dir->name, name, sizeof(dir->name) - 1);
    dir->name[sizeof(dir->name) - 1] = '\0';

    dir->parent = parent;
    dir->subdirs = NULL;
    dir->next = NULL;
    return dir;
}

void free_directory(Directory *dir) {
    if (!dir) return;

    Directory *subdir = dir->subdirs;
    while (subdir) {
        Directory *next = subdir->next;
        free_directory(subdir);
        subdir = next;
    }

    dir->subdirs = NULL;
    dir->next = NULL;
    dir->parent = NULL;

    free(dir);
}

void create_subdirectory(Directory *parent, const char *name) {
    Directory *new_dir = create_directory(name, parent);

    if (!parent->subdirs) {
        parent->subdirs = new_dir;
    } else {
        Directory *temp = parent->subdirs;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_dir;
    }
}
