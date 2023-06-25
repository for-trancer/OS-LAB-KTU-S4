#include <stdio.h>

struct process
{
	int id,wt,bt,tat;
}p[20];

void main()
{
	int n,i,tot_tat=0,tot_wt=0;
	float avg_wt,avg_tat;
	printf("Enter The Number Of Processes : ");
	scanf("%d",&n);
	printf("Enter The Burst Time : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&p[i].bt);
	}
	p[0].wt=0;
	for(i=1;i<n;i++)
	{
		p[i].wt=p[i-1].wt+p[i-1].bt;
	}
	for(i=0;i<n;i++)
	{
		p[i].id=i+1;
		p[i].tat=p[i].wt+p[i].bt;
		tot_wt=tot_wt+p[i].wt;
		tot_tat=tot_tat+p[i].tat;
	}
	printf("\nProcess\t\tBT\t\tTAT\t\tWT\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t\t%d\t\t%d\t\t%d\n",i+1,p[i].bt,p[i].tat,p[i].wt);
	}
	printf("\nGANTT CHART\n\n");
	for(i=0;i<n;i++)
	{
		if(i==n-1)
		{
		printf("|\t%d\t|",p[i].id);	
		break;
		}
		printf("|\t%d\t",p[i].id);
	}
	printf("\n");
	printf("0\t \t");
	for(i=0;i<n;i++)
	{
		printf("%d\t \t",p[i].tat);
	}
	avg_tat=(float)tot_tat/n;
	avg_wt=(float)tot_wt/n;
	printf("\n\nAverage TAT : %f\nAverage WT : %f\n",avg_tat,avg_wt);
}
