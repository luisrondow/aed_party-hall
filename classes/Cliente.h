#include "Pessoa.h"
#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

class Cliente : public Pessoa
{
private:
    char endereco[250];
    char data_nascimento[250];

public:
    Cliente();
};

Cliente::Cliente()
{
}

#endif