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

ROOT *calcular_profundidade(ROOT *arvore, int contador){
    if(arvore == NULL) return NULL;
    if(arvore->left == NULL && arvore->right == NULL){
        arvore->profundidade = contador;
    }
    else{
        if(arvore->left == NULL){
            arvore->profundidade = contador;
            arvore = calcular_profundidade(arvore->right, contador + 1);
        }
        else if(arvore->right == NULL){
            arvore->profundidade = contador;
            arvore = calcular_profundidade(arvore->left, contador + 1);
        }
        else{
            arvore->profundidade = contador;
            arvore = calcular_profundidade(arvore->left, contador + 1);
            arvore = calcular_profundidade(arvore->right, contador + 1);
        }
        
    }
    return arvore;
}

ROOT *profundidade(ROOT *arvore, int item){

    if(arvore == NULL || arvore->item == item){
        return arvore;
    }
    else{
        if(profundidade(arvore->left, item) == NULL){
            if(profundidade (arvore->right, item) == NULL);
            else{
                arvore = profundidade(arvore->right, item);
            }
        }
        else{
            arvore = profundidade(arvore->left, item);
        }
    }
    return arvore;
}

void main(){
    ROOT *arvore, *node;
    char string[100];
    int valor = 0;
    int *i = &valor;
    arvore = NULL;
    scanf("%s", string);
    int no;
    arvore = create_tree(string, i);
    scanf("%d", &no);
    arvore = calcular_profundidade(arvore, 0);
    node = profundidade(arvore, no);
    if(arvore == NULL) printf("NAO ESTA NA ARVORE\n");
    else{
        printf("ESTA NA ARVORE\n");
        printf("%d\n", arvore->profundidade);
    }

}