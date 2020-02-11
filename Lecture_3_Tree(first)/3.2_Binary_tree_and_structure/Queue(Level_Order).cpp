#include <stdio.h>
#include <stdlib.h>
#define MaxSize 6
#define ERROR NULL

typedef int ElementType;
typedef struct QNode *Queue;
struct QNode{
    BinTree Data[MaxSize];
    int rear;
    int front;
};

typedef struct TreeNode *BinTree;
typedef BinTree Position;
typedef int ElementType;
struct TreeNode
{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

/* 入队列 */
void AddQ(Queue PtrQ, BinTree item)
{
    if((PtrQ->rear+1)%MaxSize == PtrQ->front)
    {
        printf("队列满");
        return;
    }
    PtrQ->rear = (PtrQ->rear + 1) % MaxSize;
    PtrQ->Data[PtrQ->rear] = item;
}

/* 出队列 */
ElementType DeleteQ(Queue PtrQ)
{
    if(PtrQ->front == PtrQ->rear){
        printf("空队列");
        return ERROR;
    }else{
        PtrQ->front = (PtrQ->front + 1) % MaxSize;
        return PtrQ->Data[PtrQ->front];
    }
}

void LevelOrderTraversal (BinTree BT)
{
    Queue Q;
    BinTree T;
    if(!BT)
        return; /* 若是空树则直接返回 */
    Q = CreatQueue();   /* 创建并初始化队列 */
    AddQ(Q, BT);
    while(!IsEmptyQ(Q)){
        T = DeleteQ(Q);
        printf("%d\n", T->Data);    /* 访问取出队列的结点 */
        if(T->Left)
            AddQ(Q, T->Left);
        if(T->Right)
            AddQ(Q, T->Right);
    }
}