#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

/* externs */
extern char startingPoint;
extern int stringLength;
extern int cNewline; // == no. of edges on the multigraph
extern int nVertex; // total number of vertices in the graph
extern int minValue;
extern int maxValue;
extern int totValue;
extern int oddVertex;
extern int evenVertex;

/* fn prototypes */
void stage0();
int findMin(int a, int b);
int findMax(int a, int b);
