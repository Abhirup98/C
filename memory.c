#include<stdio.h>

int m,n,p[5];
int fn[]={99,99,99,99,99};

int fifo()
{
	int h=0,c=0,i,j;
	int f[]={99,99,99,99,99};
	printf("\nPage Replacement for FIFO:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			if(f[j]==p[i])
			{
				printf("-");
				break;
			}
		if(j==m)
		{
			f[c]=p[i];
			h++;
			c=(c+1)%m;
			for(j=0;j<m;j++)
				printf("%d ",f[j]);
		}
		printf("\n");
	}
	return h;
}

int min()
{
	int mi=fn[0],mp,i;
	for(i=1;i<m;i++)
		if(mi>fn[i])
			mp = i;
	return mp;
}

int lru()
{
	int f[]={99,99,99,99,99};
	int h=0,c=0,i,j,t;
	printf("\nPage Replacement for LRU:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			if(f[j]==p[i])
			{
				fn[j] = i;
				printf("-");
				break;
			}
		if(j==m)
		{
			t = min();
			if(t<m)
			{
				f[t] = p[i];
				fn[t] = i;
			}
			else
			{
				f[c]=p[i];
				c=(c+1)%m;
			}
			h++;
			for(j=0;j<m;j++)
				printf("%d ",f[j]);
		}
		printf("\n");
	}
	return h;
}

main()
{
	int i,j,fifo_pf,lru_pf;
	printf("Enter the number of pages: ");
	scanf("%d",&n);
	printf("Enter the number of frames: ");
	scanf("%d",&m);
	printf("Enter the pages:\n");
	for(i=0;i<n;i++)
		scanf("%d",&p[i]);
		
	fifo_pf = fifo();
	printf("Page Faults for FIFO: %d\n",fifo_pf);
	
	lru_pf = lru();
	printf("Page Faults for LRU: %d\n",lru_pf);
}

