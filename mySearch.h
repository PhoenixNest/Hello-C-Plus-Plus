#include <vector>
#include <algorithm>
using namespace std;

// * 顺序查找 时间复杂度：O(n)
// 无序表的顺序查找
template <class T>
int seqSeach(vector<T> &array, const T &key)
{
    int i;

    // 空一个位置设置岗哨，存取待查找的值
    array[0] = key;

    // 从表尾向前查找
    for (i = array.size() - 1; key != array[i]; --i)
        ;

    // 成功则返回元素下标，失败返回0
    return i;
}

// 有序表的顺序查找
template <class T>
int sortBySequential(vector<T> &array, const T &key)
{
    int i;

    // 空一个位置设置岗哨，存取待查找的值
    array[0] = key;

    // 从表尾向前查找
    for (i = array.size() - 1; key < array[i]; --i)
        ;

    // 返回元素位置
    if (key == array[i])
    {
        return i;
    }

    // 失败返回0
    return 0;
}

// * 二分查找(折半查找) 时间复杂度：O(logn)
// ** 比较次数少，查找速度快，平均性能好，但要求待查找表必须顺序存储且有序，适合不经常变动而查找频繁的有序表
// 非递归折半查找
template <class T>
int binarySearch(const vector<T> &array, const T &key)
{
    int low = 1;
    int high = array.size() - 1;
    int mid;

    // 查找范围不为空
    while (low <= high)
    {
        // 计算中间位置
        mid = (low + high) / 2;

        // 查找成功
        if (key == array[mid])
            return mid;

        // 继续在前半区查找，修改high
        if (key < array[mid])
            high = mid - 1;

        // 继续在后半区查找，修改low
        else
            low = mid + 1;
    }

    // 查找失败
    return 0;
}

// 递归折半查找
template <class T>
int binarySearch2(const vector<T> &array, const int &key, int low, int high)
{
    if (low > high)
        return 0;

    int mid = (low + high) / 2;
    
    if (key == array[mid])
        return mid;

    else if (key < array[mid])
        //左区间查找
        return binarySearch2(array, key, low, mid - 1);

    else
        //右区间查找
        return binarySearch2(array, key, mid + 1, high);
}