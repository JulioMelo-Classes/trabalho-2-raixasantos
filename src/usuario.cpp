#include "usuario.h"

// Recupera o identificador do usuário.
int Usuario::get_id() const
{
    return id;
}

// Recupera o nome do usuário.
string Usuario::get_nome() const
{
    return nome;
}

// Recupera o email do usuário.
string Usuario::get_email() const
{
    return email;
}

// Recupera a senha do usuário.
string Usuario::get_senha() const
{
    return senha;
}