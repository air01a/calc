#include "tokenizer.h"
#include "calcerror.h"
#include "analyseGrammaire.h"
#include "option.h"

int main(int argc, char **argv) {
	errorHandler error;
	char *equ;
	int offset=0;
	float result;

	if (argc==1)
		error=REQUESTHELP;
	else
		error=litOpt(argc,argv,&equ,&offset);
	
	if (error) {
		if (error==REQUESTHELP) {
			afficheHelp(argv[0],NULL);
			return NOERROR;
		}
		afficheHelp(argv[0],argv[offset]);
		return 2;
	}
	
	error=tokenize(equ);
	if (error!=NOERROR)
	{
		printf("\nErreur lors de l'analyse syntaxique : %s\n",errorToStr(error));
		showRef(equ,tabOfToken[lastToken()].offset);
		return 1;
	}

	error=analyseGrammaire(&offset);
	
	if (error)
	{
		printf("\nErreur lors de l'analyse grammaticale : %s\n",errorToStr(error));
		showRef(equ,tabOfToken[offset].offset);
		return 2;
	}
	
	error=calcul(&result,&offset);
	if (error)
	{
		printf("\nErreur lors du calcul : %s\n",errorToStr(error));
		showRef(equ,offset);
		return 3;
	}
	
	if (!silent)
		printf("Resultat : ");
	printf("%.6G\n",result);

	return 0;
}
