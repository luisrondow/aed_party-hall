#include <iostream>
#ifndef CONTRATO_H_INCLUDED
#define CONTRATO_H_INCLUDED

class Contrato
{
private:
    int numero;
    float valor_total;
    float valor_final;
    int forma_pagamento;
    float desconto;
    int status;
    int codigo_festa;
public:
    Contrato();
};

Contrato::Contrato(int numero, float valor_total, int forma_pagamento, int status, int codigo_festa)
{
    this->numero = numero;
    this->valor_total = valor_total;
    this->valor_final = getValorFinal(valor_total, forma_pagamento);
    this->forma_pagamento = forma_pagamento;
    this->desconto = this->valor_total - this->valor_final;
    this->status = status;
    this->codigo_festa = codigo_festa;
}

int getValorFinal(float valor_total, int forma_pagamento){
    if(forma_pagamento == 1){
        return valor_total * 0.9;
    } else if(forma_pagamento == 2){
        return valor_total * 0.95;
    } else if(forma_pagamento == 3){
        return valor_total * 0.98;
    } else{
        return valor_total;
    }
}

#endif