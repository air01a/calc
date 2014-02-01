#ifndef _OPTION_H_
#define _OPTION_H_

#include "calcerror.h"
int debug;
int silent;
int trigoDeg;

errorHandler litOpt(int argc, char **argv, char **equ, int *ind);

#endif
