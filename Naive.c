#include<stdio.h>
#include<string.h>

char P[20],T[20];

void string_matching()
{
	int s,j,f=0;
	int m=strlen(P);
	int n=strlen(T);
	for(s=0;s<=(n-m);s++)
	{
		for(j=0;j<=(m-1);j++)
			if(T[s+j]!=P[j])
				break;
		if(j==m)
		{	
			f++;
			printf("Pattern occurs at position %d\n",s);
		}
	}
	if(!f)
		printf("\nPattern not found\n");
}
	
int main()
{
	printf("Enter the Text: ");
	gets(T);
	printf("Enter the Pattern: ");
	gets(P);
	string_matching();
}

