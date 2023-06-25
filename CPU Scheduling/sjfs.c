#include <stdio.h>

struct process
{
	char name;
	int wt,bt,tat;
}p[20],temp;

void main()
{
	int n,i,j,tot_tat=0,tot_wt=0;
	float avg_wt,avg_tat;
	printf("Enter The Number Of Processes : ");
	scanf("%d",&n);
	printf("Enter The Process Name and Burst Time : \n");
	for(i=0;i<n;i++)
	{
		printf("Process Name [%d] : ",i+1);
		scanf("%s",&p[i].name);
		printf("Burst Time : ");
		scanf("%d",&p[i].bt);
	}
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(p[j].bt>p[j+1].bt)
			{
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
		}
	}
	p[0].wt=0;
	for(i=1;i<n;i++)
	{
		p[i].wt=p[i-1].wt+p[i-1].bt;
	}
	for(i=0;i<n;i++)
	{
		p[i].tat=p[i].wt+p[i].bt;
		tot_wt=tot_wt+p[i].wt;
		tot_tat=tot_tat+p[i].tat;
	}
	printf("\nProcess\t\tBT\t\tTAT\t\tWT\n");
	for(i=0;i<n;i++)
	{
		printf("%c\t\t%d\t\t%d\t\t%d\n",p[i].name,p[i].bt,p[i].tat,p[i].wt);
	}
	printf("\nGANTT CHART\n\n");
	for(i=0;i<n;i++)
	{
		if(i==n-1)
		{
		printf("|\t%c\t|",p[i].name);	
		break;
		}
		printf("|\t%c\t",p[i].name);
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