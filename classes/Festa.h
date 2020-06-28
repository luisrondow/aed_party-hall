#include <iostream>
#ifndef FESTA_H_INCLUDED
#define FESTA_H_INCLUDED

class Festa
{
private:
    int codigo;
    int quantidade_convidados;
    std::string data;
    int dia_semana;
    int horario_inicio;
    int horario_fim;
    std::string tema;
    int codigo_cliente;

public:
    Festa(int quantidade_convidados, std::string data, int dia_semana, int horario_inicio, int horario_fim, std::string tema, int codigo_cliente);
    void Store();
};

int getIdFesta()
{
    std::string x;
    std::ifstream in;
    in.open("DAO/IdFesta.txt");
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

Festa::Festa(int quantidade_convidados, std::string data, int dia_semana, int horario_inicio, int horario_fim, std::string tema, int codigo_cliente)
{
    this->codigo = getIdFesta() + 1;
    this->quantidade_convidados = quantidade_convidados;
    this->data = data;
    this->dia_semana = dia_semana;
    this->horario_inicio = horario_inicio;
    this->horario_fim = horario_fim;
    this->tema = tema;
    this->codigo_cliente = codigo_cliente;
}

void Festa::Store()
{
    int i;
    int result;
    FILE *file;
    FILE *fileId;
    std::string file_name = "DAO/Festa.txt";

    if ((file = fopen(file_name.c_str(), "r")) == NULL)
    {
        file = fopen(file_name.c_str(), "w");
        fclose(file);
    }
    else
    {
        file = fopen(file_name.c_str(), "a");
        fclose(file);
    }

    fileId = fopen("DAO/Festa.txt", "w");

    if (file == NULL || fileId == NULL)
    {
        std::cout << "Problemas na CRIACAO do arquivo" << std::endl;
        return;
    }

    fclose(fileId);

    fprintf(fileId, "%d", this->codigo);
    fprintf(file, "%d\n", this->codigo);
    fprintf(file, "%d\n", this->quantidade_convidados);
    fprintf(file, "%s\n", this->data.c_str());
    fprintf(file, "%d\n", this->dia_semana);
    fprintf(file, "%d\n", this->horario_inicio);
    fprintf(file, "%d\n", this->horario_fim);
    fprintf(file, "%s\n", this->tema.c_str());
    fprintf(file, "%d\n", this->codigo_cliente);
    fprintf(file, "\n");
    fclose(file);
}

#endif