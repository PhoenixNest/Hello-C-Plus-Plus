#include <algorithm>

// * 归并相邻的两个有序子序列
// ** 将有序序列 array[low..mid-1] 和 array[mid..high] 归并为有序序列 array[low..high]
template <class T>
void merge(T array[], T temp[], int low, int mid, int high)
{
    int i = low, j = mid, k = 0;
    while (i < mid && j <= high)
    {
        if (array[i] < array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
    }

    while (i < mid)
        temp[k++] = array[i++];

    while (j <= high)
        temp[k++] = array[j++];

    for (i = 0, k = low; k <= high;)
        array[k++] = temp[i++];
}

// * 递归二路归并排序
template <class T>
void mergeSort(T array[], T temp[], int low, int high)
{
    if (low == high)
        return;

    // 从中间划分为两个子序列
    int mid = (low + high) / 2;

    // 递归对子序列 array[low..mid]进行归并排序
    mergeSort(array, temp, low, mid);

    // 递归对子序列 array[mid+1..high]进行归并排序
    mergeSort(array, temp, mid + 1, high);

    // 归并两个子序列
    merge(array, temp, low, mid + 1, high);
}

// * 二路归并接口函数
template <class T>
void mergeSort(T array[], int size)
{
    // 辅助数组
    T *temp = new T[size];
    mergeSort(array, temp, 0, size - 1);
    delete[] temp;
}