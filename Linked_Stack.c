#include<stdio.h>
#include<malloc.h>

struct stack
{
	int info;
	struct stack *link;
}*top=NULL;

struct stack *create()
{
	struct stack *ptr;
	ptr=(struct stack *)malloc(sizeof(struct stack));
	printf("Enter data: ");
	scanf("%d",&ptr->info);
	ptr->link=NULL;
	return ptr;
}

void push()
{
	struct stack *ptr;
	ptr=create();
	if(top==NULL)
		top=ptr;
	else
	{
		ptr->link=top;
		top=ptr;
	}
}

void pop()
{
	struct stack *ptr;
	if(top==NULL)
		printf("List Empty");
	else
	{
		ptr=top;
		top=top->link;
		printf("%d has been deleted",ptr->info);
		free(ptr);
	}
}

void disp()
{
	struct stack*p;
	if(top==NULL)
		printf("List Empty");
	else
	{
		p=top;
		while(p!=NULL)
		{
			printf("%d ",p->info);
			p=p->link;
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

