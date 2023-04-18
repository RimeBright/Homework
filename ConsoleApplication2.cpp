#include <iostream>
#include "graph.h"
using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");
    Graph g;

    // добавляем вершины
    g.addVertex("Олег");
    g.addVertex("Никита");
    g.addVertex("Настя");
    g.addVertex("Ваня");
    g.addVertex("Женя");
    g.addVertex("Маша");


    // добавляем ребра
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
  
    g.getPairs();


    return 0;
}