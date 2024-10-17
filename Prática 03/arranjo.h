#ifndef PRATICA03_ARRANJO_H
#define PRATICA03_ARRANJO_H

#include <iostream>
#include <exception>

class IndiceInvalido : public std::exception {
public:
    const char* what() const noexcept override {
        return "Indice fora dos limites do array";
    }
};

template <class T>
class Arranjo {
private:
    int tamanho;
    T* items;

public:
    Arranjo(int tam) {

        tamanho = tam;
        items = new T[tamanho];
        for (int i = 0; i < tamanho; ++i) {
            items[i] = T();
        }
    }

    virtual ~Arranjo() {
        delete[] items;
    }

    virtual T get(int idx) {
        if (idx < 0 || idx >= tamanho) {
            throw IndiceInvalido();
        }
        return items[idx];
    }

    virtual void set(int idx, const T& item) {
        if (idx < 0 || idx >= tamanho) {
            throw IndiceInvalido();
        }
        items[idx] = item;
    }

    virtual void exibir() {
        for (int i = 0; i < tamanho; ++i) {
            std::cout << i << ": " << items[i] << std::endl;
        }
    }
};

#endif //PRATICA03_ARRANJO_H
