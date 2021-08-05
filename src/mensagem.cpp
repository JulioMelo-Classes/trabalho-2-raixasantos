#include "mensagem.h"

using namespace std;

string Mensagem::get_dataHora() const
{
    return dataHora;
}

int Mensagem::get_enviadaPor() const
{
    return enviadaPor;
}

string Mensagem::get_conteudo() const
{
    return conteudo;
}