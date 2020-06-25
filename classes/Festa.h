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
    Festa();
};

Festa::Festa()
{
}

#endif