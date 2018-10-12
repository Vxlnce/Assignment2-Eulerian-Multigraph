#include "list.h"
#include "stage0.h"

int minValue = INT_MAX;
int maxValue = INT_MIN;
int totValue = 0;
int oddVertex = 0;
int evenVertex = 0;

// simple version of this -> https://bit.ly/2QG9aAD
bool isEulerianCycle(){

    if(!oddVertex){return true;}
    return false;

}

bool isEulerianPath(){

    if(oddVertex == 2){return true;}
    return false;

}

int findMin(int a, int b){

    return (a < b) ? a : b;

}

int findMax(int a, int b){

    return (a > b) ? a : b;

}

void stage0(edge_t* arrEdge, vertex_t arrVertex){
    
    /* consts */
    const char* eulerian = "S0: Multigraph is Eulerian";
    const char* transversible = "S0: Multigraph is traversable";

    int i;
    // value finding
    for (i = 0; i < cNewline; i++){

        totValue += arrEdge[i].value;
        minValue = findMin(minValue, arrEdge[i].value);
        maxValue = findMax(maxValue, arrEdge[i].value);

    }
    // degree finding
    for (i = 0; i < nVertex; i++){

        // TODO.: fix degrees in first value in stdin FIXED
        if (arrVertex.degree[i] % 2 == 0){evenVertex++;}
        else{oddVertex++;}

    }
    
    puts("Stage 0 Output");
    puts("--------------");
    
    printf("S0: Map is composed of %d vertices and %d edges\n", 
            nVertex, 
            cNewline);
    printf("S0: Min. edge value: %d\n", minValue);
    printf("S0: Max. edge value: %d\n", maxValue);
    printf("S0: Total value of edges: %d\n", totValue);
    printf("S0: Route starts at \"%c\"\n", startingPoint);
    printf("S0: Number of vertices with odd degree: %d\n", oddVertex);
    printf("S0: Number of vertices with even degree: %d\n", evenVertex);
    if (isEulerianCycle()){puts(eulerian);}
    else if (isEulerianPath()){puts(transversible);}
    else{exit(EXIT_FAILURE);}

}