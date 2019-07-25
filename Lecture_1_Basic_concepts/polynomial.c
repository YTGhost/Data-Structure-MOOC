#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

clock_t start, stop;
/* clock_t是clock()函数返回的变量类型 */
double duration;
/* 记录被测函数运行时间，以秒为单位 */
#define MAXN 10
/* 多项式最大项数，即多项式阶数+1 */
#define MAXK 1e7
/* 被测函数最大重复调用次数 */
double polynomial1(int n, double a[],double x)
{
    int i;
    double p = a[0];
    for(i=1;i<=n;i++)
    {
        p += (a[i] * pow(x, i));
    }
    return p;
}
double polynomial2(int n, double a[],double x)
{
    int i;
    double p = a[n];
    for(i=n;i>0;i--)
    {
        p = a[i-1] + x*p;
    }
    return p;
}
int main()
{
    int i;
    double a[MAXN];
    for(i=0;i<MAXN;i++)
    {
        a[i] = (double)i;
    }
    start = clock();
    for(i=0;i<=MAXK;i++)
    {
        polynomial1(MAXN-1,a,1.1);
    }
    //polynomial2();
    stop = clock();
    duration = ((double)(stop - start)) / CLK_TCK;
    printf("ticks = %lf\n",(double)(stop - start));
    printf("duration = %lf\n",duration);
    system("pause");
    return 0;
}