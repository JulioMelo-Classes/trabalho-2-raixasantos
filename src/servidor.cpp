#include "servidor.h"

using namespace std;

int Servidor::get_usuarioDonoId() const
{
    return usuarioDonoId;
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

void Servidor::inserir_participante(int id_)
{
    participantesId.push_back(id_);
}
		
void Servidor::listar_canais()
{
    for(auto canal = canaisTextos.begin(); canal != canaisTextos.end(); canal++)
    {   if(canal->get_nome() != "")
        {
            cout << canal->get_nome();
            // Verificar se é diferente do último servidor do vetor
            if(canal != canaisTextos.end()-1)
                cout << endl;
        }
    }
}