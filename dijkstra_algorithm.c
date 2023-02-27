#include<stdio.h>
#include<ctype.h>
#define MAX 30
#define unvisited -1
#define visited 1
#define infinity 32767

int adjacency_mat[MAX][MAX],n;
void display_adj_mat();
void view_path_mat(int[],int,int);
int search_path(int,int,int [],int *);
typedef struct node
{
    int previous, len, status;
} Dalgo;

void main()
{
    char s,d;
    int choice,i,j,k,source,destination,min,total,pathmat[MAX];
    printf("\nEnter the number of nodes : ");
    scanf("%d",&n);
    printf("Enter the adjacency matrix \n");
    for(i=1;i<=n;i++)
           for(j=1;j<=n;j++)
            {
                printf("(%d,%d) = ",i,j);
                scanf("%d",&adjacency_mat[i][j]);
            }
    printf("The adjacency matrix is :\n");
    display_adj_mat();
    while (1)
    {
        fflush(stdin);
        printf("Enter the Source Node : ");
        scanf("%c", &s);
        fflush(stdin);
        printf("Enter the Destination Node : ");
        scanf("%c",&d);
        source=toupper(s)-64; 
        destination=toupper(d)-64;
        total=search_path(source,destination,pathmat,&min);
        view_path_mat(pathmat,total,min);
        printf("\nDo you want to continue? (1/0) : ");
            scanf("%d",&choice);
        if(choice!=1)
            break;
    }
}

void view_path_mat(int PM[MAX],int n,int len)
{
    int k;
    if (len!=0)
    {
        printf("\nMinimum length = %d",len);
        printf("\nShortest path : ");
        for(k=n;k>1;k--)
            printf("%c\t",PM[k]+64);
        printf("%c",PM[k]+64);
        printf("\nDistance = ");
        for (k=n;k>1;k--)
            printf("%d\t", adjacency_mat[PM[k]][PM[k-1]]);
    }
    else
        printf("\nNo path found");
}

void display_adj_mat()
{
    int i,j;
    printf("\n   ");
    for(i=1;i<=n;i++)
        printf("%4c",i+64);
    printf("\n\n");
    for(i=1 ; i<=n ; i++,printf("\n\n"))
        for (j=1;j<=n;j++)
        {
            if(j==1)
                printf("%4c",i+64);
            printf("%4d",adjacency_mat[i][j]);
        }
}

int search_path(int source,int destination,int pathmat[MAX],int *minL)
{
    Dalgo graph[MAX];
    int i,k,min,total=0,curVertex,newLen,u,v;
    *minL=0;
    for(i=1;i<=n;i++)
    {
        graph[i].previous=0;
        graph[i].len=infinity;
        graph[i].status=unvisited;
    }
    graph[source].previous=0;
    graph[source].len=0;
    graph[source].status=visited;
    curVertex=source;
    while(curVertex!=destination)
    {
        for(k=1;k<=n;k++)
        {
            if(adjacency_mat[curVertex][k]>0 && graph[k].status==unvisited)
            {
                newLen=graph[curVertex].len+adjacency_mat[curVertex][k];
                if(newLen < graph[k].len)
                {
                    graph[k].previous=curVertex;
                    graph[k].len=newLen;
                }
            }
        }
        min=infinity;
        curVertex=0;
        for (i=1;i<=n;i++)
        if(graph[i].status==unvisited && graph[i].len<min)
        {
            min=graph[i].len;
            curVertex=i;
        }
        if(curVertex==0)
            return 0;
        graph[curVertex].status = visited;
    }
    while(curVertex!=0)
    {
        pathmat[++total]=curVertex;
        curVertex=graph[curVertex].previous;
    }
    for(i=total;i>1;i--)
    {
        u=pathmat[i];
        v=pathmat[i-1];
        *minL=*minL+adjacency_mat[u][v];
    }
    return total;
}