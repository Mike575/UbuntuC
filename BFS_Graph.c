#include<stdio.h>
#define maxsize 100

typedef struct ArcNode
{
    int adjvex;     // the node which arc point to
    struct ArcNode* nextarc;    
}ArcNode;

typedef struct VNode    //first node
{
    char data;
    ArcNode* firstarc;
}VNode;

typedef struct
{
    VNode adjlist[maxsize];
    int n,e;
}AGraph;

void Init_AGragph(AGraph* p)
{
    p->n=5;p->e=7;

    p->adjlist[0].data=0; 
    p->adjlist[1].data=0; 
    p->adjlist[2].data=0; 
    p->adjlist[3].data=0; 
    p->adjlist[4].data=0; 
    p->adjlist[0].firstarc=
    
