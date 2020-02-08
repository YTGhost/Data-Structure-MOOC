#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10
#define ERROR NULL

typedef int ElementType;
typedef struct SNode *Stack;
struct SNode{
    ElementType Data[MaxSize];
    int Top;
};

/* 入栈 */
void Push(Stack PtrS, ElementType item)
{
    if(PtrS->Top == MaxSize - 1){
        printf("堆栈满");
        return;
    }else{
        PtrS->Data[++(PtrS->Top)] = item;
        return;
    }
}

/* 出栈 */
ElementType Pop(Stack PtrS)
{
    if(PtrS->Top == -1){
        printf("堆栈空");
        return ERROR;
    }else{
        return (PtrS->Data[(PtrS->Top)--]);
    }
}