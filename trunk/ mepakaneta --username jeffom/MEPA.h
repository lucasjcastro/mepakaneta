#ifndef MEPA_H_
#define MEPA_H_

#include <string>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
/* Declaração dos tipos de comando */
enum { crct, soma, subt, mult, divi, invr, conj, disj, nega, cmme, cmma, cmig,
        cmdg, cmeg, cmag, dsvs, dsvf, nada, leit, impr, impl, impc, inpp, amem,
        para, crvl, armz, chpr, enpr, dmem, rtpr, crvi, armi, cren, mosm, vazio};

class P
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
		vector<P> 
		pilha_P;
		/* Pilha de dados */
		int 
		*pilha_M;
		/* Pilha de registradores */
		int 
		*pilha_D;
		/* Marcador da pilha de instrução */
		int 
		i;
		/* Marcador da pilha de dados*/
		int 
		s;
	public:	
		MEPA();
		~MEPA();
		void CRCT( int );
		void CRVL( int );
		void Teste();
		void CarregaInstrucao(string);
};


#endif /*MEPA_H_*/
