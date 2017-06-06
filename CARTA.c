//******************************************************************************
//$MCI Modulo de implementacao: Modulo Carta
// Arquivo: CARTA.c
// Letras identificadoras: CAR
//
// Autor(es): gbg - Gabriela Bevilacqua Gutierrez
//
//$. ***************************************************************************

/***** Inclusoes do compilador *****/

#include <stdio.h>
#include <stdlib.h>

/***** Inclusao do respectivo modulo de definicao *****/

#define CARTA_OWN
#include "CARTA.h"
#undef CARTA_OWN

/***** Inclusao de modulos de definicao de servidores *****/

#include "DEFINICOES.h"

/***** Tipos de dados do modulo *****/

typedef struct CAR_tgCarta
{
	int simbolo;
	DEF_tpNaipe naipe;
	DEF_tpCor cor;
} CAR_tpCarta;

//******************************************************************************
//$FC Funcao: CAR_CriaCarta
//$. ***************************************************************************

CAR_tpCondRet CAR_CriaCarta (CAR_tppCarta* carta, int simbolo, DEF_tpNaipe naipe, DEF_tpCor cor)
{
	//Assertiva
	//Verifica simbolo valido
	if((simbolo <= 0) || (simbolo > 13))
	{
		return CAR_CondRetSimboloInvalido;
	}

	//Aloca espaco na memoria para a carta e verifica se tem espaco suficiente
	//na memoria para realizar tal operacao
    *carta = (CAR_tppCarta)malloc(sizeof(CAR_tpCarta));
    
    if(*carta == NULL)
	{
        return CAR_CondRetSemMemoria;
    }

	//Inicializa os valores da carta
    (*carta)->simbolo = simbolo;
    (*carta)->naipe = naipe;
    (*carta)->cor = cor;
    
	return CAR_CondRetOK;
}

//******************************************************************************
//$FC Funcao: CAR_DestroiCarta
//$. ***************************************************************************

CAR_tpCondRet CAR_DestroiCarta (CAR_tppCarta carta)
{
	//Assertiva
	//Verifica se a carta existe
	if(carta == NULL)
	{
		return CAR_CondRetCartaInexistente;
	}

	//Libera a carta
	free(carta);

	return CAR_CondRetOK;
}

//******************************************************************************
//$FC Funcao: CAR_DescobreSimbolo
//$. ***************************************************************************

CAR_tpCondRet CAR_DescobreSimbolo (CAR_tppCarta carta, int* simbolo)
{
	//Assertiva
	//Verifica se a carta existe
	if(carta == NULL)
	{
		return CAR_CondRetCartaInexistente;
	}

	//Assertiva
	//Verifica simbolo valido
	if((carta->simbolo <= 0) || (carta->simbolo > 13))
	{
		return CAR_CondRetSimboloInvalido;
	}

	//Pega o simbolo da carta
	*simbolo = carta->simbolo;
	
	return CAR_CondRetOK;
}

//******************************************************************************
//$FC Funcao: CAR_DescobreNaipe
//$. ***************************************************************************

CAR_tpCondRet CAR_DescobreNaipe (CAR_tppCarta carta, DEF_tpNaipe* naipe)
{
	//Assertiva
	//Verifica se a carta existe
	if(carta == NULL)
	{
		return CAR_CondRetCartaInexistente;
	}

	//Pega o naipe da carta
	*naipe = carta->naipe;

	return CAR_CondRetOK;
}

//******************************************************************************
//$FC Funcao: CAR_DescobreCor
//$. ***************************************************************************

CAR_tpCondRet CAR_DescobreCor (CAR_tppCarta carta, DEF_tpCor* cor)
{
	//Assertiva
	//Verifica se a carta existe
	if(carta == NULL)
	{
		return CAR_CondRetCartaInexistente;
	}

	//Pega a cor da carta
	*cor = carta->cor;

	return CAR_CondRetOK;
}

//******************************************************************************
//$FC Funcao: CAR_CartaAuxiliar
//$. ***************************************************************************

CAR_tpCondRet CAR_CartaAuxiliar (CAR_tppCarta* cartaAux, CAR_tppCarta* carta)
{
	CAR_tpCondRet debugCAR;
	int simbolo;
	DEF_tpNaipe naipe;
	DEF_tpCor cor;

	//Assertiva
	//Verifica se a carta existe
	if(*cartaAux == NULL)
	{
		return CAR_CondRetCartaInexistente;
	}

	//Encontra as informacoes da carta
	debugCAR = CAR_DescobreSimbolo(*cartaAux, &simbolo);
	if(debugCAR)
	{
		return debugCAR;
	}

	debugCAR = CAR_DescobreNaipe(*cartaAux, &naipe);
	if(debugCAR)
	{
		return debugCAR;
	}

	debugCAR = CAR_DescobreCor(*cartaAux, &cor);
	if(debugCAR)
	{
		return debugCAR;
	}

	//Cria uma nova carta com as mesmas informacoes
	debugCAR = CAR_CriaCarta(carta, simbolo, naipe, cor);
	if(debugCAR)
	{
		return debugCAR;
	}

	//Assertiva
	if(carta == NULL)
	{
		return CAR_CondRetInconsistencia;
	}

	return CAR_CondRetOK;
}

/***** Fim da implementacao: Modulo Carta *****/
