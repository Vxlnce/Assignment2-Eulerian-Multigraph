#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* externs */
extern char startingPoint;
extern size_t stringLength;
extern size_t cNewline; // == no. of edges on the multigraph
extern size_t nVertex; // total number of vertices in the graph

/* type definitions ----------------------------------------------------------*/

typedef int data_t;

typedef struct node node_t;

typedef struct edge {

	int value;
	char sVertex;
	char eVertex;

} edge_t;

typedef struct vertex {

	size_t degree;
	char vertex;

} vertex_t;

struct node {
	data_t data;
	node_t *next;
};

typedef struct list {
	node_t *head;
	node_t *foot;
} list_t;

/* end type definitions ------------------------------------------------------*/

/* function prototypes -------------------------------------------------------*/

// list operations
list_t *make_empty_list(void);
int    is_empty_list(list_t*);
void   free_list(list_t*);
list_t *insert_at_head(list_t*, data_t);
list_t *insert_at_foot(list_t *list, data_t value);
data_t get_head(list_t *list);
list_t *get_tail(list_t *list);
void delimInput(char* input, edge_t* delim);

// stage0
char* getInput();
list_t* buildList();
void stage0(char** input);

/* end function prototypes ---------------------------------------------------*/
