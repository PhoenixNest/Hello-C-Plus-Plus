#include <iostream>
using namespace std;

class Father
{
public:
  int a;
};

class Son : public Father
{
public:
  int b;
};

class Other
{
public:
  int c;
};

int main()
{
  Father *father;
  Son *son;
  Other *other;

  father = (Son *)son;

  //无法在两个无联系的指针之间进行强制类型转换
  //father = (Other *)other; //非法

  /**
   * static_cast<type>(expression)
   * 当type和expression可以互相隐式转换时才合法
   * 无法在两个无联系的指针之间进行强制类型转换
   */
  //father = static_cast<Other *> (other);

  cout << "Hello_World" << endl;

  system("pause");
  return 0;
}