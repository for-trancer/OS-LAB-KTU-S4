#include <stdio.h>
#include <unistd.h>

void main()
{
int value;
value=fork();
if(value == 0)
printf("Child Process Created! %d",value);
else if(value>0)
printf("Main Process Created : %d\n",value);
else
printf("Child Process Creattion Failed!");
}
