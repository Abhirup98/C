#include<stdio.h>
#include<math.h>

int n,tq;
struct process
{	
	int b,p,wt,ta,rm;
}p[20],tmp;

void sort_p()
{
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
			if(p[j].p>p[j+1].p)
			{
				tmp = p[j];
				p[j] = p[j+1];
				p[j+1]=tmp;
			}
}

void sort_b()
{
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
			if(p[j].b>p[j+1].b)
			{
				tmp = p[j];
				p[j] = p[j+1];
				p[j+1] = tmp;
			}
}

int scheduling()
{
	int i,g=0,res=0;
	for(i=0;i<n;i++)
	{
		g+=p[i].b;
		p[i].ta = g;
		p[i].wt = p[i].ta-p[i].b;
		res+=p[i].wt;
	}
	return res;
}

int rr_scheduling(int c)
{
	int g=0,res=0,i,j;
	for(i=1;i<=c;i++)
	{
		for(j=0;j<n;j++)
		{
			if(p[j].rm>tq)
			{
				g+=tq;
				p[j].rm-=tq;
			}
			else if(p[j].rm<=tq && p[j].rm!=0)
			{
				g+=p[j].rm;
				p[j].rm = 0;
				p[j].ta = g;
				p[j].wt = p[j].ta-p[j].b;
				res+=p[j].wt;
			}
			
		}
	}
	return res;
}

main()
{
	int i,max=0,c,temp;
	char *pro;
	float f_wt,p_wt,s_wt,rr_wt,min=99;
	printf("Enter the number of processes: ");
	scanf("%d",&n);
	printf("Enter the priority and burst time of %d processes:\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&p[i].p,&p[i].b);
		p[i].rm = p[i].b;
		if(p[i].b>max)	
			max = p[i].b;
	}
	printf("Enter the time quantum: ");
	scanf("%d",&tq);
	c = ceil(max/tq);
	
	f_wt = (float)scheduling()/n;
	printf("\nTotal time for FCFS = %d\n",scheduling());
	printf("Waiting time for FCFS = %.2f\n",f_wt);
	
	if(min>f_wt)
	{
		min = f_wt;
		pro="FCFS";
	}
	
	temp = rr_scheduling(c);
	rr_wt = (float)temp/n;
	printf("\nTotal time for Round Robin = %d\n",temp);
	printf("Waiting time for Round Robin = %.2f\n",rr_wt);
	
	if(min>rr_wt)
	{
		min = rr_wt;
		pro = "Round Robin";
	}
	
	sort_p();
	p_wt = (float)scheduling()/n;
	printf("\nTotal time for Priority = %d\n",scheduling());
	printf("Waiting time for Priority = %.2f\n",p_wt);
	
	if(min>p_wt)
	{
		min = p_wt;
		pro = "Priority";
	}
	
	sort_b();
	s_wt = (float)scheduling()/n;
	printf("\nTotal time for SJF = %d\n",scheduling());
	printf("Waiting time for SJF = %.2f\n",s_wt);
	
	if(min>s_wt)
	{
		min = s_wt;
		pro = "SJF";
	}
	
	printf("\nThe algorithm with the lowest average waiting time is %s with %.2fs time\n",pro,min);
}

