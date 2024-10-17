#include "graph.h"
#include "heap.h"

#include <queue>
#include <stdexcept> // Para lançar exceções
#include <list>      // Para usar list
#include <vector>

using namespace std;

// Cria array do tipo T com tamanho "size" e inicializa com valor "def"
template<class T>
T* array(int size, T def) {
    T *arr = new T[size];
    for (int i = 0; i < size; i++)
        arr[i] = def;
    return arr;
}

Graph::Graph(int nVert) {
    this->nVert = nVert;
    this->adj = new list<Edge>[nVert];
}

Graph::~Graph() {
    delete[] adj;
}

int Graph::size() {
    return nVert;
}

// Criação da aresta src --> dst
void Graph::edge(int src, int dst, int w) {
    if (src < 0 || src >= nVert || dst < 0 || dst >= nVert) {
        throw out_of_range("Vértice fora dos limites permitidos!");
    }
    adj[src].push_back(Edge(src, dst, w));
}

int Graph::degree(int vtx) {
    if (vtx < 0 || vtx >= nVert) {
        throw out_of_range("Vértice fora dos limites permitidos!");
    }
    return adj[vtx].size();
}

list<int> Graph::neighbors(int src) {
    if (src < 0 || src >= nVert) {
        throw out_of_range("Vértice de origem fora dos limites permitidos!");
    }
    list<int> neighborsList;
    for (const Edge& edge : adj[src]) {
        neighborsList.push_back(edge.dst);
    }
    return neighborsList;
}

int Graph::weight(int src, int dst) {
    if (src < 0 || src >= nVert || dst < 0 || dst >= nVert) {
        throw out_of_range("Vértice fora dos limites permitidos!");
    }
    for (const Edge& edge : adj[src]) {
        if (edge.dst == dst) {
            return edge.weight;
        }
    }
    throw invalid_argument("Aresta não encontrada entre os vértices dados!");
}

void Graph::print() {
    for (int i = 0; i < this->size(); i++) {
        int d = this->degree(i);
        cout << i << "(" << d << "): ";
        list<int> nei = this->neighbors(i);
        for (int dst : nei) {
            int w = this->weight(i, dst);
            cout << dst << "[" << w << "]; ";
        }
        cout << endl;
    }
}

bool Graph::isConnected() {
    int* group = new int[nVert];
    for (int i = 0; i < nVert; ++i) {
        group[i] = i; // Cada vértice começa no seu próprio grupo
    }

    for (int i = 0; i < nVert; ++i) {
        for (const Edge& edge : adj[i]) {
            int srcGroup = group[edge.src];
            int dstGroup = group[edge.dst];
            if (srcGroup != dstGroup) {
                for (int j = 0; j < nVert; ++j) {
                    if (group[j] == dstGroup) {
                        group[j] = srcGroup;
                    }
                }
            }
        }
    }

    int commonGroup = group[0];
    for (int i = 1; i < nVert; ++i) {
        if (group[i] != commonGroup) {
            delete[] group;
            return false;
        }
    }
    delete[] group;
    return true;
}

// -------- PRÁTICA 10 --------------//

list<int> Graph::dfs(int src) {
    list<int> result;
    bool* visited = array(nVert, false);  // Corrigido para usar booleano
    DFS(src, visited, result);
    delete[] visited;
    return result;
}

void Graph::DFS(int src, bool* visited, list<int> &result) {
    // Marca o vértice como visitado
    visited[src] = true;
    // Adiciona o vértice ao resultado
    result.push_back(src);

    // Visita todos os vizinhos não visitados
    for (const Edge& edge : adj[src]) {
        if (!visited[edge.dst]) {
            DFS(edge.dst, visited, result);
        }
    }
}

list<int> Graph::bfs(int src) {
    list<int> result;
    bool* visited = array(nVert, false);  // Corrigido para usar booleano
    BFS(src, visited, result);
    delete[] visited;
    return result;
}

void Graph::BFS(int src, bool* visited, list<int> &result) {
    queue<int> q;  // Fila para a BFS
    visited[src] = true;  // Marca o vértice inicial como visitado
    q.push(src);  // Adiciona o vértice inicial à fila

    while (!q.empty()) {
        int node = q.front();  // Pega o vértice da frente da fila
        q.pop();  // Remove o vértice da fila
        result.push_back(node);  // Adiciona o vértice ao resultado

        // Explora todos os vizinhos do vértice atual
        for (const Edge& edge : adj[node]) {
            int neighbor = edge.dst;
            if (!visited[neighbor]) {  // Se o vizinho ainda não foi visitado
                visited[neighbor] = true;  // Marca o vizinho como visitado
                q.push(neighbor);  // Adiciona o vizinho à fila
            }
        }
    }
}

list<int> Graph::spf(int src, int dst) {
    int* dist = array(nVert, 99999);
    int* prev = array(nVert, -1);

    dist[src] = 0;

    Heap<int> pq(nVert, dist);

    while (!(pq.empty())) {
        int node = pq.dequeue();
        for (Edge e : adj[node]) {
            int v = e.dst;
            int w = e.weight;
            int D = dist[node] + w;
            if (D < dist[v]) {
                prev[v] = node;
                dist[v] = D;
                pq.decrease(v);
            }
        }
    }

    list<int> result;
    path(dst, prev, result);

    delete[] dist;
    delete[] prev;

    return result;
}

void Graph::path(int dst, int* prev, list<int> &result) {
    // Verifica se o destino é válido
    if (dst < 0 || dst >= nVert) {
        throw out_of_range("Destino fora dos limites permitidos!");
    }

    // Inicializa um vetor para armazenar o caminho em ordem reversa
    vector<int> reversedPath;

    // Segue o vetor prev[] a partir do destino e armazena os nós em ordem reversa
    for (int at = dst; at != -1; at = prev[at]) {
        reversedPath.push_back(at);
    }

    // Adiciona os nós do vetor reversedPath à lista result na ordem correta
    for (auto it = reversedPath.rbegin(); it != reversedPath.rend(); ++it) {
        result.push_back(*it);
    }
}

