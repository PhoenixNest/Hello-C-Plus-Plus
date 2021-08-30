#include <iostream>
using namespace std;

namespace stu
{
    void test_stu()
    {
        cout << "stu" << endl;
    }
} // namespace stu

namespace stu_1
{
    void test_stu1()
    {
        cout << "stu1" << endl;
    }
} // namespace stu_1

int main()
{

    /**
     * 使用命名空间，并使用命名空间中的内容
     * 命名空间使用的声明可写在任意地点，但必须先定义，再使用
     * 写法1
     */
    // using namespace stu;
    // test_stu();

    // using namespace stu_1;
    // test_stu1();

    /**
     * 写法2
     * 可直接调用，无需声明
     * :: 作用域运算符
     */
    stu::test_stu();
    stu_1::test_stu1();

    system("pause");
    return 0;
}