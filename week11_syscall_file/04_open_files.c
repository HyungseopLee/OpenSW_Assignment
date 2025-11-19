#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
    
int main(int argc, char* argv[]){

    if (argc < 2) {
        printf("Usage: %s [file1 name] ... \n", argv[0]);
        exit(0);
    }
    int num_files = argc - 1;
    int* fd_list = (int*)malloc(sizeof(int) * num_files);
    
    // open only exisiting files (Read only)
    for (int i = 0; i < num_files; i++){
        fd_list[i] = open(argv[i+1], O_RDONLY); // read newly
        if (fd_list[i] == -1) {
            perror(argv[i+1]);
            continue;
        }
        else {
            printf("Opened successfully: %s (fd = %d)\n", argv[i + 1], fd_list[i]);
        }
    }

    // close only successfully opened files
    for (int i = 0; i < num_files; i++) {
        if (fd_list[i] != -1) {
            if (close(fd_list[i]) == -1) {
                perror("Error closing file");
            } else {
                printf("Closed successfully: %s\n", argv[i + 1]);
            }
        }
    }
    
    free(fd_list);
    return 0;
}