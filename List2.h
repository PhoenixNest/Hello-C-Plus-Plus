#include <iostream>
using namespace std;

//* ---List2---
template <class T>
class List2
{
public:
  virtual void clean();
  virtual bool empty() const = 0;
  virtual int size() const = 0;
  virtual void insert(int position, const T &value);
  virtual void remove(int position) = 0;
  virtual int search(const T &value);
  virtual T visit(int position) const = 0;
  virtual void traverse();
  virtual void inverse();
  virtual ~List2();
};

//! ----------------------------------------------------

//* ---seqList2---
template <class T>
class seqList2 : public List2<T>
{
private:
  T *data;
  int length;
  int maxSize;
  void resize();

public:
  seqList2(int initSize);
  seqList2(seqList2 &list);
  ~seqList2() { delete[] data; };

  void clean() { length = 0; };
  bool empty() const { return length == 0; };
  int size() const { return length; };
  void traverse() const;
  void inverse();

  void insert(int position, T &value);
  void remove(int position);
  int search(const T &value) const;
  T visit(int position) const;
};

//* ---seqList2 --- Method: constructor---
template <class T>
seqList2<T>::seqList2(int initSize)
{
  if (initSize <= 0)
    cout << "Bad Size" << endl;

  maxSize = initSize;
  data = new T[maxSize];
  length = 0;
}

//* ---seqList2 --- Method: insert---
template <class T>
void seqList2<T>::insert(int position, T &value)
{
  if (position < 0 || position > maxSize)
    cout << "Error" << endl;

  if (length == maxSize)
    resize();

  for (int i = length; i > position; i--)
    data[i] = data[i - 1];

  data[position] = value;
  ++length;
}

//* ---seqLsit2 --- Method: remove---
template <class T>
void seqList2<T>::remove(int position)
{
  if (position < 0 || position > maxSize)
    cout << "Error" << endl;

  for (int i = position; i < length - 1; i++)
    data[i] = data[i + 1];

  --length;
}

//* ---seqLsit2 --- Method: search---
template <class T>
int seqList2<T>::search(const T &value) const
{
  for (int i = 0; i < length; i++)
    if (value == data[i])
      return i;

  return -1;
}

//* ---seqList2 --- Method: visit---
template <class T>
T seqList2<T>::visit(int position) const
{
  if (position < 0 || position > length - 1)
    cout << "Error" << endl;

  return data[position];
}

//* ---seqList2 --- Method: traverse---
template <class T>
void seqList2<T>::traverse() const
{
  if (empty())
    cout << "Empty" << endl;
  else
  {
    cout << "Data: ";
    for (int i = 0; i < length; i++)
      cout << data[i] << endl;
  }
}

//* ---seqList2 --- Method: inverse---
template <class T>
void seqList2<T>::inverse()
{
  T temp;
  for (int i = 0; i < length / 2; i++)
  {
    temp = data[i];
    data[i] = data[length - i - 1];
    data[length - i - 1] - temp;
  }
}

//! ----------------------------------------------------

//* ---linkList2---
template <class T>
class linkList2 : public List2<T>
{
private:
  struct Node
  {
    T data;
    Node *next;
    Node(const T value, Node *p = NULL)
    {
      data = value;
      next = p;
    }

    Node(Node *p = NULL)
    {
      next = p;
    }
  };

  Node *head;
  Node *tail;
  int length;

  Node *getPosition(int position) const;

  void traverseRecursive(Node *p);

public:
  linkList2();
  ~linkList2();

  void clean();
  bool empty() const { return head->next = NULL; };
  int size() const { return length; };
  void insert(int position, const T &value);
  void remove(int position);
  int search(const T &value) const;
  T visit(int position) const;

  void traverse() const;
  void inverse();
  void headCreate();
  void tailCreate();
  int prior(const T &value) const;
  linkList2 *Union(linkList2<T> *list);

  void outPut();
};

//* ---linkList2 --- Method: constructor---
template <class T>
linkList2<T>::linkList2()
{
  head = tail = new Node();
  length = 0;
}

//* ---linkList2 --- Method: ~linkList2---
template <class T>
linkList2<T>::~linkList2()
{
  clean();
  delete head;
}

//* ---linkList2 --- Method: clean---
template <class T>
void linkList2<T>::clean()
{
  Node *p, *temp;
  p = head->next;
  while (p != NULL)
  {
    temp = p;
    p = p->next;
    delete temp;
  }

  head->next = NULL;
  tail = head;
  length = 0;
}

//* ---linkList2 --- Method: traverse---
template <class T>
void linkList2<T>::traverse() const
{
  Node *p = head->next;
  while (p != NULL)
  {
    cout << "Data: ";
    cout << p->data;
    p = p->next;
  }
}

//* ---linkList2 --- Method: getPosition---
template <class T>
typename linkList2<T>::Node *linkList2<T>::getPosition(int position) const
{
  Node *p = head;
  int count = 0;

  if (position < -1 || position > length - 1)
    return NULL;

  while (count <= position)
  {
    p = p->next;
    count++;
  }

  return p;
}

//* ---linkList2 --- Method: insert---
template <class T>
void linkList2<T>::insert(int position, const T &value)
{
  Node *p, *q;
  if (position < 0 || position > length - 1)
    cout << "Error";

  p = getPosition(position - 1);
  q = new Node(value, p->next);
  p->next = q;
  if (p == tail)
    tail = q;

  length++;
}

//* ---linkList2 --- Method: remove---
template <class T>
void linkList2<T>::remove(int position)
{
  Node *pre, *p;
  if (position < 0 || position > length - 1)
    cout << "Error";

  pre = getPosition(position - 1);
  p = p->next;
  if (p == tail)
  {
    tail = pre;
    pre->next = NULL;
    delete p;
  }
  else
  {
    pre->next = p->next;
    delete p;
  }

  length--;
}

//* ---linkList2 --- Method: search---
template <class T>
int linkList2<T>::search(const T &value) const
{
  Node *p = head->next;
  int count = 0;

  while (p != NULL && p->data != value)
  {
    p = p->next;
    count++;
  }

  if (p == NULL)
    return -1;
  else
    return count;
}

//* ---linkList2 --- Method: visit---
template <class T>
T linkList2<T>::visit(int position) const
{
  Node *p = head->next;
  int count = 0;
  if (position < 0 || position > length - 1)
    cout << "Error";

  while (count < position)
  {
    p = p->next;
    count++;
  }

  return p->data;
}

//* ---linkList2 --- Method: headCreate---
template <class T>
void linkList2<T>::headCreate()
{
  Node *p;
  T value, flag;
  cin >> flag;

  while (cin >> value, value != flag)
  {
    p = new Node(value, head->next);
    head->next = p;
    if (head == tail)
      tail = p;

    length++;
  }
}

//* ---linkList2 --- Method: tailCreate---
template <class T>
void linkList2<T>::tailCreate()
{
  Node *p;
  T value, flag;
  cin >> flag;

  while (cin >> value, value != flag)
  {
    p = new Node(value, NULL);
    tail->next = p;
    tail = p;
    length++;
  }
}

//* ---linkList2 --- Method: inverse---
template <class T>
void linkList2<T>::inverse()
{
  Node *p, *temp;
  p = head->next;
  head->next = NULL;
  if (p)
    tail = p;

  while (p)
  {
    temp = p->next;
    p->next = head->next;
    head->next = p;
    p = temp;
  }
}

//* ---linkList2 --- Method: prior---
template <class T>
int linkList2<T>::prior(const T &value) const
{
  Node *p = head->next;
  Node *pre = NULL;
  int count = -1;

  while (p && p->data != value)
  {
    pre = p;
    p = p->next;
    count++;
  }

  if (p == NULL)
    return -1;
  else
    return count;
}

//* ---linkList2 --- Method: traverseRecursive---
template <class T>
void linkList2<T>::traverseRecursive(Node *p)
{
  if (p)
    traverseRecursive(p->next);
}

//! ----------------------------------------------------