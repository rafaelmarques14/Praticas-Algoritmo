#include <iostream>
#include "lista.h"

#define MAX 100

using namespace std;

void testaTamanho(Lista<int> & lista, const char * subcaso, int tamanho) {
    cerr << "Testando tamanho() [" << subcaso << "]: ";
    if (lista.tamanho() != tamanho) {
        cerr << "FALHOU (tam = " << lista.tamanho() << ")" << endl;
        exit(1);
    }
    cerr << "OK" << endl;
}

int mainL() {
    Lista<int> lista(MAX);

    try {
        cerr << "Testando adiciona() [normal]: ";
        for (int i = 1; i <= MAX; i++) {
            lista.adiciona(i);
        }
        cerr << "OK" << endl;
    } catch (const std::exception& e) {
        cerr << "FALHOU! (" << e.what() << ")" << endl;
        return 1;
    }

    testaTamanho(lista, "cheia", MAX);

    try {
        cerr << "Testando adiciona() [overflow]: ";
        lista.adiciona(MAX + 1);
        cerr << "FALHOU!" << endl;
        return 1;
    } catch (const std::overflow_error& e) {
        cerr << "OK (" << e.what() << ")" << endl;
    }

    cerr << "Testando pega() [todos]: ";
    for (int i = MAX; i >= 1; i--) {
        try {
            if (lista.pega(i) != i) {
                cerr << "FALHOU em " << i << endl;
                lista.exibe();
                return 1;
            }
        } catch (const std::exception& e) {
            cerr << "FALHOU em " << i << " (" << e.what() << ")" << endl;
            return 1;
        }
    }
    cerr << "OK" << endl;

    cerr << "Testando remove() [todos]: ";
    try {
        for (int i = 1; i <= MAX; i++) {
            lista.remove(1);
        }
    } catch (const std::exception& e) {
        cerr << "FALHOU (" << e.what() << ")" << endl;
        return 1;
    }
    cerr << "OK" << endl;

    testaTamanho(lista, "vazia", 0);

    try {
        cerr << "Testando remove() [underflow]: ";
        lista.remove(1);
        cerr << "FALHOU!" << endl;
        return 1;
    } catch (const std::out_of_range& e) {
        cerr << "OK (" << e.what() << ")" << endl;
    }

    return 0;
}
