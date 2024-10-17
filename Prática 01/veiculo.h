
#ifndef PRATICA01_VEICULO_H
#define PRATICA01_VEICULO_H

#include <string>

class Roda {
public:
    Roda();
    ~Roda();
};

class Veiculo {
private:
    std::string nome;
    int num_rodas;
    Roda *rodas;

public:
    Veiculo(const char* param, int rodas);
    ~Veiculo();
    void setNumRodas(int rodas);
    int getNumRodas() const;
};

#endif //PRATICA01_VEICULO_H
