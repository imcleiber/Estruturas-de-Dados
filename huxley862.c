#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LISTA{
    int item;
    struct LISTA* next;
}LISTA;

LISTA add(LISTA head, int item)
{
    LISTA* new_head = (LISTA*) malloc(sizeof(LISTA));
    new_head.item = item;
    new_head.next = head;
    return new_head;
}
void maiorseq(LISTA head);{

}
void main()
{
    LISTA* head = NULL;
    
}