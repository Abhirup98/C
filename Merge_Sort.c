#include<stdio.h>

int arr[30],size;

void insert()
{
	int i;
	printf("Enter the array elements: ");
	for(i=0;i<size;i++)
		scanf("%d",&arr[i]);
}

void merge(int l,int m,int u)
{
	int i=l,j=l,k=m+1,t;
	int b[30];
	while(j<=m && k<=u)
	{
		if(arr[j]>arr[k])
			b[i++]=arr[k++];
		else
			b[i++]=arr[j++];
	}
	if(k>u)
		for(t=j;t<=m;t++)
			b[i++]=arr[t];
	else
		for(t=k;t<=u;t++)
			b[i++]=arr[t];
	for(i=l;i<=u;i++)
		arr[i]=b[i];
}


void merge_sort(int l,int u)
{
	if(l<u)
	{
		int m=(l+u)/2;
		merge_sort(l,m);
		merge_sort(m+1,u);
		merge(l,m,u);
	}
}

void disp()
{
	int i;
	for(i=0;i<size;i++)
		printf("%d ",arr[i]);
}

main()
{
	int n;
	printf("Enter the size of the array: ");
	scanf("%d",&size);
	insert();
	n=size;
	printf("Unsorted array: ");
	disp();
	merge_sort(0,size-1);
	printf("\nSorted array: ");
	disp();
}

