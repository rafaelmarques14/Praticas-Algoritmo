#include <iostream>
#include "veiculo.h"

Veiculo::Veiculo() : nome("") {}

Veiculo::Veiculo(const char* nome) : nome(nome) {
    exibirMensagem();
}

Veiculo::~Veiculo() {
    std::cout << "Destrutor de Veiculo chamado para: " << nome << std::endl;
}

const std::string& Veiculo::getNome() const {
    return nome;
}

void Veiculo::setNome(const std::string& nome) {
    this->nome = nome;
}

void Veiculo::setNomeChar(const char* nome) {
    this->nome = nome;
}

void Veiculo::exibirMensagem() const {
    std::cout << "Objeto do tipo Veiculo criado: " << nome << std::endl;
}

Terrestre::Terrestre() : Veiculo(), cap_pass(5) {}

Terrestre::Terrestre(const char* nome) : Veiculo(nome), cap_pass(5) {}

Terrestre::Terrestre(int cap_pass) : Veiculo(""), cap_pass(cap_pass) {}

Terrestre::~Terrestre() {
    std::cout << "Destrutor de Terrestre chamado para: " << nome << std::endl;
}

void Terrestre::dirigir() {
    std::cout << "Dirigindo!\n";
}

void Terrestre::mover() {
    std::cout << "Veiculo terrestre " << getNome() << " moveu.\n";
}

void Terrestre::setCapacidadeMax(int capacidade) {
    this->cap_pass = capacidade;
}

int Terrestre::getCapacidadeMax() const {
    return cap_pass;
}

Aquatico::Aquatico() : Veiculo(), carga_max(10.0f) {}

Aquatico::Aquatico(const char* nome) : Veiculo(nome), carga_max(10.0f) {}

Aquatico::Aquatico(float carga_max) : Veiculo(""), carga_max(carga_max) {}

Aquatico::~Aquatico() {
    std::cout << "Destrutor de Aquatico chamado para: " << nome << std::endl;
}

void Aquatico::nadar() {
    std::cout << "Nadando!\n";
}

void Aquatico::mover() {
    std::cout << "Veiculo aquatico " << getNome() << " moveu.\n";
}

void Aquatico::setCargaMax(float carga) {
    this->carga_max = carga;
}

float Aquatico::getCargaMax() const {
    return carga_max;
}

Aereo::Aereo() : Veiculo(), vel_max(100.0f) {}

Aereo::Aereo(const char* nome) : Veiculo(nome), vel_max(100.0f) {}

Aereo::~Aereo() {
    std::cout << "Destrutor de Aereo chamado para: " << nome << std::endl;
}

void Aereo::voar() {
    std::cout << "Voando!\n";
}

void Aereo::mover() {
    std::cout << "Veiculo aereo " << getNome() << " moveu.\n";
}

void Aereo::setVelocidadeMax(float velocidade) {
    this->vel_max = velocidade;
}

float Aereo::getVelocidadeMax() const {
    return vel_max;
}

Anfibio::Anfibio(const char* nome) : Veiculo(nome), Terrestre(), Aquatico() {}

Anfibio::~Anfibio() {
    std::cout << "Destrutor de Anfibio chamado para: " << nome << std::endl;
}

void Anfibio::mover() {
    Terrestre::mover();
    Aquatico::mover();
}