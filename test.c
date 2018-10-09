#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

int strLen = 0;
int nl = 0;

typedef struct edge {

	int value;
	char sVertex;
	char eVertex;
    

} edge_t;

char* getInput(char** string) {

    size_t capacity = 0xff;
    char* inArr = (char*)malloc(sizeof(char) * capacity);
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
    *string = (char*)malloc(capacity);
    strcpy(*string, inArr);
    return *string;

}

void fillArray(edge_t* array, char* strIn){
    
    size_t arrCapacity = sizeof(edge_t) * nl;

    char* string = strdup(strIn);

    const char* s = " \n"; // splits at space and \n delimits
    char *token;

    int i = 0;

    /* get the first token */
    token = strtok(string, s);
    //*array = (edge_t*)realloc(array, arrCapacity * (strlen(token)+1));

    array[i].sVertex = *token;
    
    i++;
    int cArray;// count elements in array, (+1 in while)

    /* walk through other tokens */
    while( token != NULL ) {
        
        i++;
        cArray = i + 1; 
        token = strtok(NULL, s);

        if (cArray % 3 == 0){
            //*array = (edge_t*)realloc(array, sizeof(int) * (strlen(token)+1));
            array[i].value = atoi(token);
        }
        else if (cArray % 2 == 0){
            //*array = (edge_t*)realloc(array, sizeof(char) * (strlen(token)+1));
            array[i].eVertex = *token;
        }
        else{
            //*array = (edge_t*)realloc(array, sizeof(char) * (strlen(token)+1));
            array[i].sVertex = *token;
        }
        
    }

}

int main(){

    char* str;
    str = getInput(&str);
    edge_t* array;
    array = (edge_t*)malloc((sizeof(edge_t) * nl) * 0xfff);

    fillArray(array, str);

    int i = 0;
    for (i; i < nl; i++){

        printf("%c, %c, %d\n", array[i].sVertex, array[i].eVertex, array[i].value);

    }

    return 0;

}
