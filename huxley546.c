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
ROOT* create_new_binary_tree(int item, ROOT* left, ROOT* right){
    ROOT* new_binary_tree = (ROOT*) malloc(sizeof(ROOT));
    new_binary_tree->item = item;
    new_binary_tree->left = left;
    new_binary_tree->right = right;
    return new_binary_tree;
}
int is_binary_search_tree(ROOT* parent, int raiz, int previous){
    int ver;
    if(parent->left == NULL && parent->right == NULL){
        return 1;
    }
    else{
        if(parent->left != NULL){
            if(parent->item < parent->left->item || previous < parent->left->item || raiz < parent->left->item) return 0;
            ver = is_binary_search_tree(parent->left, raiz, parent->item);
            //if(ver > parent->item) return 0;
            if(ver == 0) return 0;
        }
        if(parent->right != NULL){
            if(parent->item > parent->right->item || previous > parent->right->item || raiz > parent->right->item) return 0;
            ver = is_binary_search_tree(parent->right, raiz, parent->item);
            //if(ver < parent->item) return 0;
            if(ver == 0) return 0; 
        }
        
    }
    return 1;
}
ROOT *create_tree(char *string, int *i){
    if(*i == strlen(string)) return 0;
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
    char arv[1000];
    int *i = 0;
    char *valores;
    arvore = create_empty_binary_tree();
    scanf("%s", arv);
    int verification;
    arvore = create_tree(arv, i);
    verification = is_binary_search_tree(arvore, arvore->item, arvore->item);
    if(verification == 1) printf("VERDADEIRO");
    if(verification == 0) printf("FALSO");

}