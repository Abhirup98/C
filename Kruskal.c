#include<stdio.h>

struct graph
{
    int u,v,w;
}s[10],t;

int V,E,p[10],r[10]={0};

void sort()
{
    int i,j;
    for(i=1;i<=E;i++)
    {
        for(j=i+1;j<=E;j++)
        {
            if(s[i].w>s[j].w)
            {
        	    t=s[i];
           		s[i]=s[j];
            	s[j]=t;
    	    }
    	}
    }
}
  
int find(int x)
{
	if(x!=p[x])
    	x=find(p[x]);
    return x;
}
  
void link(int x,int y)
{
	if(r[x]>r[y])
		p[y]=x;
	else
		p[x]=y;
	if((r[x]==r[y]) && (x!=y))
		r[y]=r[y]+1;
}
      
void kruskal()
{
	int j,m,n,c=0;
	for(j=1;j<=E;j++)
	{
		m=find(s[j].u);
		n=find(s[j].v);
		if(m!=n)
		{
			link(m,n);
			printf("%d %d \n",s[j].u, s[j].v);
			c=c+s[j].w;
		}    
	}
	printf("\nTotal cost =  %d",c);
}

main()
{
	int i;
	printf("Enter the number of vertices: ");
	scanf("%d",&V);
	printf("Enter the nunber of edges: ");
	scanf("%d",&E);
	for(i=1;i<=V;i++)
		p[i]=i;
	for(i=1;i<=E;i++)
	{
    	printf("\nEnter the source vertex:");
    	scanf("%d",&s[i].u);
    	printf("Enter the destination vertex: ");
    	scanf("%d",&s[i].v);
    	printf("Enter the weight: ");
    	scanf("%d",&s[i].w);
    }
    sort();
    printf("\nThe edges of the tree are:");
    kruskal();
}

