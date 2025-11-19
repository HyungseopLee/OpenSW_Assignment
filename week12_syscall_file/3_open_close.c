#include <stdio.h>

// open(2)
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
// close(2)
#include <unistd.h>
// perror(3), errno
#include <errno.h>
// exit(3)
#include <stdlib.h>

int main(int argc, char* argv[]){

    if(argc != 2) {
        printf("Usage: ./3_open_close [file name]\n");
        exit(0);
    }

    int open_fd = open(argv[1], );
    if (open_fd == -1){
        printf("error open: %d\n", errno);
        perror("error msg is: ");
        exit(0);
    }
    else{
        printf("open success\n");
        exit(0);
        close(open_fd);
    }

    return 0;
}