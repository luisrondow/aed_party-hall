#include <iostream>
#include <sstream>
#include "classes/Cliente.h"
#include "classes/Fornecedor.h"
#include "classes/Funcionario.h"
#include "classes/Festa.h"
#include "classes/Pesquisa.h"
#include "classes/Relatorio.h"

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
void cadastraFornecedor()
{
    string nome, telefone, produto_fornecido;
    cout << "Digite..." << endl;

    cout << "O nome do fornecedor: ";
    getline(cin, nome);

    cout << "O telefone do fornecedor: ";
    getline(cin, telefone);

    cout << "O produto do fornecido: ";
    getline(cin, produto_fornecido);

    // Fornecedor *fornecedor = new Fornecedor(nome, telefone, produto_fornecido);
    // fornecedor->Store();
}

void cadastraFesta()
{
    Pesquisa *pesquisa = new Pesquisa();
    int codigo_cliente, quantidade_convidados, dia_semana, horario_inicio, horario_fim;
    string nome_cliente, data, tema;

    cout << "Digite..." << endl;

    cout << "O nome do cliente: ";
    getline(cin, nome_cliente);

    codigo_cliente = pesquisa->CodigoCliente(nome_cliente);

    do
    {
        cout << "A data da festa (DD/MM/YYYY): ";
        getline(cin, data);
    } while (pesquisa->ExisteDataFesta(data) == true);

    cout << "A quantidade de convidados: ";
    cin >> quantidade_convidados;

    cout << "O dia da semana (Domingo = 1 ... Sabado = 7): ";
    cin >> dia_semana;

    if (dia_semana != 7)
    {
        cout << "O horario de inicio: ";
        cin >> horario_inicio;

        do
        {
            cout << "O horario que acabara (Duracao maxima = 4 horas): ";
            cin >> horario_fim;
        } while (horario_fim > horario_inicio + 4);
        cin.ignore(1, '\n');
    }
    else
    {
        int opcao_sabado;
        cout << "Qual o Horario:" << endl;
        cout << "1 - 12 as 16 horas" << endl;
        cout << "2 - 18 as 22 horas" << endl;
        cout << "Selecione o que deseja fazer: ";
        cin >> opcao_sabado;
        cin.ignore(1, '\n');
        do
        {
            switch (opcao_sabado)
            {
            case 1:
                horario_inicio = 12;
                horario_fim = 16;
                break;
            case 2:
                horario_inicio = 18;
                horario_fim = 22;
                break;
            default:
                cout << "Opcao inválida..." << endl;
                break;
            }
        } while (opcao_sabado != 1 && opcao_sabado != 2);
    }

    cout << "O tema da festa: ";
    getline(cin, tema);

    Festa *festa = new Festa(quantidade_convidados, data, dia_semana, horario_inicio, horario_fim, tema, codigo_cliente);
    festa->Store();
}

void gerarRelatorioPorNomeCliente(string aux, Relatorio *relatorio) {
    Pesquisa *pesquisa = new Pesquisa();
    cout << "Digite o nome do cliente: ";
    getline(cin, aux);
    int codigoCliente = pesquisa->CodigoCliente(aux);
    relatorio->FestaPorCliente(codigoCliente);
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
        break;
    case 3:
        cout << "Digite o nome do fornecedor: ";
        getline(cin, nome);
        cout << "Pesquisando fornecedor com o nome " << nome << "..." << endl;
        pesquisa->Fornecedor(nome);
        break;
    default:
        cout << "Opcao inválida..." << endl;
        break;
    }
}

void relatorio(int opcao)
{
    Relatorio *relatorio = new Relatorio();
    string aux;
    switch (opcao)
    {
    case 1:
        gerarRelatorioPorNomeCliente(aux, relatorio);
        break;
    case 2:
        cout << "Gerando relatorio de festa por data..." << endl;
        break;
    default:
        cout << "Opcao inválida..." << endl;
        break;
    }
}

int main()
{

    int opcao_principal, opcao_pesquisa, opcao_relatorio;

    while (opcao_principal != 0)
    {
        char again;
        cout << "BEM VINDO AO SALAO DE FESTA PatatiPatata" << endl;
        cout << "1 - Cadastrar um cliente" << endl;
        cout << "2 - Cadastrar um Funcionários" << endl;
        cout << "3 - Cadastrar um Fornecedor" << endl;
        cout << "4 - Cadastrar uma Festa" << endl;
        cout << "5 - Pesquisar" << endl;
        cout << "6 - Relatorios" << endl;
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
            cadastraFornecedor();
            break;
        case 4:
            cadastraFesta();
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
        case 6:
            cout << "Selecione para gerar o relatorio:" << endl;
            cout << "1 - Festa por cliente" << endl;
            cout << "2 - Festa por data" << endl;
            cout << "Selecione o que deseja fazer: ";
            cin >> opcao_relatorio;
            cin.ignore(1, '\n');
            relatorio(opcao_relatorio);
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