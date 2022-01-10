#include<stdio.h>
int x[20],count=0,n;
  
void display()
{
	int i,j;
   	count++;
   	printf("\nSolution number %d:\n",count);
   	for(i=1;i<=n;i++)
   	{
    	for(j=1;j<=n;j++)
     	{
       		if(x[i]==j)
       			printf("Q");
       		else
       			printf("*");
     	}
		printf("\n");
	}
   	printf("----------\n");
}

int place(int k,int i)
{
	int j;
   	for(j=1;j<=k-1;j++)
   	{
    	if(x[j]==i)
     		return 0;
     	if(abs(k-j)==abs(i-x[j]))
     		return 0;
   	}
    return 1;
}

void n_queen(int k)
{
	int i;
   	for(i=1;i<=n;i++)
   	{
    	if(place(k,i))
     	{
       		x[k]=i;
       		if(k==n)      
       			display();
       		else
       			n_queen(k+1);
		}
    }
}

main()
{
	int i;
    printf("Enter the number of queens: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    	n_queen(i);
}

