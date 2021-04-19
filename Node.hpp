#include <iostream>
using namespace std;

#ifndef NODE_H
#define NODE_H

class Node
{
    public:
    Node(int m[3][3]);
    void getDijkCost();
    int temp[3][3];
    bool discovered;
    bool explore;
    Node *next;
    Node *prev;
    Node *parent;
    int dijk_cost;
};

#endif