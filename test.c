#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

int strLen = 0;
int nl = 0;
int nVertex = 0;

typedef struct edge {

	int value;
	char sVertex;
	char eVertex;
    

} edge_t;

typedef struct vertex {

    int* degree;
    char* vertex;

} vertex_t;

char* getInput(char** string, vertex_t* arrVertex) {

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


    printf("%s, degree[1](a): %d\n", arrVertex.vertex, arrVertex.degree[1]);

    return 0;

}
