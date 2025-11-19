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
        printf("Usage: ./%s [file1 name] [file2 name] ... \n", argv[0]);
        exit(0);
    }

    // get file descriptor for all files
    int num_files = argc - 1;
    int* fd_list = (int*)malloc(sizeof(int) * num_files);
    
    // open all files (Write only, Create if no exist, Write new)
    for (int i = 0; i < num_files; i++){
        fd_list[i] = open(argv[i+1], O_WRONLY | O_CREAT | O_TRUNC, 0644); // write newly
        // fd_list[i] = open(argv[i+1], O_WRONLY | O_CREAT | O_APPEND, 0644); // write append
        if (fd_list[i] == -1) {
            perror("Error in openeing: ");
            exit(1);
        }
    }

    char* readStr = (char*)malloc(sizeof(char) * BUF_SIZE);
    int read_result;
    while(1){
        read_result = read(0, readStr, BUF_SIZE); // get str from stdin(0)
        if (read_result == -1){
            perror("Error in reading : ");
            exit(0);
        }
        else if (read_result == 0){ // Ctrl + D
            printf("program end...\n");
            break;
        }
        for (int i = 0 ; i < num_files ; i++){
            if (write(fd_list[i], readStr, read_result) == -1) {
                perror("Error in writing: ");
            }
        }
    }

    // close all files
    for (int i = 0; i < num_files; i++){
        close(fd_list[i]);
    }

    free(readStr);
    free(fd_list);


    return 0;
}