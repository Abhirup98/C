#include<stdio.h>
#define max 30
int arr[max],top=-1;

void push()
{
	int d;
	if(top==max-1)
		printf("Stack overload");
	else
	{
		printf("Enter data: ");
		scanf("%d",&d);
		arr[++top]=d;
	}
}

void pop()
{
	if(top==-1)
		printf("Stack Empty");
	else
		printf("%d has been deleted",arr[top--]);
}

void disp()
{
	int i;
	if(top==-1)
		printf("Stack Empty");
	else
	{
		i=top;
		while(i>=0)
		{
			printf("%d ",arr[i]);
			i--;
		}
	}
}

main()
{
	int ch;
	do{
		printf("\n1. Push \n2. Pop \n3. Display \n4. Exit \n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:push();
				   break;
			case 2:pop();
				   break;
			case 3:disp();
				   break;
			case 4:printf("Thank You");
				    break;
			default:printf("Wrong Choice");
		}
	}while(ch!=4);
}

