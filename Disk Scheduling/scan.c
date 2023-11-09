#include <stdio.h>

void main()
{
    int n,i,j,k,cr,a[20],p[20],m,temp,sum,diff;
    printf("Enter The  No Of Tracks To Be Traversed : ");
    scanf("%d",&n);
    printf("Enter The Head Pointer Position : ");
    scanf("%d",&cr);
    printf("Enter The Tracks To Be Traversed :");
    for(i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
    }
    p[n]=0;
    p[n+1]=199;
    p[n+2]=cr;
    n+=3;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(p[j]>p[j+1])
            {
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
    k=0;

    for(i=0;i<n;i++)
    {
        if(p[i]==cr)
        {
            k=i;
            break;
        }
    }

    sum=0,diff=0;
    m=0;
    printf("\n %d \n",k);
    if(cr<(199-cr))
    {
        for(i=k;i>=0;i--)
        {
            a[m]=p[i];
            m++;
        }
        for(i=k+1;i<n-1;i++)
        {
            a[m]=p[i];
            m++;
        }
    }
    else
    {
        for(i=k;i<n;i++)
        {
            a[m]=p[i];
            m++;
        }
        for(i=k-1;i>0;i--)
        {
            a[m]=p[i];
            m++;
        }
    }

    printf("Traversed Order : \n");
    for(i=0;i<m;i++)
    {
        printf("%d =>",a[i]);
    }

    for(i=0;i<m-1;i++)
    {
        diff=0;
        if(a[i]>a[i+1])
        {
            diff=a[i]-a[i+1];
        }
        else
        {
            diff=a[i+1]-a[i];
        }
        sum+=diff;
    }

    printf("\nTotal Number Of Head Movements : %d",sum);
}