#include <algorithm>

// * 冒泡排序 最好时间复杂度：O(n)，最坏时间复杂度：O(n^2)，空间复杂度：O(1)
template <class T>
void bubbleSort(T array[], int size)
{
    int i, j;
    // 记录一趟排序后是否发生交换
    bool flag = true;
    for (i = 1; i < size && flag; ++i)
    {
        // 假设本趟排序没有交换
        flag = false;
        for (j = 0; j < size - i; ++j)
        {
            // 逆序排序
            if (array[j + 1] < array[j])
            {
                // 元素交换
                swap(array[j], array[j + 1]);
                flag = true;
            }
        }
    }
}

// * 快速排序 时间复杂度：O(nlogn)
// ** 目前最快的内部排序算法，适用于记录较多且基本无序的序列
//  一趟快速排序
template <class T>
// 参数列表：待排序序列，排序区间的下界，排序区间的上界
int partition(T array[], int low, int high)
{
    // 暂存枢轴
    T temp = array[low];

    // 开始进行分割
    while (low != high)
    {
        // 大下标端找小于枢轴的记录
        while (low < high && array[high] >= temp)
        {
            high--;
        }

        // 该记录移动到小下标端
        if (low < high)
        {
            array[low] = array[high];
            low++;
        }

        // 小下标端找大于枢轴的记录
        while (low < high && array[low] <= temp)
        {
            low++;
        }

        // 该记录移动到大下标端
        if (low < high)
        {
            array[high] = array[low];
            high--;
        }
    }

    // 把枢轴回填到分解位置上
    array[low] = temp;

    // 返回枢轴位置
    return low;
}

// 递归快速排序
template <class T>
void quickSort(T array[], int low, int high)
{
    int pivot;
    if (low >= high)
    {
        return;
    }
    // 一次划分，返回枢轴位置
    pivot = partition(array, low, high);

    // 对枢轴左半端进行快速排序
    quickSort(array, low, pivot - 1);

    // 对枢轴右半端进行快速排序
    quickSort(array, pivot + 1, high);
}

// 快速排序接口函数
template <class T>
// 参数列表：待排序序列，序列大小
void quickSort(T array[], int size)
{
    quickSort(array, 0, size - 1);
}

// * 堆排序 时间复杂度：O(nlogn) 空间复杂度：O(1)
// 向下调整成堆
template <class T>
// 参数列表：待排序序列，要调整的节点编号，序列大小
void siftDown(T array[], int pos, int size)
{
    int child;

    // 暂存“根”记录
    T temp = array[pos];

    for (; pos * 2 + 1 < size; pos = child)
    {
        child = pos * 2 + 1;
        if (child != size - 1 && array[child + 1] > array[child])
        {
            // 选取两个孩子中较大者
            child++;
        }

        if (array[child] > temp)
        {
            // 较大的孩子比双亲大
            array[pos] = array[child];
        }
        else
            break;
    }

    // 调整节点放入正确位置
    array[pos] = temp;
}

// 堆排序
// * 建堆(第一次for循环)的时间复杂度：O(n)
// ** 第二次for循环的时间复杂度：O(nlogn)
template <class T>
void heapSort(T array[], int size)
{
    int i;
    // 初始建堆，从最后一个非叶子节点开始调整堆
    for (i = size / 2 - 1; i >= 0; i--)
    {
        siftDown(array, i, size);
    }

    // 共size - 1趟排序(删除堆顶元素后反复调整堆)
    for (i = size - 1; i > 0; i--)
    {
        // 堆顶元素与子序列中最后一个元素交换
        swap(array[0], array[i]);

        // 将array[0..i]重新调整为大根堆
        siftDown(array, 0, i);
    }
}