#include <stdio.h>

void main()
{
    int p,r,i,j,k,y,flag,alloc[10][10],max[20][20],need[i][j],available[20],work[20],finish[10],s[20],l=0;
    printf("Enter The Number Of Processes : ");
    scanf("%d",&p);
    printf("Enter The Number Of Resources : ");
    scanf("%d",&r);
    printf("Enter The Allocation Matrix : ");
    for(i=0;i<p;i++)
    {
        for(j=0;j<r;j++)
        {
            scanf("%d",&alloc[i][j]);
        }
    }
    printf("Enter The Max Matrix : ");
    for(i=0;i<p;i++)
    {
        for(j=0;j<r;j++)
        {
            scanf("%d",&max[i][j]);
        }
    }
    printf("Enter The Available Resource : ");
    for(i=0;i<r;i++)
    {
        scanf("%d",&available[i]);
    }
    for(i=0;i<p;i++)
    {
        for(j=0;j<r;j++)
        {
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    printf("\nProcess\t\tAlloc\t\tMax\n");
    for(i=0;i<p;i++)
    {
        printf("%d\t\t",i);
        for(j=0;j<r;j++)
        {
            printf("%d ",alloc[i][j]);
        }
        printf("\t\t");
        for(j=0;j<r;j++)
        {
            printf("%d ",max[i][j]);
        }
        printf("\n");
    }
        printf("Need :\n");
        for(i=0;i<p;i++)
        {
            for(j=0;j<r;j++)
            {
                printf("%d ",need[i][j]);
            }
            printf("\n");
        }
        printf("Available : \n");
        for(i=0;i<r;i++)
        {
            printf("%d ",available[i]);
        }


        for(i=0;i<r;i++)
        {
            work[i]=available[i];
        }
        for(i=0;i<p;i++)
        {
            finish[i]=0;
        }
        for(i=0;i<p;i++)
        {
            for(j=0;j<p;j++)
            {
                if(finish[j]==0)
                {
                    int flag=0;
                    for(k=0;k<r;k++)
                    {
                        if(need[j][k]>work[k])
                        {
                            flag=1;
                            break;
                        }
                    }
                    if(flag==0)
                    {
                        s[l]=j;
                        l++;
                        for(y=0;y<r;y++)
                        {
                            work[y]+=alloc[j][y];
                        }
                        finish[j]=1;
                    }
                }
            }
        }
        flag=0;
        for(i=0;i<p;i++)
        {
            if(finish[i]==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==0){ 
             printf("\n Safe Sequence : \n");
            for(i=0;i<p;i++)
            {
                if(i==l-1)
                {
                    printf("P%d\n",s[i]);
                    break;
                }
                printf("P%d->",s[i]);
            }
        }
        else
        {
            printf("\nThe System is in Unsafe Condition!\n");
        }
}
