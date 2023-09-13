#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 10;

typedef struct lista_adj{
    int item;
    struct lista_adj *next;
}lista;

typedef struct grafo{
    lista *vertices[MAX_SIZE];
    short int *visited[MAX_SIZE];
}graph;

graph *create_graph(){
    graph *new_graph = malloc(sizeof(graph));
    for(int i = 0; i < MAX_SIZE; i++){
        new_graph->vertices[i] = NULL;
        new_graph->visited[i] = 0;
    }
    return new_graph;
}