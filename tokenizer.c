/************************************************************************************
 * 				Token.c - programme calc			    *
 * Erwan (~R/01~ 2003)								    *
 *										    * 
 * Transforme une chaine de caracteres en un tableau de Token			    *
 * 										    *
 ***********************************************************************************/

#include "tokenizer.h"
#include "option.h"
#include <error.h>
#include <string.h>
#include <stdlib.h>


//Tableau contenant les fonctions prédéfinies
char *functionRef[] = {"SQR","SQRT","COS","SIN","TAN","ARCTAN","INT","LOG","EXP",NULL};

int lastToken() {
	int i=0;

	while ((i<MAXTOKEN) && (tabOfToken[i].type!=LASTTOKEN) && (tabOfToken[i].type!=UNKNOWNTOKEN))
		i++;
	return i;
}	


// Renvoi le type de caractère que represente cara (opérateur, chiffre, parenthèse ou une lettre, ...)
errorHandler caractereType(char cara) {
	if (cara<='z' && cara>='A')
		return TYPEALPHA;
	if (cara=='*' || cara=='/' || cara=='+' || cara=='-')
		return TYPEOP;
	if ((cara>='0' && cara <='9') || (cara=='.'))
		return TYPENUM;
	if (cara=='(')
		return TYPEPAROUVR;
	if (cara==')')
		return TYPEPARFERM;
	return TYPEUNKNOWN;
}


// Si le caractère présent est un opérateur, remplit le token avec les valeurs adéquates
errorHandler getOperator(char *chaine, int *offset, token *newToken) {
	newToken->type=OPERATION;
		
	switch (chaine[*offset]) {
		case '*' : newToken->op=MULTIPLICATION;break;
		case '/' : newToken->op=DIVISION;break;
		case '+' : newToken->op=ADDITION;break;
		case '-' : newToken->op=SOUSTRACTION;break;
		default : newToken->op=TYPEUNKNOWN;
	}
	if (debug)
		printf("\t\tOPERATOR : %i\n",newToken->op);
	(*offset)++;
	return NOERROR;
}


// Si le caractère est une lettre, recherche le mot complet et le compare aux fonctions définies. Si le mot ne correspond
// a aucune fonction, on renvoi une erreur. Sinon, on remplit le token.
errorHandler getFunction(char *chaine,int *offset, token *newToken) {
	char buffer[MAXFUNCTIONSIZE+1];
	int i=0;

	while ((*offset<strlen(chaine)) && (i<MAXFUNCTIONSIZE) && (caractereType(chaine[*offset])==TYPEALPHA))
		buffer[i++]=chaine[(*offset)++];
	buffer[i]='\0';
	i=0;

	while ((functionRef[i]!=NULL) && (strcasecmp(buffer,functionRef[i])!=0))
		i++;

	if(functionRef[i]==NULL)
		return UNKNOWNFUNCTION;
	
	
	newToken->type=FUNCTION;
	newToken->function=i;
	if(debug)
		printf("\t\tFonction:%i\n",newToken->function);
	return NOERROR;
}


// Si le caractère est un chiffre,on récupere le nombre complet et on le transforme en float qu'on stocke dans le token
errorHandler getNumber(char *chaine,int *offset, token *newToken) {	
	char buffer[MAXFUNCTIONSIZE+1];
	char *errorBuff;
	int i=0;

	while ((*offset<strlen(chaine)) && (i<MAXFUNCTIONSIZE) && (caractereType(chaine[*offset])==TYPENUM))
		buffer[i++]=chaine[(*offset)++];
	buffer[i]='\0';
	*offset++;

	newToken->valueReal=strtod(buffer,&errorBuff);
	newToken->type=REAL;
	if (debug)
		printf("\t\tReal = %f \n",newToken->valueReal);
	return NOERROR;
}

// Recupere le token suivant
errorHandler nextToken(char *chaine, int *offset,token *newToken){
	int lengthChaine;
	int type;
	
	lengthChaine=strlen(chaine);
	while((*offset<lengthChaine) && (chaine[*offset]==ESPACE))
		(*offset)++;
	
	if (*offset==lengthChaine) {
		newToken->type=LASTTOKEN;
		return NOMORETOKEN;
	}
		
	newToken->offset=*offset;
	
	type=caractereType(chaine[*offset]);

	if (debug)
		printf("\t\tTYPE : %i\n",type);
	switch(type) {
		case TYPEALPHA : return getFunction(chaine,offset,newToken);
		case TYPEOP : return getOperator(chaine,offset,newToken);
		case TYPENUM : return getNumber(chaine,offset,newToken);
		case TYPEPAROUVR : newToken->type=PRIOROUVR; (*offset)++;return NOERROR;
		case TYPEPARFERM : newToken->type=PRIORFERM; (*offset)++;return NOERROR;
		default : newToken->type=UNKNOWNTOKEN;return UNKNOWNTOKEN;
	}	
	return UNKNOWNTOKEN;
}


// Transforme une chaine de caractère en une suite de token
errorHandler tokenize(char *chaine) {
int error=NOERROR;
int numToken=0;
int offset;
	
	offset=0;

	if (debug) {
		printf("\n############# Debut de l'analyse syntaxique ##############\n");
		printf("\tListe des tokens rencontrés :\n");
	}
	
	if (chaine==NULL)	
		return NOTOKEN;

	while((error==NOERROR)) // && (offset<strlen(myChaine)))	
		error=nextToken(chaine,&offset,&tabOfToken[numToken++]);
	if (error != NOMORETOKEN)
		return error;
	return NOERROR;
}
