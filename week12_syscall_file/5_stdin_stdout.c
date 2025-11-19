#include <stdio.h>

#include <unistd.h>
// read(2)
// #include <unistd.h>
// malloc(3)
#include <stdlib.h>
// exit(3)
// #include <stdlib.h>
// error handling
#include <errno.h>
// // write(2)
// #include <unistd.h>


#define BUF_SIZE 128 

int main(int argc, char* argv[]){

    if (argc != 1) {
        printf("Usage: ./%s\n", argv[0]);
        exit(0);
    }

    char* readStr = (char*)malloc(sizeof(char) * BUF_SIZE);
    int read_result;
    while(1){
        read_result = read(0, readStr, BUF_SIZE);
        if (read_result == -1){
            perror("Error in reading : ");
            break;
        }
        else if (read_result == 0){ // Ctrl + D
            printf("program end...\n");
            break;
        }
        write(1, readStr, read_result);
    }

    free(readStr);

    return 0;
}