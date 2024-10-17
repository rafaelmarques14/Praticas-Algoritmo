#ifndef LISTA_H
#define LISTA_H

#include <stdexcept>

template <class T>
class Lista {
protected:
    int capacidade;
    int tamanho_atual;

public:
    Lista(int capacidade) : capacidade(capacidade), tamanho_atual(0) {
        if (capacidade <= 0) {
            throw std::invalid_argument("Capacidade deve ser positiva.");
        }
    }

    virtual ~Lista() {}

    virtual void adiciona(const T& item) = 0;
    virtual T pega(int idx) const = 0;
    virtual void insere(int idx, const T& item) = 0;
    virtual void remove(int idx) = 0;
    virtual void exibe() const = 0;
    virtual int tamanho() const = 0;
};

#endif // LISTA_H
