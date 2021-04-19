#include <iostream>
#include <fstream>
#include <cctype>
#include <sstream>
#include <string>
#include "Graph.hpp"
using namespace std;

int main()
{
    AdjMatrix matrix;
    string filename, temp;
    filename = "test.txt";
    ifstream input(filename.c_str());

    int tempMatrix[3][3];

    if(!input.is_open())
    {
        cout << "Couldn't open file" << endl;

        return -1;
    }else
    {
        for (int k = 0; k < 3; k++) {
            for(int l = 0; l < 3; l++)
            {
                input >> tempMatrix[k][l];
            }
        }
    }
    // for(int i = 0; i < 3; i++)
    // {
    //     for(int j = 0; j < 3; j++)
    //     {
    //         cout << tempMatrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    matrix.updateMatrix(tempMatrix);
    Graph g(tempMatrix, matrix);
    Graph g1(tempMatrix, matrix);
    Graph g2(tempMatrix, matrix);
    //int result = g.BFS(tempMatrix);
    //cout << "BFS Finished with " << result << " moves." << endl;
    string alg;
    cout << "Perform BFS, DFS, or Dijkstra's algorithm by typing BFS, DFS, or Dijkstra respectively" << endl;
    cin >> alg;

    if(alg == "DFS")
    {
        cout << "DFS sequence of moves (read bottom up): " << endl;
        int result = g.DFS(tempMatrix);
        cout << endl << "DFS Finished with " << result << " moves." << endl;
    } else if(alg == "BFS") {
        cout << "BFS sequence of moves: " << endl;
        int result2 = g1.BFS(tempMatrix);
        cout << endl << "BFS Finished with " << result2 << " moves." << endl;
    } else if(alg == "Dijkstra") {
        cout << "Dijkstra's algorithm sequence of moves: ";
        int result3 = g2.Dijkstra(tempMatrix);
        cout << endl << "Dijkstra's algorithm finished with " << result3 << " cost." << endl;
    } else {
        cout << "Incorrect input" << endl;
    }
    return 0;
}