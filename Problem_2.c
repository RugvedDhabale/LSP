#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main()
{
    char filename[100];
    char mode[100];
    int fd, flags;

    printf("Entre filename: ");
    scanf("%s", filename);

    printf("Entre mode: ");
    scanf("%s", mode);

    if(strcmp(mode, "R") == 0)
    {
        flags = O_RDONLY;
    }   
    else if(strcmp(mode, "W") == 0)
    {
        flags = O_WRONLY | O_TRUNC | O_CREAT;
    }
    else if(strcmp(mode, "RW") == 0)
    {
        flags = O_RDWR | O_CREAT;
    }
    else if(strcmp(mode, "A"))
    {
        flags = O_WRONLY | O_APPEND | O_CREAT;
    }
    else
    {
        return 1;
    }

    fd = open(filename, flags, 0644);

    if(fd == -1)
    {
        perror("Error in opening file");
        return 1;
    }

    printf("FD is: %d\n", fd);

    close(fd);

    return 0;
}