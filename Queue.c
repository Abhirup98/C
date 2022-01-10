#include<stdio.h>
#define max 30
int arr[max],frnt=-1,rear=-1;

void insert()
{
	int d;
	if(rear==max-1)
		printf("Queue Overload");
	else
	{
		printf("Enter data: ");
		scanf("%d",&d);
		arr[++rear]=d;
		if(frnt==-1)
			frnt+=1;
	}
}


void delete()
{
	if(frnt==-1)
		printf("Queue Underflow");
	else
	{
		printf("%d has been deleted",arr[frnt]);
		frnt+=1;
		if(frnt>rear)
		{
			frnt=-1;
			rear=-1;
		}
	}
}


void disp()
{
	int i;
	if(frnt==-1)
		printf("Queue Empty");
	else
	{
		for(i=frnt;i<=rear;i++)
			printf("%d ",arr[i]);
	}
}

main()
{
	int ch;
	do{
		printf("\n1. Insert \n2. Delete \n3. Display \n4. Exit \n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:insert();
				   break;
			case 2:delete();
				   break;
			case 3:disp();
				    break;
			case 4:printf("Thank You");
				    break;
			default:printf("Wrong Choice");
		}
	}while(ch!=4);
}

