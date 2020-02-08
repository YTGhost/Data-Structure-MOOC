#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct SNode *Stack;
struct SNode{
    ElementType Data;
    Stack Next;
};

Stack CreateStack()
{   /* 构建一个堆栈的头结点，返回指针 */
    Stack S;
    S = (Stack)malloc(sizeof(struct SNode));
    S->Next = NULL;
    return S;
}

int IsEmpty(Stack S)
{   /* 判断堆栈S是否为空，若为空函数返回整数1，否则返回0 */
    return (S->Next == NULL);
}

/* 入栈 */
void Push(ElementType item, Stack S)
{   /* 将元素item压入堆栈S */
    Stack TmpCell;
    TmpCell = (Stack)malloc(sizeof(struct SNode));
    TmpCell->Data = item;
    TmpCell->Next = S->Next;
    S->Next = TmpCell;
}

/* 出栈 */
ElementType Pop(Stack S)
{   /* 删除并返回堆栈S的栈顶元素 */
    Stack FirstCell;
    ElementType TopElem;
    if(IsEmpty(S)){
        printf("堆栈空");
        return NULL;
    }else{
        FirstCell = S->Next;
        S->Next = FirstCell->Next;
        TopElem = FirstCell->Data;
        free(FirstCell);
        return TopElem;
    }
}