#include <iostream>
#include <vector>
using namespace std;

#ifndef ADJ_MATRX_H
#define ADJ_MATRIX_H


class AdjMatrix
{
    public:
        AdjMatrix();
        void addEdge(int u, int v);
        void removeEdge(int u, int v);
        int getEdge(int u, int v);
        vector<int> getNeighbors(int v);
        void updateMatrix(int temp[3][3]);
        void print();
        int m[3][3];
    private:
        int matrix[9][9];
};



#endif