#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>
#include <string>

using namespace std;

class Usuario{
	public:
		/*! Altera o identificador do usuário.
			@param id_ O identificador.
			@return void */
		void set_id(int id_);

		/*! Recupera o identificador do usuário.
			@return O identificador. */
		int get_id() const;

		/*! Altera o nome do usuário.
			@param nome_ O nome.
			@return void */
		void set_nome(string nome_);

		/*! Recupera o nome do usuário.
			@return O nome. */
		string get_nome() const;

		/*! Altera o email do usuário.
			@param email_ O email.
			@return void */
		void set_email(string email_);

		/*! Recupera o email do usuário.
			@return O email. */
		string get_email() const;

		/*! Altera a senha do usuário.
			@param senha_
			@return void */
		void set_senha(string senha_);

		/*! Recupera a senha do usuário.
			@return A senha. */
		string get_senha() const;

	private:
		int id; //<! Identificador do usuário.
		string nome; //<! Nome do usuário.
		string email; //<! Email do usuário.
		string senha; //<! Senha do usuário.
};

#endif
