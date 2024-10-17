#ifndef PRATICA04_FILA_ARRAY_H
#define PRATICA04_FILA_ARRAY_H

#include "fila.h"

template <class T>
class FilaArray : public Fila<T> {
private:
    T* itens;
    int inicio;
    int fim;

public:
    FilaArray(int capacidade) : Fila<T>(capacidade), inicio(0), fim(0) {
        itens = new T[capacidade];
    }

   virtual ~FilaArray()  {
        delete[] itens;
    }

    void enfileira(const T& item) override {
        if (this->cheia()) {
            throw std::overflow_error("Fila cheia");
        }
        this->itens[this->fim] = item;
        this->fim = (this->fim + 1) % this->capacidade;
        this->qtdItens++;
    }

    T desenfileira() override {
        if (this->vazia()) {
            throw std::underflow_error("Fila vazia");
        }
        T item = this->itens[this->inicio];
        this->inicio = (this->inicio + 1) % this->capacidade;
        this->qtdItens--;
        return item;
    }

    bool cheia() const override {
        return this->qtdItens == this->capacidade;
    }

    bool vazia() const override {
        return this->qtdItens == 0;
    }

    int tamanho() const override {
        return this->qtdItens;
    }
};

#endif // PRATICA04_FILA_ARRAY_H
