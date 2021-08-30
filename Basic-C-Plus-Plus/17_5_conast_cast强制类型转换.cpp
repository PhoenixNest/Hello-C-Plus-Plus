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
  const Father *father;
  Son *son;

  /**
   * const_cast<type>(expression)
   * 当type和expression一致时才合法
   */
  Father *father_noconast = const_cast<Father *>(father);
  Son *son_noconast = const_cast<Son *>(son);
  system("pause");
  return 0;
}