#ifndef PRATICA03_FUNCOES_H
#define PRATICA03_FUNCOES_H

#include <cstring>

namespace funcoes {

template <class T>
void trocar(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template <class T>
T maximo(const T a, const T b) {
    return (a > b) ? a : b;
}

template <class T>
T minimo(const T a, const T b) {
    return (a < b) ? a : b;
}

    template <>
    const char* maximo(const char* a, const char* b) {
        return (std::strcmp(a, b) > 0) ? a : b;
    }

    template <>
    const char* minimo(const char* a, const char* b) {
        return (std::strcmp(a, b) < 0) ? a : b;
    }

}

#endif //PRATICA03_FUNCOES_H
