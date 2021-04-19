#ifndef NODECOMPARE_HPP
#define NODECOMPARE_HPP

#include "Node.hpp"

class NodeCompare {
    public:
    bool operator() (const Node* lhs, const Node* rhs) {
        return lhs->dijk_cost > rhs->dijk_cost; 
    }
};

#endif