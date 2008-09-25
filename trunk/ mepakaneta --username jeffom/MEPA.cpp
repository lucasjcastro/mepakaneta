#include "MEPA.h"

MEPA::MEPA()
{
	s=-1;
	i=0;
	//Resize?
	M.resize(50,EMPTY);
	D.resize(50,EMPTY);
}

void MEPA::CRCT(int cte)
{
	s++;
	//M.push_back(cte);
	M[s] = cte;
	i++;
}

void MEPA::CRVL(int n)
{
	s++;
	M[s] = M[n];
	i++;
}

void MEPA::SOMA()
{
	M[s-1] = M[s-1] + M[s];
	s--;
	i++;
}

void MEPA::SUBT()
{
	M[s-1] = M[s-1] - M[s];
	s--;
	i++;
}

void MEPA::MULT()
{
	M[s-1] = M[s-1] * M[s];
	s--;
	i++;
}

void MEPA::DIVI()
{
	M[s-1] = (int) M[s-1]/M[s];
	s--;
	i++;
}

void MEPA::CMIG()
{
	if ( M[s-1] == M[s] )
		M[s-1] = 1;
	else
		M[s-1] = 0;
	s--;
	i++;
}

void MEPA::CMMA()
{
	if ( M[s-1] > M[s] )
		M[s-1] = 1;
	else
		M[s-1] = 0;
	s--;
	i++;
}

void MEPA::CMME()
{
	if ( M[s-1] < M[s] )
		M[s-1] = 1;
	else
		M[s-1] = 0;
	s--;
	i++;
}


void MEPA::CMAG()
{
	if ( M[s-1] >= M[s] )
		M[s-1] = 1;
	else
		M[s-1] = 0;
	s--;
	i++;
}

void MEPA::CMEG()
{
	if ( M[s-1] <= M[s] )
		M[s-1] = 1;
	else
		M[s-1] = 0;
	s--;
	i++;
}

void MEPA::CMDG()
{
	if ( M[s-1] != M[s] )
		M[s-1] = 1;
	else
		M[s-1] = 0;
	s--;
	i++;
}

void MEPA::CONJ()
{
	if( M[s-1] == 1 && M[s] == 1 )
		M[s-1] = 1;
	else
		M[s-1] = 0;
	s--;
	i++;
}

void MEPA::DISJ()
{
	if( M[s-1] == 1 || M[s] == 1 )
		M[s-1] = 1;
	else
		M[s-1] = 0;
	s--;
	i++;
}

void MEPA::NEGA()
{
	M[s] = 1-M[s];
	i++;
}

void MEPA::INVR()
{
	M[s] = -M[s];
	i++;
}

void MEPA::LEIT()
{
    s++;
    std::cin >> M[s];
    i++;
}

void MEPA::IMPR()
{
    std::cout << M[s];
    s--;
    i++;
}

void MEPA::NADA()
{
    i++;
}

void MEPA::DSVS( int L )
{
    i = L;
}

void MEPA::DSVF( int L )
{
    if( M[s] == 0 )
        i = L;
    else
        i++;

    s--;
}

void MEPA::INPP()
{
    i = 2;
    s--;
    D[0] = 0;
}

void MEPA::AMEM( int N )
{
    s += N;
    i++;
}

void MEPA::DMEM( int N )
{
    s -= N;
    i++;
}

void MEPA::PARA()
{
}

void MEPA::ARMZ( int m, int n )
{
    M[D[m]+n] = M[s];
    s--;
    i++;
}

void MEPA::CHPR( int L )
{
    s++;
    M[s]= i+1;
    i = L;
}

void MEPA::ENPR( int k )
{
    s++;
    M[s] = D[k];
    D[k] = s+1;
    i++;
}

void MEPA::RTPR( int k, int n )
{
    D[k] = M[s];
    i = M[s-1];
    s = s-(n+2);
}

void MEPA::CRVI( int k, int n )
{
    s++;
    M[s] = M[M[D[k]+n]];
    i++;
}

void MEPA::ARMI( int k, int n )
{
    M[M[D[k]+n]] = M[s];
    s--;
    i++;
}

void MEPA::CREN( int k, int n )
{
    s++;
    M[s] = D[k]+n;
    i++;
}

/* ----------- Fim funções da MEPA -----------*/

void MEPA::Teste()
{

}

void MEPA::Executar()
{
	bool stop = false;
	while ( !stop )
	{
		switch(P[i].comando)
		{
			case crct:
				CRCT(P[i].args[0]);
				break;
			case soma:
				SOMA();
				break;
			case subt:
				SUBT();
				break;
			case mult:
				MULT();
				break;
			case divi:
				DIVI();
				break;
			case invr:
				INVR();
				break;
			case conj:
				CONJ();
				break;
			case disj:
				DISJ();
				break;
			case nega:
				NEGA();
				break;
			case cmme:
				CMME();
				break;
			case cmma:
				CMMA();
				break;
			case cmig:
				CMIG();
				break;
			case cmdg:
				CMDG();
				break;
			case cmeg:
				CMEG();
				break;
			case cmag:
				CMAG();
				break;
			case dsvs:
				DSVS(P[i].args[0]);
				break;
			case dsvf:
				DSVF(P[i].args[0]);
				break;
			case nada:
				NADA();
				break;
			case leit:
				LEIT();
				break;
			case impr:
				IMPR();
				break;
			case inpp:
				INPP();
				break;
			case amem:
				AMEM(P[i].args[0]);
				break;
			case para:
				PARA();
				stop = true;
				break;
			case crvl:
				CRVL(P[i].args[0]);
				break;
			case armz:
				ARMZ(P[i].args[0],P[i].args[1]);
				break;
			case chpr:
				CHPR(P[i].args[0]);
				break;
			case enpr:
				ENPR(P[i].args[0]);
				break;
			case dmem:
				DMEM(P[i].args[0]);
				break;
			case rtpr:
				RTPR(P[i].args[0],P[i].args[1]);
				break;
			case crvi:
				CRVI(P[i].args[0],P[i].args[1]);
				break;
			case armi:
				ARMI(P[i].args[0],P[i].args[1]);
				break;
			case cren:
				CREN(P[i].args[0],P[i].args[1]);
				break;
		}
		Imprime();
		system("pause");

	}

}

void MEPA::CarregaInstrucao(string path)
{
	fstream file( path.c_str(), fstream::in );
	if( !file )
	{
		cout << "ERRO AO ABRIR ARQUIVO" << endl;
		return;
	}

	string
	instrucao,
	_buffer;

	char _temp[64];

	class pilha_P
	_tempClass;

	vector<label>
	rotulos;

	char
	proximo;

	int
	linha = 0,
	cont,
	p;

	/* Passar pelos labels
	 * eles sempre estão no começo
	 * antes da instrução */

	while( !file.eof() )
	{

		cont = 0;
		getline(file,_buffer);
		/* Verifica espacos em branco */
		while(_buffer[cont] == ' ')
		{
			cont++;
		}
		_buffer.erase(0,cont);

		p = _buffer.find_first_of(' ');
		_buffer.copy(_temp,p,0);
		_temp[p] = '\0';

		instrucao = _temp;

		/* Verifica se é um label */
		if( instrucao[0] == 'L' )
		{
			if( instrucao[1] >= '0' && instrucao[1] <= '9')
			{
				label _tempRotulo;
				_tempRotulo.label = instrucao;
				_tempRotulo.endereco = linha;
				rotulos.push_back(_tempRotulo);
			}
		}
		linha++;
	}

	/* Retorna ao início do arquivo */

	file.clear();
	file.seekg(0, ios_base::beg);
	linha = 0;

	while( !file.eof() )
	{
		cont = 0;
		getline(file,_buffer);

		/* Verifica espacos em branco */
		while(_buffer[cont] == ' ')
		{
			cont++;
		}
		_buffer.erase(0,cont);

		p = _buffer.find_first_of(' ');
		_buffer.copy(_temp,p,0);
		_temp[p] = '\0';

		instrucao = _temp;
		cout << instrucao << endl;

		/* Consome instrução do buffer */
		_buffer.erase( 0, instrucao.size() );

		/* Verifica se é um label */
		if( instrucao[0] == 'L' )
		{
			/* Caso seja Ignora ele
			 * e procura uma nova instrução */
			if( instrucao[1] >= '0' && instrucao[1] <= '9')
			{
				p = 0;
				cont = 0;

				while(_buffer[cont] == ' ')
				{
					cont++;
				}
				_buffer.erase(0,cont);

				p = _buffer.find_first_of(' ');
				_buffer.copy(_temp,p,0);
				_temp[p] = '\0';

				instrucao = _temp;
				_buffer.erase( 0, instrucao.size() );
			}
		}

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

		/* Verifica se é uma instrucao de desvio */
		if (instrucao == "DSVS" || instrucao == "DSVF" || instrucao == "CHPR")
		{
			_buffer.erase(0,1);

			proximo = _buffer[0];
			/* Verifica se o proximo caractere é um argumento */
			if ( proximo >= '0' && proximo <= '9' )
			{
				char arg[10];
				int m = 0;

				while(_buffer[m] != ' ' || _buffer[m] != ',')
				{
					m++;
				}
				_buffer.copy(arg,m,0);
				_tempClass.args.push_back( atoi(arg) );

				/* Consome parte lida do buffer */
				_buffer.erase( 0,m );
			}

			/* Caso contrário é um label de destino
			 * e verifica o vetor de labels para checar
			 * o endereço*/
			else
			{
				p = _buffer.find_first_of(' ');
				_buffer.copy(_temp,p,0);
				_temp[p] = '\0';
				_buffer.erase(0,p);

				for( int m=0; m<rotulos.size(); m++ )
				{
					label _tempRotulo = rotulos[m];
					if(rotulos[m].label == _temp)
					{
						_tempClass.args.push_back(_tempRotulo.endereco);
						break;
					}
				}

			}//end else
		}//end if

		else
		{
			_buffer.erase(0,1);

			proximo = _buffer[0];

			/* Verifica se o proximo caractere é um argumento */
			if ( proximo >= '0' && proximo <= '9' )
			{
				char arg[10];
				int m = 0;

				while(_buffer[m] != ' ' || _buffer[m] != ',')
				{
					m++;
				}
				_buffer.copy(arg,m,0);
				_tempClass.args.push_back( atoi(arg) );

				/* Consome parte lida do buffer */
				_buffer.erase( 0,m );
				}

				/* Verifica se existe outro argumento */
				if(  _buffer[0] == ',' )
				{
					_buffer.erase(0,1);
					int m = 0;
					char arg[10];
					while(_buffer[m] != ' ' || _buffer[m] != ',')
					{
						m++;
					}
					_buffer.copy(arg,m,0);
					_tempClass.args.push_back( atoi(arg) );

					/* Consome parte lida do buffer */
					_buffer.erase( 0,m );
				}
			}//end else
		}//end while
		P.push_back(_tempClass);
}//end CarregaInstrucao

void MEPA::Imprime()
{
	cout << "Instrucao Atual: ";
	if ( P[i].comando == crct )
		cout << "CRCT " << P[i].args[0];
	if ( P[i].comando == soma )
		cout << "SOMA";
	if ( P[i].comando == subt )
		cout << "SUBT";
	if ( P[i].comando == mult )
		cout <<"MULT";
	if ( P[i].comando == divi )
		cout << "DIVI";
	if ( P[i].comando == invr )
		cout << "INVR";
	if ( P[i].comando == conj )
		cout << "CONJ";
	if ( P[i].comando == disj )
		cout << "DISJ";
	if ( P[i].comando == cmme )
		cout << "CMME";
	if ( P[i].comando == cmma )
		cout << "CMMA";
	if ( P[i].comando == cmig )
		cout << "CMIG";
	if ( P[i].comando == cmdg )
		cout << "CMDG";
	if ( P[i].comando == cmeg )
		cout << "CMEG";
	if ( P[i].comando == cmag )
		cout << "CMAG";
	if ( P[i].comando == dsvs )
		cout << "DSVS " << P[i].args[0];
	if ( P[i].comando == dsvf )
		cout << "DSVF " << P[i].args[0] ;
	if ( P[i].comando == nada )
		cout << "NADA";
	if ( P[i].comando == leit )
		cout << "LEIT";
	if ( P[i].comando == impr )
		cout << "IMPR";
	if ( P[i].comando == impl )
		cout << "IMPL";
	if ( P[i].comando == impc )
		cout << "IMPC";
	if ( P[i].comando == inpp )
		cout << "INPP";
	if ( P[i].comando == amem )
		cout << "AMEM " << P[i].args[0];
	if ( P[i].comando == para )
		cout << "PARA";
	if ( P[i].comando == crvl )
		cout << "CRVL " << P[i].args[0];
	if ( P[i].comando == armz )
		cout << "ARMZ " << P[i].args[0] << "," << P[i].args[1];
	if ( P[i].comando == chpr )
		cout << "CHPR " << P[i].args[0];
	if ( P[i].comando == enpr )
		cout << "ENPR " << P[i].args[0];
	if ( P[i].comando == dmem )
		cout << "DMEM " << P[i].args[0];
	if ( P[i].comando == rtpr )
		cout << "RTPR " << P[i].args[0] << ","  << P[i].args[1];
	if ( P[i].comando == crvi )
		cout << "CRVI " << P[i].args[0] << ","  << P[i].args[1];
	if ( P[i].comando == armi )
		cout << "ARMI " << P[i].args[0] << ","  << P[i].args[1];
	if ( P[i].comando == cren )
		cout << "CREN " << P[i].args[0] << ","  << P[i].args[1];

	cout << endl;

	int cont = 0;

	cout << "Conteudo de M: ";
	while( cont < M.size() )
	{
		if( M[cont] != EMPTY )
		{
			cout << "|" <<M[cont] << "|" ;
		}
		cont++;
	}
	cout << endl;

	cont = 0;
	cout << "Conteudo de D: ";
	while( cont < D.size() )
	{
		if( D[cont] != EMPTY )
		{
			cout << "|" <<D[cont] << "|" ;
		}
		cont++;
	}
	cout << endl;
}
