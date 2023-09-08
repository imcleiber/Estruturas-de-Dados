#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct no{
    int item;
    struct no *prox;
}NO;

typedef struct elemento{
    NO *lista;
    int index;
}ELEMENTO;

typedef struct hash_table{
    ELEMENTO * table[257];
}