#include "Pessoa.h"
#ifndef FUNCIONARIO_H_INCLUDED
#define FUNCIONARIO_H_INCLUDED

class Funcionario : public Pessoa
{
private:
    char funcao[250];
    char salario[250];
    int tipo;

public:
    Funcionario();
};

Funcionario::Funcionario()
{
}

#endif