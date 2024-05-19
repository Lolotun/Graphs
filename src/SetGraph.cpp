 #include "SetGraph.hpp"

template <typename T, typename Hasher>
bool Hashtable<T,Hasher>::Add(const T &key)
{
    if (static_cast<float>(size)/table.size() >= ALPHA_LIMIT)
    {
        grow();
    }
    size_t hash = hasher(key)%table.size(); 
    int first_del = -1;
    for ( int i = -1; i < int((table.size()-1)); i++)
    {
        hash = (hash + i + 1 ) % table.size();
        if (table[hash].status == KEY && table[hash].key == key)
            return false;
        if (table[hash].status == DEL)
        {
            if (first_del == -1)
                first_del = hash;
        }
        else if (table[hash].status == NIL)
        {
            if (first_del != -1){
                hash = first_del;
                size--;// логично увеличивать size только если заполняет пустую ячейку
            }
            table[hash].key = key;
            table[hash].status = KEY;
            size ++;
            return true;
        }
    }
    table[first_del].status = KEY;
    table[first_del].key = key;
    return true;
    
}

template <typename T, typename Hasher>   
bool Hashtable<T,Hasher>::Has( T &key) const
{
    size_t hash = hasher(key)%table.size(); 
    for ( int i = -1; i < int((table.size()-1)); i++)
    {
    hash = (hash + i + 1 ) % table.size();
    if (table[hash].status == KEY && table[hash].key == key)
        return true;
    if (table[hash].status == NIL)
    {
        return false;
    }
    }
    return false;
}

template <typename T, typename Hasher>   
bool Hashtable<T,Hasher>::Delete(const T &key)
{
    size_t hash = hasher(key)%table.size(); 
    for ( int i = -1; i < int((table.size()-1)); i++)
    {
        hash = (hash + i + 1 ) % table.size();
        if (table[hash].status == KEY && table[hash].key == key)
        {   
            
            table[hash].status = DEL;
            return true;
        }    
        if (table[hash].status == NIL)
        {
            return false;
        }
    }
    return false;
}

template <typename T, typename Hasher>  
void Hashtable<T,Hasher>::grow()
{
    std::vector<Wrapper<T>> newTable(table.size() * 2);
    size_t hash;
    for (int i = 0; i < table.size(); i++)
    {
        if (table[i].status == KEY)
        {
            hash = hasher(table[i].key) % newTable.size();
            if (newTable[hash].status == NIL)
                newTable[hash] = table[i];
            else{
                bool flag = false;
                size_t j = 0;
                while (!flag)
                {
                    hash = (hash + j + 1 ) % newTable.size();
                    if (newTable[hash].status == NIL)
                    {
                        newTable[hash] = table[i]; 
                        flag = true;

                    }
                    j++;
                }
            }
        }         
    }
    std::swap(table, newTable);
};

SetGraph::SetGraph( const IGraph &graph):adjacencySets(graph.VerticesCount())
{
    for (int from = 0; from < graph.VerticesCount(); ++from)
    {
        std::vector<int> tmp = graph.GetNextVertices(from);
        if (!tmp.empty()){
            for (auto to:tmp)
                adjacencySets[from].Add(to);
        }
    }
}    
void SetGraph::AddEdge(int from, int to)
{
    assert(0 <= from && from < adjacencySets.size());
    assert(0 <= to && to < adjacencySets.size());
    adjacencySets[from].Add(to);
}
    
int SetGraph::VerticesCount() const
{
    return (int)adjacencySets.size();
}
    
std::vector<int> SetGraph::GetNextVertices(int vertex) const
{
    assert(0 <= vertex && vertex < adjacencySets.size());
    std::vector<int> nextVerices;
    for (int to = 0; to < adjacencySets.size();to++){
        if (adjacencySets[vertex].Has(to))
                nextVerices.push_back(to);// тк у нас могут быть кратные ребра
    }
    return nextVerices;
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const
{ 
    assert(0 <= vertex && vertex < adjacencySets.size());
    std::vector<int> prevVertices;
    for (int from = 0; from < adjacencySets.size(); ++from)
    {
        if (adjacencySets[from].Has(from))
            prevVertices.push_back(from);
    }
    return prevVertices;
}