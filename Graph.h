#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "ExchangeRates.h"
#include "Vertex.h"

using namespace std;

class Graph {
   public:
    // Source Country -> (Target Country, Exchange Rate, Negative Log Exchange Rate)
    map<string, vector<tuple<string, double, double>>> graph;
    map<string, Vertex> vertices;

    void addData(const ExchangeRates& exchangeRates);

    void printGraph() const;

    void bellmanFord(const string& sourceName);

    void printPath(const string& sourceName, const string& targetName) const;
};
