#include "canaltexto.h"

using namespace std;

string CanalTexto::get_nome() const
{
    return nome;
}

void CanalTexto::inserir_mensagem(Mensagem & mensagem)
{
    mensagens.push_back(mensagem);
}