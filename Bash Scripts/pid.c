#include <stdio.h>
#include <unistd.h>

void main()
{
int p;
p=getpid();
printf("Process Id : %d\n",p);
p=getppid();
printf("Parent Process Id : %d\n",p);
}
