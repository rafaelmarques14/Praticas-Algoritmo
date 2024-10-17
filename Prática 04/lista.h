#ifndef PRATICA04_LISTA_H
#define PRATICA04_LISTA_H

#include <iostream>
#include <stdexcept>

template <class T>
class Lista {
private:
    T* itens;
    int capacidade;
    int tamanho_atual;

public:
    Lista(int capacidade);
    ~Lista();

    void adiciona(const T& item);
    T pega(int idx) const;
    void insere(int idx, const T& item);
    void remove(int idx);
    void exibe() const;
    int tamanho() const;
};

template <class T>
Lista<T>::Lista(int capacidade) : capacidade(capacidade), tamanho_atual(0) {
    if (capacidade <= 0) {
        throw std::invalid_argument("Capacidade deve ser positiva.");
    }
    itens = new T[capacidade];
}

template <class T>
Lista<T>::~Lista() {
    delete[] itens;
}

template <class T>
void Lista<T>::adiciona(const T& item) {
    if (tamanho_atual >= capacidade) {
        throw std::overflow_error("Lista cheia");
    }
    itens[tamanho_atual++] = item;
}

template <class T>
T Lista<T>::pega(int idx) const {
    if (idx < 1 || idx > tamanho_atual) {
        throw std::out_of_range("Item invalido");
    }
    return itens[idx - 1];
}

template <class T>
void Lista<T>::insere(int idx, const T& item) {
    if (tamanho_atual >= capacidade) {
        throw std::overflow_error("Lista cheia");
    }
    if (idx < 1 || idx > tamanho_atual + 1) {
        throw std::out_of_range("Indice invalido");
    }
    for (int i = tamanho_atual; i >= idx; --i) {
        itens[i] = itens[i - 1];
    }
    itens[idx - 1] = item;
    ++tamanho_atual;
}

template <class T>
void Lista<T>::remove(int idx) {
    if (idx < 1 || idx > tamanho_atual) {
        throw std::out_of_range("Indice invalido");
    }
    for (int i = idx - 1; i < tamanho_atual - 1; ++i) {
        itens[i] = itens[i + 1];
    }
    --tamanho_atual;
}

template <class T>
void Lista<T>::exibe() const {
    for (int i = 0; i < tamanho_atual; ++i) {
        std::cout << itens[i] << " ";
    }
    std::cout << std::endl;
}

template <class T>
int Lista<T>::tamanho() const {
    return tamanho_atual;
}

#endif //PRATICA04_LISTA_H
