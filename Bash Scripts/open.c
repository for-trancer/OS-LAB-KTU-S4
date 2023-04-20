#include <stdio.h>
#include <unistd.h>

void main()
{
char *arr[]={"rm sample.txt",NULL};
execv(arr[0],arr);
char *args[]={"ls",NULL};
printf("Before File Creation : \n");
execv(args[0],args);
int fd=open("sample.txt",O_RDONLY | O_CREAT);
if(fd==-1)
{
printf("File Is Not Created!\n");
}
else
{
printf("File is Created!\n");
}
printf("After File Creation : \n");
execv(args[0],args);
}
