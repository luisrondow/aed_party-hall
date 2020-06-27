#include <iostream>
#include <sstream>
#include "classes/Cliente.h"
#include "classes/Fornecedor.h"
#include "classes/Funcionario.h"
#include "classes/Festa.h"
#include "classes/Pesquisa.h"

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

void cadastraFuncionario()
{
    string nome, telefone, funcao, salario;
    int tipo;

    cout << "Digite..." << endl;

    cout << "O nome do funcionario: ";
    getline(cin, nome);

    cout << "O telefone do funcionario: ";
    getline(cin, telefone);

    cout << "A funcao do funcionario: ";
    getline(cin, funcao);

    cout << "O salario do funcionario: ";
    getline(cin, salario);

    cout << "O tipo do funcionario (0 = Fixo, 1 = Temporario): ";
    cin >> tipo;

    Funcionario *funcionario = new Funcionario(nome, telefone, funcao, salario, tipo);
    funcionario->Store();
}

void pesquisar(int opcao)
{
    Pesquisa *pesquisa = new Pesquisa();
    string nome;
    switch (opcao)
    {
    case 1:
        cout << "Digite o nome do cliente: ";
        getline(cin, nome);
        cout << "Pesquisando cliente com o nome " << nome << "..." << endl;
        pesquisa->Clientes(nome);
        break;
    case 2:
        cout << "Digite o nome do funcionario: ";
        getline(cin, nome);
        cout << "Pesquisando funcionario com o nome " << nome << "..." << endl;
        pesquisa->Funcionarios(nome);
        cout << "Pesquisando funcionarios..." << endl;
        break;
    case 3:
        cout << "Pesquisando fornecedores..." << endl;
        break;
    default:
        cout << "Opcao inválida..." << endl;
        break;
    }
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
        cout << "5 - Pesquisar" << endl;
        cout << "0 - SAIR" << endl;
        cout << "Selecione o que deseja fazer: ";
        cin >> opcao_principal;
        cin.ignore(1, '\n');

        switch (opcao_principal)
        {
        case 1:
            cadastraCliente();
            break;
        case 2:
            cadastraFuncionario();
            break;
        case 3:
            cout << "Cadastrando fornecedor..." << endl;
            break;
        case 4:
            cout << "Cadastrando festa..." << endl;
            break;
        case 5:
            cout << "Selecione para pesquisar pelo nome:" << endl;
            cout << "1 - Cliente" << endl;
            cout << "2 - Funcionario" << endl;
            cout << "3 - Fornecedor" << endl;
            cout << "Selecione o que deseja fazer: ";
            cin >> opcao_pesquisa;
            cin.ignore(1, '\n');
            pesquisar(opcao_pesquisa);
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