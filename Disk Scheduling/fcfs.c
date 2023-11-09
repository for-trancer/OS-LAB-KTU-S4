#include <stdio.h>

void main()
{
    int i,m,n,tr[20],cr,sum=0,new;
    printf("Enter The Number Of Tracks : ");
    scanf("%d",&m);
    printf("Enter The Head Pointer Position : ");
    scanf("%d",&cr);
    printf("Enter The Tracks To Be Traversed : ");
    for(i=0;i<m;i++)
    {
        new=0;
        scanf("%d",&tr[i]);
        new=cr-tr[i];
        if(new<0)
        {
            new=tr[i]-cr;
        }
        cr=tr[i];
        sum+=new;
    }
    printf("\nTraversed Order : ");
    for(i=0;i<m;i++)
    {
        printf("%d ",tr[i]);
    }
    printf("\n No Of Disk Movement : %d",sum);
}
