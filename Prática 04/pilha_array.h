#ifndef PRATICA04_PILHA_ARRAY_H
#define PRATICA04_PILHA_ARRAY_H

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
            throw std::overflow_error("Estouro da pilha");
        }
        itens[topo++] = item;
    }

    T desempilha() {
        if (topo == 0) {
            throw std::underflow_error("Pilha vazia");
        }
        return itens[--topo];
    }

    int tamanho() const {
        return topo;
    }
};

#endif //PRATICA04_PILHA_ARRAY_H
