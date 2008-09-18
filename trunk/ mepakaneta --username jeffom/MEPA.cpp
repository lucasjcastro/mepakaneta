#include "MEPA.h"

MEPA::MEPA()
{
	s=0;
	i=0;
}

void MEPA::Teste()
{

}

void MEPA::CarregaInstrucao(string path)
{
	ifstream file( path.c_str(), ifstream::in );
	
	string 
	instrucao,
	_buffer;
	
	class P 
	_tempClass;
	
	vector<label> 
	rotulos;
	
	char
	proximo;
	
	int
	linha = 0;
	
	/* Verifica os labels
	 * padronizados Ln */
	while( !file.eof() )
	{
		file >> instrucao;
		if(instrucao[0] == 'L')
		{
			if(instrucao[1] >= '0' && instrucao[1] <= '9')
			{
				label _temp;
				_temp.label = instrucao;
				_temp.endereco = linha;
			}
		}
		file.ignore(100,'\n');
		linha++;
	}
	
	while( !file.eof() )
	{
		/*  Verifica se é uma instrução */
		
		if()
		/* Ignorar parte do label ?! */
		/* construir essa parte ainda */
		
		else
		{
			if ( instrucao == "AMEM" )
			{
				_tempClass.comando = amem;
			}
			else if ( instrucao == "ARMI" )
			{
				_tempClass.comando = armi;
			}
			else if ( instrucao == "ARMZ" )
			{
				_tempClass.comando = armz;
			}
			else if ( instrucao == "CHPR" )
			{
				_tempClass.comando = chpr;
			}
			else if ( instrucao == "CMAG" )
			{
				_tempClass.comando = cmag;
			}
			else if ( instrucao == "CMDG" )
			{
				_tempClass.comando = cmdg;
			}
			else if ( instrucao == "CMEG" )
			{
				_tempClass.comando = cmeg;
			}
			else if ( instrucao == "CMIG" )
			{
				_tempClass.comando = cmig;
			}
			else if ( instrucao == "CMMA" )
			{
				_tempClass.comando = cmma;
			}
			else if ( instrucao == "CMME" )
			{
				_tempClass.comando = cmme;
			}
			else if ( instrucao == "CONJ" )
			{
				_tempClass.comando = conj;
			}
			else if ( instrucao == "CRCT" )
			{
				_tempClass.comando = crct;
			}
			else if ( instrucao == "CREN" )
			{
				_tempClass.comando = cren;
			}
			else if ( instrucao == "CRVI" )
			{
				_tempClass.comando = crvi;
			}
			else if ( instrucao == "CRVL" )
			{
				_tempClass.comando = crvl;
			}
			else if ( instrucao == "DISJ" )
			{
				_tempClass.comando = disj;
			}
			else if ( instrucao == "DIVI" )
			{
				_tempClass.comando = divi;
			}
			else if ( instrucao == "DMEM" )
			{
				_tempClass.comando = dmem;
			}
			else if ( instrucao == "DSVF" )
			{
				_tempClass.comando = dsvf;
			}
			else if ( instrucao == "DSVS" )
			{
				_tempClass.comando = dsvs;
			}
			else if ( instrucao == "ENPR" )
			{
				_tempClass.comando = enpr;
			}
			else if ( instrucao == "IMPC" )
			{
				_tempClass.comando = impc;
			}
			else if ( instrucao == "IMPL" )
			{
				_tempClass.comando = impl;
			}
			else if ( instrucao == "IMPR" )
			{
				_tempClass.comando = impr;
			}
			else if ( instrucao == "INPP" )
			{
				_tempClass.comando = inpp;
			}
			else if ( instrucao == "INVR" )
			{
				_tempClass.comando = invr;
			}
			else if ( instrucao == "LEIT" )
			{
				_tempClass.comando = leit;
			}
			else if ( instrucao == "MOSM" )
			{
				_tempClass.comando = mosm;
			}
			else if ( instrucao == "MULT" )
			{
				_tempClass.comando = mult;
			}
			else if ( instrucao == "NADA" )
			{
				_tempClass.comando = nada;
			}
			else if ( instrucao == "NEGA" )
			{
				_tempClass.comando = nega;
			}
			else if ( instrucao == "PARA" )
			{
				_tempClass.comando = para;
			}
			else if ( instrucao == "RTPR" )
			{
				_tempClass.comando = rtpr;
			}
			else if ( instrucao == "SOMA" )
			{
				_tempClass.comando = soma;
			}
			else if ( instrucao == "SUBT" )
			{
				_tempClass.comando = subt;
			}		
		}
		/* Verifica se é uma instrucao de desvio */
		if (instrucao == "DSVS" || instrucao == "DSVF" || instrucao == "CHPR")
		{
			file.ignore(1,' ');
			proximo = file.peek();
			/* Verifica se o proximo caractere é um argumento */
			if ( proximo >= '0' && proximo <= '9' )
			{
				int arg;
				file >> arg;
				_tempClass.args.push_back(arg);
			}	
			
			/* Caso contrário é um label de destino 
			 * e verifica o vetor de labels para checar
			 * o endereço*/			 			
			else		
			{
				file >> _buffer;				
				for( int m=0; m<rotulos.size(); m++ )
				{
					label _tempRotulo = rotulos[m];
					if(rotulos[m].label == _buffer)
					{
						_tempClass.args.push_back(_tempRotulo.endereco);
					}
					break;
				}
			}//end else
		}
		/* Caso não seja um desvio também */
		else 
		{
			file.ignore(1,' ');
			proximo = file.peek();
			/* Verifica se o proximo caractere é um argumento */
			if ( proximo >= '0' && proximo <= '9' )
			{
				int arg;
				file >> arg;
				_tempClass.args.push_back(arg);
				proximo = file.peek();
				/* verifica se tem outro argumento */
				if ( proximo == ',' )
				{
					file.ignore( 1, ',' );
					file >> arg;
					_tempClass.args.push_back( arg );
				}
			}
		}
		
				
	}//end While
}//end CarregaInstrucao
