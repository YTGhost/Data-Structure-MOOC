#define NotFound -1
int BinarySearch(List Tbl, ElementType K)
{
    /* 在表Tbl中查找关键字为K的数据元素 */
    int left, right, mid, NoFound = -1;
    left = 1;   /* 初始左边界 */
    right = Tbl->Length;    /* 初始右边界 */
    while(left <= right)
    {
        mid = (left + right) / 2;   /* 计算中间元素坐标 */
        if(K < Tbl->Element[mid]){
            right = mid - 1;    /* 调整右边界 */
        }
        else if(K>Tbl->Element[mid]){
            left = mid + 1; /* 调整左边界 */
        }else{
            return mid; /* 查找成功，返回数据元素的下标 */
        }
        return NotFound;    /* 查找不成功，返回-1 */

    }
}