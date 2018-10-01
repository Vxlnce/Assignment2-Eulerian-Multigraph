#include "list.h"
#include <string.h>

#pragma region data_processing

//length of stdin stream counted in getInput
size_t stringLength;
size_t cNewline = 0; // -> number of 'edges' in stdin

// stdin to char*
char** getInput() {

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
    
    char* pch;
    pch = strtok(inArr, " \n");
    int itr = 0;
    char** tokenArr;
    tokenArr = (char**)malloc(sizeof(char*));
    while (pch != NULL){

        strcpy(tokenArr[i], pch);
        tokenArr = realloc(tokenArr, sizeof(char*));
        itr++;

    }
	return tokenArr;

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

    if (!fVertex){
        
        for (i = 0; i < stringLength; i++); { // TODO: make for loop count vertices



            

        }
    
    }
       
        printf("\ncNewline: %lu\nstringLength: %lu\n", cNewline, stringLength);

}
