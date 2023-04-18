#include <string>
#include <iostream>
#define __GRAPH__
#pragma once
#define SIZE 10

using namespace std;

class Graph {
public:
    Graph();
    // добавление вершины
    void addVertex(string name);
    // добавление ребра
    void addEdge(int v1, int v2);
    void getPairs();

private:
    bool edgeExists(int v1, int v2);
    bool vertexExists(string name);
    
    int size = SIZE;

    int matrix[SIZE][SIZE]; // матрица смежности

    string vertexes[SIZE]; // хранилище вершин
    string pairs[SIZE*200]; // хранилище пар
    int vertexCount; // количество добавленных вершин
};
