#ifndef SLICE_H
#define SLICE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Slice Slice;

Slice *mallocSlice(char *, int, int); 			/* allocate memory for Slices */
void printSlice(Slice *); 					/* print Slices */
void freeSlice(Slice *); 					/* free Slices */

struct Slice
{
	char * begin_slice_p; 				    /* pointer to a char in string that indecates the beginning of a Slice */
	int length; 						    /* length of the slice */
};

#endif //SLICE_H
