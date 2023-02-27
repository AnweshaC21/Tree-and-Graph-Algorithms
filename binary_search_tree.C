#include<stdio.h>
#include<conio.h>
struct node
{
	int data;
	struct node *rlink;
	struct node *llink;
} *temp=NULL;
typedef struct node NODE;
NODE *create();
void preorder(NODE *);
void inorder(NODE *);
void postorder(NODE *);
void insert(NODE *);
void main()
{
	int n,i,m;
	clrscr();
	do
	{
		printf("\n\n0. Create\n\n1. Insert\n\n2. Preorder\n\n3. Postorder\n\n4. Inorder\n\n5. Exit\n\n");
		printf("\n\nEnter your choice :: ");
		scanf("%d",&m);
		switch(m)
		{
		case 0:
			temp=create();
			break;
		case 1:
			insert(temp);
			break;
		case 2:
			printf("\n\nDisplay tree in preorder traversal\n\n");
			preorder(temp);
			break;
		case 3:
			printf("\n\nDisplay tree in postorder traversal\n\n");
			postorder(temp);
			break;
		case 4:
			printf("\n\nDisplay tree in inorder traversal\n\n");
			inorder(temp);
			break;
		case 5:
			exit(0);
		}
	}while(n!=5);
	getch();
}
void insert(NODE *root)
{
	NODE *newnode;
	if(root==NULL)
	{
		newnode=create();
		root=newnode;
	}
	else
	{
		newnode=create();
		while(1)
		{
			if(newnode->data < root->data)
			{
				if(root->llink == NULL)
				{
					root->llink=newnode;
					break;
				}
				root=root->llink;
			}
			if(newnode->data > root->data)
			{
				if(root->rlink == NULL)
				{
					root->rlink=newnode;
					break;
				}
				root=root->rlink;
			}
		}
	}
}
NODE * create()
{
	NODE *newnode;
	int n;
	newnode=(NODE *)malloc(sizeof(NODE));
	printf("\n\nEnter the data : ");
	scanf("%d",&n);
	newnode->data=n;
	newnode->llink=NULL;
	newnode->rlink=NULL;
	return newnode;
}
void postorder(NODE *temp)
{
	if(temp!=NULL)
	{
		postorder(temp->llink);
		postorder(temp->rlink);
		printf("%d->",temp->data);
	}
}
void inorder(NODE *temp)
{
	if(temp!=NULL)
	{
		inorder(temp->llink);
		printf("%d->",temp->data);
		inorder(temp->rlink);
	}
}
void preorder(NODE *temp)
{
	if(temp!=NULL)
	{
		printf("%d->",temp->data);
		preorder(temp->llink);
		preorder(temp->rlink);
	}
}