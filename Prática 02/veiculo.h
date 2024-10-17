#ifndef PRATICA02_VEICULO_H
#define PRATICA02_VEICULO_H

#include <string>

class Veiculo {
public:
    Veiculo();
    Veiculo(const char* nome);
    virtual ~Veiculo();
    const std::string& getNome() const;
    void setNome(const std::string& nome);
    void setNomeChar(const char* nome);
    virtual void mover() = 0;

protected:
    std::string nome;

private:
    void exibirMensagem() const;
};

class Terrestre : public virtual Veiculo {
public:
    Terrestre(const char* nome);
    Terrestre(int cap_pass);
    virtual ~Terrestre();
    void dirigir();
    void mover() override;
    void setCapacidadeMax(int capacidade);
    int getCapacidadeMax() const;

protected:
    Terrestre();

private:
    int cap_pass;
};

class Aquatico : public virtual Veiculo {
public:
    Aquatico(const char* nome);
    Aquatico(float carga_max);
    virtual ~Aquatico();
    void nadar();
    void mover() override;
    void setCargaMax(float carga);
    float getCargaMax() const;

protected:
    Aquatico();

private:
    float carga_max;
};

class Aereo : public Veiculo {
public:
    Aereo();
    Aereo(const char* nome);
    virtual ~Aereo();
    void voar();
    void mover() override;
    void setVelocidadeMax(float velocidade);
    float getVelocidadeMax() const;

private:
    float vel_max;
};

class Anfibio : public Terrestre, public Aquatico {
public:
    Anfibio(const char* nome);
    ~Anfibio() override;
    void mover() override;
};


#endif //PRATICA02_VEICULO_H
