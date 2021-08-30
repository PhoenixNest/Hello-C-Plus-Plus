#include <iostream>
using namespace std;

class Bean
{
  private:
    void fun1()
    {
        cout << "Bean private" << endl;
    }

  protected:
    void fun2()
    {
        cout << "Bean protected" << endl;
    }

  public:
    void fun3()
    {
        cout << "Bean public" << endl;
    }
};

class Test1 : public Bean
{
  public:
    void fun4()
    {
    }
};

/**
 * 该处以protected的方式继承了父类Bean(即Bean类中的成员可在Test2中使用，但不可在除Bean类和Test2类外使用)
 * 此时Bean类中的public方法会被降级为protected方法
 */
class Test2 : protected Bean
{
  public:
    void fun5()
    {
        //fun1(); //private方法，只可在声明的类(Bean)中使用，此时不会因为protected继承被降级
        fun2(); //protected方法，此时不会受protected继承影响
        fun3(); //public方法，此时会被降级为protected方法
    }
};

//可多层继承
class Demo : protected Test2
{
  public:
    void demo()
    {
        //可调用Bean类中的fun3()
        fun3();
        //可调用Test2类中的fun5()
        fun5();
    }
};

/**
 * 该处以private的方式继承了父类Bean()
 * 此时Bean类中的public，protected方法会被降级为private方法
 */
class Test3 : private Bean
{
  public:
    void fun6()
    {
        //fun1(); //private方法，只可在声明的类(Bean)中使用，此时不会受private继承影响
        fun2(); //protected方法，此时会被降级为private方法
        fun3(); //public方法，此时会被降级为private方法
    }
};

int main()
{
    Test1 test1;
    test1.fun3();
    test1.fun4();

    Test2 test2;
    //不可在类外调用private修饰的fun1()，protected修饰的fun2()和被降级为protected类型的fun3()
    test2.fun5();

    Test3 test3;
    //不可在类外调用private修饰的fun1()，被降级为private类型的fun2()和fun3()
    test3.fun6();

    system("pause");
    return 0;
}