#include <iostream>
#include "Pessoa.h"
#ifndef FORNECEDOR_H_INCLUDED
#define FORNECEDOR_H_INCLUDED

class Fornecedor : public Pessoa
{
private:
    std::string produto_fornecido;
public:
    Fornecedor();
};

Fornecedor::Fornecedor()
{
}

#endif