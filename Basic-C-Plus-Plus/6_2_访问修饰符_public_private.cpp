#include <iostream>
using namespace std;

// /**
//  * 类的对象可被其他类调用，也可被函数调用，但别记得声明对象
//  *  若不声明类的访问修饰符则默认是private私有的
//  */
// class People
// {
//   public:
//     //private:
//     //protected:
//     int a;
//     void fun()
//     {
//         cout << "Function" << endl;
//     }

//   private:
//     void fun3()
//     {
//         fun();
//     }
// };

// class Test
// {
//   public:
//     People p2;
//     void fun2()
//     {
//         p2.fun();
//     }
// };

// void fun1()
// {
//     People p1;
//     p1.fun();
// }

struct CP
{
    //结构体默认是public公有的
    int b;

  private:
    void fun()
    {
        cout << "Function" << endl;
    }
};

int main()
{

    // People p;
    // p.a = 10;
    // p.fun();

    CP c;
    c.b = 10;

    system("pause");
    return 0;
}