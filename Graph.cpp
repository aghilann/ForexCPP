#include "Graph.h"

#include <cmath>
#include <iostream>
#include <limits>
#include <stack>
#include <unordered_map>
#include <vector>

#include "ExchangeRates.h"
#include "Vertex.h"

void Graph::addData(const ExchangeRates& exchangeRates) {
    for (const auto& [targetName, weight] : exchangeRates.rates) {
        float negativeLogWeight = -log(weight);
        graph[exchangeRates.baseCode].push_back({targetName, weight, negativeLogWeight});

        Vertex v(targetName, numeric_limits<float>::infinity());
        vertices.insert_or_assign(targetName, v);
    }
};

void Graph::bellmanFord(const string& sourceName) {
    // Initialize source vertex
    vertices[sourceName].distance = 0;

    // Relax edges
    for (int i = 0; i < vertices.size() - 1; i++) {
        for (const auto& [sourceName, targets] : graph) {
            for (const auto& [targetName, weight, negativeLogWeight] : targets) {
                vertices[targetName].relax(vertices[sourceName], negativeLogWeight);
            }
        }
    }

    for (const auto& [sourceName, targets] : graph) {
        for (const auto& [targetName, weight, negativeLogWeight] : targets) {
            if (vertices.at(targetName).distance < vertices.at(sourceName).distance + negativeLogWeight) {
                std::cout << "Arbitrage Oppurtunity: " << sourceName << " -> " << targetName << std::endl;
            }
        }
    }
}