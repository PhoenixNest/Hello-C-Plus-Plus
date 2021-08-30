#include <iostream>
using namespace std;

class Stu
{
private:
  int age;
  double score;

public:
  Stu()
  {
    age = 0;
    score = 0.0;
  }

  //=赋值，[]下标运算，()，->必须在类内作为成员声明
  int operator=(int a)
  {
    age = a;
    return age;
  }

  //由于在类内可以直接调用私有成员，故建议在类内写运算符重载函数
  int &operator+=(int a)
  {
    age = age + a;
    return age;
  }
};

int main()
{
  Stu s1;

  //cout << (s1 = 100) << endl;
  cout << (s1 += 100) << endl;

  system("pause");
  return 0;
}