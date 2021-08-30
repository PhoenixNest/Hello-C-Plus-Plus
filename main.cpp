#include <iostream>
#include <stack>
#include <queue>
#include <cstdlib>

using namespace std;

#include "HuffmanTree.h"

#include "mySearch.h"
#include "mySortExchange.h"
#include "mySortInsertion.h"
#include "mySortMerging.h"
#include "mySortSelection.h"

// #include "seqList.h"
// #include "LinkList.h"
// #include "seqStack.h"
// #include "LinkStack.h"
// #include "seqQueue.h" 
// #include "LinkQueue.h"
// #include "BinaryLinkedList.h"


// Huffman树测试
void testHuffmanTree()
{
    char d[] = "Google";
    int w[] = {4, 6, 1, 2, 1, 1, 2};
    huffmanTree<char> tree(7);
    tree.createhuffmanTree(d, w);
    tree.huffmanEncoding();
    tree.printHuffmanCode();
}

int main()
{
    cout << "Main1" << endl;

    // seqList<int> *list = new seqList<int>(100);
    // linkList<int> *list = new linkList<int>();

    // seqStack<int> *stack = new seqStack<int>();
    // linkStack<int> *stack = new linkStack<int>();

    // seqQueue<int> *queue = new seqQueue<int>();
    // linkQueue<int> *queue = new linkQueue<int>();

    // binaryLinkedList<char> tree;

    // testHuffmanTree();

    int test[] = {8, 5, 96, 44, 28, 89, 75};

    // binaryInsertSort(test, 7);
    quickSort(test, 7);

    for (int i = 0; i < 7; i++)
        cout << test[i] << " | ";

    return 0;
}