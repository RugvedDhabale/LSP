#include<stdio.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>

int main()
{
    char dirname[100];
    char filepath[200];
    char largestfile[100];
    struct dirent *entry;
    struct stat filestat;
    DIR *dir;
    long largestsize = 0;

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
        if(stat(filepath, &filestat) == 0)
        {
            if(S_ISREG(filestat.st_mode))
            {
                if(filestat.st_size > largestsize)
                {
                    largestsize = filestat.st_size;
                    strcpy(largestfile, entry->d_name);
                }
            }
        }
    }

    printf("Largest file: %s\n", largestfile);
    printf("Size: %ld bytes\n", largestsize);

    closedir(dir);
    
    return 0;
}