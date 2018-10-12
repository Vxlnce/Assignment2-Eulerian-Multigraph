#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>


int strLen = 0;
int nl = 0;
int nVertex = 0;

int findMin(int a, int b){

    return (a < b) ? a : b;

}

int findMax(int a, int b){

    return (a > b) ? a : b;

}

typedef struct vector {

    int* array;
    int length;

} vec_t;

typedef struct edge {

	int value;
	char sVertex;
	char eVertex;
    

} edge_t;

typedef struct vertex {

    int* degree;
    char* vertex;

} vertex_t;

// stage1
vec_t travelledEdge;

// return index of edge, if not found returns -1
int findEdgePosFromVerteces(char vert1, char vert2, edge_t* arrEdge){
    
    int i;
    for (i = 0; i < nl; i++){
        bool edgeCase1 = (arrEdge[i].sVertex == vert1 &&
         arrEdge[i].eVertex == vert2);

        bool edgeCase2 = (arrEdge[i].sVertex == vert2 &&
         arrEdge[i].eVertex == vert1);

        if (edgeCase1 || edgeCase2){
            return i;
        }

    }
    
    return -1; // not found

}

void initTravelledEdge(){

    travelledEdge.length = 0;
    travelledEdge.array = (int*)malloc(sizeof(int) * nl);

}


bool isTravelled(int edgePos){

    int i;
    for (i = 0; i < travelledEdge.length; i++){
        if (travelledEdge.array[i] = edgePos){return true;}
        else {return false;}
    }

}

int findEdgeIndexFromValue(int value, edge_t* arrEdge){

    int i;
    for (i = 0; i < nl; i++){

        if (arrEdge[i].value == value){

            return i;

        }

    }
    return -1; // no value found
}

int findLowestDegree(char vertex, 
                    int degreeOfVertex,
                    edge_t* arrEdge){

    int i;

    bool isConnectedVertex;
    vec_t connectedVertex;

    // init array of connected vertices
    connectedVertex.array = (int*)malloc(sizeof(int) * degreeOfVertex);
    connectedVertex.length = 0;

    for (i = 0; i < nl; i++){

        isConnectedVertex = 
            (vertex == arrEdge[i].sVertex ||
             vertex == arrEdge[i].eVertex);

        if (isConnectedVertex){

            if (!isTravelled(i)){

                connectedVertex.array[connectedVertex.length] = i;

            }

        }

    }

    int smallestValue = INT_MAX;
    for (i = 0; i < connectedVertex.length; i++){
        int position = connectedVertex.array[i];
        int _value = arrEdge[position].value;
        smallestValue = findMin(smallestValue, _value);

    }

    return smallestValue;

}



void smallestValuePath(char startVertex, vertex_t arrVertex, edge_t* arrEdge){ // take smallest value each time

    int completeLoop = 0;



    char currentVertex = startVertex;
    int currentDegree;
    int currentVertexToStart = findEdgePosFromVerteces(currentVertex,
                                                         startVertex, 
                                                         arrEdge);
    do{

        if (completeLoop) break;

        if (currentVertexToStart != -1){

            if (!isTravelled(currentVertexToStart)){

                currentVertex = startVertex;
                completeLoop = 1;

            }

        }

        // find current degree of vertex
        int i;
        for (i = 0; i < strlen(arrVertex.vertex); i++){

            if (currentVertex == arrVertex.vertex[i]){

                currentDegree = arrVertex.degree[i];
                break;

            }
        
        }



    }
    while(currentVertex != startVertex);

    int smallestValue = findLowestDegree(currentVertex, currentDegree, arrEdge);
    


} 

// stage 0

char* getInput(char** string, vertex_t* arrVertex){

    size_t capacity = 0xff;
    size_t maxVertex = 0x35;
    char* vertex = (char*)malloc(sizeof(char) * maxVertex);
    char* inArr = (char*)malloc(sizeof(char) * capacity);
	int i = 0;

	char c;

	while((c = getchar()) != EOF) {
        
        char* resptr = strchr((*arrVertex).vertex, c);
        

        if (resptr == NULL && !isspace(c) && !isdigit(c)){
            
            (*arrVertex).vertex[strlen((*arrVertex).vertex)] = c;
            (*arrVertex).degree[strlen((*arrVertex).vertex)] = 1;
            nVertex++;

        } 
        else if (!isspace(c) && !isdigit(c)){
            // grab index and itr
            int position = resptr - (*arrVertex).vertex;
            (*arrVertex).degree[position]++;

        }

        if (capacity == i) {capacity *= 2;}
        if (c == '\n') {nl++;}

		inArr[i] = c;
		i++;
        inArr = (char*)realloc(inArr, sizeof(char) * capacity);

	}

    strLen = i;
    inArr[i+1] = '\0'; //final nullbyte close string
    *string = (char*)malloc(capacity);
    strcpy(*string, inArr);
    return *string;

}

void fillArray(edge_t* array, char* strIn){

    char* string = strdup(strIn);

    const char* s = " \n"; // splits at space and \n delimits
    char *token;

    int i = 0;

    /* get the first token */
    token = strtok(string, s);
    

    
    int cArray = 0;// count elements in array, (+1 in while)

    /* walk through other tokens */
    while( token != NULL ) {
        
        if (cArray == 2){
            array[i].value = atoi(token);
            cArray = 0;
            
        }
        else if (cArray == 1){
            array[i].eVertex = *token;
            cArray++;
            
        }
        else if (cArray == 0){
            array[i].sVertex = *token;
            cArray++;
        }
        
        if (cArray == 0)i++;
         
        token = strtok(NULL, s);

    }

}

int main(){

    size_t maxVertex = 0x35;
    vertex_t arrVertex;
    arrVertex.vertex = (char*)malloc(sizeof(char) * maxVertex);
    arrVertex.degree = (int*)malloc(sizeof(int) * maxVertex);

    char* str;
    str = getInput(&str, &arrVertex);
    edge_t* array;
    array = (edge_t*)malloc((sizeof(edge_t) * nl) * 0xfff);

    fillArray(array, str);

    return 0;

}
