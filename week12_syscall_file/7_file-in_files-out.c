#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

#define BUF_SIZE 128
    
int main(int argc, char* argv[]){

    if (argc < 2) {
        printf("Usage: ./%s [to copy file] [to paste file1] ... \n", argv[0]);
        exit(0);
    }

    // open copy file
    int copy_fd = open(argv[1], O_RDONLY);
    if (copy_fd == -1){
        perror("Error in opening copy_fd: ");
        exit(1);
    }
    // open paste file
    int num_files = argc - 2;
    int* paste_fd_list = (int*)malloc(sizeof(int) * num_files);
    for (int i = 0; i < num_files; i++){
        paste_fd_list[i] = open(argv[i+2], O_WRONLY | O_CREAT | O_TRUNC, 0644); // write newly
        if (paste_fd_list[i] == -1) {
            perror("Error in openeing paste_fd: ");
            exit(1);
        }
    }

    // read from source and write destinations
    char* readStr = (char*)malloc(sizeof(char) * BUF_SIZE);
    int read_result, i=1;
    while(1){
        read_result = read(copy_fd, readStr, BUF_SIZE);
        if (read_result == -1){
            perror("Error in reading : ");
            break;
        }
        else if (read_result == 0){ // EoF
            printf("EOF detected. Terminating reading loop...\n");
            break;
        }
        for (int j = 0 ; j < num_files ; j++){
            if (write(paste_fd_list[j], readStr, read_result) == -1) {
                perror("Error in writing: ");
                break;
            }
        }
        i += 1;
    }

    // close all files
    close(copy_fd);
    for (int i = 0; i < num_files; i++){
        close(paste_fd_list[i]);
    }
    // free
    free(readStr);
    free(paste_fd_list);


    return 0;
}