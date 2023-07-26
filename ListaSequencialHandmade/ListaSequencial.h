#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#ifndef LISTA_SEQ_ESTATICA
#define LISTA_SEQ_ESTATICA

#define MAX 1000

typedef int Item;

typedef struct {
    Item item[MAX];
    int tamanho;
}Lista;

void inicializa(Lista *l);

int compara(Item x, Item y);

bool igual(Item x, Item y);

int tamanho(Lista *l);

bool cheia(int tamanho);

bool vazia(int tamanho);

bool inserir(Item x, Lista *l);

int buscar(Item x,Lista *l);

Item enesimo(int x, Lista*l);

bool inserirNaPos(Item x,int pos, Lista *l);

bool remover(Item x, Lista *l);

Item exibirItem(int posicao, Lista *l);

void exibirLista(Lista *l);

void limpar(Lista *l);

void destruir(Lista *l);

bool alterar(Item item, int pos, Lista *l);

#endif // LISTA_SEQ_ESTATICA
