#include <iostream>

#define MAXDATA 1000    /* 该值根据具体情况定义为大于堆中所有可能元素的值 */

typedef int ElementType;
typedef struct HeapStruct *MaxHeap;

struct HeapStruct{
    ElementType *Elements;  /* 存储堆元素的数组 */
    int Size;               /* 堆的当前元素个数 */
    int Capacity;           /* 堆的最大容量 */
};

MaxHeap Create(int MaxSize)
{   /* 创建容量为MaxSize的空的最大堆 */
    MaxHeap H = (MaxHeap)malloc(sizeof(struct HeapStruct));
    H->Elements = (ElementType *)malloc((MaxSize + 1) * sizeof(ElementType));
    H->Size = 0;
    H->Capacity = MaxSize;
    H->Elements[0] = MAXDATA;
    /* 定义“哨兵”为大于堆中所有可能元素的值，便于以后更快操作 */
    return H;
}

void Insert(MaxHeap H, ElementType item)
{   /* 将元素item插入最大堆H,其中H->Elements[0]已经定义为哨兵 */
    int i;
    if(IsFull(H)){
        printf("最大堆已满");
        return;
    }
    i = ++H->Size;  /* i指向插入后堆中的最后一个元素的位置 */
    for (; H->Elements[i / 2] < item; i/=2)
        H->Elements[i] = H->Elements[i / 2]; /* 向下过滤结点 */
    H->Elements[i] = item; /* 将item插入 */
}

ElementType DeleteMax(MaxHeap H)
{
    /* 从最大堆H中取出键值为最大的元素，并删除一个结点 */
}