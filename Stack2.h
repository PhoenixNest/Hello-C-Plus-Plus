#include <iostream>
using namespace std;

//* ---Stack2---
template <class T>
class Stack2
{
public:
  virtual bool empty() const = 0;
  virtual int size() const = 0;
  virtual void push(const T &value) = 0;
  virtual T pop() = 0;
  virtual T getTop() = 0;
  virtual void clean() = 0;
  virtual ~Stack2(){};
};

//! ----------------------------------------------------

//* ---seqStack2---
template <class T>
class seqStack2 : public Stack2<T>
{
private:
  T *data;
  int top;
  int maxSize;
  void resize();

public:
  seqStack2(int initSize)
  {
    if (initSize < 0)
      cout << "Bad Size";

    data = new T[initSize];
    maxSize = initSize;
    top = -1;
  }

  ~seqStack2() { delete[] data; };
  bool empty() const { return top == -1; };
  int size() const { return top + 1; };
  void clean() { top = -1; };
  void push(const T &value);
  T pop();
  T getTop() const;
};

//* ---seqStack2 --- Method: push---
template <class T>
void seqStack2<T>::push(const T &value)
{
  if (top == maxSize - 1)
    resize();

  data[++top] = value;
}

//* ---seqStack2 --- Method: Pop---
template <class T>
T seqStack2<T>::pop()
{
  if (empty())
    cout << "Error";

  return data[top--];
}

//* ---seqStack2 --- Method: getTop---
template <class T>
T seqStack2<T>::getTop() const
{
  if (empty())
    cout << "Error";

  return data[top];
}

//* ---seqStack2 --- Method: resize---
template <class T>
void seqStack2<T>::resize()
{
  T *temp = data;
  data = new T[2 * maxSize];
  for (int i = 0; i < maxSize; ++i)
    data[i] = temp[i];

  maxSize *= 2;
  delete[] temp;
}
//! ----------------------------------------------------

//* ---linkStack2---
template <class T>
class linkStack2 : public Stack2<T>
{
private:
  struct Node
  {
    T data;
    Node *next;
    Node() { next = NULL; };
    Node(const T &value, Node *p = NULL)
    {
      data = value;
      next = p;
    }
  };

  Node *top;

public:
  linkStack2() { top = NULL; };
  ~linkStack2() { clean(); };
  void clean();
  bool empty() const { return top == NULL; };
  int size() const;
  void push(const T &value);
  T pop();
  T getTop() const;
};

//* ---linkStack2 --- Method: clean---
template <class T>
void linkStack2<T>::clean()
{
  Node *p;
  while (top != NULL)
  {
    p = top;
    top = top->next;
    delete p;
  }
}

//* ---linkStack2 --- Method: size---
template <class T>
int linkStack2<T>::size() const
{
  Node *p = top;
  int count = 0;
  while (p)
  {
    count++;
    p = p->next;
  }

  return count;
}

//* ---linkStack2 --- Method: push---
template <class T>
void linkStack2<T>::push(const T &value)
{
  Node *p = new Node(value, top);
  top = p;
}

//* ---linkStack2 --- Method: pop---
template <class T>
T linkStack2<T>::pop()
{
  if (empty())
    cout << "Error";

  Node *p = top;
  T value = p->data;
  top = top->next;
  delete p;
  return value;
}

//* ---linkStack2 --- Method: getTop---
template <class T>
T linkStack2<T>::getTop() const
{
  if (empty())
    cout << "Error";

  return top->data;
}