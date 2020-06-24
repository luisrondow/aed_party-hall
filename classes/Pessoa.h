#ifndef PESSOA_H_
#define PESSOA_H_

using namespace std;

class Pessoa
{
protected:
    int codigo;
    char nome[250];
    char telefone[250];
public:
    Pessoa();
};

Pessoa::Pessoa() {
}

#endif