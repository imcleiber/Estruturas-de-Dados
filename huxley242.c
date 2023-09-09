#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct no{
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
        new_table->table[i] = malloc(sizeof(ELEMENTO));
        new_table->table[i]->lista = NULL;
    }
    return new_table;
}

int hash(int id, int table_size){
    return id % table_size;
}

void put(HT *hash_table, int key, int size){
    int h = hash(key, size);
    NO *new_node = criar_no(key, NULL);
    if(hash_table->table[h]->lista == NULL){
        hash_table->table[h]->lista = new_node;
    }
    else{
        NO *aux = hash_table->table[h]->lista;
        if(aux != NULL){
            while(aux->prox != NULL){
                aux = aux->prox;
            }
            aux->prox = new_node;
        }
    }
}

void print_hash_table(HT *ht, int size){
    for(int i = 0; i < size; i++){
        printf("%d -> ", i);
        NO *aux = ht->table[i]->lista;
        while(aux != NULL){
            printf("%d -> ", aux->index);
            aux = aux->prox;
        }
        printf("\\");
        printf("\n");
    }
}

void main(){
    int n_tables;
    scanf("%d", &n_tables);
    for(int i = 0; i < n_tables; i++){
        int size, lidos;
        scanf("%d %d", &size, &lidos);
        HT *tabela;
        tabela = create_hash_table(size);
        for(int j = 0; j < lidos; j++){
            int lido;
            scanf("%d", &lido);
            put(tabela, lido, size);
        }
        print_hash_table(tabela, size);
        for(int k = 0; k < size; k++){
            free(tabela->table[k]->lista);
            free(tabela->table[k]);
        }
        free(tabela);
        if(i < n_tables - 1){
            printf("\n");
        }
    }
}