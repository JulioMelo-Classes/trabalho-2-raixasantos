#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>
#include <string>

using namespace std;

class Usuario{
	private:
		int id; //<! Identificador do usuário.
		string nome; //<! Nome do usuário.
		string email; //<! Email do usuário.
		string senha; //<! Senha do usuário.

	public:
		/*! Construtor */
		Usuario(int id, string nome, string email, string senha)
		{
			this->id = id;
			this->nome = nome;
			this->email = email;
			this->senha = senha;
		}

		/*! Recupera o identificador do usuário.
			@return O identificador. */
		int get_id() const;

		/*! Recupera o nome do usuário.
			@return O nome. */
		string get_nome() const;

		/*! Recupera o email do usuário.
			@return O email. */
		string get_email() const;

		/*! Recupera a senha do usuário.
			@return A senha. */
		string get_senha() const;
};

#endif
