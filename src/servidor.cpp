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

void Servidor::listar_participantes(vector<Usuario> & usuarios)
{
    for(auto itr = participantesId.begin(); itr != participantesId.end(); itr++)
    {   
        int participante = *itr;
        cout << participante << " ";
        auto usuario = find_if(usuarios.begin(), usuarios.end(), [participante](Usuario user){
                            return user.get_id() == participante; });

        if(usuario != usuarios.end())
        {
            cout << usuario->get_nome();
            if(usuario == usuarios.end()-1)
                cout << endl;
        }
    }
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
    time_t dataHora;
    struct tm * timeinfo;
    char buffer[80];

    time (&dataHora);
    timeinfo = localtime(&dataHora);
    strftime(buffer, 80, "<%d/%m/%Y - %H:%M>", timeinfo);

    string dataFormatada(buffer);

    Mensagem mensagem(dataFormatada, id, conteudo);

    if(verificar_canal(canal))
    {
        auto canalTeste = find_if(canaisTextos.begin(), canaisTextos.end(), [canal](CanalTexto canalSeg){
                                return canalSeg.get_nome() == canal; });
        canalTeste->inserir_mensagem(mensagem);
    }
}

void Servidor::listar_mensagens(string canal, vector<Usuario> & usuarios)
{
    if(verificar_canal(canal))
    {
        auto canalTeste = find_if(canaisTextos.begin(), canaisTextos.end(), [canal](CanalTexto canalSeg){
                                return canalSeg.get_nome() == canal; });
        canalTeste->imprimir_mensagens(usuarios);
    }
}