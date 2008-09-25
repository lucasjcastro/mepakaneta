/*
 * main.cpp
 *
 *  Created on: 22/09/2008
 *      Author: Boga
 */
#include "MEPA.h"

int main(char* arg[])
{
	MEPA *t = new MEPA();

	t->CarregaInstrucao(arg[0]);
	t->conteudo_P();
	t->ExecutarPasso();

}
