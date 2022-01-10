#include<stdio.h>
int x[20],g[20][20]={0};
int n,f=0,m;

void next_color(int k)   
{
	int j;
	while(1)
	{ 
		x[k]=(x[k]+1)%(m+1);
		if(x[k]==0)
			return;  
		for(j=1;j<=n;j++)
			if(g[j][k]!=0 && x[k]==x[j])
				break;
		if(j==n+1)
			return;
	}
}

void graph_col(int k)
{
	int i;
	while(1)
	{
		next_color(k);
		if(x[k]==0)
			return;
		if(k==n)
		{
			f=1;
			for(i=1;i<=n;i++)
				printf("%d ",x[i]);
        	printf("\n");
        }
        else
			graph_col(k+1);
	}
}

main()
{
	int v1,v2,e,i;
	printf("Enter the number of edges: ");
	scanf("%d",&e);
	printf("Enter the number of vertices: ");
	scanf("%d",&n);
	for(i=0;i<e;i++)
	{
		printf("\nEnter the source vertex: ");
		scanf("%d",&v1);
		printf("Enter the destination vertex: ");
		scanf("%d",&v2);
		g[v1][v2]=g[v2][v1]=1;
	}
    for(m=1;m<=n-1;m++)
  	{
    	graph_col(1);
    	if(f==1)
    	{
       		printf("Chromatic number = %d",m);
      		break;
      	}
    }
}

