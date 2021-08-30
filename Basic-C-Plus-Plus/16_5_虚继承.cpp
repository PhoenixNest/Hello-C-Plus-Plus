#include <iostream>
using namespace std;

/**
 * 虚继承可解决多继承中访问不明确的问题
 * 不建议使用，结构较为复杂，内存开销大
 */

//被子类虚继承的类称虚基类
class Test_A
{
  public:
    int a = 10;
};

//Test_B虚继承Test_A，拥有Test_A中成员变量a的使用权，但没有a的所有权
class Test_B : virtual public Test_A
{
};

//Test_C虚继承Test_A，拥有Test_A中成员变量a的使用权，但没有a的所有权
class Test_C : virtual public Test_A
{
};

//Test_D虚继承Test_B，Test_C，拥有Test_B，Test_C所继承Test_A中成员变量a的使用权，但没有a的所有权
class Test_D : virtual public Test_B, Test_C
{
};

int main()
{
    Test_D test_d;
    cout << test_d.a << endl;
    
    system("pause");
    return 0;
}