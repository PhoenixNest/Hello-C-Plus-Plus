#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>
using namespace std;

template <class T>
class List
{
public:
    virtual void clear() = 0;                          //* 清空线性表
    virtual bool empty() const = 0;                    //* 判空，空为true，非空false
    virtual int size() const = 0;                      //* 返回表长
    virtual void insert(int position, const T &value); //* 在position位置插入值为value的元素
    virtual void remove(int position) = 0;             //* 删除第position的位置的元素
    virtual int search(const T &value);                //* 查找传入值在线性表中的位置
    virtual T visit(int position) const = 0;           //* 查找position位置的元素的值
    virtual void traverse() const = 0;                 //* 遍历当前线性表
    virtual void inverse() = 0;                        //* 逆置当前线性表
    virtual ~List(){};
};

class outOfRange : public exception
{
public:
    //* 检查范围有效性
    const char *checkRange() const throw()
    {
        return "OUT of RANGE";
    }
};

class errorSize : public exception
{
public:
    //* 检查长度有效性
    const char *checkSize() const throw()
    {
        return "ERROR size";
    }
};

#endif