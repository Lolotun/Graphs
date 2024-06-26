#include "ListGraph.hpp"
#include "ArcGraph.hpp"
#include "MatrixGraph.hpp"
#include "SetGraph.hpp"


int main(int argc, const char * argv[]) {
    ListGraph listGraph(12);
    listGraph.AddEdge(0, 1);
    listGraph.AddEdge(0, 5);
    listGraph.AddEdge(1, 2);
    listGraph.AddEdge(1, 3);
    listGraph.AddEdge(1, 5);
    listGraph.AddEdge(1, 6);
    listGraph.AddEdge(3, 2);
    listGraph.AddEdge(3, 4);
    listGraph.AddEdge(3, 6);
    listGraph.AddEdge(5, 4);
    listGraph.AddEdge(5, 6);
    listGraph.AddEdge(6, 4);
    
    std::cout<< "ListGraph"<<std::endl;
    mainBFS(listGraph, [](int vertex){ std::cout << vertex << " "; });
    std::cout << std::endl;
    
    mainDFS(listGraph, [](int vertex){ std::cout << vertex << " "; });
    std::cout << std::endl;
    
    for (int vertex: topologicalSort(listGraph))
    {
        std::cout << vertex << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;


    std::cout<< "ArcGraph"<<std::endl;
    ArcGraph arcGraph(listGraph);
    arcGraph.AddEdge(7,0);
    arcGraph.AddEdge(7,8);
    mainBFS(arcGraph, [](int vertex){ std::cout << vertex << " "; });
    std::cout << std::endl;
    mainDFS(arcGraph, [](int vertex){ std::cout << vertex << " "; });
    std::cout << std::endl;
    std::cout<< "I added 7 before 0 and 8"<<std::endl;
    for (int vertex: topologicalSort(arcGraph))
    {
        std::cout << vertex << " ";
    }
    std::cout << std::endl;    
    std::cout<<"      ----"<<std::endl;


    std::cout<< "MatrixGraph"<<std::endl;
    MatrixGraph matrixGraph(arcGraph);
    mainBFS(matrixGraph, [](int vertex){ std::cout << vertex << " "; });
    std::cout << std::endl;
    mainDFS(matrixGraph, [](int vertex){ std::cout << vertex << " "; });
    std::cout << std::endl;
    std::cout << "after addition"<<std::endl;
    matrixGraph.AddEdge(4,9);
    matrixGraph.AddEdge(9,10);
    matrixGraph.AddEdge(8,10);
    mainBFS(matrixGraph, [](int vertex){ std::cout << vertex << " "; });
    std::cout << std::endl;
    mainDFS(matrixGraph, [](int vertex){ std::cout << vertex << " "; });
    std::cout << std::endl;
    for (int vertex: topologicalSort(matrixGraph))
    {
        std::cout << vertex << " ";
    }
    std::cout << std::endl;  
    std::cout << std::endl;  


    std::cout<< "SetGraph"<<std::endl;
    SetGraph setGraph(matrixGraph);
    mainBFS(setGraph, [](int vertex){ std::cout << vertex << " "; });
    std::cout << std::endl;
    mainDFS(setGraph, [](int vertex){ std::cout << vertex << " "; });
    std::cout << std::endl;
    setGraph.AddEdge(11,7);
    std::cout << "I added 11 before 7"<<std::endl;
    for (int vertex: topologicalSort(setGraph))
        {
            std::cout << vertex << " ";
        }
        std::cout << std::endl;  


    // Нужно продемонстрировать работу конструктора копирования, проинициализировав
    // графы разных классов друг от друга. Далее, показать, что вершины и ребра
    // успешно скопированы: число вершин осталось прежним, произвести BFS и DFS.
    // MatrixGraph matrixGraph(listGraph);
    // ArcGraph arcGraph(matrixGraph);
    // SetGraph setGraph(arcGraph);
    return 0;
}
