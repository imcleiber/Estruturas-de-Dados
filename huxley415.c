#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista{
    char caractere;
    struct lista *prox;
}NODE;
typedef struct pilha{
    NODE *topo;
}PILHA;

PILHA *criar_pilha(){
    PILHA *p = malloc(sizeof(PILHA));
    p->topo = NULL;
    return p;
}
NODE *criar_no(char item){
    NODE *new_node = malloc(sizeof(NODE));
    new_node->caractere = item;
    new_node->prox = NULL;
    return new_node;
}
void push(PILHA *p, char item){
    if(p->topo == NULL){
        p->topo = criar_no(item);
    }
    else
    {
        NODE *no = criar_no(item);
        no->prox = p->topo;
        p->topo = no;
    }
    return;
}
NODE *pop(PILHA *p){
    if(p->topo == NULL){
        return NULL;
    }
    else{
        NODE *no = p->topo;
        p->topo = p->topo->prox;
        no->prox = NULL;
        return no;
    }
}
void liberar_pilha(PILHA *p){
    NODE *aux, *aux2 = p->topo;
    while(aux2 != NULL){
        aux = aux2;
        aux2 = aux2->prox;
        free(aux);
    }
    free(p);
}
int verificar(char expressao[]){
    int verifica = 1;
    NODE *compara;

    PILHA *p = criar_pilha();
    for(int i = 0; expressao[i] != '\0'; i++){
        printf("#%c# ", expressao[i]);
        if(expressao[i] == ' '){
            continue;
        }
        if(expressao[i] == '(' || expressao[i] == '['){
            push(p, expressao[i]);
        }
        else{
            compara = pop(p);
            //printf("#%c#\n", compara->caractere);
            if(compara == NULL){
                verifica = 0;
                break;
            }
            if(expressao[i] == ')' && compara->caractere != '('){
                verifica = 0;
                break;
            }
            else if(expressao[i] == ']' && compara->caractere != '['){
                verifica = 0;
                break;
            }
            else continue;
        }
    }
    if(p->topo != NULL){
        verifica = 0;
    }
    liberar_pilha(p);
    return verifica;
}
void main(){
    int expressoes, j = 0, i = 0;
    char expressao[100];
    scanf("%d", &expressoes);
    while(j < expressoes){
        getchar();
        do{
            expressao[i] = getchar();
            i++;
        }while(expressao[i-1] != '\n');
        expressao[i-1] = '\0';
        if(verificar(expressao)){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        } 

        ++j;
    }
}