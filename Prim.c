#include<stdio.h>

int G[20][20],V,E,vi[20]={0};

void prims()
{
	int k=0,i,j,u,v,c=0,min;
	vi[1]=1;
	while(k<V-1)
	{
		min=99;
		for(i=1;i<=V;i++)
			for(j=1;j<=V;j++)
				if((G[i][j]<min) && (vi[i]==1) && (vi[j]==0))
				{
					min=G[i][j];
					u=i;
					v=j;
				}
		printf("\n%d %d",u,v);
		c+=min;
		vi[v]=1;
		k++;
	}
	printf("Total Cost = %d",c);
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
			G[i][j]=99;
	for(i=1;i<=E;i++)
	{
		printf("\nEnter the source vertex:");
    	scanf("%d",&x);
    	printf("Enter the destination vertex: ");
    	scanf("%d",&y);
    	printf("Enter the weight: ");
    	scanf("%d",&z);
    	G[x][y]=G[y][x]=z;
	}
	prims();
}

