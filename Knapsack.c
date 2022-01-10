#include<stdio.h>

struct knap
{	
	int p,w;
	float r;
}k[10],t;

float x[10]={0},p=0;
int W,n;

void sort()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=1;j<n-i-1;j++)
		{
			if(k[j].r<k[j+1].r)
			{
				t=k[j];
				k[j]=k[j+1];
				k[j+1]=t;
			}
		}
	}
}

int main()
{
	int i;
	printf("Enter the total number of products: ");
	scanf("%d",&n);
	printf("Enter the total weight of the sack: ");
	scanf("%d",&W);
	for(i=0;i<n;i++)
	{
		printf("\nEnter the weight of product %d: ",i+1);
		scanf("%d",&k[i].w);
		printf("Enter the profit of product %d: ",i+1);
		scanf("%d",&k[i].p);
		k[i].r=(float)k[i].p/k[i].w;
	}
	sort();
	for(i=0;i<n;i++)
	{
		if(k[i].w>W)
			break;
		else
		{
			x[i]=1;
			p=p+k[i].p*x[i];
			W=W-k[i].w;
		}
	}
	if(i<=n)
	{
		x[i]=(float)W/k[i].w;
		p=p+k[i].p*x[i];
	}
	printf("\nMaximum Profit = %f",p);
}

