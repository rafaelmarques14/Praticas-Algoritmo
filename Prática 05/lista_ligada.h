#ifndef LISTA_LIGADA_H
#define LISTA_LIGADA_H

#include "lista.h"
#include <stdexcept>
#include <iostream>

template <class T>
class ListaLigada : public Lista<T> {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& data) : data(data), next(nullptr) {}
    };

    Node* cabeca;
    Node* cauda;

public:
    ListaLigada(int capacidade) : Lista<T>(capacidade), cabeca(nullptr), cauda(nullptr) {}

    virtual ~ListaLigada() {
        while (cabeca != nullptr) {
            Node* temp = cabeca;
            cabeca = cabeca->next;
            delete temp;
        }
    }

    void adiciona(const T& item) override {
        if (this->tamanho_atual >= this->capacidade) {
            throw std::overflow_error("Lista cheia");
        }
        Node* novoNode = new Node(item);
        if (cauda != nullptr) {
            cauda->next = novoNode;
        } else {
            cabeca = novoNode;
        }
        cauda = novoNode;
        ++this->tamanho_atual;
    }

    T pega(int idx) const override {
        if (idx < 1 || idx > this->tamanho_atual) {
            throw std::out_of_range("Indice invalido");
        }
        Node* temp = cabeca;
        for (int i = 1; i < idx; ++i) {
            temp = temp->next;
        }
        return temp->data;
    }

    void insere(int idx, const T& item) override {
        if (idx < 1 || idx > this->tamanho_atual + 1) {
            throw std::out_of_range("Indice invalido");
        }
        if (this->tamanho_atual >= this->capacidade) {
            throw std::overflow_error("Lista cheia");
        }
        Node* novoNode = new Node(item);
        if (idx == 1) {
            novoNode->next = cabeca;
            cabeca = novoNode;
            if (cauda == nullptr) {
                cauda = novoNode;
            }
        } else {
            Node* temp = cabeca;
            for (int i = 1; i < idx - 1; ++i) {
                temp = temp->next;
            }
            novoNode->next = temp->next;
            temp->next = novoNode;
            if (novoNode->next == nullptr) {
                cauda = novoNode;
            }
        }
        ++this->tamanho_atual;
    }

    void remove(int idx) override {
        if (idx < 1 || idx > this->tamanho_atual) {
            throw std::out_of_range("Indice invalido");
        }
        Node* temp = cabeca;
        if (idx == 1) {
            cabeca = cabeca->next;
            if (cabeca == nullptr) {
                cauda = nullptr;
            }
            delete temp;
        } else {
            Node* prev = nullptr;
            for (int i = 1; i < idx; ++i) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
            if (temp->next == nullptr) {
                cauda = prev;
            }
            delete temp;
        }
        --this->tamanho_atual;
    }

    void exibe() const override {
        Node* temp = cabeca;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    int tamanho() const override {
        return this->tamanho_atual;
    }
};

#endif // LISTA_LIGADA_H
