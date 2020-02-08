#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct LNode *List;
struct LNode
{
    ElementType Data;
    List Next;
};

/* 求表长 */
int Length(List PtrL)
{
    List p = PtrL; /* p指向表的第一个结点 */
    int j = 0;
    while (p)
    {
        p = p->Next;
        j++; /* 当前p指向的是第j个结点 */
    }
    return j;
}

/* 按照序号查找 */
List FindKth(int K, List PtrL)
{
    List p = PtrL;
    int i = 1;
    while (p != NULL && i < K)
    {
        p = p->Next;
        i++;
    }
    // if(i == K)
    // {
    //     return p;   /* 找到第K个，返回指针 */
    // }else{
    //     return NULL;    /* 否则返回空 */
    // }
    return p;
}

/* 按值查找 */
List Find(ElementType X, List PtrL)
{
    List p = PtrL;
    while (p != NULL && p->Data != X)
    {
        p = p->Next;
    }
    return p;
}

/* 插入，在第i-1(1<=i<=n+1)个结点后插入一个值为X的新结点 */
List Insert(ElementType X, int i, List PtrL)
{
    List p, s;
    if (i == 1)
    {                                           /* 新结点插入在表头 */
        s = (List)malloc(sizeof(struct LNode)); /* 申请、填装结点 */
        s->Data = X;
        s->Next = PtrL;
        return s; /* 返回新表头指针 */
    }
    p = FindKth(i - 1, PtrL); /* 查找第i-1个结点 */
    if (p == NULL)
    {
        printf("参数i错");
        return NULL;
    }
    else
    {
        s = (List)malloc(sizeof(struct LNode)); /* 申请、填装结点 */
        s->Data = X;
        s->Next = p->Next; /* 新结点插入在第i-1个结点的后面 */
        p->Next = s;
        return PtrL;
    }
}

/* 删除，删除链表的第i(1<=i<=n)个位置上的结点 */
List Delete(int i, List PtrL)
{
    List p, s;
    if (i == 1)
    {             /* 若要删除的是表的第一个结点 */
        s = PtrL; /* s指向第一个结点 */
        if (PtrL != NULL)
        {
            PtrL = PtrL->Next;
        }
        else
        {
            return NULL;
        }
        free(s);
        return PtrL;
    }
    p = FindKth(i - 1, PtrL);
    if (p == NULL)
    {
        printf("第%d个结点不存在", i - 1);
        return NULL;
    }
    else if (p->Next == NULL)
    {
        printf("第%d个结点不存在", i);
        return NULL;
    }
    else
    {
        s = p->Next;
        p->Next = s->Next;
        free(s);
        return PtrL;
    }
}