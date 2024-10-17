#include <iostream>
#include <string>
#include "veiculo.h"

using namespace std;

/*class Veiculo{

private:
    string nome;
    int num_rodas;

public:
    Veiculo(const char* param, int rodas);

    ~Veiculo();

    void setNumRodas(int rodas);
    int getNumRodas();

};

Veiculo::Veiculo(const char* param, int rodas) : nome(param), num_rodas(rodas) {
    cout << "Objeto Veiculo construido com o nome: " << this->nome
         << " e " << this->num_rodas << " rodas" << endl;
}

Veiculo::~Veiculo() {
    cout << "Objeto Veiculo destruido: " << this->nome << endl;
}

void Veiculo::setNumRodas(int rodas) {
    this->num_rodas = rodas;
}

int Veiculo::getNumRodas() {
    return this->num_rodas;
}
*/

int main() {

    //cout << "Primeira aplicacao C++" << std::endl; Parte 1

    /*{ Parte 2
        Veiculo veiculo1("v1");
        {
            Veiculo veiculo2("v2");
            {
                Veiculo veiculo3("v3");
            }
        }
    }
    */

    /* Parte 3
     * Veiculo* obj1 = new Veiculo("v1");
    {
        Veiculo* obj2 = new Veiculo("v2");
        {
            Veiculo* obj3 = new Veiculo("v3");
                delete obj3;
        }
        delete obj2;
    }
    delete obj1; */

    Veiculo veiculo("Carro", 4);

    veiculo.setNumRodas(4);

    cout << "Numero de rodas do veiculo: " << veiculo.getNumRodas() << endl;

    return 0;
}
