#include "list.h"
#include <string.h>

#pragma region data_processing

//length of stdin stream counted in getInput
size_t stringLength;
size_t cNewline = 0; // -> number of 'edges' in stdin
size_t nVertex;

// stdin to char*
char* getInput() {

    char* inArr = (char*)malloc(sizeof(char));
	int i = 0;

	char c;

	while((c = getchar()) != EOF) {
       
        if (c == '\n'){ cNewline++;/*= cNewline;*/ }

		inArr[i] = c;
		i++;
        inArr = (char*)realloc(inArr, sizeof(char));

	}

    stringLength = i;
    inArr[i+1] = '\0'; //final nullbyte close string
    
    return inArr;

}

char** delimInput(char* input){

    char* _input;
    _input = (char*)malloc(sizeof(input));
    strcpy(_input, input);
    
    char** delimArr;
    delimArr = (char**)malloc(sizeof(char) * stringLength);

    char* pch;
    pch = strtok (input," \n");

    int i = 0, j = 0;

    for (int _i = 0; input[_i] != NULL; _i++){

        strcpy(delimArr[i][j], pch);

        if((j) % 3 == 0 && j != 0){

            j = 0;
            i++;

        }
        else {

            j++;

        }

    }

    return delimArr;

}

// putting info about multigraph into a linked list
list_t* buildList() {

    // pre malloc'd in fn...
    list_t* list = make_empty_list();
    assert(is_empty_list(list));

    return list;

}
#pragma endregion getting input from stdin and building list

void stage0(char** input){

    int i = 0, j = 0;
    char* fVertex = (char*)malloc(sizeof(char));
    int* cVertex = (int)malloc(sizeof(int));

    if (!fVertex){
        
        for (i = 0; i < stringLength; i++); { // TODO: make for loop count vertices

            for (j = 0; j < strlen(fVertex); j++){

                if (fVertex[j] == input[i]){

                    cVertex[j]++;

                }
                else{

                    nVertex++;
                    strcpy(fVertex[j], input[i]);
                    cVertex++;
                    fVertex = realloc(fVertex, sizeof(char));
                    cVertex = realloc(cVertex, sizeof(int));

                }

            }

        }
    
    }
       
        printf("\ncNewline: %lu\nstringLength: %lu\n", cNewline, stringLength);

}
