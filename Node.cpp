#include <iostream>
#include <cstring>
#include "Node.hpp"

using namespace std;

Node::Node(int m[3][3])
{
    memcpy(temp, m, 9 * sizeof(int));
    discovered = true;
    explore = false;
    next = NULL;
    prev = NULL;
    parent = NULL;
    getDijkCost();
}

void Node::getDijkCost() {
    if (parent != NULL) {
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if (temp[i][j] == 0) {
                    dijk_cost = parent->dijk_cost + parent->temp[i][j];
                }
            }
        }
    } else dijk_cost = 0;
}