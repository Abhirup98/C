#include<stdio.h>
#include<malloc.h>

struct node
{
	int info;
	struct node *link;
}*strt=NULL;

struct node *create()
{
	struct node *ptr;
	ptr=(struct node *)malloc(sizeof(struct node));
	printf("Ente value: ");
	scanf("%d",&ptr->info);
	ptr->link=NULL;
	return ptr;
}

void insert()
{
	struct node *ptr,*p=strt,*q;
	ptr=create();
	if(strt==NULL)
		strt=ptr;
	else
	{
		if(strt->info>ptr->info)
		{
			ptr->link=strt;
			strt=ptr;
		}
		while(p->link!=NULL)
		{
			q=p;
			p=p->link;
			if(ptr->info<=p->info)
			{
				ptr->link=p;
				q->link=ptr;
				break;
			}
		}
		if(p->info<ptr->info)
			p->link=ptr;
	}
}

void delete()
{
	struct node *p,*q;
	int item;
	if(strt==NULL)
		printf("List Empty");
	else
	{
		p=strt;
		printf("Enter the element to be deleted: ");
		scanf("%d",&item);
		if(strt->info==item)
		{
			p=strt;
			strt=strt->link;
			free(p);
			printf("%d has been deleted",item);
			return;
		}
		else
		{
			while(p->link!=NULL)
			{
				q=p;
				p=p->link;
				if(p->info==item)
				{
					q->link=p->link;
					free(p);
					printf("%d has been deleted",item);
					return;
				}
			}
		}
		printf("%d is not present in list",item);
	}
}

void disp()
{
	struct node *p;
	if(strt==NULL)
		printf("List Empty");
	else
	{
		p=strt;
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
				   	   	   

