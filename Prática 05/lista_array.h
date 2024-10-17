#ifndef LISTA_ARRAY_H
#define LISTA_ARRAY_H

#include "lista.h"
#include <iostream>
#include <stdexcept>

template <class T>
class ListaArray : public Lista<T> {
private:
    T* itens;
    T* cabeca;
    T* cauda;

public:
    ListaArray(int capacidade) : Lista<T>(capacidade) {
        itens = new T[capacidade];
        cabeca = itens;
        cauda = itens;
    }

    virtual ~ListaArray() {
        delete[] itens;
    }

    void adiciona(const T& item) override {
        if (this->tamanho_atual >= this->capacidade) {
            throw std::overflow_error("Lista cheia");
        }
        *cauda = item;
        ++cauda;
        ++this->tamanho_atual;
    }

    T pega(int idx) const override {
        if (idx < 1 || idx > this->tamanho_atual) {
            throw std::out_of_range("Indice invalido");
        }
        return *(cabeca + (idx - 1));
    }

    void insere(int idx, const T& item) override {
        if (this->tamanho_atual >= this->capacidade) {
            throw std::overflow_error("Lista cheia");
        }
        if (idx < 1 || idx > this->tamanho_atual + 1) {
            throw std::out_of_range("Indice invalido");
        }

        for (T* it = cauda; it > cabeca + (idx - 1); --it) {
            *it = *(it - 1);
        }
        *(cabeca + (idx - 1)) = item;
        ++cauda;
        ++this->tamanho_atual;
    }

    void remove(int idx) override {
        if (idx < 1 || idx > this->tamanho_atual) {
            throw std::out_of_range("Indice invalido");
        }

        for (T* it = cabeca + (idx - 1); it < cauda - 1; ++it) {
            *it = *(it + 1);
        }
        --cauda;
        --this->tamanho_atual;
    }

    void exibe() const override {
        for (T* it = cabeca; it < cauda; ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }

    int tamanho() const override {
        return this->tamanho_atual;
    }
};

#endif // LISTA_ARRAY_H
