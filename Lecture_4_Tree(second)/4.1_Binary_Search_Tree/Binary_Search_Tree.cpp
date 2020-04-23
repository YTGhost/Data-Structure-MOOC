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

Position Find(ElementType X, BinTree BST) /* 尾递归 */
{
    if (!BST)
    {
        return NULL; /* 查找失败 */
    }
    if (X > BST->Data)
    {
        return Find(X, BST->Right); /* 在右子树中继续查找 */
    }
    else if (X < BST->Data)
    {
        return Find(X, BST->Left); /* 在左子树中继续查找 */
    }
    else
    {               /* X == BST->Data */
        return BST; /* 查找成功，返回找到结点的地址 */
    }
}

Position IterFind(ElementType X, BinTree BST)
{
    while (BST)
    {
        if (X > BST->Data)
        {
            BST = BST->Right; /* 向右子树中移动，继续查找 */
        }
        else if (X < BST->Data)
        {
            BST = BST->Left; /* 向左子树中移动，继续查找 */
        }
        else /* X == BST->Data */
        {
            return BST; /* 查找成功，返回找到结点的地址 */
        }
    }
    return NULL; /* 查找失败 */
}

Position FindMin(BinTree BST)
{
    if (!BST)
    {
        return NULL; /* 空的二叉搜索树，返回NULL */
    }
    else if (!BST->Left)
    {
        return BST; /* 找到最左叶结点并返回 */
    }
    else
    {
        return FindMin(BST->Left); /* 沿左分支继续查找 */
    }
}

Position FindMin(BinTree BST) /* 递归 */
{
    if (!BST)
    {
        return NULL; /* 空的二叉搜索树，返回NULL */
    }
    else if (!BST->Left)
    {
        return BST; /* 找到最左叶结点并返回 */
    }
    else
    {
        return FindMin(BST->Left); /* 沿左分支继续查找 */
    }
}

Position FindMax(BinTree BST) /* 迭代 */
{
    if (BST)
    {
        while (BST->Right)
        {
            BST = BST->Right; /* 沿右分支继续查找，直到最右叶结点 */
        }
    }
    return BST;
}

BinTree Insert(ElementType X, BinTree BST)
{
    if (!BST) /* 若原树为空，生成并返回一个结点的二叉搜索树 */
    {
        BST = (BinTree)malloc(sizeof(struct TreeNode));
        BST->Data = X;
        BST->Left = BST->Right = NULL;
    }
    else /* 开始找要插入元素的位置 */
    {
        if (X < BST->Data)
        {
            BST->Left = Insert(X, BST->Left); /* 递归插入左子树 */
        }
        else if (X > BST->Data)
        {
            BST->Right = Insert(X, BST->Right); /* 递归插入右子树 */
        }
        /* else X已经存在，什么都不做 */
    }
    return BST;
}

BinTree Delete(ElementType X, BinTree BST)
{
    Position Tmp;
    if (!BST)
    {
        printf("要删除的元素未找到");
    }
    else if (X < BST->Data)
    {
        BST->Left = Delete(X, BST->Left); /* 左子树递归删除 */
    }
    else if (X > BST->Data)
    {
        BST->Right = Delete(X, BST->Right); /* 右子树递归删除 */
    }
    else if (BST->Left && BST->Right) /* 被删除结点有左右两个子结点 */
    {
        Tmp = FindMin(BST->Right); /* 在右子树中找最小的元素填充删除结点（也可以在左子树中找最大的元素填充删除结点） */
        BST->Data = Tmp->Data;
        BST->Right = Delete(BST->Data, BST->Right); /* 在删除结点的右子树中删除最小元素 */
    }
    else /* 被删除结点有一个或无子结点 */
    {
        Tmp = BST;
        if (!BST->Left) /* 有右孩子或无子结点 */
        {
            BST = BST->Right;
        }
        else if (!BST->Right) /* 有左孩子或无子结点 */
        {
            BST = BST->Left;
        }
        free(Tmp);
    }
    return BST;
}