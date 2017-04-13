//******************************************************************************
//$MCD Modulo de definicao: Modulo de Embaralhamento
// Arquivo: EMB.h
// Letras identificadoras: EMB
//
// Autor(es): gbg - Gabriela Bevilacqua Gutierrez
//			  lla - Livia Lourenco Aloise
//
//$ED Descrição do Módulo
// O modulo Embaralhamento implementa funcoes para manipulacao de
// um baralho. Cria a estrutura do baralho, uma lista duplamente
// encadeada, na qual os nos representam as cartas do baralho.
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

//******************************************************************************
//$FC Funcao: EMB_CriaCarta
//
//$ED Descrição da Funcao
// A funcao cria uma nova carta inicializando seus valores.
//
//$FV Valores de retorno
//    EMB_CondRetOK - Operacao realizada com sucesso
//    EMB_CondRetElementoInvalido - Simbolo, naipe ou cor da carta invalido
//    EMB_CondRetSemMemoria - Sem espaco na memoria
//    
//$EP Parametros
//    $P EMB_tpCarta - Parametro que recebera a carta.
//                     Esse parametro e passado por referencia.
//    $P simbolo - Parametro que passa o simbolo da carta.
//    $P naipe - Parametro que passa o naipe da carta.
//    $P cor - Parametro que passa a cor da carta.
//$. ***************************************************************************

EMB_tpCondRet EMB_CriaCarta (EMB_tpCarta* carta, char simbolo, char naipe, char cor);

//******************************************************************************
//$FC Funcao: EMB_CriaBaralho
//
//$ED Descrição da Funcao
// A funcao cria um baralho organizado, no qual as cartas ficam agrupadas
// por naipe e em cada naipe em sequencia numerica.
//
//$FV Valores de retorno
//    EMB_CondRetOK - Operacao realizada com sucesso
//    EMB_CondRetSemMemoria - Sem espaco na memoria para criar a carta
//    EMB_CondRetBaralhoVazio - O baralho esta vazio
//    
//$. ***************************************************************************

EMB_tpCondRet EMB_CriaBaralho (LIS_tppLista* baralho);

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
