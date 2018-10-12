#include "stage1.h"

vec_t travelledEdge;

// return index of edge, if not found returns -1
int findEdgePosFromVerteces(char vert1, char vert2, edge_t* arrEdge){
    
    int i;
    for (i = 0; i < cNewline; i++){
        bool edgeCase1 = (arrEdge[i].sVertex == vert1 &&
         arrEdge[i].eVertex == vert2);

        bool edgeCase2 = (arrEdge[i].sVertex == vert2 &&
         arrEdge[i].eVertex == vert1);

        if (edgeCase1 || edgeCase2){
            return i;
        }

    }
    
    return -1; // not found

}

void initTravelledEdge(){

    travelledEdge.length = 0;
    travelledEdge.array = (int*)malloc(sizeof(int) * cNewline);

}


bool isTravelled(int edgePos){

    int i;
    for (i = 0; i < travelledEdge.length; i++){
        if (travelledEdge.array[i] = edgePos){return true;}
        else {return false;}
    }

}


int findLowestDegree(char vertex, 
                    int degreeOfVertex,
                    edge_t* arrEdge){

    int i;

    bool isConnectedVertex;
    vec_t connectedVertex;

    // init array of connected vertices
    connectedVertex.array = (int*)malloc(sizeof(int) * degreeOfVertex);
    connectedVertex.length = 0;

    for (i = 0; i < cNewline; i++){

        isConnectedVertex = 
            (vertex == arrEdge[i].sVertex ||
             vertex == arrEdge[i].eVertex);

        if (isConnectedVertex){

            if (!isTravelled(i)){

                connectedVertex.array[connectedVertex.length] = i;

            }

        }

    }

    int smallestValue = INT_MAX;
    for (i = 0; i < connectedVertex.length; i++){
        int position = connectedVertex.array[i];
        int _value = arrEdge[position].value;
        smallestValue = findMin(smallestValue, _value);

    }

    return smallestValue;

}



void smallestValuePath(char startVertex, vertex_t arrVertex, edge_t* arrEdge){ // take smallest value each time

    int completeLoop = 0;

    char currentVertex = startVertex;
    int currentDegree;
    int currentVertexToStart = findEdgePosFromVerteces(currentVertex,
                                                         startVertex, 
                                                         arrEdge);
    if (currentVertexToStart != -1){

        if (!isTravelled(currentVertexToStart)){

            currentVertex = startVertex;
            completeLoop = 1;

        }

    }

    // find current degree of vertex
    int i;
    for (i = 0; i < strlen(arrVertex.vertex); i++){

        if (currentVertex == arrVertex.vertex[i]){

            currentDegree = arrVertex.degree[i];
            break;

        }

    }


    int smallestValue = findLowestDegree(currentVertex, currentDegree, arrEdge);
    

}

void stage1(){



}