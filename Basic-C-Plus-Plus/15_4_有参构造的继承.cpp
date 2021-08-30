#include <iostream>
using namespace std;

class Basic
{
  public:
    Basic(int a, double b)
    {
        cout << "Basic" << endl;
    }
};

class Bean : public Basic
{
  public:
    Bean(int a) : Basic(1, 1.5)
    {
        cout << "Bean" << endl;
    }
};

class Test1 : public Bean
{
  public:
    /**
     * 由于Test1继承了Bean，Bean类的构造函数为带参数的构造函数，故需要在Test1的构造函数的参数列表中加上父类的有参构造
     * 即有关父类Bean的构造函数的初始化在子类的参数列表中实现
     * 
     * 该处参数列表中的Bean(1)中的1即为传入父类Bean类构造参数中的参数
     * 
     * 继承无法跨级继承，即a继承b，b继承c，但a与c无直接关系
     */
    Test1() : Bean(10)
    {
        cout << "Test1" << endl;
    }

    //也可通过Test1的有参构造向父类Bean的构造函数传递有参构造
    Test1(int a) : Bean(a)
    {
        cout << "Test1 plus" << endl;
    }
};

int main()
{
    Test1 test1;
    Test1 t1(10);

    system("pause");
    return 0;
}