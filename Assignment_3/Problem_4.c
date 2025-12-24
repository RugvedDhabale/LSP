#include<stdio.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>
#include<unistd.h>
int main()
{
    char dirname[100];
    char filepath[200];
    struct dirent *entry;
    struct stat filestat;
    DIR *dir;
    int count = 0;

    printf("Enter directory name: ");
    scanf("%s", dirname);

    dir = opendir(dirname);

    if(dir == NULL)
    {
        perror("Error opening directory");
        return 1;
    }
    while((entry = readdir(dir)) != NULL)
    {
        sprintf(filepath, "%s/%s", dirname, entry->d_name);

        if(stat(filepath, &filestat) == 0)
        {
            if(S_ISREG(filestat.st_mode) && filestat.st_size == 0)
            {
                printf("Deleting: %s\n", entry->d_name);

                unlink(filepath);

                count++;
            }
        }
    }

    printf("Total files deleted: %d\n", count);

    closedir(dir);
    
    return 0;
}