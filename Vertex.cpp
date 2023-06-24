
#include "Vertex.h"

#include <algorithm>

Vertex::Vertex(const string& name, float distance) : name(name), distance(distance) {}

void Vertex::relax(const Vertex& incomingEdgeVertex, float edgeWeight) {
    float newWeight = incomingEdgeVertex.distance + edgeWeight;
    this->distance = std::min(this->distance, newWeight);
}