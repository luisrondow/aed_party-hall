#include <iostream>
#include "Pessoa.h"
#ifndef FORNECEDOR_H_INCLUDED
#define FORNECEDOR_H_INCLUDED

class Fornecedor : public Pessoa
{
private:
    std::string produto_fornecido;

public:
    Fornecedor(std::string nome, std::string telefone, std::string produto_fornecido);
    void Store();
};

int getIdFornecedor()
{
    std::string x;
    std::ifstream in;
    in.open("DAO/IdFornecedor.txt");
    in >> x;

    if (x == "")
    {
        return 0;
    }
    else
    {
        return std::stoi(x);
    }
}

Fornecedor::Fornecedor()
{
    this->codigo = getIdFornecedor() + 1;
    this->nome = nome;
    this->telefone = telefone;
    this->produto_fornecido = produto_fornecido;
}

void Fornecedor::Store()
{
    int i;
    int result;
    FILE *file;
    FILE *fileId;
    std::string file_name = "DAO/Fornecedor.txt";

    if ((file = fopen(file_name.c_str(), "r")) == NULL)
    {
        file = fopen(file_name.c_str(), "w");
    }
    else
    {
        file = fopen(file_name.c_str(), "a");
    }

    fileId = fopen("DAO/IdFornecedor.txt", "w");

    if (file == NULL || fileId == NULL)
    {
        std::cout << "Problemas na CRIACAO do arquivo" << std::endl;
        return;
    }

    fprintf(fileId, "%d", this->codigo);
    fprintf(file, "%d\n", this->codigo);
    fprintf(file, "%s\n", this->nome.c_str());
    fprintf(file, "%s\n", this->telefone.c_str());
    fprintf(file, "%s\n", this->produto_fornecido.c_str());
    fprintf(file, "\n");
    fclose(file);
}

#endif