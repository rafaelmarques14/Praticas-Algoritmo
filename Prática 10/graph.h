#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <list>

using namespace std;

class Graph {
private:
    // Aresta
    struct Edge {
        int src;        // Origem da aresta
        int dst;        // Destino da aresta (nó vizinho)
        int weight;     // Peso da aresta
        Edge(int src, int dst, int weight) : src(src), dst(dst), weight(weight) {}
    };

    int nVert;            // Número de vértices
    list<Edge> * adj;    // Array de listas de adjacência (list da STL)

public:
    Graph(int nVert);
    ~Graph();

    int size();    // Retorna número de vértices

    // Prática 09
    void edge(int src, int dst, int w);  // Cria src -> dst com peso w
    int degree(int vtx);                 // Retorna grau de um vértice
    int weight(int src, int dst);        // Retorna peso da aresta de src para dst
    list<int> neighbors(int src);        // Retorna lista de vertices ligados a src
    bool isConnected();                  // Verifica se o grafo é conexo

    // Prática 10
    list<int> dfs(int src);              // Busca em profundidade
    list<int> bfs(int src);              // Busca em largura
    list<int> spf(int src, int dst);     // Menor caminho entre src e dst

    void print();                        // Exibe o grafo
    friend ostream & operator<<(ostream & out, const Graph::Edge & edge); // Usado na exibição

private:
    // Prática 10
    void DFS(int src, bool* visited, list<int> &result);  // DFS de fato
    void BFS(int src, bool* visited, list<int> &result);  // BFS de fato
    void path(int dst, int* prev, list<int> &result);     // Função auxiliar para caminho mais curto
};

#endif // GRAPH_H
