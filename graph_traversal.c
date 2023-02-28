#include <stdio.h>
#include <stdlib.h>

int a[10][10], visited[10], n;

void breadthSearch(int);
void depthSearch(int);
void insertAdjacency();

void main()
{
    int i, choice;
        while (1)
        {
        printf("\nGraph Traversals : ");
        printf("\n1. Breadth - First Traversal \n");
        printf("2. Depth - First Traversal \n");
        printf("3. Exit \n");
        printf("Enter the Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertAdjacency();
            printf("Nodes are visited in this order ");
            for (i = 1; i <= n; i++)
                if (visited[i] == 0)
                    breadthSearch(i);
            printf("\n");
            break;
        case 2:
            insertAdjacency();
            printf("Nodes are visited in this order ");
            for (i = 1; i <= n; i++)
                if (visited[i] == 0)
                    depthSearch(i);
            printf("\n");
            break;
        default:
            exit(1);
        }
    }
}

void insertAdjacency()
{
    int i, j;
    printf("\nEnter the number of nodes: ");
    scanf("%d",&n);
    printf("Enter the adjacency matrix: \n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (i!=j)
            {
                printf("Enter the value of (%d, %d) element: ", i, j);
                scanf("%d", &a[i][j]);
            }
    for (i = 1; i <= n; i++)
        visited[i] = 0;
}

void breadthSearch(int k)
{
    int i;
    printf("-> %d ", k);
    visited[k] = 1;
    for (i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            if (a[k][i] != 0)
            {
                breadthSearch(i);
            }
        }
        break;
    }
}

void depthSearch(int k)
{
    int i;
    printf("-> %d ", k);
    visited[k] = 1;
    for (i = 1; i <= n; i++)
        if (visited[i] == 0)
            if (a[k][i] != 0)
                depthSearch(i);
}
