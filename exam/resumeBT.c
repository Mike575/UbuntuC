#include<stdio.h>
#include<stdlib.h>

typedef struct BTNode
{
	char data;
	struct BTNode* lchild;
	struct BTNode* rchild;
}BTNode;
//Back L1~R1;Center L2~R2
BTNode* BCresume(int a[],int b[],int L1,int R1,int L2,int R2)
{
	int k;
	if(L1>R1) return NULL;
	else
	{
		BTNode* s=(BTNode*)malloc((sizeof(BTNode));
		s->data=a[R1];
		for(k=L2;k<=R2;++k)
			if(b[k]==a[R1]) break;
		s->lchild=BCresume(a,b,L1,L1+k-L2-1,L2,k-1);
		s->rchild=BCresume(a,b,L1+k-L2;R1-1,k+1,R2);
		return s;
	}
}

// Pre: L1~R1; Center: L2~R2
BTNode* PCresume(int a[],int b[],int L1,int R1,int L2,int R2)
{
	int k;
	if(L1>R1) return NULL;
	else
	{
		BTNode* s=(BTNode*)malloc((sizeof(BTNode));
		s->data=a[R1];
		for(k=L2;k<=R2;++k)
			if(b[k]==a[R1]) break;
		s->lchild=PCresume(a,b,L1+1,L1+k-L2,L2,k-1);
		s->rchild=PCresume(a,b,L1+k-L2+1,R1,k+1,R2);
		return s;
	}
}

void PreTraverse(BTNode* tree)
{
	if(tree!=NULL)
	{
		printf(" %c",tree->data);
		PreTraverse(tree->lchild);
		PreTraverse(tree->rchild);
	}
}
void PostTraverse(BTNode* tree)
{
	if(tree!=NULL)
	{
		PostTraverse(tree->lchild);
		PostTraverse(tree->rchild);
		printf(" %c",tree->data);
	}
}

int main()
{
	
}
