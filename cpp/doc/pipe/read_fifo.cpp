#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <string>
#include <iostream>
#include <string.h>
int main()
{
    const char *fifo_name = "/tmp/my_fifo";
    int pipe_fd = -1;

    int res = 0;
    int open_mode = O_RDONLY;
    char buffer[PIPE_BUF + 1];
    int bytes_read = 0;


    memset(buffer, '\0', sizeof(buffer));

    printf("Process %d opening FIFO O_RDONLY\n", getpid());
    while(true)
    {
        pipe_fd = open(fifo_name, open_mode);
        //printf("Process %d result %d\n",getpid(), pipe_fd);
        if(pipe_fd != -1)
        {
            printf("start read");

            res = read(pipe_fd, buffer, PIPE_BUF + 1);
            printf("Ser:> %s,data lenth is %d\n",buffer,res);
            close(pipe_fd);
        }
        else
            exit(EXIT_FAILURE);
    }

    printf("Process %d finished, %d bytes read\n", getpid(), bytes_read);
    exit(EXIT_SUCCESS);
}
