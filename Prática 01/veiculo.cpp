#include <iostream>
#include "veiculo.h"

Roda::Roda() {
    std::cout << "Objeto Roda construido" << std::endl;
}

Roda::~Roda() {
    std::cout << "Objeto Roda destruido" << std::endl;
}

Veiculo::Veiculo(const char* param, int num_rodas) : nome(param), num_rodas(num_rodas) {
    rodas = new Roda[num_rodas];
    std::cout << "Novo objeto Veiculo construido" << std::endl;
}

Veiculo::~Veiculo() {
    delete[] rodas;
    std::cout << "Objeto Veiculo destruido" << std::endl;
}

void Veiculo::setNumRodas(int num_rodas) {
    delete[] rodas;
    this->num_rodas = num_rodas;
    rodas = new Roda[num_rodas];
}

int Veiculo::getNumRodas() const {
    return num_rodas;
}

