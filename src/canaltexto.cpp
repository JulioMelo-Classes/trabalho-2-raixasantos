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

void CanalTexto::imprimir_mensagens(vector<Usuario> & usuarios)
{
    for(auto mensagem = mensagens.begin(); mensagem != mensagens.end(); mensagem++)
    {   
        int id = mensagem->get_enviadaPor();
        auto usuario = find_if(usuarios.begin(), usuarios.end(), [id](Usuario user){
                            return user.get_id() == id; });
                            
        cout << usuario->get_nome() << " " << mensagem->get_dataHora()
            << " " << mensagem->get_conteudo();
        if(mensagem != mensagens.end()-1)
            cout << endl;
    }
}