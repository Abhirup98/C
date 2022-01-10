#include<stdio.h>
int n,s,arr[20];
void bSearch(int lb,int ub,int s)
{
    if(lb<=ub)
    {
        int mid = (lb + ub)/2;
        if (arr[mid] == s)
			printf("Element present at position %d",mid);
        if (arr[mid] < s)
            bSearch(mid+1,ub,s);
        else
            bSearch(lb,mid-1,s);
    }
	if(lb>ub)
	    printf("Element not present");
}
int main()
{
    int i;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    printf("Enter the array elements: ");
    for(i=0;i<n;i++)
    	scanf("%d",&arr[i]);
    printf("Enter the element to be searched: ");
    scanf("%d",&s);
    bSearch(0,n,s);
}

