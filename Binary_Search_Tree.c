#include<stdio.h>
#include<malloc.h>

struct tree
{
	int info;
	struct tree *left,*right;
}*root=NULL,*ptr;

struct tree *create()
{
	ptr=(struct tree *)malloc(sizeof(struct tree));
	printf("Ente value: ");
	scanf("%d",&ptr->info);
	ptr->left=NULL;
	ptr->right=NULL;
	return ptr;
}

void insert()
{
	struct tree *parent=NULL,*p=root;
	int f=0;
	ptr=create();
	while(p!=NULL && !f)
	{
		parent=p;
		if(ptr->info==p->info)
			f=1;
		else
		{
			if(ptr->info<p->info)
				p=p->left;
			else
				p=p->right;
		}
	}
	if(!f)
	{
		if(parent==NULL)
			root=ptr;
		else
		{
			if(ptr->info<parent->info)
				parent->left=ptr;
			else
				parent->right=ptr;
		}
	}
	else
		printf("No Duplicate Values\n");
}

void inorder(struct tree *root)
{
	if(root==NULL)
		return;
	else
	{
		inorder(root->left);
		printf("%d ",root->info);
		inorder(root->right);
	}
}

void preorder(struct tree *root)
{
	if(root==NULL)
		return;
	else
	{
		printf("%d ",root->info);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(struct tree *root)
{
	if(root==NULL)
		return;
	else
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->info);
	}
}

main()
{
	int ch;
	do{
		printf("\n1. Insert \n2. Preorder \n3. Inorder \n4. Postorder \n5. Exit \n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:insert();
				   break;
			case 2:preorder(root);
				   break;
			case 3:inorder(root);
				   break;
			case 4:postorder(root);
				   break;
			case 5:printf("Thank You");
				   break;
			default:printf("Wrong Choice");
		}
	}while(ch!=5);
}

