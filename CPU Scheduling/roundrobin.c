#include <stdio.h>

struct process
{
	char name;
	int wt,bt,tat,tbt;
}p[20];
// For Generating Gantt Chart
struct gantt
{
	char name;
	int time;
}d[20];

void main()
{
	int n,i,j,tot_tat=0,tot_wt=0,f=1,t;
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
		p[i].tbt=p[i].bt; // Creating a backup for use it in table (temp)
	}
	printf("Enter The Time Quantum : ");
	scanf("%d",&t);
	i=0; // for traversing the processes
	int x=0; // denotes the time
	int y=0; // denotes the no of completed process
	int k=0; // for generating gantt chart
	while(1)
	{
		if(p[i].bt>0)
		{
			if(p[i].bt>t)
			{
				p[i].bt=p[i].bt-t;
				x=x+t;
				d[k].name=p[i].name; // adding process name to gantt
				d[k].time=x; // adding its time to gantt chart
				k++;
			}
			else
			{
				x=x+p[i].bt;
				p[i].bt=0;
				p[i].tat=x;
				p[i].wt=p[i].tat-p[i].tbt;
				tot_tat=tot_tat+p[i].tat;
				tot_wt=tot_wt+p[i].wt;
				y++; // increase the number of finished process
				d[k].name=p[i].name;
				d[k].time=x;
				k++;
				if(y==n) // if all process has finished execution
				{
					break;
				}
			}
		}
		if(i==n-1) // if there is remaining burst time and we are at the last process
		{
			i=0; // start the process again
		}
		else
		{
			i=i+1; 
		}
	}
	printf("\nProcess\t\tBT\t\tTAT\t\tWT\n");
	for(i=0;i<n;i++)
	{
		printf("%c\t\t%d\t\t%d\t\t%d\n",p[i].name,p[i].tbt,p[i].tat,p[i].wt); // using the temp burst time for table
	}
	printf("\nGANTT CHART\n\n");
	for(i=0;i<k;i++)
	{
		if(i==k-1)
		{
		printf("|\t%c\t|",d[i].name);	
		break;
		}
		printf("|\t%c\t",d[i].name);
	}
	printf("\n");
	printf("0\t \t");
	for(i=0;i<k;i++)
	{
		printf("%d\t \t",d[i].time);
	}
	avg_tat=(float)tot_tat/n;
	avg_wt=(float)tot_wt/n;
	printf("\n\nAverage TAT : %f\nAverage WT : %f\n",avg_tat,avg_wt);
}
