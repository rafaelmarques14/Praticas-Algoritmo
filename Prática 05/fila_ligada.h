#ifndef PRATICA04_FILA_LIGADA_H
#define PRATICA04_FILA_LIGADA_H

#include "fila.h"

template <class T>
class FilaLigada : public Fila<T> {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& data) : data(data), next(nullptr) {}
    };

    Node* frente;
    Node* tras;

public:
    FilaLigada(int capacidade) : Fila<T>(capacidade), frente(nullptr), tras(nullptr) {}

    virtual ~FilaLigada()  {
        while (!this->vazia()) {
            desenfileira();
        }
    }

    void enfileira(const T& item) override {
        if (this->cheia()) {
            throw std::overflow_error("Fila cheia");
        }
        Node* novoNode = new Node(item);
        if (this->vazia()) {
            frente = tras = novoNode;
        } else {
            tras->next = novoNode;
            tras = novoNode;
        }
        this->qtdItens++;
    }

    T desenfileira() override {
        if (this->vazia()) {
            throw std::underflow_error("Fila vazia");
        }
        Node* nodeRemovido = frente;
        T item = nodeRemovido->data;
        frente = frente->next;
        delete nodeRemovido;
        this->qtdItens--;
        if (this->vazia()) {
            tras = nullptr;
        }
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

#endif // PRATICA04_FILA_LIGADA_H
