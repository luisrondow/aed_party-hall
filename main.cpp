#include <iostream>
#include <sstream>
#include "classes/Cliente.h"

using namespace std;

void cadastraCliente()
{
    string nome, endereco, telefone, data_nascimento;
    cout << "Digite..." << endl;

    cout << "O nome do cliente: ";
    getline(cin, nome);

    cout << "O endereco do cliente: ";
    getline(cin, endereco);

    cout << "O telefone do cliente: ";
    getline(cin, telefone);

    cout << "A data de nascimento(DD/MM/YYYY) do cliente: ";
    getline(cin, data_nascimento);

    Cliente *cliente = new Cliente(nome, endereco, telefone, data_nascimento);
    cliente->Store();
}

int main()
{

    int opcao_principal, opcao_pesquisa;

    while (opcao_principal != 0)
    {
        char again;
        cout << "BEM VINDO AO SALAO DE FESTA PatatiPatata" << endl;
        cout << "1 - Cadastrar um cliente" << endl;
        cout << "2 - Cadastrar um Funcionários" << endl;
        cout << "3 - Cadastrar um Fornecedor" << endl;
        cout << "4 - Cadastrar uma Festa" << endl;
        cout << "0 - SAIR" << endl;
        cout << "Selecione o que deseja fazer: ";
        cin >> opcao_principal;
        cin.ignore(1,'\n');

        switch (opcao_principal)
        {
        case 1:
            cadastraCliente();
            break;
        case 2:
            cout << "Cadastrando funcionários..." << endl;
            break;
        case 3:
            cout << "Cadastrando fornecedor..." << endl;
            break;
        case 4:
            cout << "Cadastrando festa..." << endl;
            break;
        case 0:
            break;
        default:
            cout << "Opcao inválida..." << endl;
            break;
        }

        cout << "Deseja sair? (s/n)" << endl;
        cin >> again;

        if (again == 's')
        {
            opcao_principal = 0;
        }
    }

    return 0;
}