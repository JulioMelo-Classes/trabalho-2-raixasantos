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
  Usuario usuario;

  if(usuarios.size() > 0)
  {
    bool existe = false;
    for(auto i : usuarios) 
    {
      // Verificar se o email já existe
      if(i.get_email().compare(email) == 0)
      {
        existe = true;
      }
    }
    
    if(existe)
      return "Usuário já existe!";

    usuario.set_id(usuarios.size()+1);
  }
  if (usuarios.size() == 0)
  {
    usuario.set_id(1);
  }

  usuario.set_email(email);
  usuario.set_senha(senha);
  usuario.set_nome(nome);

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
      if(user.get_email().compare(email) == 0 && 
        user.get_senha().compare(senha) == 0)
      {
          usuariosLogados.insert({user.get_id(),{"",""}});
          cout << "Logado como " << user.get_email(); 
          return "";
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
  std::map<int, std::pair<std::string, std::string>>::iterator desconectar;
  
  for(auto user : usuariosLogados)
  {
    // Verificar se é o usuário que deseja desconectar
    if(user.first == id)
    {
      desconectar = usuariosLogados.find(id);
      usuariosLogados.erase(desconectar);
      cout << "Desconectando usuário " << usuarios[id-1].get_email(); 
      return "";
    }
  }

  return "Não está conectado";
}

string Sistema::create_server(int id, const string nome) {
  Servidor servidor;

  // Verificar id
  bool existe = false;
  for(auto usuario : usuarios)
  {
    if(id == usuario.get_id())
      existe = true;
  }
  if (!existe)
  {
    return "Usuário não existe";
  }

  for(auto serv : servidores) 
  {
    // Verificar se o nome já existe
    if(serv.get_nome().compare(nome) == 0)
    {
      return "Servidor com esse nome já existe";
    }
  }

  servidor.set_nome(nome);
  servidor.set_usuarioDonoId(id);

  servidores.push_back(servidor);   

  return "Servidor criado";
}

string Sistema::set_server_desc(int id, const string nome, const string descricao) {
  for(auto serv : servidores) 
  {
    // Verificar se existe o servidor
    if(serv.get_nome().compare(nome) == 0)
    {
      // Verificar se id é autorizado a modificar
      if(serv.get_usuarioDonoId() == id)
      {
        serv.set_descricao(descricao);
        cout << "Descrição do servidor '" << nome << "' modificada!";
        return "";
      }
      else
      {
        return "Você não pode alterar a descrição de um servidor que não foi criado por você.";
      }
    }
  }
  
  cout << "Servidor '" << nome << "' não existe";
  return "";
}

string Sistema::set_server_invite_code(int id, const string nome, const string codigo) {
  for(auto serv : servidores) 
  {
    // Verificar se existe o servidor
    if(serv.get_nome().compare(nome) == 0)
    {
      // Verificar se id é autorizado a modificar
      if(serv.get_usuarioDonoId() == id)
      {
        if(codigo.compare("") == 0)
        {
          serv.set_codigoConvite("");
          cout << "Código de convite do servidor '" << nome << "' removido!"; 
        }
        else
        {
          serv.set_codigoConvite(codigo);
          cout << "Código de convite do servidor '" << nome << "' modificado!";
        }
        return "";
      }
      else
      {
        return "Você não pode alterar o código de convite de um servidor que não foi criado por você.";
      }
    }
  }

  cout << "Servidor '" << nome << "' não existe";
  return "";
}

string Sistema::list_servers(int id) {
  for(auto serv = servidores.begin(); serv != servidores.end(); serv++)
  { 
    cout << (*serv).get_nome();
    // Verificar se é diferente do último servidor do vetor
    if(serv != servidores.end()-1)
      cout << endl;
  }
  return "";
}

string Sistema::remove_server(int id, const string nome) {
  for(auto serv = servidores.begin(); serv != servidores.end(); serv++)
  {
    if(((*serv).get_nome()).compare(nome) == 0)
    {
      if(((*serv).get_usuarioDonoId()) == id)
      {
        for(auto users : usuariosLogados)
        {
          if(users.second.first.compare(((*serv).get_nome())) == 0)
          {
            users.second.first = "";
            users.second.second = "";
          }
        }

        servidores.erase(serv);
        cout << "Servidor '" << nome << "' removido";
        return "";
      }
      else
      {
        cout << "Você não é dono do servidor '" << (*serv).get_nome() << "'";
        return "";
      }
    }
  }
  
  cout << "Servidor '" << nome << "' não encontrado";
  return "";
}

string Sistema::enter_server(int id, const string nome, const string codigo) {
  return "enter_server NÃO IMPLEMENTADO";
}

string Sistema::leave_server(int id, const string nome) {
  return "leave_server NÃO IMPLEMENTADO";
}

string Sistema::list_participants(int id) {
  return "list_participants NÃO IMPLEMENTADO";
}

string Sistema::list_channels(int id) {
  return "list_channels NÃO IMPLEMENTADO";
}

string Sistema::create_channel(int id, const string nome) {
  return "create_channel NÃO IMPLEMENTADO";
}

string Sistema::enter_channel(int id, const string nome) {
  return "enter_channel NÃO IMPLEMENTADO";
}

string Sistema::leave_channel(int id) {
  return "leave_channel NÃO IMPLEMENTADO";
}

string Sistema::send_message(int id, const string mensagem) {
  return "send_message NÃO IMPLEMENTADO";
}

string Sistema::list_messages(int id) {
  return "list_messages NÃO IMPLEMENTADO";
}




/* IMPLEMENTAR MÉTODOS PARA OS COMANDOS RESTANTES */
