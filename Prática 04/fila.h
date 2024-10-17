#ifndef PRATICA04_FILA_H
#define PRATICA04_FILA_H

#include <stdexcept>

template <class T>
class Fila {
private:
    T* itens;
    int capacidade;
    int qtdItens;
    int inicio;
    int fim;

public:
    Fila(int cap) : capacidade(cap), qtdItens(0), inicio(0), fim(0) {
        if (cap <= 0) {
            throw std::invalid_argument("Capacidade deve ser positiva.");
        }
        itens = new T[cap];
    }

    ~Fila() {
        delete[] itens;
    }

    void enfileira(const T& item) {
        if (cheia()) {
            throw std::overflow_error("Fila cheia");
        }
        itens[fim] = item;
        fim = (fim + 1) % capacidade;
        qtdItens++;
    }

    T desenfileira() {
        if (vazia()) {
            throw std::underflow_error("Fila vazia");
        }
        T item = itens[inicio];
        inicio = (inicio + 1) % capacidade;
        qtdItens--;
        return item;
    }

    bool cheia() const {
        return qtdItens == capacidade;
    }

    bool vazia() const {
        return qtdItens == 0;
    }

    int tamanho() const {
        return qtdItens;
    }
};

#endif // PRATICA04_FILA_H
