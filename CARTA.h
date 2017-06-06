//******************************************************************************
//$MCD Modulo de definicao: Modulo Carta
// Arquivo: CARTA.h
// Letras identificadoras: CAR
//
// Autor(es): gbg - Gabriela Bevilacqua Gutierrez
//
//$ED Descrição do Módulo
// O modulo Carta implementa a estrutura da carta e as principais funcoes
// referentes a manipulacao de uma carta.
//
//$. ***************************************************************************

#if !defined( CARTA_MOD )
#define CARTA_MOD

/***** Controle de escopo do arquivo de definicao *****/

#if defined( CARTA_OWN )
	#define CARTA_EXT
#else
	#define CARTA_EXT extern
#endif

/***** Inclusao de modulos de definicao de servidores *****/

#include "DEFINICOES.h"

/***** Tipo de dados exportados pelo modulo *****/

typedef struct CAR_tgCarta* CAR_tppCarta;

/***** Tipo enumerado do modulo *****/

typedef enum
{
	CAR_CondRetOK					= 0,
	CAR_CondRetSemMemoria			= 1,
	CAR_CondRetCartaInexistente		= 2,
	CAR_CondRetSimboloInvalido		= 3,
	CAR_CondRetInconsistencia		= 4
} CAR_tpCondRet;

//******************************************************************************
//$FC Funcao: CAR_CriaCarta
//
//$ED Descrição da Funcao
// A funcao cria uma nova carta inicializando seus valores de simbolo, naipe e
// cor.
//
//$FV Valores de retorno
//    CAR_CondRetOK
//    CAR_CondRetSemMemoria
//	  CAR_CondRetSimboloInvalido
//    
//$EP Parametros
//    $P carta - Parametro que recebera a carta.
//       Esse parametro e passado por referencia.
//    $P simbolo - Parametro que passa o simbolo da carta.
//    $P naipe - Parametro que passa o naipe da carta.
//    $P cor - Parametro que passa a cor da carta.
//$. ***************************************************************************

CAR_tpCondRet CAR_CriaCarta (CAR_tppCarta* carta, int simbolo, DEF_tpNaipe naipe, DEF_tpCor cor);

//******************************************************************************
//$FC Funcao: CAR_DestroiCarta
//
//$ED Descrição da Funcao
// A funcao destroi uma carta.
//
//$FV Valores de retorno
//    CAR_CondRetOK
//	  CAR_CondRetCartaInexistente
//    
//$EP Parametros
//    $P carta - Parametro que passa uma carta.
//$. ***************************************************************************

CAR_tpCondRet CAR_DestroiCarta (CAR_tppCarta carta);

//******************************************************************************
//$FC Funcao: CAR_DescobreSimbolo
//
//$ED Descrição da Funcao
// A funcao acessa o simbolo de uma carta.
//
//$FV Valores de retorno
//    CAR_CondRetOK
//	  CAR_CondRetCartaInexistente
//    
//$EP Parametros
//    $P carta - Parametro que passa uma carta.
//	  $P simbolo - Parametro que recebera o simbolo da carta.
//		 Esse parametro e passado por referencia.
//$. ***************************************************************************

CAR_tpCondRet CAR_DescobreSimbolo (CAR_tppCarta carta, int* simbolo);

//******************************************************************************
//$FC Funcao: CAR_DescobreNaipe
//
//$ED Descrição da Funcao
// A funcao acessa o naipe de uma carta.
//
//$FV Valores de retorno
//    CAR_CondRetOK
//	  CAR_CondRetCartaInexistente
//    
//$EP Parametros
//    $P carta - Parametro que passa uma carta.
//	  $P naipe - Parametro que recebera o naipe da carta.
//		 Esse parametro e passado por referencia.
//$. ***************************************************************************

CAR_tpCondRet CAR_DescobreNaipe (CAR_tppCarta carta, DEF_tpNaipe* naipe);

//******************************************************************************
//$FC Funcao: CAR_DescobreCor
//
//$ED Descrição da Funcao
// A funcao acessa a cor de uma carta.
//
//$FV Valores de retorno
//    CAR_CondRetOK
//	  CAR_CondRetCartaInexistente
//    
//$EP Parametros
//    $P carta - Parametro que passa uma carta.
//	  $P cor - Parametro que recebera a cor da carta.
//		 Esse parametro e passado por referencia.
//$. ***************************************************************************

CAR_tpCondRet CAR_DescobreCor (CAR_tppCarta carta, DEF_tpCor* cor);

//******************************************************************************
//$FC Funcao: CAR_CartaAuxiliar
//
//$ED Descrição da Funcao
// A funcao pega o endereco de uma carta, acessa seus dados de simbolo, naipe e
// cor e cria uma nova carta com esses dados.
//
//$FV Valores de retorno
//    CAR_CondRetOK
//    CAR_CondRetSemMemoria
//	  CAR_CondRetCartaInexistente
//	  CAR_CondRetSimboloInvalido
//    
//$EP Parametros
//    $P cartaAux - Parametro que passa uma carta.
//		 Esse parametro e passado por referencia.
//	  $P carta - Parametro que recebera a nova carta.
//		 Esse parametro e passado por referencia.
//$. ***************************************************************************

CAR_tpCondRet CAR_CartaAuxiliar (CAR_tppCarta* cartaAux, CAR_tppCarta* carta);

#undef CARTA_EXT

#endif

/***** Fim da definicao: Modulo Carta *****/
