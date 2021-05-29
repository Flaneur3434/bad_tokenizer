#include "tokenization.h"

int
main(void)
{
	char *const ipAddr = "192.168.1.45";
	TokenList tokenList;

	tokenList = mallocTokenList(ipAddr, '.');

	printTokenList(tokenList);
	freeTokenList(tokenList);

	return 0;
}