#ifndef SERVIDOR_H
#define SERVIDOR_H
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdlib>

#include "usuario.h"
#include "canaltexto.h"

using namespace std;

class Servidor{
	private:
		int usuarioDonoId; //<! Id do usuário que criou o canal.
		string nome; //<! Nome do servidor.
		string descricao; //<! Descriçãdo do canal.
		string codigoConvite; //<! Código do convite do servidor.
		std::vector<CanalTexto> canaisTextos; //<! Vetor com todos os canais de texto do servidor.
		std::vector<int> participantesId; //<! Vetor com os ids dos participantes do servidor.

	public:
		/* Construtor */
		Servidor(int usuarioDonoId, string nome)
		{
			this->usuarioDonoId = usuarioDonoId;
			this->nome = nome;
		}

		/*! Recupera o identificador do usuário que criou o canal.
			@return O identificador. */
		int get_usuarioDonoId() const;

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

		/* Insere o id do novo participante do servidor. 
			@param id_
			@return void */
		void inserir_participante(int id);	

		/* Listar participantes. */	
		void listar_participantes(vector<Usuario> & usuarios);

		/* Verifica a existencia de um canal. */
		bool verificar_canal(string nome_);
		
		/* Cria um canal de texto. 
			@param nome_
			@return void */
		bool criar_canal(string nome_);

		/* Lista os canais do servidor. */
		void listar_canais();

		/* Armazena a mensagem enviada. */
		void salvar_mensagem(int id, string mensagem, string canal);

		/* Lista as mensagens do canal do servidor. */
		void listar_mensagens(string canal, vector<Usuario> & usuarios);
};

#endif
