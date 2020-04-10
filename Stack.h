#ifndef _STACK_H_
#define _STACK_H_

#include <iostream>
using namespace std;

template <class T>
class Stack
{
public:
    virtual bool empty() const = 0;        //* 判栈空
    virtual int size() const = 0;          //* 返回栈大小
    virtual void push(const T &value) = 0; //* 进栈
    virtual T pop() = 0;                   //* 出栈
    virtual T getTop() const = 0;          //* 返回栈顶元素
    virtual void clear() = 0;              //* 清空栈
    virtual ~Stack(){};
};

class outOfRange : public exception
{
public:
    const char *what() const throw()
    {
        return "OUT of RANGE";
    }
};

class errorSize : public exception
{
public:
    const char *what() const throw()
    {
        return "ERROR size";
    }
};

#endif