#include "analyseGrammaire.h"
#include "tokenizer.h"
#include "stack.h"
#include "option.h"

int estPrioritaire(int op) {
	if ((op==MULTIPLICATION) || (op==DIVISION))
		return 1;
	return 0;
}

errorHandler analyseExpression(int *offset,int numberOfToken) {
	int error=NOERROR;
	token *tok;
	
	switch (tabOfToken[(*offset)].type) {
		case PRIOROUVR : (*offset)++;error=analyseOperation(offset,numberOfToken,0);(*offset)++;return error;
		case REAL : push1(&tabOfToken[(*offset)++]);return NOERROR;
		case FUNCTION : tok=&tabOfToken[(*offset)++];
				error=analyseExpression(offset,numberOfToken);
				if (error)
					return error;
				error=push1(tok);
				return error;
		case OPERATION : if ((tabOfToken[*offset+1].type==REAL) && (tabOfToken[*offset].op==SOUSTRACTION)) {
					tabOfToken[*offset+1].valueReal=-tabOfToken[*offset+1].valueReal;
					push1(&tabOfToken[*offset+1]);
					*offset+=2;
					return NOERROR;
				 }
	}
	return REALEXPECTED;
}

errorHandler analyseOperation(int *offset,const int numberOfToken,int recursif) {
	token *tok;
	errorHandler error;
	
	error=analyseExpression(offset,numberOfToken);
	if (error)
		return error;
	while (*offset<numberOfToken) {
		tok=&tabOfToken[*offset];
	
		if (tok->type == PRIORFERM) {
			return NOERROR;
		}
		if(tok->type != OPERATION)
			return OPERATOREXPECTED;

		if(estPrioritaire(tok->op))
		{	
			(*offset)++;
			error=analyseExpression(offset,numberOfToken);
			if (!error)
				error=push1(tok);
		} else {
			if(recursif)
				return NOERROR;
			(*offset)++;
			error=analyseOperation(offset,numberOfToken,1);
			if (!error) 
				error=push1(tok);
			
		}
		if(error)
			return error;
	}
	return NOERROR;
}

void printStack() {
	int i=0;
	token *tok;


	resetStack1();
	printf("\n\tEtat de la Pile\n");
	i=pop1(&tok);

	while (i==0) {
			
		switch (tok->type) {
			case OPERATION : printf("\t\tOPERATEUR : ");
					switch (tok->op) {
						case MULTIPLICATION : printf("*\n");break;
						case DIVISION : printf("/\n");break;
						case ADDITION : printf("+\n");break;
						case SOUSTRACTION : printf("-\n");break;
					}
					break;
			case REAL : printf("\t\tREAL : %f\n",tok->valueReal);break;
			case FUNCTION : printf("\t\tFunction : %i\n",tok->function);break;
		}
		i=pop1(&tok);					
	}
}


errorHandler analyseGrammaire(int *offset){
	int error=0;

	if (debug)
		printf("\n############# Debut de l'analyse Grammaticale ##############\n");	
	
	*offset=0;
	error=analyseOperation(offset,lastToken(),0);
	if (*offset<lastToken() && (!error))
		error=ERRORPARFERMANTE;
		
	if (debug)
		printStack();
	
	return error;
}
