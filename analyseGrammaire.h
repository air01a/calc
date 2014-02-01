#ifndef _ANALYSEGRAMM_
#define _ANALYSEGRAMM_

#include "calcerror.h"
#include "stack.h"

errorHandler analyseOperation(int *offset,const int numberOfToken,int recursif);
errorHandler analyseGrammaire(int *offset);


#endif
