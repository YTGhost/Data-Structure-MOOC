#include <stdio.h>
#include <stdlib.h>
#define MaxSize 6
#define ERROR NULL

typedef int ElementType;
typedef struct QNode *Queue;
struct QNode{
    ElementType Data[MaxSize];
    int rear;
    int front;
};

/* 入队列 */
void AddQ(Queue PtrQ, ElementType item)
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