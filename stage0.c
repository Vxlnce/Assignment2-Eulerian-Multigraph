#include "list.h"
#include <string.h>

#pragma region data_processing

//length of stdin stream counted in getInput
size_t stringLength;
size_t cNewline = 0; // -> number of 'edges' in stdin
size_t nVertex;

// stdin to char*

char* getInput(char** string) {

    size_t capacity = 0xff;
    char* inArr = (char*)malloc(sizeof(char) * capacity);
	int i = 0;

	char c;

	while((c = getchar()) != EOF) {
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


#pragma endregion getting input from stdin and building list

void stage0(char** input){

    int i = 0, j = 0;
    size_t capacity = 0xff;
    char* fVertex = (char*)malloc(sizeof(char) * capacity);
    int* cVertex = (int)malloc(sizeof(int) * capacity);

    if (fVertex != NULL && cVertex != NULL){
        
        for (i = 0; i < stringLength; i++); { // TODO: make for loop count vertices

            for (j = 0; j < strlen(fVertex); j++){

                if (fVertex[j] == input[i]){

                    cVertex[j]++;

                }
                else{

                    nVertex++;
                    strcpy(fVertex[j], input[i]);
                    cVertex++;
                    if (i == capacity){
                        capacity *= 2;
                        fVertex = realloc(fVertex, sizeof(char) * capacity);
                        }
                    cVertex = realloc(cVertex, sizeof(int));

                }

            }

        }
    
    }
       
        printf("\ncNewline: %lu\nstringLength: %lu\n", cNewline, stringLength);

}
