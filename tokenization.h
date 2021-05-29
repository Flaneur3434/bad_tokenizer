#ifndef TOKENIZATION_H
#define TOKENIZATION_H

#include "slice.h"

typedef struct TokenList TokenList;

int getNumOfTokens(char *, char); 			/* get number of tokens in string */
Slice **mallocTokenArr(char *, char, int); 		/* allocate memory for array of pointers to slices */
void freeTokenArr(Slice **, int); 			/* free all allocated slices and tokenArr */
TokenList mallocTokenList(char *, char); 		/* abstraction for mallocTokenArr */
void freeTokenList(TokenList);				/* abstraction for freeTokenArr */
void printTokenList(TokenList);				/* print all slices in tokenArr */

struct TokenList
{
	Slice **sectionArr;					/* pointer to array of pointers of Slices */
	int numOfSections; 					/* number of tokens */
};

#endif //TOKENIZATION_H