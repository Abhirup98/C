#include<stdio.h>
#define INF 999;

int G[10][10],E[10][2],par[10];

void path(int s,int t)
{
	if(s==par[t])
		printf("%d ",t);
	else
	{
		path(s,par[t]);
		path(par[t],t);
	}
}

void BellmanFord(int v,int e,int t)
{
	int i,j,s=1,x,y,d[20];
	for(i=1;i<=v;i++)
	{
		d[i]=INF;
		par[i]=0;
	}
	d[s]=0;
	for(i=1;i<=v-1;i++)
	{
		for(j=1;j<=e;j++)
		{
			x=E[j][0];
			y=E[j][1];
			if(d[y]>(d[x]+G[x][y]))
			{
				d[y]=d[x]+G[x][y];
				par[y]=x;
			}
		}
	}
	for(i=2;i<=v;i++)
		printf("\nThe shortest path from %d to %d is %d",s,i,d[i]);
	printf("\n\nThe shortest path from %d to %d is \n",s,t);
	printf("%d ",s);
	path(s,t);
}

int main()
{
	int i,j,v,e,x,y,z,t;
	printf("Enter the number of vertices: ");
	scanf("%d",&v);
	printf("Enter the number of edges: ");
	scanf("%d",&e);
	for(i=1;i<=v;i++)
	{
		for(j=1;j<=v;j++)
		{
			if(i==j)
				G[i][j]=0;
			else
				G[i][j]=INF;
		}
	}
	for(i=1;i<=e;i++)
	{
		printf("\nEnter the source vertex: ");
		scanf("%d",&x);
		printf("Enter the destination vertex: ");
		scanf("%d",&y);
		printf("Enter the weight of the edge: ");
		scanf("%d",&z);
		G[x][y]=z;
		E[i][0]=x;
		E[i][1]=y;
	}
	printf("\nEnter the target vertex: ");
	scanf("%d",&t);
	BellmanFord(v,e,t);
}

