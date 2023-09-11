#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct binary_tree{
    int item;
    int profundidade;
    struct binary_tree* left;
    struct binary_tree* right;
}ROOT;

ROOT* create_new_binary_tree(int item, ROOT* right, ROOT* left){
    ROOT* new_binary_tree = (ROOT*) malloc(sizeof(ROOT));
    new_binary_tree->item = item;
    new_binary_tree->left = left;
    new_binary_tree->right = right;
    return new_binary_tree;
}

ROOT *create_tree(char string[], int *i){
    if(*i == strlen(string)) return NULL;
    while(string[*i] == '(' || string[*i] == ' ') (*i)++;

    if(string[*i] == ')'){
        while(string[*i] == ')') (*i)++;
        return NULL;
    }
    char n[1000];
    int j = 0;
    while(string[*i] >= '0' && string[*i] <= '9'){
        n[j] = string[*i];
        (*i)++;
        j++;
    }
    n[j] = '\0';
    int item = atoi(n);
    return create_new_binary_tree(item, create_tree(string, i), create_tree(string, i));
}

void calcular_profundidade(ROOT *arvore, int contador){
    if(arvore == NULL) return;
    else{
        arvore->profundidade = contador;
        calcular_profundidade(arvore->left, contador + 1);
        calcular_profundidade(arvore->right, contador + 1);
    }
    return;
}

void profundidade(ROOT *arvore, int item, ROOT **procurado){

    if(arvore == NULL){
        return;
    }
    if(arvore->item == item){
        *procurado = arvore;
        return;
    }
    else{
        if(arvore->left == NULL){
            profundidade(arvore->right, item, procurado);
        }
        else if(arvore->right == NULL){
            profundidade(arvore->left, item, procurado);
        }
        else{
            profundidade(arvore->right, item, procurado);
            profundidade(arvore->left, item, procurado);
        }
    }
    return;
}

void main(){
    ROOT *arvore, *node = NULL;
    char string[100];
    int valor = 0;
    int *i = &valor;
    arvore = NULL;
    scanf("%s", string);
    int no;
    arvore = create_tree(string, i);
    scanf("%d", &no);
    calcular_profundidade(arvore, 0);
    profundidade(arvore, no, &node);
    if(node == NULL){
        printf("NAO ESTA NA ARVORE\n");
        printf("-1\n");
    }
    else{
        printf("ESTA NA ARVORE\n");
        printf("%d\n", node->profundidade);
    }

}