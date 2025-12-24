#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
    char filename[100];
    char buffer[1];
    int fd;
    int bytesread;
    int totalbytes = 0;

    printf("Enter filename: ");
    scanf("%s", filename);

    fd = open(filename, O_RDONLY);
    if(fd == -1)
    {
        perror("Error in opening file");
        return 1;
    }

    while((bytesread = read(fd, buffer, 1)) > 0)
    {
        write(1, buffer, 1);
        totalbytes += bytesread;
    }

    printf("\nTotal bytes read: %d\n", totalbytes);

    close(fd);

    return 0;
}