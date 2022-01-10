#include<stdio.h>

int p[10]={0},d[10]={0},j[10];
   
void job_seq(int n)
{
	int k=1,i,r,q,c=0;
   	j[1]=1;
  	for(i=1;i<=n;i++)
  	{
    	r=k;
    	while(d[j[r]]>d[i] && d[j[r]]!=r)
    		r=r-1;
    	if(d[j[r]]<=d[i] && d[i]>r)
    	{
      		for(q=k;q<=r+1;q++)
      			j[q+1]=j[q];
    		j[r+1]=i;
    		k=k+1;
    	}
   	}
	printf("The job sequence is:\n");
   	for(i=1;i<=k;i++)
  	{
    	printf("%d ",j[i]);
     	c=c+p[j[i]];
	}
 	printf("\nTotal profit: %d ", c);
}

main()
{
	int n,i;
  	printf("Enter the number of jobs: ");
  	scanf("%d",&n);
  	for(i=1;i<=n;i++)
  	{
  		printf("\nEnter the profit: ");
  		scanf("%d",&p[i]);
  		printf("Enter the deadline: ");
  		scanf("%d",&d[i]);
  	}
  	job_seq(n);
}

