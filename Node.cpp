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

void Node::printBoard() const {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << temp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}