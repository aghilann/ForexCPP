# Bellman-Ford Arbitrage Detector

This project is a sophisticated financial tool built to detect arbitrage opportunities using the Bellman-Ford algorithm. The Bellman-Ford algorithm finds the shortest path from a single source vertex to all other vertices in a weighted, directed graph. The unique capability of this algorithm to detect negative-weight cycles is leveraged here to identify potential arbitrage situations in the financial markets, enabling the theoretical possibility of risk-free profit.

In the application, currencies are mapped onto vertices, and the edge weight corresponds to the exchange rate. Because the Bellman-Ford algorithm aims to find the minimum distance, the exchange rate is transformed by taking its logarithm and multiplying it by -1. This effectively transforms the problem into finding the path that maximizes returns.

![Arbitrage Graph](https://camo.githubusercontent.com/76fb8d86954e56056cb73b5efd15377d4f4b950ad0125300d3971b2a232ff04a/687474703a2f2f7777772e6d79636572746e6f7465732e636f6d2f77702d636f6e74656e742f75706c6f6164732f323031372f31312f6172626974726167652d67726170682e706e67)

## Features

- **Efficient Arbitrage Detection**: Uses the Bellman-Ford algorithm to accurately and efficiently detect potential arbitrage opportunities in real-time.
- **Currency Representation**: Maps currencies onto a directed, weighted graph, with edges corresponding to exchange rates between currencies.
- **Exchange Rate Transformation**: Transforms exchange rates to fit the optimization goal of the Bellman-Ford algorithm, effectively finding the path yielding maximum returns.
- **Multithreading**: Employs multithreading to parallelize API calls, resulting in a performance increase of up to 70%.
- **Optimized Code**: Utilizes modern C++17 features to minimize data copying while ensuring immutability, leading to highly efficient and maintainable code.

## Getting Started

To run this project, you will need a modern C++ compiler that supports C++17. Detailed instructions on how to set up and execute the project will be added here.

This application presents a unique blend of financial understanding and computer science, showing how algorithms can be effectively used to tackle complex real-world problems. Please feel free to explore, provide feedback, and contribute to the project. Enjoy exploring those arbitrage opportunities!
