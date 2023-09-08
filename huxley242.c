#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct no{
    int item;
    int index;
    struct no *prox;
}NO;

typedef struct elemento{
    NO *lista;
}ELEMENTO;

typedef struct hash_table{
    ELEMENTO *table[257];
}HT;

NO * criar_no(int index, NO *prox){
    NO *new_node = malloc(sizeof(NO));
    new_node->index = index;
    new_node->prox = prox;

    return new_node;
}

HT *create_hash_table(int size){
    HT *new_table = malloc(sizeof(HT));
    for(int i = 0; i < size; i++){
        new_table->table[i] = NULL;
    }

    return new_table;
}

int hash(int id, int table_size){
    return id % table_size;
}

void put(HT *hash_table, int key, int size){
    int h = hash(key, size);
    if(hash_table->table[h]->lista == NULL){
        hash_table->table[h]->lista = criar_no(key, NULL);
    }
    else{
        NO *aux = hash_table->table[h]->lista->prox;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = criar_no(key, NULL);
    }
}