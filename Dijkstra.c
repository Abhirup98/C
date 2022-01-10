#include<stdio.h>

int G[10][10],V,E,vi[10]={0},di[10]={0};

void dj()
{
	int k=1,min,i,s=1,j,u;
	for(i=1;i<=V;i++)
		di[i]=G[s][i];
	vi[s]=1;
	di[s]=0;
	while(k<V-1)
	{
		min=999;
		for(i=1;i<=V;i++)
			if((di[i]<min) && (vi[i]==0))
			{
				min=di[i];
				u=i;
			}
	    vi[u]=1;
		for(i=1;i<=V;i++)
		   if(di[u]+G[u][i]<di[i] && vi[i]==0)
		     di[i]=di[u]+G[u][i];
	k++;
  	}
  	for(i=1;i<=V;i++)
		printf("%d ",di[i]);
}

int main()
{
	int i,j,x,y,z;
	printf("Enter the number of vertices: ");
	scanf("%d",&V);
	printf("Enter the number of edges: ");
	scanf("%d",&E);
	for(i=1;i<=V;i++)
		for(j=1;j<=V;j++)
			G[i][j]=9999;
	for(i=1;i<=E;i++)
	{
		printf("\nEnter the source vertex: ");
		scanf("%d",&x);
		printf("Enter the destination vertex: ");
		scanf("%d",&y);
		printf("Enter the weight: ");
		scanf("%d",&z);
		G[x][y]=z;
	}
	dj();
}

