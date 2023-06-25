#include <stdio.h>
#include <unistd.h>
// first combile demo.c to get the output

void main()
{
char *args[]={"./demo.out",NULL};
execv(args[0],args);
}
