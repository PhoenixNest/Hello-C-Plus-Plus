#ifndef _LINK_STACK_H_
#define _LINK_STACK_H_
#include <iostream>

#include "Stack.H"

template <class T>
class linkStack : public Stack<T>
{
private:
    struct Node
    {
        T data;
        Node *next;
        Node() { next = NULL; }
        Node(const T &value, Node *p = NULL)
        {
            data = value;
            next = p;
        }
    };
    Node *top;

public:
    linkStack() { top = NULL; };               //* 初始化空栈
    ~linkStack() { clear(); };                 //* 析构函数
    void clear();                              //* 清空栈
    bool empty() const { return top == NULL; } //* 判栈空，时间复杂度：O(n)
    int size() const;                          //* 返回链栈长度
    void push(const T &value);                 //* 进栈
    T pop();                                   //* 出栈
    T getTop() const;                          //* 返回栈顶元素
};

//* 清空栈
//** 时间复杂度：O(n)
template <class T>
void linkStack<T>::clear()
{
    Node *p;
    while (top != NULL)
    {
        p = top;         //* p指向当前栈顶元素
        top = top->next; //*top指针依次指向写一个栈顶元素
        delete p;        //* 释放p指向的当前元素
    }
}

//* 栈长度
//** 时间复杂度：O(n)
template <class T>
int linkStack<T>::size() const
{
    Node *p = top;
    int count = 0;
    while (p) //* 遍历栈，统计元素个数
    {
        count++;
        p = p->next;
    }

    return count;
}

//* 进栈
//** 时间复杂度：O(1)
template <class T>
void linkStack<T>::push(const T &value)
{
    Node *p = new Node(value, top); //* 在栈顶插入元素
    top = p;                        //* 更新栈顶指针
}

//* 出栈
//** 时间复杂度：O(1)
template <class T>
T linkStack<T>::pop()
{
    if (empty())
        throw outOfRange();

    Node *p = top;
    T value = p->data; //* 保留栈顶元素的值
    top = top->next;   //* 更新栈顶指针至下一个栈顶元素
    delete p;          //* 释放出栈的栈顶元素
    return value;      //* 返回出栈元素值
}

//* 取栈顶元素值
//** 时间复杂度：O(1)
template <class T>
T linkStack<T>::getTop() const
{
    if (empty())
        throw outOfRange();

    return top->data; //* 返回栈顶元素值
}

#endif