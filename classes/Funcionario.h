#include <iostream>
#include <fstream>
#include <stdio.h>
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
    Funcionario(std::string nome, std::string telefone, std::string funcao, std::string salario, int tipo);
    void Store();
};

int getIdFuncionario()
{
    std::string x;
    std::ifstream in;
    in.open("DAO/IdFuncionario.txt");
    in >> x;

    if (x == "")
    {
        return 0;
    } else {
        return std::stoi(x);
    }
}

Funcionario::Funcionario(std::string nome, std::string telefone, std::string funcao, std::string salario, int tipo)
{
    this->codigo = getIdFuncionario() + 1;
    this->nome = nome;
    this->telefone = telefone;
    this->funcao = funcao;
    this->salario = salario;
    this->tipo = tipo;
}

void Funcionario::Store()
{
    int i;
    int result;
    FILE *file;
    FILE *fileId;
    std::string file_name = "DAO/Funcionario.txt";

    if ((file = fopen(file_name.c_str(), "r")) == NULL)
    {
        file = fopen(file_name.c_str(), "w");
    }
    else
    {
        file = fopen(file_name.c_str(), "a");
    }

    fileId = fopen("DAO/IdFuncionario.txt", "w");

    if (file == NULL || fileId == NULL)
    {
        std::cout << "Problemas na CRIACAO do arquivo" << std::endl;
        return;
    }

    fprintf(fileId, "%d", this->codigo);
    fprintf(file, "%d\n", this->codigo);
    fprintf(file, "%s\n", this->nome.c_str());
    fprintf(file, "%s\n", this->telefone.c_str());
    fprintf(file, "%s\n", this->funcao.c_str());
    fprintf(file, "%s\n", this->salario.c_str());
    fprintf(file, "%d\n", this->tipo);
    fprintf(file, "\n");
    fclose(file);
}

#endif