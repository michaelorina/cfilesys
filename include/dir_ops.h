#ifndef DIR_OPS_H
#define DIR_OPS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Directory {
    char name[256];
    struct Directory *parent;
    struct Directory *subdirs;
    struct Directory *next;
} Directory;

Directory *create_directory(const char *name, Directory *parent);
void free_directory(Directory *dir);
void create_subdirectory(Directory *parent, const char *name);

#endif
