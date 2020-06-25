#include <iostream>
#include "Pessoa.h"
#ifndef FUNCIONARIO_H_INCLUDED
#define FUNCIONARIO_H_INCLUDED

class Funcionario : public Pessoa
{
private:
    std::string funcao;
    std::string salario;
    int tipo;

public:
    Funcionario();
};

Funcionario::Funcionario()
{
}

#endif