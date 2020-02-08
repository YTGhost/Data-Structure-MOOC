#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode
{
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
Position BinarySearch(List L, ElementType X);

int main()
{
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch(L, X);
    printf("%d\n", P);

    return 0;
}

/* 你的代码将被嵌在这里 */
Position BinarySearch(List L, ElementType X)
{
    Position S = 1;
    Position E = L->Last;
    Position center = (S + E) / 2;
    while(1)
    {
        if(S == E){
            if(X == L->Data[center]){
                return center;
            }else{
                return NotFound;
            }
        }
        if(X > L->Data[center])
        {
            S = center + 1;
        }else if(X < L->Data[center]){
            E = center;
        }else{
            return center;
        }
        center = (S + E) / 2;
    }
}