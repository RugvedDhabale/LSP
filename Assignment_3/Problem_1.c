#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
int main()
{
    char source[100];
    char dest[100];
    char buffer[1024];
    int source_fd;
    int dest_fd;
    int bytesread;
    struct stat filestat;

    printf("Enter source file: ");
    scanf("%s", source);

    printf("Enter destination file: ");
    scanf("%s", dest);

    source_fd = open(source, O_RDONLY);

    if(source_fd == -1)
    {
        perror("Error opening source file");
        return 1;
    }
    fstat(source_fd, &filestat);

    dest_fd = open(dest, O_WRONLY | O_CREAT | O_TRUNC, filestat.st_mode);

    if(dest_fd == -1)
    {
        perror("Error opening destination file");
        close(source_fd);
        return 1;
    }

    while((bytesread = read(source_fd, buffer, 1024)) > 0)
    {
        write(dest_fd, buffer, bytesread);
    }

    printf("File copied successfully\n");

    close(source_fd);

    close(dest_fd);
    
    return 0;
}