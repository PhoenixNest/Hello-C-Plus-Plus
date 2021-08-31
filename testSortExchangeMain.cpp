#include <iostream>
using namespace std;

// #include "mySortExchange.h"

//* 冒泡排序
void bubbleSort(int array[], int size)
{
  bool flag = true;
  for (int i = 1; i < size && flag; ++i)
  {
    flag = false;
    for (int j = 0; j < size - i; ++j)
    {
      if (array[j + 1] < array[j])
      {
        swap(array[j], array[j + 1]);
        flag = true;
      }
    }
  }
}

//* 二分排序
void mBinaryInsertSort(int array[], int size)
{
  int low, mid, high;
  int temp;
  for (int pos = 1; pos < size; pos++)
  {
    temp = array[pos];
    low = 0;
    high = pos - 1;
    while (low <= high)
    {
      mid = (low + high) / 2;
      if (temp < array[mid])
        high = mid - 1;

      else
        low = mid + 1;
    }
    for (int j = pos - 1; j >= low; j--)
      array[j + 1] = array[j];

    array[low] = temp;
  }
}

//* 快速排序
int fastSort(int array[], int low, int high)
{
  int temp = array[low];
  while (low != high)
  {
    while (low < high && array[high] >= temp)
      high--;

    array[low] = array[high];
    // if (low < high)
    // {
    //   array[low] = array[high];
    //   low++;
    // }

    while (low < high && array[low] <= temp)
      low++;

    array[high] = array[low];
    // if (low < high)
    // {
    //   array[high] = array[low];
    //   high--;
    // }
  }

  array[low] = temp;

  return low;
}

//* 堆排序
// -- 调堆
void siftDown(int array[], int pos, int size)
{
  int child;
  int temp = array[pos];
  for (; pos * 2 + 1 < size; pos = child)
  {
    child = pos * 2 + 1;
    if (child != size - 1 && array[child + 1] > array[child])
      child++;

    if (array[child] > temp)
      array[pos] = array[child];
    else
      break;
  }

  array[pos] = temp;
}

//* -- 正式堆排序
void heapSort(int array[], int size)
{
  // --- 建堆
  for (int i = size / 2 - 1; i >= 0; i--)
    siftDown(array, i, size);

  // --- 调堆
  for (int i = size - 1; i > 0; i--)
  {
    swap(array[0], array[i]);
    siftDown(array, 0, i);
  }
}

int main()
{
  cout << "Main2" << endl;

  int size = 7;
  int array[] = {8, 5, 250, 44, 28, 89, 75};

  // bubbleSort(array, size);
  // fastSort(array, 0, size - 1);
  // mBinaryInsertSort(array, size);
  // heapSort(array, size);

  for (int i = 0; i < size; i++)
    cout << array[i] << " | ";

  return 0;
}