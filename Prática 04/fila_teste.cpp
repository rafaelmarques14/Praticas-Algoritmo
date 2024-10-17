/*
 * fila_teste.cpp
 *
 *  Created on: 10 de mar de 2020
 *      Author: IFPE
 */

#include <iostream>
#include "fila.h"

#define MAX 100

using namespace std;

int mainF() {
    Fila<int> fila(MAX);

    try {
        cerr << "Testando enfileira() [normal]: ";
        for (int i = 0; i < MAX; i++) {
            fila.enfileira(i);
        }
        cerr << "OK" << endl;
    } catch (const std::exception& e) {
        cerr << "FALHOU! (" << e.what() << ")" << endl;
        return 1;
    }

    cerr << "Testando tamanho() [cheia]: ";
    if (fila.tamanho() != MAX) {
        cerr << "FALHOU (tam = " << fila.tamanho() << ")" << endl;
        return 1;
    }
    cerr << "OK" << endl;

    try {
        cerr << "Testando enfileira() [overflow]: ";
        fila.enfileira(MAX + 1);
        cerr << "FALHOU!" << endl;
        return 1;
    } catch (const std::overflow_error& e) {
        cerr << "OK (" << e.what() << ")" << endl;
    } catch (const std::exception& e) {
        cerr << "FALHOU! (" << e.what() << ")" << endl;
        return 1;
    }

    cerr << "Testando desenfileira() [normal]: ";
    for (int i = 0; i < MAX; i++) {
        if (fila.desenfileira() != i) {
            cerr << "FALHOU em " << i << endl;
            return 1;
        }
    }
    cerr << "OK" << endl;

    cerr << "Testando tamanho() [vazia]: ";
    if (fila.tamanho() != 0) {
        cerr << "FALHOU (tam = " << fila.tamanho() << ")" << endl;
        return 1;
    }
    cerr << "OK" << endl;

    try {
        cerr << "Testando desenfileira() [underflow]: ";
        fila.desenfileira();
        cerr << "FALHOU!" << endl;
        return 1;
    } catch (const std::underflow_error& e) {
        cerr << "OK (" << e.what() << ")" << endl;
    } catch (const std::exception& e) {
        cerr << "FALHOU! (" << e.what() << ")" << endl;
        return 1;
    }

    return 0;
}
