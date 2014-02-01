#include "calcerror.h"
#define NULL 0

char *messErreur[] = {"Pas d'erreur d�t�ct�e","Fonction demand�e inconnue","Op�rateur demand� inconnu","Impossible de lire le nombre r��l","Pile pleine, impossible d'analyser cette cha�ne","Le programme a tent� de lire un objet inexistant sur la pile","La fonction entr�e est trop longue (plus de 20 car)","La fonction demand�e n'est pas r�ferenc�e correctement","Ce token n'est pas referenc�","Il n'y a  plus de token a analys�","L'analyse syntaxique a d�t�ct�e une fonctione inconnue","Un r��l est attendu","Op�rateur attendu","Parenth�se fermante, mais pas de parenth�se fermante","Division par z�ro","Racine d'un nombre n�gatif","TAN d'un nombe0[PI]"};

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
	printf("-s = --silent : n'affiche que le r�sultat\n");
	printf("-h = --help : affiche ce message\n");
	printf("-------------------------------------------------------\n");
	printf("			R1 2003\n");
}
