#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef int Item;

typedef struct{
    Item item;
    struct No* prox;
}No;

typedef struct{
    No* cabeca;
    int tamanho;
}Lista;


void inicializa(Lista* l);

No* criaNo(Item item, No* prox);

bool inserir(Item item, Lista *l);

void mostraLista(Lista *l);

int procurar(Lista *l, Item item);

Item retornaDaPos(Lista *l, int pos);

bool inserirNaPos(Lista *l, Item item, int pos);

void limpar(Lista *l);

void destruir(Lista *l);
