#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

int main()
{
char path[20];
struct stat *file;
file=malloc(sizeof(struct stat));
printf("Enter The File Name : ");
scanf("%s",path);
stat(path,file);
printf("\n User Id : %d",file->st_uid);
printf("\n Block Size : %ld",file->st_blksize);
printf("\n Modification Or Last Acess Time  : %ld",file->st_atime);
printf("\n Size : %ld",file->st_size);
printf("\n No. Of Links : %ld\n",file->st_nlink);
}
