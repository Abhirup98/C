#include<stdio.h>
#include<malloc.h>

struct node
{
	int info;
	struct node *link;
}*frnt=NULL,*rear=NULL;

struct node *create()
{
	struct node *ptr;
	ptr=(struct node *)malloc(sizeof(struct node));
	printf("Enter data: ");
	scanf("%d",&ptr->info);
	ptr->link=NULL;
	return ptr;
}

void insert()
{
	struct node *ptr;
	ptr=create();
	if(frnt==NULL)
	{
		frnt=ptr;
		rear=ptr;
	}
	else
	{
		rear->link=ptr;
		rear=ptr;
	}
}

void delete()
{
	struct node *ptr;
	if(frnt==NULL)
		printf("Queue Empty");
	else
	{
		ptr=frnt;
		frnt=frnt->link;
		printf("%d has been deleted",ptr->info);
		free(ptr);
	}
}

void disp()
{
	struct node *ptr;
	if(frnt==NULL)
		printf("Queue Empty");
	else
	{
		ptr=frnt;
		while(ptr!=NULL)
		{
			printf("%d ",ptr->info);
			ptr=ptr->link;
		}
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

