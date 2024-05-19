#include "ArcGraph.hpp"



ArcGraph::ArcGraph(const IGraph &graph): veritcesCount(graph.VerticesCount())
{
    for (int from = 0; from < graph.VerticesCount(); ++from)
    {
        std::vector<int> tmp = graph.GetNextVertices(from);
        if (!tmp.empty()){
            for (auto to:tmp)
                edgeList.push_back(std::pair<int,int>(from,to));
        }
    }
}

void ArcGraph::AddEdge(int from, int to)
{
    assert(0 <= from && from < veritcesCount);
    assert(0 <= to && to < veritcesCount);
    edgeList.push_back(std::pair<int,int>(from,to));
}
    
int ArcGraph::VerticesCount() const
{
    return veritcesCount;
}
    
std::vector<int> ArcGraph::GetNextVertices(int vertex) const
{
    assert(0 <= vertex && vertex < veritcesCount);
    std::vector<int> nextVerices;
    for (auto& p:edgeList){
        if (p.first == vertex)
            nextVerices.push_back(p.second);
    }
    return nextVerices;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const
{ 
    assert(0 <= vertex && vertex < veritcesCount);
    std::vector<int> prevVerices;
    for (auto& p:edgeList){
        if (p.second == vertex)
            prevVerices.push_back(p.first);
    }
    return prevVerices;
}
