#include "graph.h"

Graph::Graph() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            matrix[i][j] = 0;
    vertexCount = 0;
}
// добавление вершины
void Graph::addVertex(string name)
{
    vertexes[vertexCount] = name;
    vertexCount++;
}
// добавление ребра
void Graph::addEdge(int v1, int v2)
{
    matrix[v1][v2] = 1;
    matrix[v2][v1] = 1;
}
// проверка существования ребра
bool Graph::edgeExists(int v1, int v2)
{
    return matrix[v1][v2] > 0;
}

void Graph::getPairs()
{
    
    for (int i = 0; i < vertexCount; i++)
    {
        cout << "====================================" << endl;
        for(int j=0; j< vertexCount; j++)
        {   
            if (matrix[i][j] == 1 && j != i)
            {
                cout << vertexes[i] << " " << vertexes[j] << endl;
                for (int k = 0; k < vertexCount; k++)
                    if (matrix[k][j] == 1 && j != k && k != i)
                    {
                        cout << vertexes[i] << " " << vertexes[k] << endl;
                        for (int p = 0; p < vertexCount; p++)
                            if (matrix[p][k] == 1 && p != i && j != p && p != k)
                                cout << vertexes[i] << " " << vertexes[p] << endl;
                    }
            }
        }
    }
}