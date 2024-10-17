#include <iostream>
#include "funcoes.h"
#include "arranjo.h"
#include "aluno.h"

int main() {

    using namespace funcoes;

    int x = 5, y = 10, z = 30;
    std::cout << "Antes: x = " << x << " y = " << y << std::endl;
    trocar(x, y);
    std::cout << "Depois : x = " << x << " y = " << y << std::endl;
    std::cout << "Minimo entre " << x << " e " << y << ": " << minimo(x, y) << std::endl;
    std::cout << "Maximo entre " << y << " e " << z << ": " << maximo(y, z) << std::endl;
    std::cout << "Minimo de \"strA\" e \"strB\": " << minimo("strA", "strB") << std::endl;
    std::cout << "Maximo de \"strA\" e \"strB\": " << maximo("strA", "strB") << std::endl;

    Arranjo<int> arr(10);
    arr.set(4, 5);
    arr.set(7, 15);
    arr.set(8, 22);
    arr.exibir();

    Arranjo<float> arrFloat(5);
    arrFloat.set(0, 1.1f);
    arrFloat.set(1, 2.2f);
    arrFloat.set(2, 3.3f);
    arrFloat.set(3, 4.4f);
    arrFloat.set(4, 5.5f);
    arrFloat.exibir();

    try {
        std::cout << "Tentando acessar indice invalido:" << std::endl;
        arrFloat.get(10);
    } catch (const IndiceInvalido& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }

    Arranjo<Aluno> turma(3);
    turma.set(0, Aluno("Joao", "1234"));
    turma.set(1, Aluno("Maria", "5235"));
    turma.set(2, Aluno("Jose", "2412"));
    turma.exibir();

    return 0;
}
