#include <iostream>
using namespace std;

class Father
{
  private:
    int a;

  public:
    Father()
    {
        a = 10;
    }

    void fun(int a)
    {
        cout << a << endl;
    }

    friend void test();
};

class Son : public Father
{
  private:
    int a;

  public:
    Son()
    {
        a = 20;
    }

    void fun()
    {
        cout << a << endl;
    }
};

//父类的友元
void test()
{
    Father f;
    cout << f.a << endl;

    //子类无法继承父类中的友元函数
    // Son s;
    // s.fun();
}

int main()
{
    /**
     * 子类继承父类
     * 父类和子类中的重名成员会被子类覆盖
     * 但如果加上作用域运算符就不会覆盖，而是形成共存
     * 同时父类中的有参函数不会因子类的继承而重载
     */
    Son s;
    s.fun();

    int i = 10;
    s.Father::fun(i);

    system("pause");
    return 0;
}