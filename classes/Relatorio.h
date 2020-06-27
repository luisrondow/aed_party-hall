#include <iostream>
#include <fstream>
#ifndef RELATORIO_H_
#define RELATORIO_H_

class Relatorio
{
    const int LINHAS_CLIENTE = 5;
    const int LINHAS_FUNCIONARIO = 6;
public:
    void FestaPorData(std::string nome);
    void FestaPorCliente(std::string nome);
};

void Relatorio::FestaPorData(std::string nome)
{
}

void Relatorio::FestaPorCliente(std::string nome)
{
}

#endif