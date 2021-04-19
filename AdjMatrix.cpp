#include <iostream>
#include "AdjMatrix.hpp"
using namespace std;

AdjMatrix::AdjMatrix()
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

void AdjMatrix::addEdge(int u, int v)
{
    matrix[u][v] = 1;
}

void AdjMatrix::removeEdge(int u, int v)
{
    matrix[u][v] = 0;
}

vector<int> AdjMatrix::getNeighbors(int v)
{
    vector<int> neighbors;
    for(int i = 0; i < 9; i++)
    {
        if(matrix[v][i] == 1)
        {
            neighbors.push_back(i);
        }
    }
    return neighbors;
}

void AdjMatrix::print()
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cout << getEdge(i, j) << " ";
        }
        cout << endl;
    }
}

int AdjMatrix::getEdge(int u, int v)
{
    return matrix[u][v];
}

void AdjMatrix::updateMatrix(int tempM[3][3])
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            removeEdge(i, j);
        }
    }
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            int x;
            x = tempM[i][j];
            if(i == 0 && j == 0)
            {
                int temp = tempM[0][1];
                addEdge(x, temp);
                temp = tempM[1][0];
                addEdge(x, temp);
            } else if(i == 0 && j == 1) {
                int temp = tempM[0][0];
                addEdge(x, temp);
                temp = tempM[0][2];
                addEdge(x, temp);
                temp = tempM[1][1];
                addEdge(x, temp);
            } else if(i == 0 && j == 2) {
                int temp = tempM[0][1];
                addEdge(x, temp);
                temp = tempM[1][2];
                addEdge(x, temp);
            } else if(i == 1 && j == 0) {
                int temp = tempM[0][0];
                addEdge(x, temp);
                temp = tempM[1][1];
                addEdge(x, temp);
                temp = tempM[2][0];
                addEdge(x, temp);
            } else if(i == 1 && j == 1) {
                int temp = tempM[0][1];
                addEdge(x, temp);
                temp = tempM[1][0];
                addEdge(x, temp);
                temp = tempM[1][2];
                addEdge(x, temp);
                temp = tempM[2][1];
                addEdge(x, temp);
            } else if(i == 1 && j == 2) {
                int temp = tempM[0][2];
                addEdge(x, temp);
                temp = tempM[1][1];
                addEdge(x, temp);
                temp = tempM[2][2];
                addEdge(x, temp);
            } else if(i == 2 && j == 0) {
                int temp = tempM[1][0];
                addEdge(x, temp);
                temp = tempM[2][1];
                addEdge(x, temp);
            } else if(i == 2 && j == 1) {
                int temp = tempM[2][0];
                addEdge(x, temp);
                temp = tempM[1][1];
                addEdge(x, temp);
                temp = tempM[2][2];
                addEdge(x, temp);
            } else if(i == 2 && j == 2) {
                int temp = tempM[1][2];
                addEdge(x, temp);
                temp = tempM[2][1];
                addEdge(x, temp);
            }
        }
    }
}
