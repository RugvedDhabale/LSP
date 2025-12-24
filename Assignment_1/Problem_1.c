#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
    char filename[100];
    int fd;

    printf("Entre filename: ");
    scanf("%s", filename);

    fd = open(filename, O_RDONLY);

    if(fd == -1)
    {
        perror("Error in opening file");
        return 1;
    }

    printf("File opened successfully\n");
    printf("FD is: %d\n", fd);

    close(fd);

    return 0;
}