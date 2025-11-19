#include <stdio.h>

// open(2)
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
// close(2)
#include <unistd.h>
// read(2)
// #include <unistd.h>
// malloc(3)
#include <stdlib.h>
// exit(3)
// #include <stdlib.h>
// error handling
#include <errno.h>


#define BUF_SIZE 128 // 1char, 2Bytes -> read 64characters at once

// int open(const char *pathname, int flags);
// ssize_t read(int fd, void *buf, size_t count);

int main(int argc, char* argv[]){

    if (argc != 2) {
        printf("Usage: %s [file name]\n", argv[0]);
        exit(0);
    }

    int open_fd = open(argv[1], O_RDONLY);
    if (open_fd == -1){
        printf("errno: %d\n", errno);
        perror("Error in opening file: ");
        exit(0);
    }
    
    // success opening, and then read
    char* readStr = (char*)malloc(sizeof(char) * BUF_SIZE);
    int read_result = 0;
    while(1) {
        read_result = read(open_fd, readStr, BUF_SIZE);
        // Error handling
        if (read_result == -1) {
            printf("errno: %d\n", errno);
            perror("Error in reading file: ");
        }
        // End of File
        else if (read_result == 0){
            printf("\n--- End of File ---\n");
            close(open_fd);
            break;
        }
        printf("%s\n", readStr);
    }

    free(readStr);
    close(open_fd);

    return 0;
}