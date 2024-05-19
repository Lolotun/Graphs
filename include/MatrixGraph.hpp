#pragma once
#include "Graph.hpp"

struct MatrixGraph: public IGraph
{
public:
    MatrixGraph(int size)
    : adjacencyMatrix(size, std::vector<int>(size, 0))
    {
    }
    
    MatrixGraph(const IGraph &graph);
    ~MatrixGraph()
    {
    }
    
    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;
private:
    std::vector<std::vector<int>> adjacencyMatrix;//int так как мы не ставили ограничений на число ребер из одной вершини в дргугую
};
