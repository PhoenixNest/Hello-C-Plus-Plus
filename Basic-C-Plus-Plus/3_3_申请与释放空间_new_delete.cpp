#include <iostream>
using namespace std;

int main()
{
    //申请空间 ---这里申请了一个整型长度的空间(4字节)
    int *p = new int; //写法1：new + type 注意类型匹配 申请空间需要指针接收
    //int *p = new int(100); //写法2：new + type(value) 注意类型匹配 这里先初始化了空间的大小为100
    char *c = new char;

    //赋值
    *p = 10;
    //读取
    cout << *p << endl;

    //释放空间 delete + 指针
    delete p;

    cout << "-----" << endl;

    //申请结构体空间
    struct Node
    {
        //写代码
        void test()
        {
            cout << "p1" << endl;
        }
    };
    Node n;
    n.test();
    Node *p1 = new Node;

    //释放空间 delete + 指针
    delete p1;

    cout << "-----" << endl;

    //申请数组空间 这里初始化大小为5个元素
    int *p2 = new int[5];
    /**
     * 初始化数组(这里谜之不行)
     * memset(指针，初始化的值(定义为多少就全部初始化为多少)，元素的个数 * 字节长度_sizaof(类型))
     * memset(p1, 0, 5 * sizeof(int));
     */

    //赋值
    p2[0] = 1;
    p2[1] = 2;
    p2[2] = 3;
    p2[3] = 4;
    p2[4] = 5;

    //输出
    cout << p2[0] << endl;
    cout << p2[1] << endl;
    cout << p2[2] << endl;
    cout << p2[3] << endl;
    cout << p2[4] << endl;

    //释放数组 delete[] + 指针 记得在delete后加方括号
    delete[] p2;

    system("pause");
    return 0;
}