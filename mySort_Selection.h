#include <algorithm>

// * 直接选择排序 时间复杂度：O(n^2) 空间复杂度：O(1)
template <class T>
void straightSeleSort(T R[], int size)
{
    int pos, min, j;
    for (pos = 0; pos < size - 1; pos++)
    {
        // min为一趟排序中最小记录的下标
        min = pos;

        // pos为待存放当前最小记录的位置
        for (j = pos + 1; j < size; ++j)
        {
            // 查找最小记录
            if (R[j] < R[min])
            {
                min = j;
            }
        }
        if (pos != min)
        {
            // 交换
            swap(R[pos], R[min]);
        }
    }
}