#include <iostream>
using namespace std;

class Stu
{
  public:
    int age;
    Stu()
    {
        age = 15;
    }

    int operator++()
    {
        age += 1;
        return age;
    }

    int operator--()
    {
        age -= 1;
        return (age);
    }

    int operator++(int n)
    {
        //记录自增前的对象中的值
        n = age;
        //对对象中的值进行自增操作
        age += 1;
        //将记录自增前的对象中的值返回
        return n;
    }

    int operator--(int n)
    {
        //记录自减前的对象中的值
        n = age;
        //对对象中的值进行自减操作
        age -= 1;
        //将记录自减前的对象中的值返回
        return n;
    }
};

//前置自加重载(例：int a; ++a;)，只需传入一个对象的引用即可
// int operator++(Stu &s)
// {
//     s.age += 1;
//     return (s.age);
// }

//前置自减重载(例：int a; --a;)，只需传入一个对象的引用即可
// int operator--(Stu &s)
// {
//     s.age -= 1;
//     return (s.age);
// }

/**
 * 后置自增重载(例：int a; a++;
 * 可将该处引入的普通变量的形式参数n理解为一个标记，即带额外普通变量的自增自减重载为后置自增自减函数
 */
// int operator++(Stu &s, int n)
// {
//     //记录自增前的对象中的值
//     n = s.age;
//     //对对象中的值进行自增操作
//     s.age += 1;
//     //将记录自增前的对象中的值返回
//     return n;
// }

//后置自减重载(例：int a; a++;)
// int operator--(Stu &s, int n)
// {
//     //记录自减前的对象中的值
//     n = s.age;
//     //对对象中的值进行自减操作
//     s.age -= 1;
//     //将记录自减前的对象中的值返回
//     return n;
// }

int main()
{

    Stu s;
    cout << "origin s.sge = " << s.age << endl;

    //前置自增自减
    int a = 0;
    //a在前置自增自减语句执行时进行+1(-1)操作，并覆盖原先的值，此时若该值赋予新的变量，新变量会被同时覆盖新值
    int b = ++a; //输出的值为：b = 1 , a = 1

    Stu s1;
    //该处会调用前置自增(++s1)重载
    cout << "after ++s1, s1.age = " << (++s1) << endl;

    Stu s2;
    //该处会调用前置自减(--s2)重载
    cout << "after --s2, s2.age = " << (--s2) << endl;

    //后置自增自减
    int c = 10;
    //c在后置自增自减语句执行后进行+1(-1)操作,并覆盖原先的值，此时若该值赋予新的变量，新变量的值不会改变
    int d = c++; //输出的值为：d = 10 , c = 11

    Stu s3;
    //该处会调用后置自增(s3++)重载
    cout << "before s3++, s3.age = " << s3++ << "(parameter n will not be changed in this time)" << endl;
    cout << "after s3++, s3.age = " << s3.age << endl;

    Stu s4;
    //该处会调用后置自增(s4--)重载
    cout << "before s4--, s4.age = " << s4-- << "(parameter n will not be changed in this time)" << endl;
    cout << "after s4--, s4.age = " << s4.age << endl;

    system("pause");
    return 0;
}