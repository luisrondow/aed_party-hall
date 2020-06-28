#include <iostream>
#include <fstream>
#ifndef RELATORIO_H_
#define RELATORIO_H_

class Relatorio
{
    const int LINHAS_FESTA = 8;
    const int LINHAS_FUNCIONARIO = 6;

public:
    void FestaPorData(std::string nome);
    void FestaPorCliente(int codigo_cliente);
};

void Relatorio::FestaPorData(std::string nome)
{
}

void Relatorio::FestaPorCliente(int codigo_cliente)
{
    int linhas_festa[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    int cont = 0;
    int quant_festa = 0;
    int certain_line = 8;
    int i;
    std::ifstream file_festa;
    std::string line;

    file_festa.open("DAO/Festa.txt");

    if (file_festa.is_open())
    {
        while (getline(file_festa, line) && quant_festa < 10)
        {
            cont++;
            if (cont == certain_line)
            {
                if (std::to_string(codigo_cliente).compare(line) == 0)
                {
                    linhas_festa[quant_festa] = cont - 7;
                    quant_festa++;
                }
                certain_line = cont + 9;
            }
        }
    }
    else
    {
        std::cout << "Nao ha nenhum festa cadastrados" << std::endl;
    }

    file_festa.close();

    for (i = 0; i < 10; i++)
    {
        file_festa.open("DAO/Festa.txt");
        int linha_festa = linhas_festa[i];
        // std::cout << linha_festa << std::endl;
        if (linha_festa > 0)
        {
            int file_cont = 0, festa_line_counter = 0;
            bool canPrint = false;

            if (file_festa.is_open())
            {
                while (getline(file_festa, line))
                {
                    file_cont++;
                    if ((file_cont == linha_festa || canPrint == true) && festa_line_counter <= LINHAS_FESTA)
                    {
                        canPrint = true;
                        festa_line_counter++;
                        std::cout << line << std::endl;
                    }
                }
            }
            else
            {
                std::cout << "Nao ha nenhum festa cadastrados" << std::endl;
            }
        }
        file_festa.close();
    }
}

#endif