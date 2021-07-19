#include "mensagem.h"

using namespace std;

void Mensagem::set_dataHora(string dataHora_)
{
    dataHora = dataHora_;
}

string Mensagem::get_dataHora() const
{
    return dataHora;
}

void Mensagem::set_enviadaPor(int enviadaPor_)
{
    enviadaPor = enviadaPor_;
}

int Mensagem::get_enviadaPor() const
{
    return enviadaPor;
}

void Mensagem::set_conteudo(string conteudo_)
{
    conteudo = conteudo_;
}

string Mensagem::get_conteudo() const
{
    return conteudo;
}