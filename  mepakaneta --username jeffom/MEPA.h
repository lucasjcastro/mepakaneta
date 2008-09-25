#ifndef MEPA_H_
#define MEPA_H_

#include <string>
#include <iostream>
#include <vector>
#include <fstream>

#define EMPTY -1

using namespace std;

/* Declaração dos tipos de comando */
enum { crct, soma, subt, mult, divi, invr, conj, disj, nega, cmme, cmma, cmig,
        cmdg, cmeg, cmag, dsvs, dsvf, nada, leit, impr, impl, impc, inpp, amem,
        para, crvl, armz, chpr, enpr, dmem, rtpr, crvi, armi, cren};

class pilha_P
{
	public:
		int comando;
		string label;
		vector<int> args;
};

class label
{
	public:
		int endereco;
		string label;
};

class MEPA
{
private:
	/* Pilha de intrução */
	vector<pilha_P>
	P;
	/* Pilha de dados */
	vector<int>
	M;
	/* Pilha de registradores */
	vector<int>
	D;
	/* Marcador da pilha de instrução */
	int
	i;
	/* Marcador da pilha de dados*/
	int
	s;

	/**
	 *  Carrega constante no topo da pilha
	 * @param valor a ser inserido no topo
	 */
	void CRCT( int );

	/**
	 *  carrega valor de M[D[m]+n] para o topo da pilha
	 * @param  m é o nível léxico, e n o número da variável em VAR
	 */
	void CRVL( int , int );

	/**
	 *
	 */
	void CRVL( int);
	/**
	 *  Soma o valor do topo com o valor armazenado
	 *  uma posição abaixo e então guarda o valor
	 *  no novo topo
	 */
	void SOMA();

	/**
	 *  Subtrai o valor do topo com o valor armazenado
	 *  uma posição abaixo e então guarda o valor
	 *  no novo topo
	 */
	void SUBT();

	/**
	 *  Multiplica o valor do topo com o valor armazenado
	 *  uma posição abaixo e então guarda o valor
	 *  no novo topo
	 */
	void MULT();

	/**
	 *  Divide o valor do topo com o valor armazenado
	 *  uma posição abaixo e então guarda o valor
	 *  no novo topo
	 */
	void DIVI();

	/**
	 *  Compara o valor do topo com o valor uma posição
	 *  abaixo e verifica se é igual
	 */
	void CMIG();

	/**
	 *  Compara o valor do topo com o valor uma posição
	 *  abaixo e verifica se é maior
	 */
	void CMMA();

	/**
	 *  Compara o valor do topo com o valor uma posição
	 *  abaixo e verifica se é menor
	 */
	void CMME();

	/**
	 *  Compara o valor do topo com o valor uma posição
	 *  abaixo e verifica se é maior ou igual
	 */
	void CMAG();

	/**
	 *  Compara o valor do topo com o valor uma posição
	 *  abaixo e verifica se é menor ou igual
	 */
	void CMEG();

	/**
	 *  Compara o valor do topo com o valor uma posição
	 *  abaixo e verifica se é diferente
	 */
	void CMDG();

	/**
	 *  Faz a operação lógica "AND" entre o topo da pilha
	 *  e o valor uma posição abaixo
	 */
	void CONJ();

	/**
	 *  Faz a operação lógica "OR" entre o topo da pilha
	 *  e o valor uma posição abaixo
     */
	void DISJ();

	/**
	 *  Faz a operação lógica "NOT" com o valor do topo
	 */
	void NEGA();

	/**
	 *  Complementa o sinal do valor do topo da pilha
	 */
	void INVR();

	/**
	 *  Lê um valor no dispositivo de entrada (teclado)
	*  e armazena-o no topo da pilha
	 */
	void LEIT();

	/**
	 *  imprime no dispositivo de saída (monitor)
	 *  o conteúdo do topo da pilha
	 */
	void IMPR();

	/**
	 *  equivalente a NOP,
	 *  será utilizada na geração de endereços de destino de desvios
	 */
	void NADA();

	/**
	 *  desvia sempre, i.e., desvio incondicional
	 * @param endereco do LABEL L
	 */
	void DSVS( int );

	/**
	 *  Desvio Condicional, desvia para o LABEL L se o topo da pilha for FALSE (zero)
	 * @param endereco do LABEL L
	 */
	void DSVF( int );

	/**
	 *  inicia programa principal
	 */
	void INPP();

	/**
	 *  aloca memória para N variáveis
	 * @param numero de variaveis a serem alocadas
	 */
	void AMEM( int );

	/**
	 *  desaloca memória para N variáveis
	 * @param numero de variaveis a serem desalocadas
	 */
	void DMEM( int );

	/**
	 *  encerra a execução da MEPA
	 */
	void PARA();

	/**
	 *  armazena o valor do topo da pilha em M[D[m]+n]
	 * @param  m é o nível léxico, e n o número da variável em VAR
	 */
	void ARMZ( int, int );


	void ARMZ (int );
	/**
	 *  chama o procedimento cuja primeira instrução se encontra no LABEL L
	 * @param  endereco do LABEL L
	 */
	 void CHPR( int );

	/**
	 *  salva no topo da pilha o endereço do registro de ativação
	 *  do procedimento de nível léxico K que estava ativado
	 * @param  nivel lexico do procedimento
	 */
	 void ENPR( int );

	/**
	 *  retorna do procedimento de nível léxico k com n parâmetros
	 * @param  nivel lexico do procedimento e numero de parametros
	 */
	void RTPR( int, int );

	/**
	 *  carrega valor indireto
	 * @param  nivel lexico e deslocamento da variavel
	 */
	void CRVI( int, int );

	/**
	 *  armazena valor indiretamente
	 * @param  nivel lexico e deslocamento da variavel
	 */
	void ARMI( int, int );

	/**
	 *  carrega endereço indireto
	 * @param  nivel lexico e deslocamento da variavel
	 */
	void CREN( int, int );

	void ClearArray ( char[]  , int );
	public:
		MEPA();
		~MEPA();
		void Teste();
		/**
		 * Executa as instruções da pilha P
		 *  */
		void Executar();
		/**
		 * Executa as instruções da pilha P
		 * mostrando passo a passo
		 *  */
		void ExecutarPasso();
		/**
		 * Carrega as instruçõe na pilha P
		 *  @param string
		 *  */
		void CarregaInstrucao(string);
		/**
		 * Imprime situação atual das pilhas
		 *  */
		void Imprime();
		//Teste para trace de erro
		void conteudo_P();

};


#endif /*MEPA_H_*/
