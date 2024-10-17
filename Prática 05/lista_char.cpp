#include <iostream>
#include "lista_array.h"

using namespace std;

int mainChar() {  // Changed to main() to make it the entry point
    ListaArray<char> lista(10);  // Initialize with a capacity of 10

    try {
        lista.adiciona('a');    // a
        lista.adiciona('b');    // a b
        lista.adiciona('c');    // a b c
        lista.adiciona('d');    // a b c d
        lista.adiciona('e');    // a b c d e
        lista.exibe();          // a b c d e (saída)

        lista.remove(3);        // a b d e
        lista.exibe();          // a b d e (saída)

        cout << lista.pega(4) << endl;  // e
        lista.insere(2, 'f');   // a f b d e
        lista.exibe();          // a f b d e (saída)

        lista.adiciona('g');    // a f b d e g
        lista.insere(4, 'h');   // a f b h d e g
        cout << lista.pega(2) << endl;  // f
        lista.exibe();          // a f b h d e g (saída)
    } catch (const std::exception& e) {
        cerr << "Erro: " << e.what() << endl;
    }

    return 0;
}
