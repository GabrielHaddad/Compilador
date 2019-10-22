#include <stdio.h>
#include <stdlib.h>
#include "file.h"

int getProxChar(FILE *arq) {
    int c = fgetc(arq);
    if (c != EOF){
        return c;
    }
    return -1;
}
