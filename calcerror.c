#include "calcerror.h"
#define NULL 0

char *messErreur[] = {"Pas d'erreur détéctée","Fonction demandée inconnue","Opérateur demandé inconnu","Impossible de lire le nombre réél","Pile pleine, impossible d'analyser cette chaîne","Le programme a tenté de lire un objet inexistant sur la pile","La fonction entrée est trop longue (plus de 20 car)","La fonction demandée n'est pas réferencée correctement","Ce token n'est pas referencé","Il n'y a  plus de token a analysé","L'analyse syntaxique a détéctée une fonctione inconnue","Un réél est attendu","Opérateur attendu","Parenthèse fermante, mais pas de parenthèse fermante","Division par zéro","Racine d'un nombre négatif","TAN d'un nombe0[PI]"};

char messDefault[]="Erreur inconnue";

char *errorToStr(errorHandler error) {
	if ((error>=0) && (error<=16))
		return messErreur[error];
	return messDefault;
}

char *showRef(char *chaine, int offset) {
	int i=0;

	printf("%s\n",chaine);
	while (i++ < offset)
		printf(" ");
	printf("^\n");
}

void afficheHelp(char *cmd,char *opt) {
	if (opt!=NULL)
		printf("Option %s inconnue. \n",opt);
	printf ("Usage : %s [-h -s -d] equation\n",cmd);
	printf("-d = --debug : passe en mode debug (affiche la pile)\n");
	printf("-s = --silent : n'affiche que le résultat\n");
	printf("-h = --help : affiche ce message\n");
	printf("-------------------------------------------------------\n");
	printf("			R1 2003\n");
}
