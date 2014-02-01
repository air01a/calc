#include "option.h"
#include <getopt.h>
#include <stdio.h>

#define MODEDEBUG 'd'
#define MODESILENT 's'
#define MODEHELP 'h'
#define TRIGODEG 't'

errorHandler litOpt(int argc, char **argv,char **equ,int *ind) {
static struct option long_options[] = 
{
	{"debug",0,0,MODEDEBUG},
	{"silent",0,0,MODESILENT},
	{"help",0,0,MODEHELP},
	{"trigo-deg",0,0,TRIGODEG},
	{0,0,0,0}
};
	int opt,opt_index=0,option=0;
	debug=silent=0;
	*ind=0;
	option=0;
	trigoDeg=0;
	
	while (opt!=EOF)
	{
		opt = getopt_long(argc,argv,"dsht",long_options,&opt_index);
		option++;
		switch(opt) {
			case MODEDEBUG : debug=1;break;
			case MODESILENT : silent=1;break;
			case MODEHELP : return REQUESTHELP;
			case TRIGODEG : trigoDeg=1; break;
			case EOF : break;
			default : return INVALIDOPT;
		}

	}
	if((option==(argc-1)))
	{
		*equ=argv[option++];
		
		return NOERROR;
	}
	*ind=option+1;
	return TOOMANYARGS;
}
