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
}