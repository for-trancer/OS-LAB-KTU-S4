#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <dirent.h>
#include <fcntl.h>

int main()
{
char path[20];
printf("Enter The Name Of The File To Be Created : ");
scanf("%s",path);
int fd=creat(path,S_IWRITE | S_IREAD);
if(fd>0)
{
printf("File %s is Created!",path);
}
else
{
printf("Error!");
}
DIR *dirp;
struct dirent *dkrp;
dirp=opendir(".");
while((dkrp=readdir(dirp))!=NULL)
printf("\n%s\n",dkrp->d_name);
closedir(dirp);
}
