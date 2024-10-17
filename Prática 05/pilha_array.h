#ifndef PRATICA04_PILHA_ARRAY_H
#define PRATICA04_PILHA_ARRAY_H

#include "pilha.h"

template <class T>
class PilhaArray : public Pilha<T> {
private:
    T* itens;

public:
    PilhaArray(int capacidade) : Pilha<T>(capacidade) {
        this->itens = new T[capacidade];
    }

    virtual ~PilhaArray()  {
        delete[] this->itens;
    }

    void empilha(T item) override {
        if (this->topo == this->capacidade) {
            throw std::runtime_error("Estouro da pilha");
        }
        this->itens[this->topo++] = item;
    }

    T desempilha() override {
        if (this->topo == 0) {
            throw std::runtime_error("Pilha vazia");
        }
        return this->itens[--this->topo];
    }

    int tamanho() const override {
        return this->topo;
    }
};

#endif // PRATICA04_PILHA_ARRAY_H
