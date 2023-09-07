#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct tree{
    int item;
    struct tree *left;
    struct tree *right;
}TREE;

TREE *criar_arvore(int item){
    TREE *new_branch = (TREE*) malloc(sizeof(TREE));
    new_branch->item = item;
    new_branch->left = NULL;
    new_branch->right = NULL;

    return new_branch;
}

TREE *criar_arvore_binaria_busca(TREE* raiz, int item){
    if(raiz == NULL){
        raiz = criar_arvore(item);
    }
    else{
        if(item < raiz->item){
            raiz->left = criar_arvore_binaria_busca(raiz->left, item);
        }
        else{
            raiz->right = criar_arvore_binaria_busca(raiz->right, item);
        }
    }
    return raiz;
}

void printar_arvore(TREE* parent){
    if(parent == NULL){
        printf(" () ");
    }
    else
    {
        printf(" ( %d ", parent->item);
        printar_arvore(parent->left);
        printar_arvore(parent->right);
        printf(") ");
    }
}

int main(){
    TREE *arvore = NULL;
    int inserido;
    while(scanf("%d", &inserido) != EOF){
        printf("----\n");
        printf("Adicionando %d\n", inserido);
        printf("  ");
        arvore = criar_arvore_binaria_busca(arvore, inserido);
        printar_arvore(arvore);
        printf("\n");
    }
    printf("----\n");
    return 0;
}