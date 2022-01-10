#include<stdio.h>
 
int d[10][10],w[10][10];

void f_war(int v)
{
	int i,j,k;
    for(i=1;i<=v;i++)
	    for(j=1;j<=v;j++)
			d[i][j]=w[i][j];	
	for(k=1;k<=v;k++)
		for(i=1;i<=v;i++)
      		for(j=1;j<=v;j++)
         		if(d[i][k]+d[k][j]<d[i][j])
               		d[i][j]=d[i][k]+d[k][j];
	printf("The final matrix:\n");
	for(i=1;i<=v;i++)
	{
    	for(j=1;j<=v;j++)
      		printf("%d ",d[i][j]);
		printf("\n");
	}   
}

main()
{
	int v,e,i,j,t,s,W;
   	printf("Enter the number of vertices: ");
   	scanf("%d",&v);
   	printf("Enter the number of edges: ");
   	scanf("%d",&e);
   	for(i=1;i<=v;i++)
   	{
    	for(j=1;j<=v;j++)
     	{
       		if(i==j)
       			w[i][j]=0;
       		else
       			w[i][j]=999;
      	}
    }
   	for(i=1;i<=e;i++)
   	{
     	printf("\nEnter source vertex:");
     	scanf("%d",&t);
     	printf("Enter destination vertex:");
     	scanf("%d",&s);
     	printf("Enter Weight:");
     	scanf("%d",&W);
     	w[t][s]=W;
    }
    f_war(v);
}

