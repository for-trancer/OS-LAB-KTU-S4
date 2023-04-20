#include <stdio.h>
#include <unistd.h>

void main()
{
char *args[]={"./demo.out",NULL};
execv(args[0],args);
}
