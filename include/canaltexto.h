#ifndef CANALTEXTO_H
#define CANALTEXTO_H
#include <iostream>
#include <string>
#include <vector>

#include "mensagem.h"

using namespace std;

class CanalTexto{
	private:
		string nome; //<! Nome do canal.
		std::vector<Mensagem> mensagens; //<! Vetor com mensagens do canal.
	public:
		/*! Altera o nome do canal.
			@param nome_ O nome.
			@return void */
		CanalTexto(string nome)
		{
			this->nome = nome;
		}

		/*! Recupera o nome do canal.
			@return O nome. */
		string get_nome() const;

		/* Insere a mensagem do canal. */
		void inserir_mensagem(Mensagem & mensagem);
};

#endif
