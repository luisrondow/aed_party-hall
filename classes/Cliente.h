#include <iostream>
#include <fstream>
#include <stdio.h>
#include "Pessoa.h"

#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

class Cliente : public Pessoa
{
private:
    std::string endereco;
    std::string data_nascimento;

public:
    Cliente(std::string nome, std::string endereco, std::string telefone, std::string data_nascimento);
    void Store();
};

int getId()
{
    std::string x;
    std::ifstream in;
    in.open("DAO/IdCliente.txt");
    in >> x;

    if (x == "")
    {
        return 0;
    } else {
        return std::stoi(x);
    }
}

Cliente::Cliente(std::string nome, std::string endereco, std::string telefone, std::string data_nascimento)
{
    this->codigo = getId() + 1;
    this->nome = nome;
    this->endereco = endereco;
    this->telefone = telefone;
    this->data_nascimento = data_nascimento;
}

void Cliente::Store()
{
    int i;
    int result;
    FILE *file;
    FILE *fileId;
    std::string file_name = "DAO/Cliente.txt";

    if ((file = fopen(file_name.c_str(), "r")) == NULL)
    {
        file = fopen(file_name.c_str(), "w");
    }
    else
    {
        file = fopen(file_name.c_str(), "a");
    }

    fileId = fopen("DAO/IdCliente.txt", "w");

    if (file == NULL || fileId == NULL)
    {
        printf("Problemas na CRIACAO do arquivo\n");
        return;
    }

    fprintf(fileId, "%d", this->codigo);
    fprintf(file, "%d\n", this->codigo);
    fprintf(file, "%s\n", this->nome.c_str());
    fprintf(file, "%s\n", this->endereco.c_str());
    fprintf(file, "%s\n", this->telefone.c_str());
    fprintf(file, "%s\n", this->data_nascimento.c_str());
    fprintf(file, "\n");
    fclose(file);
}

#endif