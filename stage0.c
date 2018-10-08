#include "list.h"
#include <string.h>

#pragma region data_processing

//length of stdin stream counted in getInput
size_t stringLength;
size_t cNewline = 0; // -> number of 'edges' in stdin
size_t nVertex;

// stdin to char*
void getInput(char* string) {

    char* inArr = (char*)malloc(sizeof(char));
	
    size_t capacity = 0xff;

    int i = 0;

	char c;

	while((c = getchar()) != EOF) {
        
        if (capacity == i) {capacity *= 2;}
        if (c == '\n'){ cNewline++;/*= cNewline;*/ }

		inArr[i] = c;
		i++;
        inArr = (char*)realloc(inArr, sizeof(char) * i);

	}

    stringLength = i;
    inArr[i+1] = '\0'; //final nullbyte close string
    


}

void delimInput(char* input, edge_t* delim){

    char* _input;
    strcpy(_input, input);

    delim = (edge_t*)malloc(sizeof(edge_t) * cNewline);

    if (delim != NULL){

        int i = 0;
        char* token;
        token = strtok(_input, "\n");

        while(token =! NULL){

            char* _token;
            _token = strtok(token, " ");

            int itr = 0;

            while (_token != NULL){

                if (itr == 0){ // frst var on line -> sVertex

                    strcpy(delim[i].sVertex, _token);

                }
                if (itr == 1){ // scnd var on line -> eVertex

                    strcpy(delim[i].eVertex, _token);

                }
                if (itr == 2){ // thrd var on line -> edge value

                    strcpy(delim[i].value, atoi(_token));

                }

                itr++;

            }

        } 

    }

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
