#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main()
{
    char filename[100];
    char mode[10];
    int iRet, flag;

    printf("Enter filename: ");
    scanf("%99s", filename);

    printf("Enter mode (read / write / execute): ");
    scanf("%9s", mode);

    if(strcmp(mode, "read") == 0)
    {
        flag = R_OK;
    }
    else if(strcmp(mode, "write") == 0)
    {
        flag = W_OK;
    }
    else if(strcmp(mode, "execute") == 0)
    {
        flag = X_OK;
    }
    else
    {
        return 1;
    }

    iRet = access(filename, flag);

    if(iRet == 0)
    {
        printf("Accessible\n");
    }
    else
    {
        printf("Not accessible\n");
        perror("Reason");
    }

    return 0;
}
