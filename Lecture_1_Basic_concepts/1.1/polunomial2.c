#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

clock_t start1, stop1, start2, stop2;
/* clock_t是clock()函数返回的变量类型 */
double duration1, duration2;
/* 记录被测函数运行时间，以秒为单位 */
#define MAXN 101
/* 多项式最大项数，即多项式阶数+1 */
#define MAXK 1e7
/* 被测函数最大重复调用次数 */
double polynomial1(int n, double a[],double x)
{
    int i;
    double p = a[0];
    for(i=1;i<=n;i++)
    {
        p += (a[i] * pow(x, i)/i);
    }
    return p;
}
double polynomial2(int n, double a[],double x)
{
    int i;
    double p = a[n];
    for(i=n;i>0;i--)
    {
        p = a[i-1] + p/i*x;
    }
    return p;
}
int main()
{
    int i;
    double a[MAXN];
    for(i=0;i<MAXN;i++)
    {
        a[i] = 1.0;
    }
    start1 = clock();
    for(i=0;i<=MAXK;i++)
    {
        polynomial1(MAXN-1,a,1.1);
    }
    stop1 = clock();
    start2 = clock();
    for(i=0;i<=MAXK;i++)
    {
        polynomial2(MAXN-1,a,1.1);
    }
    stop2 = clock();
    duration1 = ((double)(stop1 - start1)) / CLK_TCK /MAXK;
    duration2 = ((double)(stop2 - start2)) / CLK_TCK /MAXK;
    printf("ticks1 = %lf\n",(double)(stop1 - start1));
    printf("duration1 = %6.2e\n",duration1);
    printf("ticks2 = %lf\n",(double)(stop2 - start2));
    printf("duration2 = %6.2e\n",duration2);
    system("pause");
    return 0;
}