#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

typedef int ElementType;
typedef int position;

typedef struct LNode *List;
struct LNode
{
    ElementType Data[MAXSIZE];
    position Last;
};

/* 初始化，建立空的顺序表 */
List MakeEmpty()
{
    List PtrL;
    PtrL = (List)malloc(sizeof(struct LNode));
    PtrL->Last = -1; /* 因为初始化时为空的表 */
    return PtrL;
}

/* 查找，查找X所在位置 */
int Find(ElementType X, List PtrL)
{
    int i = 0;
    while (i <= PtrL->Last && PtrL->Data[i] != X)
    {
        i++;
    }
    if (i > PtrL->Last) /* 如果没找到，返回-1 */
    {
        return -1;
    }else{
        return i;   /* 找到后返回的是存储位置 */
    }
}

/* 插入，在第i（1<=i<=n+1）个位置上插入一个值为X的新元素 */
void Insert(ElementType X, int i, List PtrL)
{
    int j;
    if(PtrL->Last == MAXSIZE - 1)
    {
        printf("表满");
        return;
    }
    if(i<1 || i>PtrL->Last+2)   /* i > MAXSIZE + 1 */
    {
        printf("位置不合法");
        return;
    }
    for (j = PtrL->Last; j >= i - 1;j--)
    {
        PtrL->Data[j + 1] = PtrL->Data[j];  /* 倒序后挪 */
    }
    PtrL->Data[i - 1] = X;  /* 新元素插入 */
    PtrL->Last++;   /* Last指向最后元素 */
    return;
}

/* 删除，删除表第i（1<=i<=n）个位置上的元素 */
void Delete(int i, List PtrL)
{
    int j;
    if(i<1 || i > PtrL->Last+1) /* i > MAXSIZE */
    {
        printf("不存在第%d个元素", i);
        return;
    }
    for (j = i; j <= PtrL->Last; j++)
    {
        PtrL->Data[j - 1] = PtrL->Data[j];
    }
    PtrL->Last--;
    return;
}