#include "slice.h"

Slice *
mallocSlice(char *string, int begin, int end)
{
	Slice *temp_slice_p = malloc(sizeof(Slice));
	temp_slice_p->begin_slice_p = string+begin;
	temp_slice_p->length = end-begin;

	return temp_slice_p;
}

void
printSlice(Slice *slice)
{
	int i;

	for(i = 0; i < slice->length; i++)
	{
		printf("%c", *(slice->begin_slice_p + i));
	}

	printf("\n");
}

void
freeSlice(Slice *slice)
{
	free(slice);
}