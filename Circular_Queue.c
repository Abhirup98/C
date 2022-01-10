#include<stdio.h>
#define max 10
int arr[max],frnt=-1,rear=-1;

void insert()
{
	int d;
	if((rear==max-1 && frnt==0)||(rear==frnt-1))
		printf("Queue Overflow");
	else
	{
		printf("Enter data: ");
		scanf("%d",&d);
		if(rear==-1)
		{
			frnt=0;
			rear=0;
		}
		else if(rear==max-1)
			rear=0;
		else
			rear+=1;
		arr[rear]=d;
	}
}

void delete()
{
	int x;
	if(frnt==-1)
		printf("Queue Underflow");
	else
	{
		x=arr[frnt];
		if(frnt==rear)
		{
			frnt=-1;
			rear=-1;
		}
		else if(frnt==max-1)
			frnt=0;
		else
			frnt+=1;
		printf("%d has been deleted",x);	
	}
}

void disp()
{
	int i;
	if(frnt==-1)
		printf("Queue Empty");
	else if(frnt>rear)
	{
		for(i=frnt;i<max;i++)
			printf("%d \t",arr[i]);
		for(i=0;i<=rear;i++)
			printf("%d \t",arr[i]);
	}
	else
		for(i=frnt;i<=rear;i++)
			printf("%d \t",arr[i]);
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

