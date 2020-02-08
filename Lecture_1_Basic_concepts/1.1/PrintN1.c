#include <stdio.h>
#include <stdlib.h>
void PrintN1 (int N)
{
    int i;
    for(i=1;i<=N;i++)
    {
        printf("%d\n",i);
    }
}

void PrintN2 (int N)
{
    if(N)
    {
        PrintN2(N-1);
        printf("%d\n",N);
    }
}

int main()
{
    int N;
    scanf("%d",&N);
    // PrintN1(N);
    PrintN2(N);
    system("pause");
    return 0;
}