#pragma once

#include "stage0.h"
#include "list.h"
#include <stdbool.h>

typedef struct vector {

    int* array;
    int length;

} vec_t;

/* externs */
extern int* travelledEdge;

void stage1();
int findLowestDegree(char vertex, int degreeOfVertex, edge_t* arrEdge);
int findEdgePosFromVerteces(char vert1, char vert2, edge_t* arrEdge);
void smallestValuePath(char startVertex, vertex_t arrVertex, edge_t* arrEdge);