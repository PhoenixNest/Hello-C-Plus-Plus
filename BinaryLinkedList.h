#ifndef _BINARY_LINKED_LIST_H_
#define _BINARY_LINKED_LIST_H_
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

#include "BinaryTree.h"

//* 二叉树的二叉链表表示法(链式存储)
template <class T>
class binaryLinkedList : public binaryTree<T>
{
private:
    struct Node
    {
        Node *left;  //* 指向左孩子的指针
        Node *right; //* 指向右孩子的指针
        T data;      //* 结点的数据域

        Node() : left(NULL), right(NULL){}; //* 无参构造
        Node(T value, Node *leftNode = NULL, Node *rightNode = NULL)
        {
            data = value;
            left = leftNode;
            right = rightNode;
        }

        ~Node(){};
    };

    enum Tags
    {
        Left,
        Right
    };
    struct StackElement
    {
        Node *pointer;
        Tags tag;
        StackElement(){};
    };

    Node *root;                               //* 私有，指向二叉树的根结点
    void clear(Node *node);                   //* 私有，清空
    int size(Node *node) const;               //* 私有，二叉树的结点总数
    int height(Node *node) const;             //* 私有，二叉树的高度
    int leafNum(Node *node) const;            //* 私有，二叉树的叶子结点总数
    void preOrder(Node *node) const;          //* 私有，递归，前序遍历
    void inOrder(Node *node) const;           //* 私有，递归，中序遍历
    void postOrder(Node *node) const;         //* 私有，递归，后续遍历
    void preOrderCreate(T flag, Node *&node); //* 私有，创建二叉树

public:
    binaryLinkedList() : root(NULL){};           //* 公有，构造空二叉树
    ~binaryLinkedList() { clear(); };            //* 公有，析构，清空二叉树
    bool empty() const { return root == NULL; }; //* 公有，判空
    void clear()                                 //* 公有，清空
    {
        if (root)
        {
            clear(root);
            root = NULL;
        }
    }
    int size() const { return size(root); };     //* 公有，求结点总数
    int height() const { return height(root); }; //* 公有，求树高
    int leafNum() { return leafNum(root); };     //* 公有，二叉树叶子结点个数
    void preOrderTraverse()                      //* 公有，递归，前序遍历
    {
        if (root)
        {
            preOrder(root);
        }
    }

    void inOrderTraverse() //* 公有，递归，中序遍历
    {
        if (root)
        {
            inOrder(root);
        }
    }

    void postOrderTraverse() //* 公有，递归，后序遍历
    {
        if (root)
        {
            postOrder(root);
        }
    }

    void levelOrderTraverse() const;                            //* 层次遍历
    void preOrderWithStack() const;                             //* 非递归，前序遍历
    void inOrderWithStack() const;                              //* 非递归，中序遍历
    void postOrderWithStack() const;                            //* 非递归，后序遍历
    void levelOrderCreate(T flag);                              //* 利用带外部结点的层次序列创建二叉树
    void preOrderCreate(T flag) { preOrderCreate(flag, root); } //* 利用带外部结点的前序序列创建二叉树

    void makeTree(const T &value, binaryLinkedList &lt, binaryLinkedList &rt)
    {
        root = new Node(value, lt.root, rt.root);
        lt.root = NULL;
        rt.root = NULL;
    }

    T getRoot() const { return root->data; }         //* 取根结点的值
    T getleft() const { return root->left->data; }   //* 取左孩子的值
    T getRight() const { return root->right->data; } //* 取右孩子的值
};

template <class T>
void binaryLinkedList<T>::clear(Node *node)
{
    if (node->left)        //* 判断是否带左孩子
        clear(node->left); //* 清空左孩子

    if (node->right)        //* 判断是否带右孩子
        clear(node->right); //* 清空右孩子

    delete node; //* 清除根结点
}

template <class T>
int binaryLinkedList<T>::size(Node *node) const
{
    if (node == NULL) //* 递归出口。空树结点数为0
        return 0;

    return 1 + size(node->left) + size(node->right); //* 结点数 = 左右子结点数之和 + 根结点
}

template <class T>
int binaryLinkedList<T>::height(Node *node) const
{
    if (node == NULL)
        return 0;
    else
    {
        int leftHeight = height(node->left);                              //* 左子树高度
        int rightHeight = height(node->right);                            //* 右子树高度
        return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight); //* 树高 = 左右子树中的最大值 + 1
    }
}

template <class T>
int binaryLinkedList<T>::leafNum(Node *node) const
{
    if (node == NULL)
        return 0; //* 空树
    else if ((node->left == NULL) && (node->right == NULL))
        return 1; //* 只有根结点
    else
        return leafNum(node->left) + leafNum(node->right); //* 叶子数 = 左孩子数 + 右孩子数
}

//* 递归，前序遍历，根左右，DLR
template <class T>
void binaryLinkedList<T>::preOrder(Node *node) const
{
    if (node)
    {
        cout << node->data << " "; //* 访问数据域
        preOrder(node->left);      //* 递归遍历左子树
        preOrder(node->right);     //* 递归遍历右子树
    }
}

//* 递归，中序遍历，左根右，LDR
template <class T>
void binaryLinkedList<T>::inOrder(Node *node) const
{
    if (node)
    {
        preOrder(node->left);      //* 递归遍历左子树
        cout << node->data << " "; //* 访问数据域
        preOrder(node->right);     //* 递归遍历右子树
    }
}

//* 递归，后序遍历，左右根，LRD
template <class T>
void binaryLinkedList<T>::postOrder(Node *node) const
{
    if (node)
    {
        preOrder(node->left);      //* 递归遍历左子树
        preOrder(node->right);     //* 递归遍历右子树
        cout << node->data << " "; //* 访问数据域
    }
}

//* 非递归，前序遍历
//** 算法思想：
//** 每遇到一个结点，先访问该结点，并把该结点入栈，然后继续遍历左子树。
//** 遍历完左子树后，从栈顶弹出这个结点，并按照他的right域再去遍历该结点的右孩子树。
template <class T>
void binaryLinkedList<T>::preOrderWithStack() const
{
    stack<Node *> s;
    Node *p = root;
    while (!s.empty() || p)
    {
        if (p)
        {
            s.push(p);              //* 指针入栈
            cout << p->data << " "; //* 访问当前结点数据域
            p = p->left;            //* 工作指针指向左子树
        }
        else
        {
            p = s.top();  //* 取栈顶元素
            s.pop();      //* 出栈
            p = p->right; //* 工作指针指向右子树
        }
    }
}

//* 非递归中序遍历
//** 算法思想：
//** 每遇到一个结点就把它入栈，然后遍历左子树
//** 遍历完左子树后，从栈顶弹出这个结点并访问该结点，然后按照他的right域遍历该结点的右子树
template <class T>
void binaryLinkedList<T>::inOrderWithStack() const
{
    stack<Node *> s;
    Node *p = root;
    while (!s.empty() || p)
    {
        if (p)
        {
            s.push(p);   //* 指针入栈
            p = p->left; //* 工作指针指向左子树
        }
        else //* 左子树访问结束，转向访问右子树
        {
            p = s.top();            //* 获取栈顶元素
            s.pop();                //* 出栈
            cout << p->data << " "; //* 访问当前结点数据域
            p = p->right;           //* 工作指针指向右子树
        }
    }
}

//* 非递归后续遍历
//** 算法思想：
//**
//**
template <class T>
void binaryLinkedList<T>::postOrderWithStack() const
{
    enum ChildType
    {
        left,
        right
    };

    struct StackElem
    {
        Node *pointer;
        ChildType flag;
    };

    StackElem elem;
    stack<StackElement> s;

    Node *p = root;

    while (!s.empty() || p)
    {
        while (p != NULL)
        {
            elem.pointer = p;
            elem.flag = left;
            s.push(elem);
            p = p->left;
        }

        elem = s.top();
        s.pop();
        p = elem.pointer;
        if (elem.flag == left)
        {
            elem.flag = right;
            s.push(elem);
            p = p->right;
        }
        else
        {
            cout << p->data << " ";
            p = NULL;
        }
    }
}

//* 层次遍历(广度优先遍历 / 宽度优先遍历)
//** 算法思想：
//** 1.初始化一个队列，把根结点(如果有)入队。
//** 2。若队列非空，则循环执行步骤 3～步骤 5，否则遍历结束。
//** 3.出队一个结点，并访问数据域。
//** 4.若该结点的左子树非空，则将左子树入队。
//** 5.若该结点的右子树非空，则将右子树入队。
template <class T>
void binaryLinkedList<T>::levelOrderTraverse() const
{
    queue<Node *> que; //* 队列
    Node *p = root;    //* 根结点
    if (p)
        que.push(p); //* 根结点入队

    while (!que.empty())
    {
        p = que.front;          //* 取队首元素
        que.pop();              //* 出队
        cout << p->data << " "; //* 访问当前结点的数据域
        if (p->left != NULL)
            que.push(p->left); //* 左子树进队

        if (p->right != NULL)
            que.push(p->right); //* 右子树进队
    }
}

//* 带外部结点的前序序列构造二叉链表表示的二叉树
template <class T>
void binaryLinkedList<T>::preOrderCreate(T flag, Node *&t)
{
    T value;
    cin >> value;
    if (value != flag) //* 递归出口(value = flag)
    {
        t = new Node(value);
        preOrderCreate(flag, t->left);  //* 递归创建左子树
        preOrderCreate(flag, t->right); //* 递归创建右子树
    }
}

//* 带外部结点的层次序列构造二叉链表表示的二叉树

#endif