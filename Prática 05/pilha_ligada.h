#ifndef PRATICA04_PILHA_LIGADA_H
#define PRATICA04_PILHA_LIGADA_H

#include "pilha.h"
#include <stdexcept>

template <class T>
class PilhaLigada : public Pilha<T> {
private:
    struct Node {
        T item;
        Node* next;
        Node(T item, Node* next = nullptr) : item(item), next(next) {}
    };

    Node* topo;

public:
    PilhaLigada(int capacidade) : Pilha<T>(capacidade), topo(nullptr) {}

    virtual ~PilhaLigada()  {
        while (topo != nullptr) {
            desempilha();
        }
    }

    void empilha(T item) override {
        if (this->tamanho() == this->capacidade) {
            throw std::runtime_error("Estouro da pilha");
        }
        topo = new Node(item, topo);
    }

    T desempilha() override {
        if (this->tamanho() == 0) {
            throw std::runtime_error("Pilha vazia");
        }
        Node* temp = topo;
        T item = topo->item;
        topo = topo->next;
        delete temp;
        return item;
    }

    int tamanho() const override {
        int count = 0;
        Node* current = topo;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }
};

#endif // PRATICA04_PILHA_LIGADA_H
