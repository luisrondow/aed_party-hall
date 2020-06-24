#include "Pessoa.h"
#ifndef FORNECEDOR_H_INCLUDED
#define FORNECEDOR_H_INCLUDED

class Fornecedor : public Pessoa
{
private:
    char produto_fornecido[250];
public:
    Fornecedor();
};

Fornecedor::Fornecedor()
{
}

#endif