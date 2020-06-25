#include <iostream>
#ifndef PESSOA_H_
#define PESSOA_H_

class Pessoa
{
protected:
    int codigo;
    std::string nome;
    std::string telefone;
public:
    Pessoa();
};

Pessoa::Pessoa() {
}

#endif