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
		/*! Construtor */
		Mensagem(string dataHora, int enviadaPor, string conteudo)
		{
			this->dataHora = dataHora;
			this->enviadaPor = enviadaPor;
			this->conteudo = conteudo;
		}
		
		/*! Recupera a data e a hora da mensagem.
			@return A data e a hora. */
		string get_dataHora() const;

		/*! Recupera o identificador de quem enviou a mensagem.
			@return O identificador. */
		int get_enviadaPor() const;

		/*! Recupera o conteúdo da mensagem.
			@return O conteúdo. */
		string get_conteudo() const;
};

#endif
