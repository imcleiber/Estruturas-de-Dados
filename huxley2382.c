#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct binary_tree{
    int item;
    struct binary_tree* left;
    struct binary_tree* right;
}ROOT;

ROOT *create_empty_binary_tree(){
    return NULL;
}
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
void altura_folhas(ROOT *arvore, int *verification, int altura_max, int altura_atual){
    if(*verification == -1){
        return;
    }
    if(arvore->left == NULL && arvore->right == NULL){
        if(altura_max != altura_atual){
            *verification = -1;
        }
        return;
    }
    else{
        altura_folhas(arvore->left, verification, altura_max, altura_atual + 1);
        altura_folhas(arvore->right, verification, altura_max, altura_atual + 1);
    }
    return;
}
void is_complete(ROOT *arvore, int *size, int array[], int *verification, int *contador, int *altura_max, int altura_atual){
    if(arvore == NULL){
        return;
    }
    if(arvore->left == NULL && arvore->right == NULL){
        (*contador)++;
        *altura_max = altura_atual;
        return;
    }
    else if(arvore->right == NULL){
        *verification = -1;
        is_complete(arvore->left, size, array, verification, contador, altura_max, altura_atual + 1);
        array[*size] = arvore->item;
        (*size)++;
    }
    else if(arvore->left == NULL){
        *verification = -1;
        array[*size] = arvore->item;
        (*size)++;
        is_complete(arvore->right, size, array, verification, contador, altura_max, altura_atual + 1);
    }
    else{
        (*contador)++;
        is_complete(arvore->left, size, array, verification, contador, altura_max, altura_atual + 1);
        is_complete(arvore->right, size, array, verification, contador, altura_max, altura_atual + 1);
    }

    return;
}
void main(){
    ROOT *arvore = create_empty_binary_tree();
    char string[100];
    int valor = 0, *i = &valor;
    scanf("%s", string);
    arvore = create_tree(string, i);

    int *size, *verification, *contador, *altura_maxima, nodes[100];
    size = malloc(sizeof(int));
    verification = malloc(sizeof(int));
    contador = malloc(sizeof(int));
    altura_maxima = malloc(sizeof(int));
    *altura_maxima = 0;
    *size = 0;
    *verification = 1;
    *contador = 0;
    
    is_complete(arvore, size, nodes, verification, contador, altura_maxima, 0);
    altura_folhas(arvore, verification, *altura_maxima, 0);
    if(*verification == -1){
        printf("nao completa\n");
        printf("nos com um filho: ");
        for(int j = 0 ; j < *size; j++){
            if(j + 1 == *size){
                printf("%d\n", nodes[j]);
            }
            else{
                printf("%d ", nodes[j]);
            }
        }
    }
    else{
        printf("completa\n");
        printf("total de nos: %d\n", *contador);
    }
}