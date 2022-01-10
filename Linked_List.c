#include<stdio.h>
#include<malloc.h>

struct node
{
	int info;
	struct node *link;
}*strt1=NULL,*strt2=NULL,*strt=NULL;

struct node *insert_beg(struct node *st,int d)
{
	struct node *ptr;
	ptr=(struct node *)malloc(sizeof(struct node));
	ptr->info=d;
	ptr->link=NULL;
	if(st==NULL)
		st=ptr;
	else
	{
		ptr->link=st;
		st=ptr;
	}
	return st;
}

struct node *insert_end(struct node *st,int d)
{
	struct node *ptr,*p;
	ptr=(struct node *)malloc(sizeof(struct node));
	ptr->info=d;
	ptr->link=NULL;
	if(st==NULL)
		st=ptr;
	else
	{
		p=st;
		while(p->link!=NULL)
			p=p->link;
		p->link=ptr;
	}
	return st;
}

struct node *insert_any(struct node *st,int d)
{
	struct node *ptr,*p,*q;
	int pos,i;
	ptr=(struct node *)malloc(sizeof(struct node));
	ptr->info=d;
	ptr->link=NULL;
	if(st==NULL)
		st=ptr;
	else
	{
		p=st;
		i=0;
		printf("Enter the position: ");
		scanf("%d",&pos);
		if(pos==1)
		{
			ptr->link=st;
			st=ptr;
		}
		while(p!=NULL)
		{
			q=p;
			p=p->link;
			if(pos-2==i)
			{
				ptr->link=p;
				q->link=ptr;
				break;
			}
			i++;
		}
		if(p==NULL)
			printf("Position exceeded the number of nodes");
	}
	return st;
}

void del_beg()
{
	struct node *ptr;
	if(strt==NULL)
		printf("List Empty");
	else
	{
		ptr=strt;
		strt=strt->link;
		printf("%d has been deleted",ptr->info);
		free(ptr);
	}
}

void del_end()
{
	struct node *p,*q;
	if(strt==NULL)
		printf("List Empty");
	else
	{
		p=strt;
		while(p->link!=NULL)
		{
			q=p;
			p=p->link;
		}
		q->link=NULL;
		printf("%d has been deleted",p->info);
		free(p);
	}
}

void del_any()
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

void search()
{
	struct node *p;
	int item,i=1;
	if(strt==NULL)
		printf("List Empty");
	else
	{
		p=strt;
		printf("Enter the element to be searched: ");
		scanf("%d",&item);
		while(p!=NULL)
		{
			if(p->info==item)
				break;
			p=p->link;
			i++;
		}
		if(p==NULL)
			printf("%d is not present in list",item);
		else
			printf("%d is present at position %d",item,i);
	}
}

void reverse()
{
	struct node *p,*q,*r;
	if(strt==NULL)
		printf("List Empty");
	else
	{
		p=strt;
		r=NULL;
		while(p!=NULL)
		{
			q=p->link;
			p->link=r;
			r=p;
			p=q;
		}
		strt=r;
		printf("The list has been has been reversed");
	}
}

void sort()
{
	struct node *end,*p,*q;
	int tmp;
	if(strt==NULL)
		printf("List Empty");
	else
	{
		for(end=NULL;end!=strt->link;end=q)
		{
			for(p=strt;p->link!=end;p=p->link)
			{
				q=p->link;
				if(p->info>q->info)
				{
					tmp=p->info;
					p->info=q->info;
					q->info=tmp;
				}
			}
		}
		printf("The list has been sorted");
	}
}

void merge(struct node *s1,struct node *s2)
{
	struct node *p1=s1,*p2=s2;
	while(p1!=NULL && p2!=NULL)
	{
		if(p1->info<p2->info)
		{
			strt=insert_end(strt,p1->info);
			p1=p1->link;
		}
		else if(p1->info>p2->info)
		{
			strt=insert_end(strt,p2->info);
			p2=p2->link;
		}
		else
		{
			strt=insert_end(strt,p1->info);
			p1=p1->link;
			p2=p2->link;
		}
	}
	while(p1!=NULL)
	{
		strt=insert_end(strt,p1->info);
		p1=p1->link;
	}
	while(p2!=NULL)
	{
		strt=insert_end(strt,p2->info);
		p2=p2->link;
	}
}

void disp(struct node *st)
{
	struct node *p;
	if(st==NULL)
		printf("List Empty");
	else
	{
		p=st;
		while(p!=NULL)
		{
			printf("%d ",p->info);
			p=p->link;
		}
	}
}

main()
{
	int ch,d,n,i;
	do{
		printf("\n\n-----MENU-----");
		printf("\n1. Insert at Begining \n2. Insert at End \n3. Insert at Position \n4. Search \n5. Sort \n6. Merge \n7. Reverse \n8. Delete from Begining \n9. Delete from End \n10. Delete Element \n11. Display \n12. Exit \n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter value: ");
				   scanf("%d",&d);
				   strt=insert_beg(strt,d);
				   break;
			case 2:printf("Enter value: ");
				   scanf("%d",&d);
				   strt=insert_end(strt,d);
				   break;
			case 3:printf("Enter value: ");
				   scanf("%d",&d);
				   strt=insert_any(strt,d);
				   break;
			case 4:search();
				   break;
			case 5:sort();
				   break;
			case 6:printf("Enter the size of the 2nd list: ");
				   scanf("%d",&n);
				   for(i=0;i<n;i++)
				   {
				   		printf("Enter value: ");
						scanf("%d",&d);
						strt1=insert_end(strt1,d);
				   }
				   printf("The 2nd list is:\n");
				   disp(strt1);
				   strt2=strt;
				   strt=NULL;
				   merge(strt1,strt2);
				   printf("\nThe merged list is:\n");
				   disp(strt);
				   break;
			case 7:reverse();
				   break;
			case 8:del_beg();
				   break;
			case 9:del_end();
				   break;
			case 10:del_any();
				   break;
			case 11:disp(strt);
				    break;
			case 12:printf("Thank You");
				    break;
			default:printf("Wrong Choice");
		}
	}while(ch!=12);
}

