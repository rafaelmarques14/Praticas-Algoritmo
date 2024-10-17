#ifndef PRATICA04_PILHA_H
#define PRATICA04_PILHA_H

#include <stdexcept>

template <class T>
class Pilha {
protected:
    int capacidade;
    int topo;

public:
    Pilha(int capacidade) : capacidade(capacidade), topo(0) {}

    virtual ~Pilha() {}

    virtual void empilha(T item) = 0;
    virtual T desempilha() = 0;
    virtual int tamanho() const = 0;
};

#endif // PRATICA04_PILHA_H
