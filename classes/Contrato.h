#ifndef CONTRATO_H_INCLUDED
#define CONTRATO_H_INCLUDED

class Contrato
{
private:
    int numero;
    float valor_total;
    float desconto;
    float valor_final;
    char forma_pagamento[250];
    char status[250];
    int codigo_festa;
public:
    Contrato();
};

Contrato::Contrato()
{
}

#endif