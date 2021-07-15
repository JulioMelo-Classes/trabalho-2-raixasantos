#include "usuario.h"

// Altera o identificador do usuário.
void Usuario::set_id(int id_)
{
    id = id_;
}

// Recupera o identificador do usuário.
int Usuario::get_id() const
{
    return id;
}

// Altera o nome do usuário.
void Usuario::set_nome(string nome_)
{
    nome = nome_;
}

// Recupera o nome do usuário.
string Usuario::get_nome() const
{
    return nome;
}

// Altera o email do usuário.
void Usuario::set_email(string email_)
{
    email = email_;
}

// Recupera o email do usuário.
string Usuario::get_email() const
{
    return email;
}

// Altera a senha do usuário.
void Usuario::set_senha(string senha_)
{
    senha = senha_;
}

// Recupera a senha do usuário.
string Usuario::get_senha() const
{
    return senha;
}