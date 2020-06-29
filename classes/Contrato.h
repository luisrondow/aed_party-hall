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
    int status_pagamento;
    int codigo_festa;
public:
    Contrato(int numero, float valor_total, int forma_pagamento, int status_pagamento, int codigo_festa);
    void atualizaStatusPagamento(int status_pagamento);
    float getValorFinal(float valor_total, int forma_pagamento);
    void Store();
};

Contrato::Contrato(int numero, float valor_total, int forma_pagamento, int status_pagamento, int codigo_festa)
{
    this->numero = numero;
    this->valor_total = valor_total;
    this->valor_final = this->getValorFinal(valor_total, forma_pagamento);
    this->forma_pagamento = forma_pagamento;
    this->desconto = this->valor_total - this->valor_final;
    this->status_pagamento = status_pagamento;
    this->codigo_festa = codigo_festa;
}

float Contrato::getValorFinal(float valor_total, int forma_pagamento){
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

void Contrato::atualizaStatusPagamento(int statusPagamento){
    this->status_pagamento = status_pagamento;
}

void Contrato::Store()
{
    int i;
    FILE *file;
    std::string file_name = "DAO/Contrato.txt";

    if ((file = fopen(file_name.c_str(), "r")) == NULL)
    {
        file = fopen(file_name.c_str(), "w");
    }
    else
    {
        file = fopen(file_name.c_str(), "a");
    }

    if (file == NULL)
    {
        std::cout << "Problemas na CRIACAO do arquivo" << std::endl;
        return;
    }

    fprintf(file, "%d\n", this->numero);
    fprintf(file, "%f\n", this->valor_total);
    fprintf(file, "%f\n", this->valor_final);
    fprintf(file, "%d\n", this->forma_pagamento);
    fprintf(file, "%d\n", this->desconto);
    fprintf(file, "%d\n", this->status_pagamento);
    fprintf(file, "\n");
    fclose(file);
}
#endif