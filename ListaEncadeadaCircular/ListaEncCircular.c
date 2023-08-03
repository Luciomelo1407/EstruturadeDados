#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "ListaEncCircular.h"

void inicializa(Lista* l){
    l->cabeca = (No*)malloc(sizeof(No));
    // l->cabeca = NULL;
    l->cabeca->prox = l->cabeca;
    l->tamanho = 0;

    if(!(l->cabeca)){
        exit(EXIT_FAILURE);
    }
}

No* criaNo(Item item, No* prox){

    No* novoNo = malloc(sizeof(No));
    novoNo->prox = prox;
    novoNo->item = item;
    return novoNo;

}

bool inserir(Item item, Lista *l){
    l->cabeca->prox = criaNo(item, l->cabeca->prox);
    l->tamanho++;
    if(l->cabeca->prox){
        return true;
    }else{
        exit(EXIT_FAILURE);
    }
}

void mostraLista(Lista *l){
    No* swap = l->cabeca->prox;

    printf("[");
    while(!(swap == l->cabeca)){
        printf("%d",swap->item);
        if(!(swap->prox == l->cabeca)){
            printf(", ");
        }
        swap = swap->prox;
    }
    printf("]");

}

int procurar(Lista *l, Item item){

    int pos;
    No* swap = l->cabeca->prox;
    for(pos = 0; swap != l->cabeca ;pos++){
        if(swap->item == item){
            return pos;
        }
        swap = swap->prox;
    }

    return -1;
}

Item retornaDaPos(Lista *l, int pos){

    No* swap = l->cabeca->prox;
    for(int i = 0; i!= pos;i++ ){
        swap = swap->prox;
    }

    return swap->item;

}

bool inserirNaPos(Lista *l, Item item, int pos){
    
    No* swap = l->cabeca->prox;

    if(pos == 0){
        l->cabeca->prox = criaNo(item, l->cabeca->prox);
    }else{
        for(int i = 0; i<pos - 1;i++){
            swap = swap->prox;
        }
        swap->prox = criaNo(item, swap->prox);
    }

}

void limpar(Lista *l){

    No* swap = l->cabeca->prox;
    No* prox;
    while(swap!=l->cabeca){
        prox = swap->prox;
        free(swap);
        swap = prox;
    }
    l->cabeca->prox = prox;
    l->tamanho = 0;
}

void destruir(Lista *l){
    free(l->cabeca);
    free(l);
}
