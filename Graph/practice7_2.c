#include<stdio.h>
#include<stdlib.h>
#define maxsize 12
#define true 1
#define false 0
typedef struct ArcNode
{
    struct ArcNode* nextarc;
    int adjvex;
//  int weight;
}ArcNode;

typedef struct VNode
{
    ArcNode* firstarc;
    int data;
}VNode;

typedef struct AGraph
{
    VNode adjlist[maxsize];
    int n,e;
}AGraph;

void Create_AGraph(AGraph* G)
{
    printf("please input VNode and ArcNode number\n");
    scanf("%d %d",&(G->n),&(G->e));
    printf("please input adjacent arc\n");
    ArcNode* p;
    int i=0,j=0;
    for(int k=0;k<G->n;k++)
    {
        G->adjlist[k].firstarc=NULL;
        G->adjlist[k].data=k;
    }
    for(int k=0;k<G->e;k++)
    {
        p=(ArcNode*)malloc(sizeof(ArcNode));
        if(p==NULL) printf("malloc fail\n");
        scanf("%d %d",&i,&j);
        p->adjvex=j;
        p->nextarc=G->adjlist[i].firstarc;
        G->adjlist[i].firstarc=p;
    }
    p=NULL;
    free(p);
}


void DFS(AGraph* G,int visit[maxsize],int v,int &en,int &vn)
{
    ArcNode* p;
    visit[v]=1; ++vn;
    printf("DFS:%d\n",v);
    p=G->adjlist[v].firstarc;
    while(p!=NULL)
    {
        ++en;
        if(visit[p->adjvex]==0)
        {
            DFS(G,visit,p->adjvex,en,vn);
        }
        p=p->nextarc;
    }
}
int Is_Gist(AGraph* G,int visit[maxsize])
{
    int en=0,vn=0;
    DFS(G,visit,0,en,vn);
    if((vn==G->n)&&(en==G->n-1))
        return true;
    else
        return false;   
}
int main(void)
{
    AGraph* G;
    G=(AGraph*)malloc(sizeof(AGraph));
    int visit[maxsize];
    for(int i=0;i<maxsize;i++)    visit[i]=0;
    Create_AGraph(G);
    if (Is_Gist(G,visit)==true)
        {
            printf("tree\n");
        }else{
            printf("flase\n");
        }
    return 0;
}


