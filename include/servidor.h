#ifndef SERVIDOR_H
#define SERVIDOR_H
#include <iostream>
#include <string>
#include <vector>

#include "canaltexto.h"

using namespace std;

/*
CP1 classe Servidor ok
*/
class Servidor{
	private:
		int usuarioDonoId; //<! Id do usuário que criou o canal.
		string nome; //<! Nome do servidor.
		string descricao; //<! Descriçãdo do canal.
		string codigoConvite; //<! Código do convite do servidor.
		std::vector<CanalTexto> canaisTextos; //<! Vetor com todos os canais de texto do servidor.
		std::vector<int> participantesId; //<! Vetor com os ids dos participantes do servidor.

	public:
		/*! Altera o identificador do usuário que criou o canal.
			@param usuarioDonoId_ O identificador.
			@return void */
		void set_usuarioDonoId(int usuarioDonoId_);

		/*! Recupera o identificador do usuário que criou o canal.
			@return O identificador. */
		int get_usuarioDonoId() const;

		/*! Altera o nome do servidor.
			@param nome_ O nome.
			@return void */
		void set_nome(string nome_);

		/*! Recupera o nome do servidor.
			@return O nome. */
		string get_nome() const;

		/*! Altera a descrição do servidor.
			@param descricao_ A descrição.
			@return void */
		void set_descricao(string descricao_);

		/*! Recupera a descrição.
			@return A descrição. */
		string get_descricao() const;

		/*! Altera o código de convite do servidor.
			@param codigoConvite_ O código.
			@return void */
		void set_codigoConvite(string codigoConvite_);

		/*! Recupera o código de convite do servidor.
			@return O código. */
		string get_codigoConvite() const;
		
};

#endif
