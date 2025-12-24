#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main()
{
    char filename[100];
    char str[1000];
    int fd;
    int byteswritten;

    printf("Enter filename: ");
    scanf("%s", filename);
    getchar();

    printf("Enter string: ");
    fgets(str, 1000, stdin);

    fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);

    if(fd == -1)
    {
        perror("Error in opening file");
        return 1;
    }

    byteswritten = write(fd, str, strlen(str));
    printf("Number of bytes written: %d\n", byteswritten);

    close(fd);
    
    return 0;
}