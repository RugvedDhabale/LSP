#include<stdio.h>
#include<dirent.h>

int main()
{

    char dirname[100];
    struct dirent *entry;
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
        if(entry->d_name[0] != '.')
        {
            printf("%s\n", entry->d_name);
        }
    }

    closedir(dir);

    return 0;
}