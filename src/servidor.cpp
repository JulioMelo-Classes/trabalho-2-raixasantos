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

void Servidor::inserir_participante(int id)
{
    participantesId.push_back(id);
}

bool Servidor::verificar_canal(string nome_)
{
    auto canalTeste = find_if(canaisTextos.begin(), canaisTextos.end(), [nome_](CanalTexto canal){
                            return canal.get_nome() == nome_; });
    
    if(canalTeste != canaisTextos.end())
        return true;

    return false;
}
		
bool Servidor::criar_canal(string nome_)
{   
    if(verificar_canal(nome_))
        return false;

    CanalTexto canal(nome_);
    canaisTextos.push_back(canal);
    return true;
}

void Servidor::listar_canais()
{
    for(auto canal = canaisTextos.begin(); canal != canaisTextos.end(); canal++)
    {   if(canal->get_nome() != "")
        {
            cout << "\n"<< canal->get_nome();
        }
    }
}

void Servidor::salvar_mensagem(int id, string conteudo, string canal)
{
    string dataHora;
    Mensagem mensagem(dataHora, id, conteudo);

    if(verificar_canal(canal))
    {
        auto canalTeste = find_if(canaisTextos.begin(), canaisTextos.end(), [canal](CanalTexto canalSeg){
                                return canalSeg.get_nome() == canal; });
        canalTeste->inserir_mensagem(mensagem);
    }
}