#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int strLen = 0;
int nl = 0;

typedef struct edge {

	int value;
	char sVertex;
	char eVertex;

} edge_t;

void getInput(char* string) {

    size_t capacity = 0xff;
    char* inArr = (char*)malloc(sizeof(char));
	int i = 0;

	char c;

	while((c = getchar()) != EOF) {
        if (capacity == i) {capacity *= 2;}
        if (c == '\n') {nl++;}

		inArr[i] = c;
		i++;
        inArr = (char*)realloc(inArr, sizeof(char) * capacity);

	}

    strLen = i;
    inArr[i+1] = '\0'; //final nullbyte close string

}

void fillArray(edge_t* array){

    int i = 0;

    for (i; i < nl; i++){

            /*array[i] = (edge_t) {
                .sVertex = 'a',
                .eVertex = 'A',
                .value = 1
            };*/

            array[i].sVertex = 'a';
            array[i].eVertex = 'A';
            array[i].value = 12;

    }

}

int main(){

    char* str;
    str = (char*)malloc(sizeof(char) * strLen);
    getInput(str);

    edge_t* array;
    array = (edge_t*)malloc(sizeof(edge_t) * nl);

    fillArray(array);

    int i = 0;
    for (i; i < nl; i++){

        printf("%c, %c, %d\n", array[i].sVertex, array[i].eVertex, array[i].value);

    }

    return 0;

}