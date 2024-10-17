#ifndef PRATICA04_FILA_H
#define PRATICA04_FILA_H

#include <stdexcept>

template <class T>
class Fila {
protected:
    int capacidade;
    int qtdItens;

public:
    Fila(int cap) : capacidade(cap), qtdItens(0) {
        if (cap <= 0) {
            throw std::invalid_argument("Capacidade deve ser positiva.");
        }
    }

    virtual ~Fila() {}

    virtual void enfileira(const T& item) = 0;
    virtual T desenfileira() = 0;
    virtual bool cheia() const = 0;
    virtual bool vazia() const = 0;
    virtual int tamanho() const = 0;
};

#endif // PRATICA04_FILA_H
