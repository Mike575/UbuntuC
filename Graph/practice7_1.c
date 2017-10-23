#include<stdio.h>
#include<stdlib.h>
#define maxsize 12

typedef struct ArcNode
{
    struct ArcNode* nextarc;
    int adjvex;
//  int weight; 
}ArcNode;

typedef struct VNode
{
    int data;
    ArcNode* firstarc;
}VNode;

typedef struct AGraph
{
    VNode adjlist[maxsize];
    int n,e;
}AGraph;

void Create_AGraph(AGraph* G)
{
    ArcNode* p;
    int i=0,j=0;
    printf("please input VNode and ArcNode Number\n");
    scanf("%d %d",&(G->n),&(G->e));
    printf("VNode:%d ArcNode:%d\n",G->n,G->e);
    for(int k=0;k<maxsize;k++)
    {
        G->adjlist[k].data=k;
        G->adjlist[k].firstarc=NULL;
    }
    for(int k=0;k<G->e;k++)
    {
        p=(ArcNode*)malloc(sizeof(ArcNode));
        if(p==NULL) printf("malloc ArcNode fail\n");
        printf("please input adjacent arc\n");
        scanf("%d %d",&i,&j);
        p->adjvex=j;
        p->nextarc=G->adjlist[i].firstarc;
        G->adjlist[i].firstarc=p;
    }
    p=NULL;
    free(p);
}

void Init_array(int visit[maxsize])
{
    int* p=visit;
    for(int k=0;k<maxsize;k++) 
        {
            visit[k]=0;
        }
}

void BFS(AGraph* G,int visit[maxsize],int v)
{
    ArcNode* p;
    int queue[maxsize];
    for(int k=0;k<maxsize;k++) queue[k]=0;
    int rear=0,front=0,j=0;
    printf("BFS:%d\n",v);
    visit[v]=1;
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
                printf("BFS:%d\n",p->adjvex);
                visit[p->adjvex]=1;
                rear=(rear+1)%maxsize;
                queue[rear]=p->adjvex;
            }
            p=p->nextarc;
        }
    }
   printf("the fartest VNode:%d\n",queue[rear]);
}

int main(void)
{
    int visit[maxsize];
    Init_array(visit);
    for(int k=0;k<maxsize;k++) printf("%d ",visit[k]);
    AGraph* G;
    G=(AGraph*)malloc(sizeof(AGraph));
    Create_AGraph(G);
    BFS(G,visit,0);
}
