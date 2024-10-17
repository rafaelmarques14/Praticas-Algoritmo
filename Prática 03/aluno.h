#ifndef PRATICA03_ALUNO_H
#define PRATICA03_ALUNO_H

#include <iostream>
#include <string>
#include "arranjo.h"


class Aluno {
private:
    std::string nome;
    std::string mat;

public:
    Aluno() {}
    Aluno(const char* nome, const char* mat) : nome(nome), mat(mat) {}

    friend class Arranjo<Aluno>;
};


template <>
void Arranjo<Aluno>::set(int idx, const Aluno& aluno) {
    if (idx < 0 || idx >= this->tamanho) {
        throw IndiceInvalido();
    }
    this->items[idx].nome = aluno.nome;
    this->items[idx].mat = aluno.mat;
}

template <>
void Arranjo<Aluno>::exibir() {
    for (int i = 0; i < this->tamanho; ++i) {
        std::cout << i << ": " << this->items[i].mat << " = " << this->items[i].nome << std::endl;
    }
}

#endif //PRATICA03_ALUNO_H
