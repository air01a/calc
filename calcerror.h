/************************************************************************************
 * 				calcerror.h - programme calc			    *
 * Erwan (~R/01~ 2003)								    *
 *										    * 
 * Definition des types et constantes pour la gestion des erreurs		    *
 * 										    *
 * *********************************************************************************/



#ifndef _CALCERROR_H
#define _CALCERROR_H


#define NOERROR 0
#define UNKNOWNFUNCTION 1
#define UNKNOWNOPERATOR 2
#define NOTAREAL 3
#define STACKFULL 4
#define STACKEMPTY 5
#define FUNCTIONTOOLONG 6
#define FUNCTIONHANDLERNULL 7
#define NOTOKEN 8
#define NOMORETOKEN 9
#define UNKNOWNTOKEN 10
#define REALEXPECTED 11
#define OPERATOREXPECTED 12
#define ERRORPARFERMANTE 13
#define DIVISIONBYZERO 14
#define RACINENEGATIVE 15
#define TANINFINIE 16

#define ERRORREADOPT 50
#define INVALIDOPT 51


#define REQUESTHELP 100
#define TOOMANYARGS 101
#define TOOFEWARGS 102


typedef unsigned int errorHandler;

char *errorToStr(errorHandler error);
char *showRef(char *chaine, int offset);
void afficheHelp(char *cmd,char *opt);
#endif
