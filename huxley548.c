#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

typedef struct node{
    int item;
    struct lista *next;
}NODE;

typedef struct elemento{
    NODE *lista;
    NODE *next;
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
}