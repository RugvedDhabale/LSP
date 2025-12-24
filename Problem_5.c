#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    char filename[100];
    int fd, nbytes;
    char buffer[1024];
    int bytesRead;

    printf("Enter filename: ");
    scanf("%99s", filename);

    printf("Enter number of bytes to read: ");
    scanf("%d", &nbytes);

    fd = open(filename, O_RDONLY);

    if(fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    if(nbytes > sizeof(buffer))
        nbytes = sizeof(buffer);

    bytesRead = read(fd, buffer, nbytes);

    if(bytesRead == -1)
    {
        perror("Error reading file");
        close(fd);
        return 1;
    }

    write(1, buffer, bytesRead);

    close(fd);
    return 0;
}
