#include<stdio.h>
#include<dirent.h>
#include<string.h>

int main()
{
    char dirname[100];
    char filename[100];
    char filepath[200];
    struct dirent *entry;
    DIR *dir;
    int found = 0;

    printf("Enter directory name: ");
    scanf("%s", dirname);

    printf("Enter file name: ");
    scanf("%s", filename);

    dir = opendir(dirname);

    if(dir == NULL)
    {
        perror("Error opening directory");
        return 1;
    }

    while((entry = readdir(dir)) != NULL)
    {
        if(strcmp(entry->d_name, filename) == 0)
        {
            sprintf(filepath, "%s/%s", dirname, filename);
            printf("File found: %s\n", filepath);
            found = 1;
            break;
        }
    }

    if(!found)
    {
        printf("File not found\n");
    }

    closedir(dir);
    
    return 0;
}