#include <iostream>
using namespace std;

void merge(int array[], int temp[], int low, int mid, int high)
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

void mergeSort(int array[], int temp[], int low, int high)
{
  if (low == high)
    return;

  int mid = (low + high) / 2;

  mergeSort(array, temp, low, mid);
  mergeSort(array, temp, mid + 1, high);
  merge(array, temp, low, mid + 1, high);
}

void mergeSort(int array[], int size)
{
  int *temp = new int[size];
  mergeSort(array, temp, 0, size - 1);
  delete[] temp;
}

int main()
{
  cout << "Main5" << endl;

  int size = 8;
  int array[] = {236, 180, 366, 145, 22, 9, 416, 636};

  mergeSort(array, size);

  for (int i = 0; i < size; i++)
    cout << array[i] << " | ";

  return 0;
}