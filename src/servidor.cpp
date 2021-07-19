#include "servidor.h"

using namespace std;

void Servidor::set_usuarioDonoId(int usuarioDonoId_)
{
    usuarioDonoId = usuarioDonoId_;
}

int Servidor::get_usuarioDonoId() const
{
    return usuarioDonoId;
}

void Servidor::set_nome(string nome_)
{
    nome = nome_;
}

string Servidor::get_nome() const
{
    return nome;
}

void Servidor::set_descricao(string descricao_)
{
    descricao = descricao_;
}

string Servidor::get_descricao() const
{
    return descricao;
}

void Servidor::set_codigoConvite(string codigoConvite_)
{
    codigoConvite = codigoConvite_;
}

string Servidor::get_codigoConvite() const
{
    return codigoConvite;
}