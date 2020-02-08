#include <stdio.h>
#include <stdlib.h>
int MaxSubseqSum1(int A[], int N);
int MaxSubseqSum2(int A[], int N);
int MaxSubseqSum3(int A[], int N);
int MaxSubseqSum4(int A[], int N);
int Max3(int A, int B, int C);
int DivideAndConquer(int List[], int left, int right);

// 三重循环遍历
int MaxSubseqSum1(int A[], int N)
{
    int ThisSum = 0, MaxSum = 0;
    int i, j, k;
    for (i = 0; i < N; i++)
    {
        for (j = i; j < N; j++)
        {
            for (k = i; k <= j; k++)
                ThisSum += A[k];
            if (ThisSum > MaxSum)
            {
                MaxSum = ThisSum;
            }
            ThisSum = 0;
        }
    }
    return MaxSum;
}
// 二重循环遍历
int MaxSubseqSum2(int A[], int N)
{
    int ThisSum, MaxSum = 0;
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = i; j < N; j++)
        {
            ThisSum += A[j];
            if (ThisSum > MaxSum)
            {
                MaxSum = ThisSum;
            }
        }
        ThisSum = 0;
    }
    return MaxSum;
}
// 分而治之
int MaxSubseqSum3(int A[], int N)
{
    return DivideAndConquer(A, 0, N - 1);
}
// 在线处理
int MaxSubseqSum4(int A[], int N)
{
    int ThisSum = 0, MaxSum = 0;
    int i;
    for (i = 0; i < N; i++)
    {
        ThisSum += A[i];
        if (ThisSum > MaxSum)
            MaxSum = ThisSum;
        else if (ThisSum < 0)
            ThisSum = 0;
    }
    return MaxSum;
}
int Max3(int A, int B, int C)
{
    return A > B ? (A > C ? A : C) : (B > C ? B : C);
}
int DivideAndConquer(int List[], int left, int right)
{
    int MaxLeftSum, MaxRightSum;             // 存放左右子问题的解
    int MaxLeftBorderSum, MaxRightBorderSum; // 存放跨分界线的结果

    int LeftBorderSum, RightBorderSum;
    int center, i;

    if (left == right) // 递归终止的条件，子列只有1个数字
    {
        if (List[left] > 0)
        {
            return List[left];
        }
        else
        {
            return 0;
        }
    }

    // 分
    center = (left + right) / 2; // 找到中分点
    //  递归求得两边子列的最大和
    MaxLeftSum = DivideAndConquer(List, left, center);
    MaxRightSum = DivideAndConquer(List, center + 1, right);

    // 下面求跨分界线的最大子列和
    MaxLeftBorderSum = 0;
    LeftBorderSum = 0;
    for (i = center; i >= left; i--) // 从中线向左扫描
    {
        LeftBorderSum += List[i];
        if (LeftBorderSum > MaxLeftBorderSum)
        {
            MaxLeftBorderSum = LeftBorderSum;
        }
    } /* 左边扫描结束 */

    MaxRightBorderSum = 0;
    RightBorderSum = 0;
    for (i = center+1; i <= right; i++) /* 从中线向右扫描 */
    {
        RightBorderSum += List[i];
        if (RightBorderSum > MaxRightBorderSum)
        {
            MaxRightBorderSum = RightBorderSum;
        }
    } /* 右边扫描结束 */

    /* 下面返回治的结果 */
    return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}

int main()
{
    int K;
    scanf("%d", &K);
    int a[K];
    int i;
    for (i = 0; i < K; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("%d", MaxSubseqSum4(a, K));
    system("pause");
    return 0;
}