//******************************************************************************
//$MCD Modulo de identificacao: Modulo de Embaralhamento
// Arquivo: EMB.c
// Letras identificadoras: EMB
//
// Autor(es): gbg - Gabriela Bevilacqua Gutierrez
//			  lla - Livia Lourenco Aloise
//
//
//$. ***************************************************************************

#if !defined( EMB_MOD )
#define EMB_MOD

/********** Controle de escopo do arquivo de definicao ***********/

#if defined( EMB_OWN )
	#define EMB_EXT
#else
	#define EMB_EXT extern
#endif

/***** Bibliotecas incluidas pelo modulo *****/

#include "LISTA.h"
#include "EMB.h"
#include "Definicoes.h"

/***** Tipo de dados exportado pelo modulo *****/

struct carta
{
	char simbolo;
	char naipe;
	char cor;
};

typedef struct carta EMB_tpCarta;

/***** Tipo enumerado do modulo *****/

typedef enum
{
	EMB_CondRetOK				= 0,
	EMB_CondRetSemMemoria		= 1,
	EMB_CondRetElementoInvalido	= 2,
	EMB_CondRetBaralhoVazio		= 3,
	EMB_CondRetBaralhoInexistente= 4,
	EMB_CondRetCartaInexistente = 5
} EMB_tpCondRet;

/******************************************************************************
//$FC Funcao: EMB_CriaCarta
***************************************************************************/

EMB_tpCondRet EMB_CriaCarta (EMB_tpCarta* carta, DEF_tpSimbolos simbolo, DEF_tpNaipe naipe, DEF_tpCor cor)
{
    
    *carta=(EMB_tpCarta*)malloc(sizeof(EMB_tpCarta));
    
    if(*carta==NULL){
        return EMB_CondRetSemMemoria;
    }
    /*
    if(   (simbolo<1 || simbolo>13)   ){
        return EMB_CondRetElementoInvalido
    }
    */
    (*carta)->simbolo=simbolo;
    (*carta)->naipe=naipe;
    (*carta)->cor=cor;
    
    return EMB_CondRetOK;
    
}

/******************************************************************************
//$FC Funcao: EMB_CriaBaralho
***************************************************************************/

EMB_tpCondRet EMB_CriaBaralho (LIS_tppLista* baralho)
{
    int i,j;
    for (i=1;i<5;i++)
    {
        if(i<3){
            cor=1;
        }
        else{
            cor=2;
        }
        for(j=0;j<13;j++)
        {
            baralho->valor=EMB_CriaCarta(carta,j,i,cor)
        }
            
    
    
    
}

//******************************************************************************
//$FC Funcao: EMB_EmbaralhaCartas
//
//$ED Descrição da Funcao
// A funcao reorganiza o baralho de forma que as cartas fiquem em sequencia
// aleatoria tanto para naipe quanto cor e simbolo.
//
//$FV Valores de retorno
//    EMB_CondRetOK - Operacao realizada com sucesso
//    EMB_CondRetBaralhoVazio - O baralho esta vazio
//    
//$. ***************************************************************************

EMB_tpCondRet EMB_EmbaralhaCartas (LIS_tppLista* baralho);

//******************************************************************************
//$FC Funcao: EMB_DestroiCarta
//
//$ED Descrição da Funcao
// A funcao destroi uma carta.
//
//$FV Valores de retorno
//    EMB_CondRetOK - Operacao realizada com sucesso
//    EMB_CondRetCartaInexistente - Tentar destruir uma carta que nao existe
//    
//$. ***************************************************************************

EMB_tpCondRet EMB_DestroiCarta (EMB_tpCarta* carta);

//******************************************************************************
//$FC Funcao: EMB_DestroiBaralho
//
//$ED Descrição da Funcao
// A funcao destroi um baralho.
//
//$FV Valores de retorno
//    EMB_CondRetOK - Operacao realizada com sucesso
//    EMB_CondRetBaralhoInexistente - Tentar destruir um baralho que nao existe
//    
//$. ***************************************************************************

EMB_tpCondRet EMB_DestroiBaralho (LIS_tppLista* baralho);

#undef EMB_EXT

#endif

/***** Fim da definição: Modulo Embaralhamento *****/
