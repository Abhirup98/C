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
	printf("Enter value: ");
	scanf("%d",&ptr->info);
	ptr->link=NULL;
	return ptr;
}

void insert()
{
	struct node *ptr,*p;
	ptr=create();
	if(strt==NULL)
	{
		strt=ptr;
		ptr->link=ptr;
	}
	else
	{
		p=strt;
		while(p->link!=strt)
			p=p->link;
		ptr->link=strt;
		strt=ptr;
		p->link=strt;
	}
}

void reverse()
{
	struct node *p,*q,*r;
	if(strt==NULL)
		printf("List Empty");
	else
	{
		p=strt->link;
		q=strt;
		strt->link=NULL;
		while(p!=NULL)
		{
			r=p->link;
			p->link=q;
			q=p;
			p=r;
		}
		strt=q->link;
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
		do{
			printf("%d ",p->info);
			p=p->link;
		}while(p!=strt);
	}
}

main()
{
	int i=0;
	for(i=0;i<5;i++)
		insert();
	printf("Original");
	disp();
	reverse();
	printf("\nRversed list:");
	disp();
}

