#include "list.h"
#include <string.h>

#pragma region data_processing
// stdin to char*
char* getInput() {

    char* inArr = (char*)malloc(sizeof(char));
	int i = 0;

	char c;

	while((c = getchar()) != EOF) {

		inArr[i] = c;
		i++;
        inArr = (char*)realloc(inArr, sizeof(char));

	}
    printf ("%s\n", inArr);
	return inArr;

}
// putting info about multigraph into a linked list
list_t* buildList() {

    // pre malloc'd in fn...
    list_t* list = make_empty_list();
    assert(is_empty_list(list));

    return list;

}
#pragma endregion getting input from stdin and building list

void stage0(char* input){

    int i = 0, j = 0, cEdge = 0, cVertex = 0;
    char* fVertex = (char*)malloc(sizeof(char));

    for (i = 0; i < strlen(input); i++) {

        if (input[i] == '\n') { cEdge++;printf("%d", cEdge); }

        if (!(input[i] == '\n')) {

            for (j; j < strlen(fVertex); j++) {

                if (fVertex[j] == input[i]) { continue; }
                else {

                    cVertex++;
                    fVertex = (char*)realloc(fVertex, sizeof(char));
                    printf("%d", cVertex);

                }

            }

        }

    }

    printf("\ncEdge: %i, cVertex: %i, fVertex: %s\n", cEdge, cVertex, fVertex);

}
