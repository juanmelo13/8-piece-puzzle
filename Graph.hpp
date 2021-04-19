#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include "AdjMatrix.hpp"
#include "Node.hpp"
using namespace std;

#ifndef GRAPH_H
#define GRAPH_H

class Graph
{

    public:
        Graph();
        Graph(int temp[3][3], AdjMatrix);
        int BFS(int temp[3][3]);
        int DFS(int temp[3][3]);
        int Dijkstra(int temp[3][3]);
        void makeMove(int temp[3][3], Node* n);
        bool checkResult(int temp[3][3]);
        Node* createNode(int temp [3][3], Node* n);
        AdjMatrix matrix;
        queue<Node*> q;
        vector<Node*> explored;
        Node *head;
        vector<Node*> discovered;
    private:
        int move[3][3];
        Node *next;
};

#endif