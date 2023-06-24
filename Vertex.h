#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>
#include <map>
#include <string>

using namespace std;

class Vertex {
   public:
    float distance;
    string name;
    Vertex() = default;
    Vertex(const string& name, float distance);
    void relax(const Vertex& incomingEdgeVertex, float edgeWeight);
};

#endif  // VERTEX_H