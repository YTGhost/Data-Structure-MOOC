#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef int MaxSize;
typedef struct SNode *Stack;
struct SNode
{
    BinTree Data;
    Stack Next;
};

typedef struct TreeNode *BinTree;
typedef BinTree Position;
struct TreeNode
{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

Stack CreateStack()
{ /* 构建一个堆栈的头结点，返回指针 */
    Stack S;
    S = (Stack)malloc(sizeof(struct SNode));
    S->Next = NULL;
    return S;
}

int IsEmpty(Stack S)
{ /* 判断堆栈S是否为空，若为空函数返回整数1，否则返回0 */
    return (S->Next == NULL);
}

/* 入栈 */
void Push(Stack S, BinTree T)
{ /* 将元素item压入堆栈S */
    Stack TmpCell;
    TmpCell = (Stack)malloc(sizeof(struct SNode));
    TmpCell->Data = T;
    TmpCell->Next = S->Next;
    S->Next = TmpCell;
}

/* 出栈 */
BinTree Pop(Stack S)
{ /* 删除并返回堆栈S的栈顶元素 */
    Stack FirstCell;
    BinTree TopElem;
    if (IsEmpty(S))
    {
        printf("堆栈空");
        return NULL;
    }
    else
    {
        FirstCell = S->Next;
        S->Next = FirstCell->Next;
        TopElem = FirstCell->Data;
        free(FirstCell);
        return TopElem;
    }
}

/* 中序非递归遍历 */
void InOrderTraversal1(BinTree BT)
{
    BinTree T = BT;
    Stack S = CreateStack(); /* 创建并初始化堆栈S */
    while (T || !IsEmpty(S))
    {
        while (T)
        { /* 一直向左并将沿途结点压入堆栈 */
            Push(S, T);
            T = T->Left;
        }
        if (!IsEmpty(S))
        {
            T = Pop(S);             /* 结点弹出堆栈 */
            printf("%5d", T->Data); /* (访问)打印结点 */
            T = T->Right;           /* 转向右子树 */
        }
    }
}

/* 先序非递归遍历 */
void InOrderTraversal1(BinTree BT)
{
    BinTree T = BT;
    Stack S = CreateStack(); /* 创建并初始化堆栈S */
    while (T || !IsEmpty(S))
    {
        while (T)
        { /* 一直向左并将沿途结点压入堆栈 */
            Push(S, T);
            printf("%5d", T->Data); /* (访问)打印结点 */
            T = T->Left;
        }
        if (!IsEmpty(S))
        {
            T = Pop(S);             /* 结点弹出堆栈 */
            T = T->Right;           /* 转向右子树 */
        }
    }
}
