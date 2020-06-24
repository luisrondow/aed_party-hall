#ifndef FESTA_H_INCLUDED
#define FESTA_H_INCLUDED

class Festa
{
private:
    int codigo;
    int quantidade_convidados;
    char data[250];
    float dia_semana[250];
    int horario_inicio;
    int horario_fim;
    char tema[250];
    int codigo_cliente;
public:
    Festa();
};

Festa::Festa()
{
}

#endif