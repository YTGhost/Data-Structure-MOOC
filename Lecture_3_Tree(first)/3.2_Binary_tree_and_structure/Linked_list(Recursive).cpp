#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode *BinTree;
typedef BinTree Position;
typedef int ElementType;
struct TreeNode
{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

/* 先序递归遍历 */
void PreOrderTraversal(BinTree BT)
{
    if (BT)
    {
        printf("%d", BT->Data);
        PreOrderTraversal(BT->Left);
        PreOrderTraversal(BT->Right);
    }
}

/* 中序递归遍历 */
void InOrderTraversal(BinTree BT)
{
    if (BT)
    {
        InOrderTraversal(BT->Left);
        printf("%d", BT->Data);
        InOrderTraversal(BT->Right);
    }
}

/* 后序递归遍历 */
void PostOrderTraversal(BinTree BT)
{
    if(BT)
    {
        PostOrderTraversal(BT->Left);
        PostOrderTraversal(BT->Right);
        printf("%d", BT->Data);
    }
}