#include <iostream>
#include <fstream>
#ifndef PESQUISA_H_
#define PESQUISA_H_

class Pesquisa
{
    const int LINHAS_CLIENTE = 5;
    const int LINHAS_FUNCIONARIO = 6;
public:
    void Clientes(std::string nome);
    void Funcionarios(std::string nome);
};

void Pesquisa::Clientes(std::string nome)
{
    int linha_cliente = -1;
    int cont = 0;
    std::ifstream file_cliente;
    std::string line;

    file_cliente.open("DAO/Cliente.txt");

    if (file_cliente.is_open())
    {
        while (getline(file_cliente, line) && linha_cliente == -1)
        {
            if (nome.compare(line) == 0)
            {
                linha_cliente = cont--;
            }
            cont++;
        }
    }
    else
    {
        std::cout << "Nao ha nenhum cliente cadastrados" << std::endl;
    }

    file_cliente.close();

    if (linha_cliente != -1)
    {
        int file_cont = 0, cliente_line_counter = 0;
        bool canPrint = false;

        file_cliente.open("DAO/Cliente.txt");

        if (file_cliente.is_open())
        {
            while (getline(file_cliente, line))
            {
                file_cont++;
                if ((file_cont == linha_cliente || canPrint == true ) && cliente_line_counter <= LINHAS_CLIENTE)
                {
                    canPrint = true;
                    cliente_line_counter++;
                    std::cout << line << std::endl;
                }
            }
            file_cliente.close();
        }
        else
        {
            std::cout << "Nao ha nenhum cliente cadastrados" << std::endl;
        }
    }
    else
    {
        std::cout << "Nao ha nenhum cliente com este nome" << std::endl;
    }
}

void Pesquisa::Funcionarios(std::string nome)
{
    int linha_funcionario = -1;
    int cont = 0;
    std::ifstream file_funcionario;
    std::string line;

    file_funcionario.open("DAO/Funcionario.txt");

    if (file_funcionario.is_open())
    {
        while (getline(file_funcionario, line) && linha_funcionario == -1)
        {
            if (nome.compare(line) == 0)
            {
                linha_funcionario = cont--;
            }
            cont++;
        }
    }
    else
    {
        std::cout << "Nao ha nenhum funcionario cadastrado" << std::endl;
    }

    file_funcionario.close();

    if (linha_funcionario != -1)
    {
        int file_cont = 0, funcionario_line_counter = 0;
        bool canPrint = false;

        file_funcionario.open("DAO/Funcionario.txt");

        if (file_funcionario.is_open())
        {
            while (getline(file_funcionario, line))
            {
                file_cont++;
                if ((file_cont == linha_funcionario || canPrint == true ) && funcionario_line_counter <= LINHAS_FUNCIONARIO)
                {
                    canPrint = true;
                    funcionario_line_counter++;
                    std::cout << line << std::endl;
                }
            }
            file_funcionario.close();
        }
        else
        {
            std::cout << "Nao ha nenhum funcionario cadastrado" << std::endl;
        }
    }
    else
    {
        std::cout << "Nao ha nenhum funcionario com este nome" << std::endl;
    }
}

#endif