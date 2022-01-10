#include<stdio.h>
#define max 30

int arr[max],size;

void insert()
{
	int i;
	printf("Enter the array elements:\n");
	for(i=0;i<size;i++)
		scanf("%d",&arr[i]);
}

void max_heapify(int n,int i)
{
	int l,r,largest,tmp;
	l=2*i+1;
	r=2*i+2;
	if(l<n && arr[l]>arr[i])
		largest=l;
	else
		largest=i;
	if(r<n && arr[r]>arr[largest])
		largest=r;
	if(i!=largest)
	{
		tmp=arr[i];
		arr[i]=arr[largest];
		arr[largest]=tmp;
		max_heapify(n,largest);
	}
}

void sort()
{
	int i,tmp;
	for(i=size/2-1;i>=0;i--)
		max_heapify(size,i);
	for(i=size-1;i>=0;i--)
	{
		tmp=arr[0];
		arr[0]=arr[i];
		arr[i]=tmp;
		max_heapify(i,0);
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
	printf("Enter the size of the array: ");
	scanf("%d",&size);
	insert();
	printf("Unsorted array: ");
	disp();
	sort();
	printf("\nSorted array: ");
	disp();
}

