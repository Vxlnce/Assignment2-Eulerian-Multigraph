#include "list.h"
 
//length of stdin stream counted in getInput
int stringLength;
int cNewline = 0; // -> number of 'edges' in stdin
int nVertex;

// stdin to char*

char* getInput(char** string, vertex_t* arrVertex) {

    size_t capacity = 0xff;
    
    char* inArr = (char*)malloc(sizeof(char) * capacity);
	int i = 0;

	char c;

	while((c = getchar()) != EOF) {

        // check if char has already been found
        char* resptr = strchr((*arrVertex).vertex, c);
        // printf("%p", resptr);
        // value/whitespace not a vertex
        bool isValue = !isspace(c) && !isdigit(c);
        //nprintf("%c", c);
        // NULL -> not been found before
        if (resptr == NULL && isValue){
            int position = strlen((*arrVertex).vertex);
            // not counting first char in input..?
            (*arrVertex).vertex[position] = c;
            (*arrVertex).degree[position] = 1;
            nVertex++;

        } 
        else if (isValue){ // found before, find pos and inc
            
            int position = (resptr - (*arrVertex).vertex);
            (*arrVertex).degree[position]++;

        }

        // alloc memory if needed
        if (capacity == i) {capacity *= 2;}
        if (c == '\n') {cNewline++;}

		inArr[i] = c;
		i++;
        inArr = (char*)realloc(inArr, sizeof(char) * capacity);
    

	}
    // copy inArr to *string, keep work done
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

    // modified from -> https://bit.ly/2wJ5G7M
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