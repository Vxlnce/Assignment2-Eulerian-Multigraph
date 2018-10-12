#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

/* type definitions ----------------------------------------------------------*/

typedef struct edge {

	int value;
	char sVertex;
	char eVertex;

} edge_t;

typedef struct vertex {

    int* degree;
    char* vertex;

} vertex_t;

/* end type definitions ------------------------------------------------------*/

/* function prototypes -------------------------------------------------------*/

void delimInput(char* input, edge_t* delim);
char* getInput(char** string, vertex_t* arrVertex);
void fillArray(edge_t* array, char* strIn);

/* end function prototypes ---------------------------------------------------*/
