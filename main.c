#include <stdio.h>
#include "list.h"

int main() {
    buildList();

    char** array = getInput();
    stage0(array);

    // printf("%i\n", stringLength);

    return 0;

}
