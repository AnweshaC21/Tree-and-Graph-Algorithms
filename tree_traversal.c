// binary search tree

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *left;
    struct node *right;
} tree;

tree *bintree=NULL,*newnode;
tree *createnode();
tree *createtree();
tree *insertnode(tree*,tree*);
void preorder(tree*);
void inorder(tree*);
void postorder(tree*);

void main()
{
    int ch;
    printf("Enter elements into Binary Search Tree \n");
    bintree = createtree();
    while(1)
    {
        printf("\nMENU\n");
        printf("1) Preorder Traversal \n");
        printf("2) Inorder Traversal \n");
        printf("3) Postorder Traversal \n");
        printf("4) Exit \n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        if(bintree==NULL)
        {
            printf("Binary Tree is Empty");
            return;
        }
        switch(ch)
        {
            case 1:
                printf("Preorder Traversal : ");
                preorder(bintree);
                printf("\n");
                break;
            case 2:
                printf("Inorder Traversal is : ");
                inorder(bintree);
                printf("\n");
                break;
            case 3:
                printf("Postorder Traversal : ");
                postorder(bintree);
                printf("\n");
                break;
            default:
                exit(1);
        }
    }
    free(bintree);
}
tree *createnode()
{
    newnode=(tree*)malloc(sizeof(tree));
    printf("Enter value : ");
    scanf("%d",&newnode->val);
    newnode->left=NULL;
    newnode->right=NULL;
}
tree *createtree()
{
    int ch=1;
    while(ch==1)
    {
        newnode=createnode();
        bintree=insertnode(bintree,newnode);
        printf("Want to add more? (1/0) : ");
        scanf("%d",&ch);
    }
    return bintree;
}
tree *insertnode(tree *btree,tree *temp)
{
    if(btree==NULL)
        return temp;
    else if(temp->val < btree->val)
        btree->left=insertnode(btree->left,temp);
    else if(temp->val > btree->val)
        btree->right=insertnode(btree->right,temp);
    else
    {
        printf("This value is already there\n");
        return btree;
    }
    return btree;
}
void inorder(tree *btree)
{
    if(btree!=NULL)
    {
        inorder(btree->left);
        printf("%d\t",btree->val);
        inorder(btree->right);
    }
}
void preorder(tree *btree)
{
    if(btree!=NULL)
    {
        printf("%d\t",btree->val);
        preorder(btree->left);
        preorder(btree->right);
    }
}
void postorder(tree *btree)
{
    if(btree!=NULL)
    {
        postorder(btree->left);
        postorder(btree->right);
        printf("%d\t",btree->val);
    }
}