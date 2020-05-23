#ifndef _ADJ_MATRIX_GRAPH_H_
#define _ADJ_MATRIX_GRAPH_H_
#include <iostream>
using namespace std;

#include "Graph.H"

template <class VertexType, class EdgeType>
class adjMatrix : public Graph<VertexType, EdgeType>
{
private:
    VertexType *vertexs;       //* 顶点向量
    EdgeType **edges;          //* 邻接矩阵
    EdgeType noEdge;           //* 无边标志
    void dfs(int start) const; //* 从start顶点出发深度优先遍历

public:
    adjMatrix(int size, EdgeType noEdgeFlag);
    ~adjMatrix();
    void createGraph(const VertexType V[], const EdgeType E[]);
    bool searchEdge(int from, int to) const;        //* 查找边
    bool insertEdge(int from, int to, EdgeType w);  //* 插入边
    bool removeEdge(int from, int to);              //* 删除一条边
    void dfsTraverse() const;                       //* 调用父类中的dfs深度优先遍历
    void bfsTraverse() const;                       //* 广度优先遍历
    bool topSort() const;                           //* 拓补排序
    void prim(EdgeType noEdge) const;               //* 普里姆算法求最小生成树
    void kruskal() const;                           //* 克鲁斯卡尔算法求最小生成树
    void printMsd() const;                          //* 输出最小生成树
    void floyd() const;                             //* 弗洛伊德算法求各顶点最短路径
    void printFloyd(EdgeType **D, int **pre) const; //* 输出各顶点间的最短路径
    void printGraph() const;                        //* 输出图
};

//* 构造函数
template <class VertexType, class EdgeType>
adjMatrix<VertexType, EdgeType>::adjMatrix(int size, EdgeType noEdgeFlag)
{
    this->verNum = size;
    this->edgeNum = 0;
    noEdge = noEdgeFlag;
    vertexs = new VertexType[this->verNum];
    edges = new EdgeType *[this->verNum];
    for (int i = 0; i < this->verNum; i++)
    {
        edges[i] = new EdgeType *[this->verNum];
        for (int i = 0; i < this->verNum; i++)
        {
            edges[i] = noEdge;
        }
    }
    this->visited = new bool[this->verNum];
    this->TE = new typename Graph<VertexType, EdgeType>::mstEdge[this->verNum - 1];
}

//* 弗洛伊德算法求各顶点最短路径
template <class VertexType, class EdgeType>
void adjMatrix<VertexType, EdgeType>::floyd() const
{
    EdgeType **D = new EdgeType *[this->verNum];
    int **pre = new int *[this->verNum];
    int i, j, k;

    for (i = 0; i < this->verNum; ++i)
    {
        D[i] = new EdgeType[this->verNum];
        pre[i] = new int[this->verNum];
        for (j = 0; i < this->verNum; ++j)
        {
            D[i][j] = (i == j) ? 0 : edges[i][j];
            pre[i][j] = (edges[i][j] == noEdge) ? -1 : i;
        }
    }

    printFloyd(D, pre);
    cout << "---Start--- \n";
    //* 迭代过程
    for (k = 0; k < this->verNum; ++k)
    {
        for (i = 0; i < this->verNum; ++i)
        {
            for (j = 0; j < this->verNum; ++j)
            {
                if (D[i][k] != noEdge && D[k][j] != noEdge && D[i][k] + D[k][j] < D[i][j])
                {
                    D[i][j] = D[i][k] + D[k][j];
                    pre[i][j] = pre[k][j];
                }
            }
        }
        printFloyd(D, pre);
        cout << "---End--- \n";
    }

    //* printFloyd(D, pre);
    for (i = 0; i < this->verNum; i++)
    {
        delete[] D[i];
        delete[] pre[i];
    }
    delete[] D;
    delete[] pre;
}

//* 输出弗洛伊德算法的各顶点最短路径
template <class VertexType, class EdgeType>
void adjMatrix<VertexType, EdgeType>::printFloyd(EdgeType **D, int **pre) const
{
    int i, j, k;
    cout << "最短路径: \n";
    for (i = 0; i < this->verNum; ++i)
    {
        for (j = 0; j < this->verNum; ++j)
        {
            cout << pre[i][j] << '\t';
        }
        cout << endl;
    }

    cout << "结点的上一个指针域: \n";
    for (i = 0; i < this->verNum; ++i)
    {
        for (j = 0; j < this->verNum; ++j)
        {
            cout << pre[i][j] << '\t';
        }
        cout << endl;
    }
}

//* 输出图
template <class VertexType, class EdgeType>
void adjMatrix<VertexType, EdgeType>::printGraph() const
{
    int i, j;
    for (i = 0; i < this->verNum; i++)
    {
        cout << vertexs[i] << ":";
        for (j = 0; j < this->verNum; j++)
        {
            cout << edges[i][j] << " ";
        }
        cout << endl;
    }
}

#endif