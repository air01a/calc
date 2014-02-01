/************************************************************************************
 * 				Stack.c - programme calc			    *
 * Erwan (~R/01~ 2003)								    *
 *										    * 
 * Gestion de la pile								    *
 * 										    *
 * *********************************************************************************/

#include "stack.h"
#include "calcerror.h"



token *stack1[MAXTOKEN]; //Contient les réferences vers les token (contenus dans tokenizer.c
token *stack2[MAXTOKEN];

int sp1=0,sp2=0,bp1=0;

//Place un token dans la pile
errorHandler push1(token *tok) {
	if (sp1<MAXTOKEN)
	{
		stack1[sp1]=tok;
		sp1++;bp1++;
		return NOERROR;
	}

	return STACKFULL;
}

errorHandler push2(token *tok){
	if (sp2<MAXTOKEN){
		stack2[sp2]=tok;
		sp2++;
		return NOERROR;
	}

	return STACKFULL;

}

errorHandler pop2(token **tok) {
	if(sp2>0)
	{
		sp2--;
		(*tok)=stack2[sp2];		
		return NOERROR;
	}

	return STACKEMPTY;

}

//Recupére un token dans la pile

errorHandler pop1(token **tok) {
	if(sp1<bp1)
	{
		(*tok)=stack1[sp1];
		sp1++;
		return NOERROR;
	}

	return STACKEMPTY;
}




void resetStack1() {
	sp1=0;
}

void resetStack2() {
	sp2=0;
}
