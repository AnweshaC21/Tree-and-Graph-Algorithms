#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
struct node *newNode(int data)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
void insert_node(struct node *root,int n1,int n2,char lr)
{
	if(root==NULL)
		return;
	if(root->data==n1)
	{
		switch(lr)
		{
		case 'l':
			root->left=newNode(n2);
			break;
		case 'r':
			root->right=newNode(n2);
			break;
		}
	}
	else
	{
		insert_node(root->left,n1,n2,lr);
		insert_node(root->right,n1,n2,lr);
	}
}
void inorder(struct node *root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	printf("%d\t",root->data);
	inorder(root->right);
}
int main()
{
	struct node *root=NULL;
	int n;
	clrscr();
	printf("\nEnter the number of edges : ");
	scanf("%d",&n);
	printf("\nInput nodes of binary tree in order\n\nparent-child-left(or)right-\n\n");
	while(n--)
	{
		char lr;
		int n1,n2;
		scanf("%d %d",&n1,&n2);
		scanf("%d",&lr);
		if(root==NULL)
		{
			root=newNode(n1);
			switch(lr)
			{
			case 'l':
				root->left=newNode(n2);
				break;
			case 'r':
				root->right=newNode(n2);
				break;
			}
		}
		else
		{
			insert_node(root,n1,n2,lr);
		}
	}
	printf("\nInorder Traversal : ");
	inorder(root);
	getch();
	return 0;
}