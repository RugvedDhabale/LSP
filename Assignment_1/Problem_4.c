#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

int main()
{
    char filename[100];
    struct stat fileStat;

    printf("Enter filename: ");
    scanf("%99s\n", filename);

    if(stat(filename, &fileStat) == -1)
    {
        perror("stat");
        return 1;
    }

    printf("File Size: %ld bytes\n", fileStat.st_size);
    printf("Inode Number: %ld\n", fileStat.st_ino);
    printf("Hard Links: %ld\n", fileStat.st_nlink);
    printf("Owner UID: %d\n", fileStat.st_uid);
    printf("Owner GID: %d\n", fileStat.st_gid);

    printf("Permissions: ");
    printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
    printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
    printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
    printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXOTH) ? "x\n" : "-\n");

    printf("Last Access Time: %s", ctime(&fileStat.st_atime));
    printf("Last Modification Time: %s", ctime(&fileStat.st_mtime));

    if(S_ISREG(fileStat.st_mode))
        printf("File Type: Regular File\n");
    else if(S_ISDIR(fileStat.st_mode))
        printf("File Type: Directory\n");
    else
        printf("File Type: Other\n");

    return 0;
}
