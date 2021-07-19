#ifndef MENSAGEM_H
#define MENSAGEM_H
#include <iostream>
#include <string>

using namespace std;

class Mensagem{
    private:
        string dataHora; //<! Data e hora da mensagem.
        int enviadaPor; //<! Id do usuário que enviou a mensagem.
        string conteudo; //<! Conteúdo da mensagem.

    public:
        /*! Altera a data e a hora da mensagem.
			@param dataHora_ A data e a hora.
			@return void */
		void set_dataHora(string dataHora_);

		/*! Recupera a data e a hora da mensagem.
			@return A data e a hora. */
		string get_dataHora() const;

        /*! Altera o identificador de quem enviou a mensagem.
			@param enviadaPor_ O identificador.
			@return void */
		void set_enviadaPor(int enviadaPor_);

		/*! Recupera o identificador de quem enviou a mensagem.
			@return O identificador. */
		int get_enviadaPor() const;

        /*! Altera o conteúdo da mensagem.
			@param conteudo_ O conteúdo.
			@return void */
		void set_conteudo(string conteudo_);

		/*! Recupera o conteúdo da mensagem.
			@return O conteúdo. */
		string get_conteudo() const;
};

#endif
