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
/*
Cp2 ok
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
		/*! Construtor */
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

		/*! Insere o id do novo participante do servidor. 
			@param id_ O id do participante.
			@return void */
		void inserir_participante(int id);	

		/*! Lista os participantes do servidor. 
			@param usuarios Um vetor de usuários.
			@return void */
		void listar_participantes(vector<Usuario> & usuarios);

		/*! Verifica a existencia de um canal. 
			@param nome_ O nome do canal.
			@return True, caso exista um canal. False, caso contrário. */
		bool verificar_canal(string nome_);
		
		/*! Cria um canal de texto. 
			@param nome_ O nome do canal.
			@return True, se a criação foi bem sucedida. False, caso contrário. */
		bool criar_canal(string nome_);

		/*! Lista os canais do servidor. 
			@return void */
		void listar_canais();

		/*! Armazena a mensagem enviada. 
			@param id O id do participante que enviou a mensagem.
			@param mensagem O conteúdo da mensagem.
			@param canal O canal de origem da mensagem.
			@return void */
		void salvar_mensagem(int id, string mensagem, string canal);

		/*! Lista as mensagens do canal do servidor. 
			@param canal O canal de origem das mensagens.
			@param usuarios Um vetor de usuários.
			@return void */
		void listar_mensagens(string canal, vector<Usuario> & usuarios);
};

#endif
