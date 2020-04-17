#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

template <class T>
class binaryTree
{
public:
    virtual int height() const = 0;              //* 树高
    virtual int size() const = 0;                //* 树的结点总数
    virtual void clear() = 0;                    //* 清空
    virtual bool empty() const = 0;              //* 判空
    virtual void preOrderTraverse() const = 0;   //* 先序遍历
    virtual void inOrderTraverse() const = 0;    //* 中序遍历
    virtual void postOrderTraverse() const = 0;  //* 后序遍历
    virtual void levelOrderTraverse() const = 0; //* 层次遍历
    virtual ~binaryTree(){};
};

#endif