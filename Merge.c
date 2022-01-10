#include<stdio.h>
#include<malloc.h>

struct node
{
	int info;
	struct node *link;
}*strt1=NULL,*strt2=NULL,*strt=NULL;

struct node *insert(struct node *s,int data)
{
	struct node *ptr,*p;
	ptr=(struct node *)malloc(sizeof(struct node));
	ptr->info=data;
	ptr->link=NULL;
	if(s==NULL)
		s=ptr;
	else
	{
		p=s;
		while(p->link!=NULL)
			p=p->link;
		p->link=ptr;
	}
	return s;
}

void merge(struct node *s1,struct node *s2)
{
	struct node *p1=s1,*p2=s2;
	while(p1!=NULL && p2!=NULL)
	{
		if(p1->info<p2->info)
		{
			strt=insert(strt,p1->info);
			p1=p1->link;
		}
		else if(p1->info>p2->info)
		{
			strt=insert(strt,p2->info);
			p2=p2->link;
		}
		else
		{
			strt=insert(strt,p1->info);
			p1=p1->link;
			p2=p2->link;
		}
	}
	while(p1!=NULL)
	{
		strt=insert(strt,p1->info);
		p1=p1->link;
	}
	while(p2!=NULL)
	{
		strt=insert(strt,p2->info);
		p2=p2->link;
	}
}

void disp(struct node *s)
{
	struct node *p;
	if(s==NULL)
		printf("List Empty");
	else
	{
		p=s;
		while(p!=NULL)
		{
			printf("%d ",p->info);
			p=p->link;
		}
	}
}

main()
{
	struct node *ptr;
	int n1,n2,i,data;
	printf("Enter the size of 1st list: ");
	scanf("%d",&n1);
	for(i=0;i<n1;i++)
	{
		printf("Enter value: ");
		scanf("%d",&data);
		strt1=insert(strt1,data);
	}
	printf("Enter the size of 2nd list: ");
	scanf("%d",&n2);
	for(i=0;i<n2;i++)
	{
		printf("Enter value: ");
		scanf("%d",&data);
		strt2=insert(strt2,data);
	}
	printf("\nThe 1st list is:\n");
	disp(strt1);
	printf("\nThe 2nd list is:\n");
	disp(strt2);
	printf("\nThe merged list is:\n");
	merge(strt1,strt2);
	disp(strt);
}

