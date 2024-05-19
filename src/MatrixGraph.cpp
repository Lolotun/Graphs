#include "MatrixGraph.hpp"


MatrixGraph::MatrixGraph(const IGraph &graph):adjacencyMatrix(graph.VerticesCount(), std::vector<int>(graph.VerticesCount(), 0))
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
    assert(0 <= vertex && vertex < adjacencyMatrix.size());
    std::vector<int> nextVerices;
    for (int to = 0; to < adjacencyMatrix[vertex].size();to++){
        if (adjacencyMatrix[vertex][to] > 0){
            for (int i = 0; i < adjacencyMatrix[vertex][to]; i++)
                nextVerices.push_back(to);// тк у нас могут быть кратные ребра
        }
    }
    return nextVerices;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const
{ 
   assert(0 <= vertex && vertex < adjacencyMatrix.size());
    std::vector<int> nextVerices;
    for (int from = 0; from < adjacencyMatrix[vertex].size();from++){
        if (adjacencyMatrix[from][vertex] > 0){
            for (int i = 0; i < adjacencyMatrix[from][vertex]; i++)
                nextVerices.push_back(from);// тк у нас могут быть кратные ребра
        }
    }
    return nextVerices;
}
