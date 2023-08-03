#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef int Item;

typedef struct estrutura{
    Item item;
    struct estrutura *prox; 
}No;

typedef struct {
    No* cabeca;
    int tamanho;
}Lista;

void inicializar(Lista *l);

int tamanho(Lista *l);

No* criaNo(Item item, No* prox);

bool inserir(Item item, Lista *l);

void mostraLista(Lista *l);

void mostraDireiro( Lista *l);

int compara(Item x, Item y);

bool vazia(Lista *l);

int buscar(Item item, Lista *l);

bool alterar(Item item, int pos, Lista *l);

bool inserirNaPos(Item item, int pos, Lista *l);

bool remover(Item item, Lista *l);

void limpar(Lista *l);

void destruir(Lista *l);

