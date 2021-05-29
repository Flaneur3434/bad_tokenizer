#include "tokenization.h"

int
getNumOfTokens(char *string, char delimiter)
{
	int i, stringLen, numOfSections;
	
	stringLen = strlen(string); numOfSections = 0;
	
	for (i = 0; string[i] != '\0'; i++)
	{
		if (string[i] == delimiter)
		{
			numOfSections++;
		}
	}
	
	return ++numOfSections;
}

Slice **
mallocTokenArr( char *string, char delimiter, int numOfSections)
{
	int stringLen, begToken, endToken, token_counter;
	Slice **sectionArr;

	sectionArr = malloc(sizeof(Slice)*numOfSections);
	stringLen = strlen(string);
	endToken =0; begToken = 0; token_counter = 0;
	
	for (;string[endToken] != '\0'; endToken++)
	{
		if (string[endToken] == delimiter)
		{
			(sectionArr)[token_counter++] = mallocSlice(string, begToken, endToken);
			begToken = ++endToken; //skip delimiter
		}
	}

	(sectionArr)[token_counter] = mallocSlice(string, begToken, stringLen);
	
	return sectionArr;
}

void
freeTokenArr(Slice **sectionArr, int numOfSections)
{
	int i;
	for (i = 0; i < numOfSections; i++)
	{
		freeSlice(sectionArr[i]);
	}
	free(sectionArr);
}

TokenList 
mallocTokenList(char *string, char delimiter)
{
	int numOfSections, i;
	Slice **sectionArr;

	numOfSections = getNumOfTokens(string, '.');
	sectionArr = mallocTokenArr(string, '.', numOfSections);
	TokenList sectionList = (TokenList) {.sectionArr = sectionArr, .numOfSections = numOfSections};

	return sectionList;
}

void
freeTokenList(TokenList sectionList)
{
	freeTokenArr(sectionList.sectionArr, sectionList.numOfSections);
}

void
printTokenList(TokenList sectionList)
{
	int i;

	for (i = 0; i < sectionList.numOfSections; i++)
	{
		printSlice(sectionList.sectionArr[i]);
	}
}