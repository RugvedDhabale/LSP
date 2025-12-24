#include<stdio.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>

int main()
{
    char dirname[100];
    char filepath[200];
    struct dirent *entry;
    struct stat filestat;
    DIR *dir;

    printf("Enter directory name: ");
    scanf("%s", dirname);

    dir = opendir(dirname);

    if(dir == NULL)
    {
        perror("Error in opening directory");
        return 1;
    }

    while((entry = readdir(dir)) != NULL)
    {
        sprintf(filepath, "%s/%s", dirname, entry->d_name);
        if(lstat(filepath, &filestat) == 0)
        {
            printf("%s - ", entry->d_name);
            if(S_ISREG(filestat.st_mode))
            {
            printf("Regular\n");
            }
            else if(S_ISDIR(filestat.st_mode))
            {
            printf("Directory\n");
            }
            else if(S_ISLNK(filestat.st_mode))
            {
                printf("Link\n");
            }
            else if(S_ISFIFO(filestat.st_mode))
            {
                printf("FIFO\n");
            }
            else if(S_ISSOCK(filestat.st_mode))
            {
                printf("Socket\n");
            }
            else if(S_ISBLK(filestat.st_mode))
            {
                printf("Block\n");
            }
            else if(S_ISCHR(filestat.st_mode))
            {
                printf("Char\n");
            }
        }
    }   

    closedir(dir);

    return 0;
}