#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

typedef struct node{
    int item;
    struct lista *next;
}NODE;

typedef struct lista{
    NODE *head;
    NODE *tail;
} LISTA;

typedef struct elemento{
    LISTA *lista;
    struct elemento *next;
}ELEMENT;

typedef struct pilha{
    ELEMENT *top;
}STACK;

void print_list(NODE *lista){
    NODE *aux = lista;
    while(aux->next != NULL){
        printf("%d ", aux->item);
        aux = aux->next;
    }
    printf(" %d\n", aux->item);
    return;
}

STACK *create_stack(){
    STACK *new_stack = malloc(sizeof(STACK));
    new_stack->top = NULL;
    return new_stack;
}

void add_tail(LISTA *lista, int item){
    NODE *new_node = malloc(sizeof(NODE));
    if(lista->tail == NULL){
        new_node->item = item;
        new_node->next = NULL;
        lista->head = new_node;
        lista->tail = new_node;
    }
    else{
        new_node->next = NULL;
        new_node->item = item;
        lista->tail->next = new_node;
        lista->tail = lista->tail->next;
    }
    return;
}

void push(STACK *pilha, ELEMENT *item){
    NODE *new_top = malloc(sizeof(NODE));
    new_top->item = item;
    new_top->next = pilha->top;
    pilha->top = new_top;
    return;
}

bool is_empty(STACK *pilha){
    if(pilha->top == NULL){
        return true;
    }
    else{
        return false;
    }
}

void pop(STACK *pilha){
    if(is_empty(pilha)){
        printf("EMPTY STACK\n");
    }
    else{
        ELEMENT *retirar;
        retirar = pilha->top;
        print_lista(retirar->lista)
        pilha->top = pilha->top->next;
        free(retirar);
    }
    return;
}