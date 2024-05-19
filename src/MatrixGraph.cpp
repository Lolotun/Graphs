#include "MatrixGraph.hpp"


MatrixGraph::MatrixGraph(const IGraph &graph)
{
    for (int from = 0; from < graph.VerticesCount(); ++from)
    {
        std::vector<int> tmp = graph.GetNextVertices(from);
        if (!tmp.empty()){
            for (auto to:tmp)
                adjacencyMatrix[from][to]+=1;
        }
    }
}

void MatrixGraph::AddEdge(int from, int to)
{
    assert(0 <= from && from < adjacencyMatrix.size());
    assert(0 <= to && to < adjacencyMatrix.size());
    adjacencyMatrix[from][to] += 1;
}
    
int MatrixGraph::VerticesCount() const
{
    return (int)adjacencyMatrix.size();
}
    
std::vector<int> MatrixGraph::GetNextVertices(int vertex) const
{
    assert(0 <= vertex && vertex < adjacencyLists.size());
    return adjacencyLists[vertex];
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const
{ 
    assert(0 <= vertex && vertex < adjacencyLists.size());
    std::vector<int> prevVertices;
    
    for (int from = 0; from < adjacencyLists.size(); ++from)
    {
        for (int to: adjacencyLists[from])
        {
            if (to == vertex)
                prevVertices.push_back(from);
        }
    }
    return prevVertices;
}
