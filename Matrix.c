#include<stdio.h>
int main()
{
	int a[3][3]={{1,2,3},{0,4,5},{0,0,6}},i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
		    printf("%d   ",a[i][j]);
	     }
		 printf("\n");
     }	  	   
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(j<i && a[i][j]==0)
				printf("  ");
			else
				printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}

