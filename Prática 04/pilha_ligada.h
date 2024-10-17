#ifndef PRATICA04_PILHA_LIGADA_H
#define PRATICA04_PILHA_LIGADA_H

#include <stdexcept>

template <class T>
class Pilha {
private:
    struct No {
        T dado;
        No* prox;
        No(T dado, No* prox = nullptr) : dado(dado), prox(prox) {}
    };

    No* topo;
    int capacidade;
    int tamanhoAtual;

public:
    Pilha(int capacidade) : capacidade(capacidade), topo(nullptr), tamanhoAtual(0) {}

    ~Pilha() {
        while (topo != nullptr) {
            desempilha();
        }
    }

    void empilha(T item) {
        if (tamanhoAtual == capacidade) {
            throw std::overflow_error("Estouro da pilha");
        }
        No* novoNo = new No(item, topo);
        topo = novoNo;
        tamanhoAtual++;
    }

    T desempilha() {
        if (topo == nullptr) {
            throw std::underflow_error("Pilha vazia");
        }
        No* noRemovido = topo;
        T dado = noRemovido->dado;
        topo = topo->prox;
        delete noRemovido;
        tamanhoAtual--;
        return dado;
    }

    int tamanho() const {
        return tamanhoAtual;
    }
};

#endif //PRATICA04_PILHA_LIGADA_H
