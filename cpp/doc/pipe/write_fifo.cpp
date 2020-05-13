#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h> 
int main()
{
    const char *fifo_name = "/tmp/my_fifo";
    int pipe_fd = -1;

    int res = 0;
    const int open_mode = O_WRONLY;

    char buffer[PIPE_BUF + 1];

    if(access(fifo_name, F_OK) == -1)
    {
        printf ("Create the fifo pipe.\n");
        res = mkfifo(fifo_name, 0777);

        if(res != 0)
        {
            fprintf(stderr, "Could not create fifo %s\n", fifo_name);
            exit(EXIT_FAILURE);
        }
    }

    printf("Process %d opening FIFO O_WRONLY\n", getpid());
    pipe_fd = open(fifo_name, open_mode);
    printf("Process %d result %d\n", getpid(), pipe_fd);

    if(pipe_fd != -1)
    {
        printf("start write");
        buffer[0] = '1';
        buffer[1] = '\0';
        res = write(pipe_fd, buffer, strlen(buffer)+1);
        if(res == -1)
        {
            printf("Write error on pipe\n");
            exit(EXIT_FAILURE);
        }
        close(pipe_fd);
        printf("write success");
    }
    else
        exit(EXIT_FAILURE);

    printf("Process %d finished\n", getpid());
    exit(EXIT_SUCCESS);
}
