#include <iostream>
#include <string.h>
#include <stdio.h>
#include <queue>
#include <math.h>
using namespace std;
int h;
typedef struct BiTNode{
    char data;
    struct BiTNode *lchild,*rchild;
}BiNode,*BiTree;
typedef struct{
    BiTree bt;
    int num;
}tnode;
queue <tnode> Q;
void create(BiTree T,char BT[])
{
    int len=pow(2,h-1);
    tnode temp;
    temp.bt=T;
    temp.num=1;
    T=(BiTree)malloc(sizeof(BiTNode));
    T->data=BT[1];
    temp.bt=T;
    temp.num=1;
    Q.push(temp);
    while(!Q.empty())
    {
        temp=Q.front();
        BiNode* p=temp.bt;
        int i=temp.num;
        if(BT[2*i]=='#'||2*i>len)
            p->lchild=NULL;
        else {
            p->lchild=(BiTree)malloc(sizeof(BiNode));
            p->lchild->data=BT[2*i];
            temp.bt=p->lchild;
            temp.num=2*i;
            Q.push(temp);
        }
        if(BT[2*i+1]=='#'||2*i+1>len)
            p->rchild=NULL;
        else {
            p->rchild=(BiTree)malloc(sizeof(BiNode));
            p->rchild->data=BT[2*i+1];
            temp.bt=p->rchild;
            temp.num=2*i+1;
            Q.push(temp);
        }
    }
}
int main()
{

   return 0;
}
