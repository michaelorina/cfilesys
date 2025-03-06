#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/fs.h"
#include "../include/dir_ops.h"

#define MAX_COMMAND 256

void start_cli(FileSystem *fs) {
    char command[MAX_COMMAND];
    char *args[3];

    while (1) {
        printf("cfs> ");
        if (fgets(command, MAX_COMMAND, stdin) == NULL) {
            break;
        }

        command[strcspn(command, "\n")] = 0;

        int argc = 0;
        char *token = strtok(command, " ");
        while (token != NULL && argc < 3) {
            args[argc++] = token;
            token = strtok(NULL, " ");
        }

        if (argc == 0) continue;
        if (strcmp(args[0], "exit") == 0) {
            printf("Exiting cfilesys...\n");
            break;
        } else if (strcmp(args[0], "mkdir") == 0 && argc == 2) {
            create_subdirectory(fs->current, args[1]);
        } else if (strcmp(args[0], "ls") == 0) {
            print_directory_structure(fs->current, 0);
        } else if (strcmp(args[0], "cd") == 0 && argc == 2) {
            change_directory(fs, args[1]);
        } else {
            printf("Unknown command: %s\n", args[0]);
        }
    }
}

int main() {
    FileSystem *fs = init_file_system();

    if (!fs) {
        fprintf(stderr, "Error initializing file system.\n");
        return EXIT_FAILURE;
    }

    printf("Welcome to cfilesys! Type commands to interact.\n");
    start_cli(fs);

    free_file_system(fs);  
    return EXIT_SUCCESS;
}
