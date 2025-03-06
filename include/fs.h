#ifndef FS_H
#define FS_H

#include "dir_ops.h"

typedef struct FileSystem {
    Directory *root;
    Directory *current;
} FileSystem;

FileSystem *init_file_system();
void free_file_system(FileSystem *fs);
void change_directory(FileSystem *fs, const char *path);
void print_directory_structure(Directory *dir, int depth);

#endif
