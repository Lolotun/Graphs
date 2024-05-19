#pragma once
#include <Graph.hpp>
#include <functional>

const size_t DEFAULT_SIZE = 2;
const float ALPHA_LIMIT = 0.75;

enum Status
{
    DEL = 1,
    NIL,
    KEY 
};

template<typename T>
struct Wrapper
{
    Status status = NIL;
    T key;
};

template <typename T, typename Hasher>
class Hashtable
{
public:
    Hashtable(size_t initial_size = DEFAULT_SIZE)
    : size(0), table(initial_size)
    {
    };
    
    ~Hashtable(){};
    
    bool Add(const T &key);
    bool Has( T &key) const;
    bool Delete(const T &key);
    
private:
    void grow();
    std::vector<Wrapper<T>> table;
    size_t size;
    Hasher hasher;
};

struct SetGraph: public IGraph
{
public:
    SetGraph(int size)
    : adjacencySets(size)
    {
    }
    
    SetGraph( const IGraph &graph);
    ~SetGraph()
    {
    }
    
    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;
private:
    std::vector<Hashtable<int,std::hash<int>>> adjacencySets;
};

