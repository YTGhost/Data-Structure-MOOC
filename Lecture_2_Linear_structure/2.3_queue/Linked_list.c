#include <stdio.h>
#include <stdlib.h>
#define MaxSize 6
#define ERROR NULL

typedef int ElementType;
typedef struct QNode *Queue;
struct Node{
    ElementType Data;
    struct Node *Next;
};
struct QNode{   /* 链队列结构 */
    struct Node *rear;  /* 指向队尾结点 */
    struct Node *front; /* 指向队头结点 */
};

/* 出队列 */
ElementType DeleteQ(Queue PtrQ)
{
    struct Node *FrontCell;
    ElementType FrontElem;
    if(PtrQ->front == NULL){
        printf("队列空");
        return ERROR;
    }
    FrontCell = PtrQ->front;
    if(PtrQ->front == PtrQ->rear)   /* 若队列只有一个元素 */
    {
        PtrQ->front = PtrQ->rear = NULL;    /* 删除后队列置为空 */
    }else{
        PtrQ->front = PtrQ->front->Next;
    }
    FrontElem = FrontCell->Data;
    free(FrontCell);    /* 释放被删除结点空间 */
    return FrontElem;
}
