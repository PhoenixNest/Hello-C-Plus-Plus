#include <iostream>
using namespace std;

//* 直接选择排序
void straightSelectSort(int array[], int size)
{
  int min;
  for (int pos = 0; pos < size - 1; pos++)
  {
    min = pos;
    for (int i = pos + 1; i < size; ++i)
    {
      if (array[i] < array[min])
        min = i;
    }

    if (pos != min)
      swap(array[pos], array[min]);
  }
}

int main()
{
  cout << "Main4" << endl;

  int size = 7;
  int array[] = {8, 5, 192, 44, 28, 89, 86};

  // straightSelectSort(array, size);

  for (int i = 0; i < size; i++)
    cout << array[i] << " | ";

  return 0;
}