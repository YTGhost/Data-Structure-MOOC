int SequentialSearch (List Tbl, ElementType K)
{
    /* 在Element[1]~Element[n]中查找关键字为K的数据元素 */
    int i;
    Tbl->Element[0] = K;    /* 建立哨兵 */
    for (i = Tbl->Length; Tbl->Element[i] != K; i--)
        ;
    return i;   /* 查找成功返回所在单元下标；不成功返回0 */
}