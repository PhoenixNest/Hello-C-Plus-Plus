#include <iostream>
using namespace std;

/**
 * 结构体类似于Java的类
 */
struct test
{
    int m;
    void fun(){
        cout << "fun" << endl;
    }
};


int main()
{

    test a;
    a.fun();

    system("pause");
    return 0;
}