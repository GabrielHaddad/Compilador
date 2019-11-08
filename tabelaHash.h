#ifndef TABELAHASH_H_INCLUDED
#define TABELAHASH_H_INCLUDED

#define HASH_SIZE 1427
#include "file.h"

struct hash {
    int size;
    struct Token **token;
};


struct hash* criaHash();
int hashCode(int key);
int insereHash(struct hash* ha, struct Token* token);
int procuraHash(struct hash* ha, int value);

#endif // TABELAHASH_H_INCLUDED
