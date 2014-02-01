/************************************************************************************
 * 				stack.h - programme calc			    *
 * Erwan (~R/01~ 2003)								    *
 *										    * 
 * Definition de tous les types et constantes concernant la gestion de la pile	    *
 * 										    *
 * *********************************************************************************/

#include "tokenizer.h"
#include "calcerror.h"


#ifndef _STACK_H
#define _STACK_H
errorHandler push1(token *tok);
errorHandler pop1(token **tok);
errorHandler push2(token *tok);
errorHandler pop2(token **tok);
void resetStack1();
void resetStack2();

#endif

