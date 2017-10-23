#include<stdio.h>
#include<stdlib.h>
#define maxsize 12

typedef struct ArcNode
{
    struct ArcNode* nextarc;
    int adjvex;
//    float Weight;
}ArcNode;

typedef struct VNode
{
    char data;
    ArcNode* firstarc;
}VNode;

typedef struct AGraph
{
    VNode adjlist[maxsize];
    int n,e;
}AGraph;

void Init(int visit[],int num)
{
    int* p;
    p=visit;
    for(int i=0;i<num;i++)
    {
        *p=0;
        printf("Init visit[%d]:%d\n",i,*p);
        ++p;
    }
}

void Create_AGraph(AGraph* G)
{
    int i,j;
    printf("Please input VNode and ArcNode number\n");
    scanf("%d %d",&(G->n),&(G->e));
    printf("VNode and ArcNode number is %d and %d\n",G->n,G->e);
    for(int i=0;i<maxsize;i++)
    {   
        G->adjlist[i].data=i;
        G->adjlist[i].firstarc=NULL;
    }
    ArcNode* p;
    printf("please input adjacent Node, such as 1 2\n");
    for(int k=0;k<G->e;k++)
    {
        p=(ArcNode*)malloc(sizeof(ArcNode));
        if(p==NULL)
        {
            printf("malloc ArcNode fail");
            exit(0);
        }
        scanf("%d %d",&i,&j);
        p->adjvex=j;
        p->nextarc=G->adjlist[i].firstarc;
        G->adjlist[i].firstarc=p;
    }
    p=NULL;
    free(p);
    
}
void PrintGraph(AGraph* G)
{
    ArcNode* p;
    for(int i=0;i<G->n;i++)
    {
        p=G->adjlist[i].firstarc;
        printf("\nArcNode%d point to: ",i);
        while(p!=NULL)
         {
            printf("%d ",p->adjvex);
            p=p->nextarc;
         }
    }
    printf("\n");
}

void DFS(AGraph* G,int visit[maxsize],int v)
{
    ArcNode* p;
    visit[v]=1;
    printf("DFS:%d\n",v);
    p=G->adjlist[v].firstarc;
    while(p!=NULL)
    {
        if(visit[p->adjvex]==0)
            {
                DFS(G,visit,p->adjvex);
            }
        p=p->nextarc;
    }
}
void BFS(AGraph* G,int visit[maxsize],int v)
{
    ArcNode* p;
    int queue[maxsize];
    for(int i=0;i<maxsize;i++)    queue[i]=0;
    int rear=0,front=0,j=0;
    visit[v]=1;
    printf("BFS:%d\n",v);
    rear=(rear+1)%maxsize;
    queue[rear]=v;
    while(front!=rear)
    {
        front=(front+1)%maxsize;
        j=queue[front];
        p=G->adjlist[j].firstarc;
        while(p!=NULL)
        {
            if(visit[p->adjvex]==0)
            {   
                visit[p->adjvex]=1;
                printf("BFS:%d\n",p->adjvex);
                rear=(rear+1)%maxsize;
                queue[rear]=p->adjvex;
            }
            p=p->nextarc;
        }
        
    }
}
int main(void)
{
    int visit[maxsize];
    Init(visit,maxsize);
    AGraph* G;
    G=(AGraph*)malloc(sizeof(AGraph));
    Create_AGraph(G);
    PrintGraph(G);
    DFS(G,visit,0);
    Init(visit,maxsize);
    BFS(G,visit,0);
    return 0;
}














