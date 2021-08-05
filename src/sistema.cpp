#include "sistema.h"
#include "usuario.h"
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

/* COMANDOS */
string Sistema::quit() {
  return "Saindo...";
}

string Sistema::create_user (const string email, const string senha, const string nome) {
  int id;

  for(auto user = usuarios.begin(); user != usuarios.end(); user++)
  {
    if(user->get_email() == email)
      return "Usuário já existe!";
  }
  
  id = usuarios.size() + 1;
  Usuario usuario(id, nome, email, senha);
  usuarios.push_back(usuario);
  return "Usuário criado";
}

string Sistema::login(const string email, const string senha) {
  //Verificação se existe usuário para se conectar
  if(usuarios.size() > 0)
  {
    //Verificação se o email ou a senha pode se conectar
    for(auto user : usuarios)
    {
      if(user.get_email() == email && user.get_senha() == senha)
      {
          usuariosLogados.insert({user.get_id(),{"",""}});
          return "Logado como " + user.get_email();
      }
    }
    return "Senha ou usuário inválido!";
  }
  else
  {
    return "Não existe nenhum usuário conectável";
  }
}

string Sistema::disconnect(int id) {
  auto desconectar = usuariosLogados.find(id);

  if(desconectar != usuariosLogados.end())
  {
    usuariosLogados.erase(desconectar);
    return "Desconectando usuário " + usuarios[id].get_email();
  }
  return "Não está conectado";
}

string Sistema::create_server(int id, const string nome) {
  // Verificar id
  auto conectado = usuariosLogados.find(id);
  if(conectado == usuariosLogados.end())
  {
    return "Não está conectado";
  }

  for(auto serv : servidores) 
  {
    // Verificar se o nome já existe
    if(serv.get_nome() == nome)
    {
      return "Servidor com esse nome já existe";
    }
  }

  Servidor servidor(id, nome);
  servidores.push_back(servidor);   
  return "Servidor criado";
}

string Sistema::set_server_desc(int id, const string nome, const string descricao) {
  // Verificar id
  auto conectado = usuariosLogados.find(id);
  if(conectado == usuariosLogados.end())
    return "Não está conectado";

  for(auto serv : servidores) 
  {
    // Verificar se existe o servidor
    if(serv.get_nome() == nome)
    {
      // Verificar se id é autorizado a modificar
      if(serv.get_usuarioDonoId() == id)
      {
        serv.set_descricao(descricao);
        return "Descrição do servidor '" + nome + "' modificada!";
      }
      else
        return "Você não pode alterar a descrição de um servidor que não foi criado por você.";
    }
  }
  
  return "Servidor '" + nome + "' não existe";
}

string Sistema::set_server_invite_code(int id, const string nome, const string codigo) {
  // Verificar id
  auto conectado = usuariosLogados.find(id);
  if(conectado == usuariosLogados.end())
    return "Não está conectado";

  for(auto serv = servidores.begin(); serv != servidores.end(); serv++) 
  {
    // Verificar se existe o servidor
    if(serv->get_nome() == nome)
    {
      // Verificar se id é autorizado a modificar
      if(serv->get_usuarioDonoId() == id)
      {
        if(codigo == (""))
        {
          serv->set_codigoConvite("");
          return "Código de convite do servidor '" + nome + "' removido!"; 
        }
        else
        {
          serv->set_codigoConvite(codigo);
          return "Código de convite do servidor '" + nome;
        }
      }
      else
        return "Você não pode alterar o código de convite de um servidor que não foi criado por você.";
    }
  }

  return "Servidor '" + nome + "' não existe";
}

string Sistema::list_servers(int id) {
  for(auto serv = servidores.begin(); serv != servidores.end(); serv++)
  { 
    cout << serv->get_nome();
    // Verificar se é diferente do último servidor do vetor
    if(serv != servidores.end()-1)
      cout << endl;
  }
  return "";
}

string Sistema::remove_server(int id, const string nome) {
  // Verificar id
  auto conectado = usuariosLogados.find(id);
  if(conectado == usuariosLogados.end())
    return "Não está conectado";

  for(auto serv = servidores.begin(); serv != servidores.end(); serv++)
  {
    if(serv->get_nome() == nome)
    {
      if(serv->get_usuarioDonoId() == id)
      {
        for(auto users : usuariosLogados)
        {
          if(users.second.first == serv->get_nome())
          {
            users.second.first = "";
            users.second.second = "";
          }
        }

        servidores.erase(serv);
        return "Servidor '" + nome + "' removido";
      }
      else
        return "Você não é dono do servidor '" + serv->get_nome() + "'";
    }
  }
  
  return "Servidor '" + nome + "' não encontrado";
}

string Sistema::enter_server(int id, const string nome, const string codigo) {
  auto conectar = usuariosLogados.find(id);
  if(conectar == usuariosLogados.end())
    return "Não está conectado";

  if(conectar->second.first == nome)
    return "Você já está nesse servidor!";

  for(auto serv = servidores.begin(); serv != servidores.end(); serv++)
  {
    if(serv->get_nome() == nome)
    {
      if(codigo == "")
      {
        if(serv->get_codigoConvite() != "")
        {
          return "Servidor requer código de convite!";
        }
        else
        {
          serv->inserir_participante(id);
          conectar->second.first = serv->get_nome();
          return "Entrou no servidor com sucesso";
        }
      }
      else
      {
        if(serv->get_codigoConvite() == codigo)
        {
          serv->inserir_participante(id);
          conectar->second.first = serv->get_nome();
          return "Entrou no servidor com sucesso";
        }
        else
        {
          return "Código de convite incorreto";
        }
      }
    }
  }
  return "Servidor não existe!";
}

string Sistema::leave_server(int id, const string nome) {
  auto desconectar = usuariosLogados.find(id);
  if(desconectar == usuariosLogados.end())
    return "Não está conectado";

  if(desconectar->second.first == nome){
    desconectar->second.first = "";
    return "Saindo do servidor '" + nome + "'";
  }
  else
    return "Você não está em qualquer servidor!";
}

string Sistema::list_participants(int id) {
  auto userServer = usuariosLogados.find(id);
  
  if(userServer == usuariosLogados.end())
    return "Não está conectado";

  if(userServer->second.first == "")
    return "Usuário não está conectado em nenhum servidor";

  string nomeServ = userServer->second.first;

  auto servidor = find_if(servidores.begin(), servidores.end(), [nomeServ](Servidor servidor){
                            return servidor.get_nome() == nomeServ; });

  servidor->listar_participantes(usuarios);

  return "";
}

string Sistema::list_channels(int id) { 
  auto usuario = usuariosLogados.find(id);

  if(usuario == usuariosLogados.end())
    return "Não está conectado";

  if(usuario->second.first == "")
    return "Usuário não está conectado em nenhum servidor";

  cout << "#canais de texto";
  for(auto serv = servidores.begin(); serv != servidores.end(); serv++)
  {
    if(serv->get_nome() == usuario->second.first)
      serv->listar_canais();
  }

  return "";
}

string Sistema::create_channel(int id, const string nome) {
  auto usuario = usuariosLogados.find(id);

  if(usuario == usuariosLogados.end())
    return "Não está conectado";

  if(usuario->second.first == "")
    return "Usuário não está conectado em nenhum servidor";

  string nomeServ = usuario->second.first;

  auto servidor = find_if(servidores.begin(), servidores.end(), [nomeServ](Servidor servidor){
                            return servidor.get_nome() == nomeServ; });

  if(servidor != servidores.end())
  {
    if(servidor->criar_canal(nome))
      return "Canal de texto ‘" + nome + "’ criado!";
  }

  return "Canal de texto ‘" + nome + "’ já existe!";
}

string Sistema::enter_channel(int id, const string nome) {
  auto usuario = usuariosLogados.find(id);

  if(usuario == usuariosLogados.end())
    return "Não está conectado";

  if(usuario->second.first == "")
    return "Usuário não está conectado em nenhum servidor";
  
  string nomeServ = usuario->second.first;

  auto servidor = find_if(servidores.begin(), servidores.end(), [nomeServ](Servidor servidor){
                            return servidor.get_nome() == nomeServ; });

  if(servidor != servidores.end())
  {
    if(servidor->verificar_canal(nome))
    {
      usuario->second.second = nome;
      return "Entrou no canal '" + nome + "’!";
    }
    else
      return "Canal ‘" + nome + "’ não existe";
  }

  return "";
}

string Sistema::leave_channel(int id) {
  auto usuario = usuariosLogados.find(id);

  if(usuario == usuariosLogados.end())
    return "Não está conectado";

  if(usuario->second.first == "")
    return "Usuário não está conectado em nenhum servidor";
  
  usuario->second.second = "";
    return "Saindo do canal...";
}

string Sistema::send_message(int id, const string mensagem) {
  auto usuario = usuariosLogados.find(id);

  if(usuario == usuariosLogados.end())
    return "Não está conectado";

  if(usuario->second.first == "")
    return "Usuário não está conectado em nenhum servidor";
  
  string nomeServ = usuario->second.first,
          nomeCanal = usuario->second.second;


  auto servidor = find_if(servidores.begin(), servidores.end(), [nomeServ](Servidor servidor){
                            return servidor.get_nome() == nomeServ; });

  servidor->salvar_mensagem(id, mensagem, nomeCanal);
  return "Mensagem enviada";
}

string Sistema::list_messages(int id) {
  auto usuario = usuariosLogados.find(id);

  if(usuario == usuariosLogados.end())
    return "Não está conectado";

  if(usuario->second.first == "")
    return "Usuário não está conectado em nenhum servidor";
  
  string nomeServ = usuario->second.first,
          nomeCanal = usuario->second.second;

  auto servidor = find_if(servidores.begin(), servidores.end(), [nomeServ](Servidor servidor){
                            return servidor.get_nome() == nomeServ; });

  servidor->listar_mensagens(nomeCanal, usuarios);

  return "";
}