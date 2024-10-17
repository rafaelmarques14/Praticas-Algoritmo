#include <iostream>
#include <stdexcept>

using namespace std;

class ListaOrdenada {
private:
    int *items;
    int tamanho, capacidade;

public:
    explicit ListaOrdenada(int cap) : capacidade(cap), tamanho(0) {
        items = new int[cap];
    }

    ~ListaOrdenada() {
        delete[] items;
    }

    void insere(int item) {
        if (tamanho >= capacidade) {
            throw runtime_error("Capacidade excedida");
        }

        int i;
        for (i = tamanho - 1; i >= 0 && items[i] > item; i--) {
            items[i + 1] = items[i];
        }
        items[i + 1] = item;
        tamanho++;
    }

    void remove(int item) {
        int pos = buscaBinaria(0, tamanho - 1, item);
        if (pos == -1) {
            throw runtime_error("Elemento nao encontrado");
        }
        for (int i = pos; i < tamanho - 1; i++) {
            items[i] = items[i + 1];
        }
        tamanho--;
    }

    int buscaSequencial(int key) const {
        for (int i = 0; i < tamanho; i++) {
            if (items[i] == key) {
                return i;
            }
            if (items[i] > key) {
                return -1;
            }
        }
        return -1;
    }

    int buscaBinaria(int item) const {
        return buscaBinaria(0, tamanho - 1, item);
    }

    int valida() const {
        for (int i = 0; i < tamanho - 1; i++) {
            if (items[i] > items[i + 1]) return 0;
        }
        return 1;
    }

    void exibe() const {
        for (int i = 0; i < tamanho; i++) {
            cout << i << ": " << items[i] << "; ";
        }
        cout << endl;
    }

    int getTamanho() const {
        return tamanho;
    }

private:
    int buscaBinaria(int inicio, int final, int item) const {
        while (inicio <= final) {
            int meio = inicio + (final - inicio) / 2;
            if (items[meio] == item) {
                return meio;
            }
            if (items[meio] < item) {
                inicio = meio + 1;
            } else {
                final = meio - 1;
            }
        }
        return -1;
    }
};

int main() {
    ListaOrdenada lista(10);

    int elementos[] = {10, 5, 25, 1, 64, 13, 50, 99, 33, 12};

    cout << "Testando insercao..." << endl;
    for (int elem : elementos) {
        lista.insere(elem);
    }

    cout << "Lista: ";
    lista.exibe();

    if (lista.getTamanho() == 10) {
        cout << "Tamanho OK." << endl;
    } else {
        cout << "ERRO: Tamanho errado (!= 10): " << lista.getTamanho() << endl;
        return 1;
    }

    if (lista.valida()) {
        cout << "Lista esta ordenada." << endl;
    } else {
        cout << "ERRO: Lista nao esta ordenada." << endl;
        return 1;
    }

    cout << endl << "Testando remocao..." << endl;
    try {
        lista.remove(5);
        lista.remove(50);
        lista.remove(33);
        lista.remove(-100);
        cout << "ERRO: Excecao nao lancada na remocao. Abortando." << endl;
        return 1;
    } catch (const runtime_error& e) {
        cout << "Excecao lancada na remocao: " << e.what() << endl;
    }

    cout << "Lista: ";
    lista.exibe();

    if (lista.getTamanho() == 7) {
        cout << "Tamanho OK." << endl;
    } else {
        cout << "ERRO: Tamanho errado (!= 7): " << lista.getTamanho() << endl;
        return 1;
    }

    if (lista.valida()) {
        cout << "Lista esta ordenada." << endl;
    } else {
        cout << "ERRO: Lista nao esta ordenada." << endl;
        return 1;
    }

    cout << endl << "Testando buscas..." << endl;

    cout << "- Itens presentes: ";

    int bs10 = lista.buscaSequencial(10);
    int bb10 = lista.buscaBinaria(10);

    int bs25 = lista.buscaSequencial(25);
    int bb25 = lista.buscaBinaria(25);

    if ((bs10 == 1) && (bb10 == 1) && (bs25 == 4) && (bb25 == 4)) {
        cout << "OK" << endl;
    } else {
        cout << "ERRO" << endl;
        return 1;
    }

    cout << "- Itens ausentes: ";

    int bs20 = lista.buscaSequencial(20);
    int bb20 = lista.buscaBinaria(20);

    int bs77 = lista.buscaSequencial(77);
    int bb77 = lista.buscaBinaria(77);

    if ((bs20 == -1) && (bb20 == -1) && (bs77 == -1) && (bb77 == -1)) {
        cout << "OK" << endl;
    } else {
        cout << "ERRO" << endl;
        return 1;
    }

    cout << "- Itens removidos: ";

    int bs5 = lista.buscaSequencial(5);
    int bb5 = lista.buscaBinaria(5);

    int bs33 = lista.buscaSequencial(33);
    int bb33 = lista.buscaBinaria(33);

    if ((bs5 == -1) && (bb5 == -1) && (bs33 == -1) && (bb33 == -1)) {
        cout << "OK" << endl;
    } else {
        cout << "ERRO" << endl;
        return 1;
    }

    return 0;
}
