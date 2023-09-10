#include <stdio.h>
#include <stdlib.h>
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
int is_binary_search_tree(ROOT* parent){
    if(parent == NULL){
        return 1;
    }
    if(parent->left == NULL && parent->right == NULL){
        return 1;
    }
    else if(parent->left == NULL){
        if(parent->right->item < parent->item){
            return 0;
        }
    }
    else if(parent->right == NULL){
        if(parent->left->item > parent->item){
            return 0;
        }
    }
    else{
        return 0;
    }


    return is_binary_search_tree(parent->left) && is_binary_search_tree(parent->right);
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
void main(){
    ROOT* arvore;
    char arv[100];
    int valor = 0;
    int *i = &valor;
    arvore = NULL;
    scanf("%s", arv);
    int verification;
    arvore = create_tree(arv, i);
    verification = is_binary_search_tree(arvore);
    if(verification == 1) printf("VERDADEIRO\n");
    if(verification == 0) printf("FALSO\n");

}