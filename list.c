#include "list.h"

#pragma 
//length of stdin stream counted in getInput
int stringLength;
int cNewline = 0; // -> number of 'edges' in stdin
int nVertex;

// stdin to char*

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
        if (c == '\n') {cNewline++;}

		inArr[i] = c;
		i++;
        inArr = (char*)realloc(inArr, sizeof(char) * capacity);

	}

    stringLength = i;
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