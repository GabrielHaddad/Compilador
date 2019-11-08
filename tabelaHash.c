#include <stdio.h>
#include <stdlib.h>
#include "tabelaHash.h"

struct hash* criaHash() {
    int i;
    struct hash* ha = (struct hash*) malloc(sizeof(struct hash));

    ha->size = HASH_SIZE;
    ha->token = (struct Token**) malloc(HASH_SIZE * sizeof(struct Token*));

    for(i = 0; i < ha->size; i++) {
        ha->token[i] = NULL;
    }

    return ha;
}

int hashCode(int key) {
   return key % HASH_SIZE;
}

int insereHash(struct hash* ha, struct Token* token) {
   int hashIndex = hashCode(token->value);

   ha->token[hashIndex] = token;

   return 1;
}

int procuraHash(struct hash* ha, int value) {

   int hashIndex = hashCode(value);

   if(ha->token[hashIndex] != NULL) {
        return 1;
   }

   return -1;
}


