#include<stdio.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
    char sourcedir[100];
    char destdir[100];
    char sourcepath[200];
    char destpath[200];
    char buffer[1024];

    struct dirent *entry;
    struct stat filestat;
    DIR *dir;

    int count = 0;
    int source_fd;
    int dest_fd;
    int bytesread;

    printf("Enter source directory: ");
    scanf("%s", sourcedir);
    printf("Enter destination directory: ");
    scanf("%s", destdir);

    dir = opendir(sourcedir);

    if(dir == NULL)
    {
        perror("Error opening source directory");
        return 1;
    }
    while((entry = readdir(dir)) != NULL)
    {
        sprintf(sourcepath, "%s/%s", sourcedir, entry->d_name);
        if(stat(sourcepath, &filestat) == 0 && S_ISREG(filestat.st_mode))
        {
            sprintf(destpath, "%s/%s", destdir, entry->d_name);
            if(rename(sourcepath, destpath) == 0)
            {
                count++;
            }
            else
            {
                source_fd = open(sourcepath, O_RDONLY);
                dest_fd = open(destpath, O_WRONLY | O_CREAT | O_TRUNC, filestat.st_mode);
                if(source_fd != -1 && dest_fd != -1)
                {
                    while((bytesread = read(source_fd, buffer, 1024)) > 0)
                    {
                        write(dest_fd, buffer, bytesread);
                    }
                    close(source_fd);

                    close(dest_fd);

                    unlink(sourcepath);
                    
                    count++;
                }
            }
        }
    }

    printf("Files moved: %d\n", count);

    closedir(dir);
    
    return 0;
}