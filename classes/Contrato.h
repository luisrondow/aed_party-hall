#include <iostream>
#ifndef CONTRATO_H_INCLUDED
#define CONTRATO_H_INCLUDED

class Contrato
{
private:
    int numero;
    float valor_total;
    float desconto;
    float valor_final;
    int forma_pagamento;
    int status;
    int codigo_festa;
public:
    Contrato();
};

Contrato::Contrato()
{
}

#endif