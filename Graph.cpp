#include <iostream>
#include "Graph.hpp"

using namespace std;

Graph::Graph()
{
    //unused
}

Graph::Graph(int temp[3][3], AdjMatrix m1)
{
    memcpy(move, temp, 9 * sizeof(int));
    matrix = m1;
    head = new Node(temp);
    head->next = NULL;
    head->prev = NULL;
    head->discovered = true;
    head->explore = false;
    q.push(head);
}

int Graph::BFS(int temp[3][3])
{
    bool done = checkResult(temp);
    int cost = 0;
    if(done == true){
        return cost;
    }else
    {
        while(q.empty() != true)
        {
            Node* n1 = q.front();
            matrix.updateMatrix(n1->temp);
            q.pop();
            explored.push_back(n1);
            done = checkResult(n1->temp);
            if(done == true){
                stack<Node*> path;
                while(n1->parent != NULL)
                {
                    path.push(n1);
                    n1 = n1->parent;
                    cost++;
                }
                for(int i = 0; i < 3; i++)
                {
                    for(int j = 0; j < 3; j++)
                    {
                        cout << temp[i][j] << " ";
                    }
                    cout << endl;
                }
                cout << endl;
                while(path.empty() != true){
                    for(int i = 0; i < 3; i++)
                    {
                        for(int j = 0; j < 3; j++)
                        {
                            cout << path.top()->temp[i][j] << " ";
                        }
                        cout << endl;
                    }
                    cout << endl;
                    path.pop();
                }
                return cost;
            }
            makeMove(n1->temp, n1);
        }
    }
    return -1; 
}

int Graph::DFS(int temp[3][3])
{
    bool done = checkResult(temp);
    int cost = 0;

    //This only checks if the original input matrix is the goal state
    if(done == true)
    {
        return cost;
    }

    //n1 equals the node at the front of the queue, the next state will always be the only node in the queue
    Node* n1 = q.front();
    matrix.updateMatrix(n1 -> temp);
    q.pop();

    //when a state is being visited, it is marked as discovered
    discovered.push_back(n1);

    //the possibleMoves vector is filled with the possible moves that can be made in the current state
    vector<int> possibleMoves = matrix.getNeighbors(0);

    string move;
    //looping through all the possible moves to see if they contain the goal state
    for(unsigned int i = 0; i < possibleMoves.size(); i++)
    {
        //a child matrix is declared and initially made identical to the current state
        int childMatrix[3][3];
        for(int j = 0; j < 3; j++)
        {
            for(int k = 0; k < 3; k++)
            {
                childMatrix[j][k] = temp[j][k];
            }
        }

        //values for the matrix location of the possible move is stored
        int spaceJ, spaceK, moveJ, moveK;
        for(int j = 0; j < 3; j++)
        {
            for(int k = 0; k < 3; k++)
            {
                if(temp[j][k] == 0)
                {
                    spaceJ = j;
                    spaceK = k;
                }
                if(temp[j][k] == possibleMoves.at(i))
                {
                    moveJ = j;
                    moveK = k;
                }
            }
        }

        //The child matrix is then altered to reflect how the current state would look if the possible move is made
        childMatrix[spaceJ][spaceK] = possibleMoves.at(i);
        childMatrix[moveJ][moveK] = 0;

        //The possible move is checked to see if it is the goal state. If it is, the recursive algorithm will return
        done = checkResult(childMatrix);
        if(done == true)
        {
            //printing the goal state
            for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 3; j++)
                {
                    cout << childMatrix[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;

            //printing the position before the goal state
            for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 3; j++)
                {
                    cout << (n1 -> temp)[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;
            
            /*//finding what move led to the goal state
            if(spaceJ > moveJ)
            {
                move = "up";
            } else if(spaceJ < moveJ) {
                move = "down";
            } else if(spaceK > moveK) {
                move = "left";
            } else if(spaceK < moveK) {
                move = "right";
            }
            
            //printing the move that led to the goal state
            cout << move << endl;*/

            return 1;
        }
    }

    //looping through all the possible moves in the current state
    for(unsigned int i = 0; i < possibleMoves.size(); i++)
    {
        //a child matrix is declared and initially made identical to the current state
        int childMatrix[3][3];
        for(int j = 0; j < 3; j++)
        {
            for(int k = 0; k < 3; k++)
            {
                childMatrix[j][k] = temp[j][k];
            }
        }

        //values for the matrix location of the possible move is stored
        int spaceJ, spaceK, moveJ, moveK;
        for(int j = 0; j < 3; j++)
        {
            for(int k = 0; k < 3; k++)
            {
                if(temp[j][k] == 0)
                {
                    spaceJ = j;
                    spaceK = k;
                }
                if(temp[j][k] == possibleMoves.at(i))
                {
                    moveJ = j;
                    moveK = k;
                }
            }
        }

        //The child matrix is then altered to reflect how the current state would look if the possible move is made
        childMatrix[spaceJ][spaceK] = possibleMoves.at(i);
        childMatrix[moveJ][moveK] = 0;

        //the possible move is then checked to see if it is a state that has already been discovered. This avoids duplicate states
        bool undiscovered = true;
        for(unsigned int j = 0; j < discovered.size(); j++)
        {
            if(childMatrix[0][0] == (discovered.at(j) -> temp)[0][0] && childMatrix[0][1] == (discovered.at(j) -> temp)[0][1] && childMatrix[0][2] == (discovered.at(j) -> temp)[0][2] && childMatrix[1][0] == (discovered.at(j) -> temp)[1][0] && childMatrix[1][1] == (discovered.at(j) -> temp)[1][1] && childMatrix[1][2] == (discovered.at(j) -> temp)[1][2] && childMatrix[2][0] == (discovered.at(j) -> temp)[2][0] && childMatrix[2][1] == (discovered.at(j) -> temp)[2][1] && childMatrix[2][2] == (discovered.at(j) -> temp)[2][2])
            {
                undiscovered = false;
            }
        }

        //if the possible move has not been discovered then it is accessed as the next state
        if(undiscovered == true)
        {
            //a new node is created with the child state and it is enqueued
            Node* n2 = createNode(childMatrix, n1);
            q.push(n2);

            //cost equals the value returned from DFS of the child state
            cost = DFS(n2 -> temp);
        }

        //cost is checked once this state is returned to from its child. If cost is greater than zero, the goal state has been found
        if(cost > 0)
        {
            //printing all positions including the start state that led to the goal state
            for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 3; j++)
                {
                    cout << (n1 -> temp)[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;
            
            /*//finding what move was made at this point on the way to the goal state
            if(spaceJ > moveJ)
            {
                move = "up";
            } else if(spaceJ < moveJ) {
                move = "down";
            } else if(spaceK > moveK) {
                move = "left";
            } else if(spaceK < moveK) {
                move = "right";
            }

            //printing that move
            cout << move << endl;*/
            
            return (cost + 1);
        }
    }

    //once we have looped through all possible moves for a state, the state is marked as explored
    explored.push_back(n1);

    //if this return statement is reached, that means this state did not lead to the goal state
    return 0;
}

void Graph::makeMove(int temp[3][3], Node* n, bool dijkstra)
{
    vector<int> possibleMoves = matrix.getNeighbors(0);
    while(possibleMoves.empty() != true){
        int min = possibleMoves.at(0);
        int minIdx = 0;
        unsigned int i;
        for(i = 1; i < possibleMoves.size(); i++)
        {
            if(min > possibleMoves.at(i))
            {
                min = possibleMoves.at(i);
                minIdx = i;
            }
        }
        possibleMoves.erase(possibleMoves.begin() + minIdx);

        int childMatrix[3][3];
        for(int j = 0; j < 3; j++)
        {
            for(int k = 0; k < 3; k++)
            {
                childMatrix[j][k] = temp[j][k];
            }
        }

        //Find space and move positions in puzzle
        int spaceI, spaceJ, minI, minJ;
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(temp[i][j] == 0)
                {
                    spaceI = i;
                    spaceJ = j;
                }
                if(temp[i][j] == min)
                {
                    minI = i;
                    minJ = j;
                }
            }
        }
        childMatrix[spaceI][spaceJ] = min;
        childMatrix[minI][minJ] = 0;

        bool unexplored = true;
        for(unsigned int j = 0; j < explored.size(); j++)
        {
            if(childMatrix[0][0] == (explored.at(j) -> temp)[0][0] && childMatrix[0][1] == (explored.at(j) -> temp)[0][1] && childMatrix[0][2] == (explored.at(j) -> temp)[0][2] && childMatrix[1][0] == (explored.at(j) -> temp)[1][0] && childMatrix[1][1] == (explored.at(j) -> temp)[1][1] && childMatrix[1][2] == (explored.at(j) -> temp)[1][2] && childMatrix[2][0] == (explored.at(j) -> temp)[2][0] && childMatrix[2][1] == (explored.at(j) -> temp)[2][1] && childMatrix[2][2] == (explored.at(j) -> temp)[2][2])
            {
                unexplored = false;
            }
        }

        if(unexplored == true)
        {
            Node* n1 = createNode(childMatrix, n);
            q.push(n1);

            // If moving with Dijkstra, push node into priority queue
            if (dijkstra) frontier.push(n1);
        }
    }
}
Node* Graph::createNode(int temp[3][3], Node* n)
{
    Node *n1 = new Node(temp);
        if(head->next == NULL){
            head->next = n1;
            n1->prev = head;
            n1->parent = head;
        }else
        {
            Node *itr = head;
            while(itr->next != NULL)
            {
                itr = itr->next;
            }
            itr->next = n1;
            n1->prev = itr;
            n1->parent = n;
            n1->getDijkCost();
        }
    return n1;
}

bool Graph::checkResult(int temp[3][3])
{
    if(temp[0][0] == 1 && temp[0][1] == 2 && temp[0][2] == 3 && temp[1][0] == 8 && temp[1][1] == 0 && temp[1][2] == 4 && temp[2][0] == 7 && temp [2][1] == 6 && temp[2][2] == 5)
    {
        return true;
    }
    return false;
}

int Graph::Dijkstra(Node* current) {
    bool done = checkResult(current->temp);
    if (done != true) {
        // Update the matrix with the current state
        matrix.updateMatrix(current->temp);
        // Generate the possible moves
        makeMove(current->temp, current, true);

        // The top node will be the one with lowest dijkstra cost
        Node* next = frontier.top();
        cout << next->dijk_cost << endl; 
        frontier.pop();
        return Dijkstra(next);
    } else {
        Node* iter = current;
        while (iter != NULL) {
            iter->printBoard();
            cout << endl;
            iter = iter->parent;
        }
        return current->dijk_cost;
    }
}