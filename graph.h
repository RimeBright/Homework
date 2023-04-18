#include <string>
#include <iostream>
#define __GRAPH__
#pragma once
#define SIZE 10

using namespace std;

class Graph {
public:
    Graph();
    // ���������� �������
    void addVertex(string name);
    // ���������� �����
    void addEdge(int v1, int v2);
    void getPairs();

private:
    bool edgeExists(int v1, int v2);
    bool vertexExists(string name);
    
    int size = SIZE;

    int matrix[SIZE][SIZE]; // ������� ���������

    string vertexes[SIZE]; // ��������� ������
    string pairs[SIZE*200]; // ��������� ���
    int vertexCount; // ���������� ����������� ������
};
