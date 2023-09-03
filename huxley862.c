#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LISTA{
    char item;
    struct LISTA* next;
}LISTA;

LISTA *add(LISTA *head, char item)
{
    LISTA* new_head = (LISTA*) malloc(sizeof(LISTA));
    new_head->item = item;
    new_head->next = head;
    return new_head;
}
void maiorseq(LISTA *head){
    int indice = 0;
    int inicio = 0;
    int possivel_inicio = 0;
    int possivel_tam = 0; 
    int tamanho = 0;

    while(head != NULL){
        if(head->item == '0'){
            possivel_inicio = indice;
            ++indice;
            head = head->next;
            while(head != NULL){
                if(head->item == '0'){
                    ++possivel_tam;
                    ++indice;
                    head = head->next;
                }
                else{
                    ++indice;
                    head = head->next;
                    break;
                }
            }
        }
        else
        {
            ++indice;
            head = head->next;
        }
        if(possivel_tam > tamanho){
            inicio = possivel_inicio;
            tamanho = possivel_tam;
            possivel_tam = 0;
        }
         
    }

    printf("%i %i\n", inicio, inicio + tamanho);
    return;
}
void main()
{
    LISTA *head1 = NULL, *head2 = NULL;
    char sequencia [50];
    char caractere;
    int inicio_da_sequencia = 0;
    while(1){
        int i = 0;
        scanf("%s", sequencia);
        if(sequencia[i + 1] == '\0') break;
        while(sequencia[i] != '\0'){
            head1 = add(head1, sequencia[i]);
            ++i;
        }
        while(head1 != NULL){
            head2 = add(head2, head1->item);
            head1 = head1->next;
        }
        maiorseq(head2);
        free(head1);
        free(head2);
    }
    return;
}