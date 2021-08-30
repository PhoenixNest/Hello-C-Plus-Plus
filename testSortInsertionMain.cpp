#include <iostream>
using namespace std;

// #include "mySortInsertion.h"

//* 直接插入排序
void straightInsertSort(int array[], int size)
{
  int i;
  int temp;
  for (int pos = 1; pos < size; pos++)
  {
    temp = array[pos];
    for (i = pos - 1; temp < array[i] && i >= 0; i--)
      array[i + 1] = array[i];

    array[i + 1] = temp;
  }
}

//* 折半插入排序
void binaryInsertSort(int array[], int size)
{
  int low, high, mid;
  int temp;
  for (int pos = 1; pos < size; pos++)
  {
    temp = array[pos];

    low = 0;
    high = pos - 1;

    while (low <= high)
    {
      mid = (low + high) / 2;

      if (temp <= array[mid])
        high = mid - 1;
      else
        low = mid + 1;
    }

    for (int j = pos - 1; j >= low; j--)
      array[j + 1] = array[j];

    array[low] = temp;
  }
}

//* 希尔排序
void shellSort(int array[], int size)
{
  int gap, pos;
  int i;
  int temp;

  for (gap = size / 2; gap > 0; gap /= 2)
  {
    for (pos = gap; pos < size; pos++)
    {
      temp = array[pos];
      for (i = pos - gap; i >= 0 && array[i] > temp; i -= gap)
        array[i + gap] = array[i];

      array[i + gap] = temp;
    }
  }
}

int main()
{
  cout << "Main3" << endl;

  int size = 7;
  int array[] = {8, 5, 144, 44, 28, 89, 86};

  // straightInsertSort(array, size);
  // binaryInsertSort(array, size);
  // shellSort(array, size);

  for (int i = 0; i < size; i++)
    cout << array[i] << " | ";

  return 0;
}