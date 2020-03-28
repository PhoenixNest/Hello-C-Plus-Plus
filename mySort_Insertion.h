#include <algorithm>

// * 直接插入排序 最好的时间复杂度：O(n)，最差的时间复杂度：O(n^2)，空间复杂度：O(1)
template <class T>
void straightInsertSort(T array[], int size)
{
    // pos为待插入记录位置
    int pos, j;
    // 哨兵，缓冲区
    T temp;

    for (pos = 1; pos < size; pos++)
    {
        // 将待插入记录存入临时变量
        temp = array[pos];

        // 从后往前查找插入位置
        for (j = pos - 1; temp < array[j] && j >= 0; j--)
        {
            // 将大于待插入记录的记录向后移动
            array[j + 1] = array[j];
        }

        // 将待插入记录放到合适位置
        array[j + 1] = temp;
    }
}

// * 折半插入排序 时间复杂度：O(n^2)
template <class T>
void binaryInsertSort(T array[], int size)
{
    int pos, j, low, high, mid;
    T temp;
    // 假设第一个记录有序
    for (pos = 1; pos < size; pos++)
    {
        // 将待排序记录array[pos]存入临时变量
        temp = array[pos];

        // 设置折半查找的范围
        low = 0;
        high = pos - 1;

        // 在array[lwo..high]的区间中折半查找有序插入位置
        while (low <= high)
        {
            // 计算中间位置
            mid = (low + high) / 2;

            // 插入点在低半区
            if (temp < array[mid])
            {
                high = mid - 1;
            }
            // 插入点在高半区
            else
            {
                low = mid + 1;
            }

            for (j = pos - 1; j >= low; j--)
            {
                // 记录后移
                array[j + 1] = array[j];
            }
            // 插入待排序记录
            array[low] = temp;
        }
    }
}

// * 希尔排序 时间复杂度约：O(n^1.3) 空间复杂度：O(1)
template <class T>
void shellSort(T array[], int size)
{
    // gap为希尔增量，即步长。pos为待插入记录位置
    int gap, pos, j;
    T temp;
    for (gap = size / 2; gap > 0; gap /= 2)
    {
        for (j = pos - gap; j >= 0 && array[j] > temp; j -= gap)
        {
            // 记录后移
            array[j + gap] = array[j];
        }

        // 将待插入记录放到合适位置
        array[j + gap] = temp;
    }
}