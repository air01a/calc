#include "stack.h"
#include "tokenizer.h"
#include "option.h"
#include <math.h>
#define valueDegToRad 0.0174532925
#define degToRad(a) ((*a)*valueDegToRad)

errorHandler pCos(double *real) {
	if (trigoDeg)
		degToRad(real);
	*real=cos(*real);
	return NOERROR;
}

errorHandler pSin(double *real) {
	if (trigoDeg)
		degToRad(real);
	*real=sin(*real);
	return NOERROR;
}

errorHandler pTan(double *real) {
	float tmp;
	
	tmp=*real;
	if (trigoDeg)
		degToRad(real);
	*real=sin(*real);
	if (*real==0)
		return TANINFINIE;
		
	*real=tmp/(*real);
	return NOERROR;
}

errorHandler doOperation(int op) {
	token *tok1,*tok2;
	
	pop2(&tok1);
	pop2(&tok2);
	if ((tok1->type!=REAL) || (tok2->type!=REAL))
		return REALEXPECTED;
	
	switch (op) {
		case MULTIPLICATION : tok1->valueReal=tok2->valueReal*tok1->valueReal;
				      push2(tok1);return NOERROR;
		case DIVISION : if (tok1->valueReal==0)
					return DIVISIONBYZERO;
				tok1->valueReal=tok2->valueReal/tok1->valueReal;
				push2(tok1);return NOERROR;
		case SOUSTRACTION : tok1->valueReal=tok2->valueReal-tok1->valueReal;
				    push2(tok1);return NOERROR;
		case ADDITION : tok1->valueReal=tok2->valueReal+tok1->valueReal;
				push2(tok1);return NOERROR;
	}
}				      
	
errorHandler doFunction(int funct) {
	token *tok1;
	pop2(&tok1);
	errorHandler err;
	
	if (tok1->type!=REAL)
		return REALEXPECTED;
	
	switch(funct) {
		case SQR : tok1->valueReal*=tok1->valueReal;push2(tok1);return NOERROR;
		case SQRT : if (tok1->valueReal<0)
				    return RACINENEGATIVE;
			    tok1->valueReal=sqrt(tok1->valueReal);
			    push2(tok1);
			    return NOERROR;
		case COS : err=pCos(&tok1->valueReal);
			   push2(tok1);
			   return err;
		case SIN : err=pSin(&tok1->valueReal);
			   push2(tok1);
			   return err;
		case TAN : err=pTan(&tok1->valueReal);
			   push2(tok1);
			   return err;
		case INT : tok1->valueReal=floor(tok1->valueReal);
			   push2(tok1);
			   return NOERROR;
	}
	return NOERROR;
}


errorHandler calcul(float *result,int *offset) {
	errorHandler err=NOERROR,error=NOERROR;
	token *tok;

	resetStack1();

	err=pop1(&tok);
	while (!err)
	{
		switch (tok->type) {
			case REAL : push2(tok);break;
			case OPERATION : 
	 		       error=doOperation(tok->op);
			       break;
			case FUNCTION :
			       error=doFunction(tok->function);
			       break;
		}
		if (error) {
			*offset= tok->offset;
			return error;	
		}
		err=pop1(&tok);
	}
	pop2(&tok);
	*result=tok->valueReal;
	return NOERROR;
}
