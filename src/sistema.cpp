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
      // Verificar se o email já existe.
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
  return "login NÃO IMPLEMENTADO";
}

string Sistema::disconnect(int id) {
  return "disconnect NÃO IMPLEMENTADO";
}

string Sistema::create_server(int id, const string nome) {
  return "create_server NÃO IMPLEMENTADO";
}

string Sistema::set_server_desc(int id, const string nome, const string descricao) {
  return "set_server_desc NÃO IMPLEMENTADO";
}

string Sistema::set_server_invite_code(int id, const string nome, const string codigo) {
  return "set_server_invite_code NÃO IMPLEMENTADO";
}

string Sistema::list_servers(int id) {
  return "list_servers NÃO IMPLEMENTADO";
}

string Sistema::remove_server(int id, const string nome) {
  return "remove_server NÃO IMPLEMENTADO";
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
