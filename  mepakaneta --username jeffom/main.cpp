/*
 * main.cpp
 *
 *  Created on: 22/09/2008
 *      Author: Boga
 */
#include "MEPA.h"

int main()
{
	MEPA *t = new MEPA();
	//t->Teste();
	t->CarregaInstrucao("teste.mep");
	//t->conteudo_P();
	t->Executar();

}
