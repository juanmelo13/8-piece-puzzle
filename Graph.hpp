#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include "AdjMatrix.hpp"
#include "Node.hpp"
#include "NodeCompare.hpp"

using namespace std;

#ifndef GRAPH_H
#define GRAPH_H

typedef priority_queue<Node*, vector<Node*>,NodeCompare> DijkstraQ;

class Graph
{

    public:
        Graph();
        Graph(int temp[3][3], AdjMatrix);
        int BFS(int temp[3][3]);
        int DFS(int temp[3][3]);
        int Dijkstra(Node* current);
        void makeMove(int temp[3][3], Node* n, bool dijkstra = false);
        bool checkResult(int temp[3][3]);
        Node* createNode(int temp [3][3], Node* n);
        AdjMatrix matrix;
        queue<Node*> q;
        vector<Node*> explored;
        Node *head;
        vector<Node*> discovered;
        DijkstraQ frontier;
    private:
        int move[3][3];
        Node *next;
};

#endif