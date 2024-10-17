#ifndef PRATICA04_PILHA_H
#define PRATICA04_PILHA_H

#include <stdexcept>

template <class T>
class Pilha {
private:
    T* itens;
    int capacidade;
    int topo;

public:
    Pilha(int capacidade) : capacidade(capacidade), topo(0) {
        itens = new T[capacidade];
    }

    ~Pilha() {
        delete[] itens;
    }

    void empilha(T item) {
        if (topo == capacidade) {
            throw "Estouro da pilha";
        }
        itens[topo++] = item;
    }

    T desempilha() {
        if (topo == 0) {
            throw "Pilha vazia";
        }
        return itens[--topo];
    }

    int tamanho() {
        return topo;
    }
};

#endif //PRATICA04_PILHA_H
