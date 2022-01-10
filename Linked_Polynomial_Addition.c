#include<stdio.h>
#include<malloc.h>

struct node
{
	int coef,expo;
	struct node *link;
}*strt1=NULL,*strt2=NULL,*strt=NULL;

struct node *insert(struct node *s,int c,int e)
{
	struct node *ptr,*p;
	ptr=(struct node *)malloc(sizeof(struct node));
	ptr->coef=c;
	ptr->expo=e;
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
		if(p1->expo>p2->expo)
		{
			strt=insert(strt,p1->coef,p1->expo);
			p1=p1->link;
		}
		else if(p1->expo<p2->expo)
		{
			strt=insert(strt,p2->coef,p2->expo);
			p2=p2->link;
		}
		else
		{
			strt=insert(strt,p1->coef+p2->coef,p1->expo);
			p1=p1->link;
			p2=p2->link;
		}
	}
	while(p1!=NULL)
	{
		strt=insert(strt,p1->coef,p1->expo);
		p1=p1->link;
	}
	while(p2!=NULL)
	{
		strt=insert(strt,p2->coef,p2->expo);
		p2=p2->link;
	}
}

void disp(struct node *st)
{
	struct node *p=st;
	while(p!=NULL)
	{
		if(p->expo==0)
			printf("%d",p->coef);
		else if(p->expo==1)
			printf("%dx ",p->coef);
		else
			printf("%dx^%d ",p->coef,p->expo);
		if(p->link!=NULL)
			printf("+ ");
		p=p->link;
	}
}

main()
{
	int ex,co;
	char ch='y';
	printf("Enter the 1st polynomial:\n");
	do{
		printf("Enter Coefficient: ");
		scanf("%d",&co);
		printf("Enter Exponent: ");
		scanf("%d",&ex);
		strt1=insert(strt1,co,ex);
		printf("Do you want to enter more values?(Y/N)\n");
		ch=getch();
	}while(ch=='y' || ch=='Y');
	printf("\nEnter the 2nd polynomial:\n");
	do{
		printf("Enter Coefficient: ");
		scanf("%d",&co);
		printf("Enter Exponent: ");
		scanf("%d",&ex);
		strt2=insert(strt2,co,ex);
		printf("Do you want to enter more values?(Y/N)\n");
		ch=getch();
	}while(ch=='y' || ch=='Y');
	printf("\nThe 1st polynomial is:\n");
	disp(strt1);
	printf("\nThe 2nd polynomial is:\n");
	disp(strt2);
	merge(strt1,strt2);
	printf("\nThe added polynomial is:\n");
	disp(strt);
}

