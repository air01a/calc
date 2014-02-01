/************************************************************************************
 * 				Token.h - programme calc			    *
 * Erwan (~R/01~ 2003)								    *
 *										    * 
 * Definition de tous les types et constantes concernant les token		    *
 * 										    *
 ************************************************************************************/
#include <stdio.h>
#include "calcerror.h"

#ifndef _TOKENIZER_H_
#define _TOKENIZER_H_

#define AUTORIZEDCHAR "0123456789.*-/"
#define SEPARATOR "()*-/+"
#define MULTIPLICATION 0
#define DIVISION 1
#define ADDITION 2
#define SOUSTRACTION 3

#define SQR 0
#define SQRT 1
#define COS 2
#define SIN 3
#define TAN 4
#define ARCTAN 5
#define INT 6
#define LOG 7
#define EXP 8

#define LASTTOKEN 0
#define FUNCTION 1
#define OPERATION 2
#define REAL 3
#define INTEGER 4
#define PRIOROUVR 5
#define PRIORFERM 6

#define TYPEALPHA 1
#define TYPEOP 2
#define TYPENUM 3
#define TYPEPAROUVR 4
#define TYPEPARFERM 5
#define TYPEUNKNOWN 255

#define ESPACE ' '
#define MAXFUNCTIONSIZE 20
#define MAXTOKEN 150

//Pour chaque fonction, on affecte une opération
typedef struct {
	unsigned short int type; //Token d'une opération ou d'une multiplication
	char tokenStr[MAXFUNCTIONSIZE];
	void *funcOperation;
} functionDef;


//La structure d'un token
typedef struct {
	unsigned short int type; //Le token est il un réél, une fonction, ...
	double valueReal; //SI le token est un réél, quelle est sa valeur
	unsigned short int function; //Si le token est une fonction, quelle est sa référence dans le tableau
	unsigned short int op; //Si le token est un opérateur, lequel
	int offset;  //Quelle est sa position dans la chaine analysée (sert pour la gestion des erreurs
} token;

//Stocke tous les tokens
token tabOfToken[MAXTOKEN];
#endif
