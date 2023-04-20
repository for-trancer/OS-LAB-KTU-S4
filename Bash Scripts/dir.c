#include <stdio.h>
#include <dirent.h>
#include <unistd.h>

struct dirent *dkrp;

int main()
{
DIR *dirp;
char path[20];
printf("Enter The Path : ");
scanf("%s",path);
if((dirp=opendir(path))==NULL)
printf("Error Directory Not Found!");
while((dkrp=readdir(dirp))!=NULL)
printf("\n%s\n",dkrp->d_name);
closedir(dirp);
}
