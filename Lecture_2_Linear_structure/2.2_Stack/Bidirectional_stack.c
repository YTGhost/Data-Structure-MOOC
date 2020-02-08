#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10

typedef int ElementType;
typedef struct DStack *Stack;
struct DStack
{
    ElementType Data[MaxSize];
    int Top1; /* 堆栈1的栈顶指针 */
    int Top2; /* 堆栈2的栈顶指针 */
} S;

/* 入栈 */
void Push(Stack PtrS, ElementType item, int Tag)
{ /* Tag作为区分两个堆栈的标志，取值为1和2 */
    if (PtrS->Top1 - PtrS->Top2 == 1)
    {
        printf("堆栈满");
        return;
    }
    if (Tag == 1) /* 对第一个堆栈操作 */
    {
        PtrS->Data[++(PtrS->Top1)] = item;
    }
    else
    {
        PtrS->Data[++(PtrS->Top2)] = item;
    }
}

/* 出栈 */
ElementType Pop(Stack PtrS, int Tag)
{
    if (Tag == 1)
    {
        if (PtrS->Top1 == -1)
        {
            printf("堆栈1空");
            return NULL;
        }
        else
        {
            return (PtrS->Data[(PtrS->Top1)--]);
        }
    }
    else
    {
        if (PtrS->Top2 == MaxSize)
        {
            printf("堆栈2空");
            return NULL;
        }
        else
        {
            return PtrS->Data[(PtrS->Top2)++];
        }
    }
}