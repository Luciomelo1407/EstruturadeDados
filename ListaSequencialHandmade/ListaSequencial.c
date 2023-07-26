#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "ListaSequencial.h"

void inicializa(Lista *l){
    l->tamanho = 0;
}

int compara(Item x, Item y){
    if(x > y){
        return 1;
    }
    if(igual(x,y)){
        return 0;
    }
    if(y > x){
        return -1;
    }
}

bool igual(Item x, Item y){
    if(x == y){
        return true;
    }else{
        return false;
    }
}

int tamanho(Lista *l){
    return l->tamanho;
}

bool cheia(int tamanho){
    if(tamanho == MAX){
        return true;
    }else{
        return false;
    }
}

bool vazia(int tamanho){
    if(tamanho == 0){
        return true;
    }else{
        return false;
    }
}

bool inserir(Item x, Lista *l){
    if(cheia(tamanho(l))){
        return false;
    }else{
        l->item[l->tamanho++] = x;
        return true;
    }
}

int buscar(Item x,Lista *l){
    for(int i = 0; i < tamanho(l); i++){
        if(l->item[i] == x){
            return i;
        }
    }
    return -1;
}

Item enesimo(int x, Lista*l){
    return l->item[x];
}

bool alterar(Item x,int pos, Lista *l){
    if(pos >=0 && pos <= tamanho(l)){
        l->item[pos] = x;
        return true;
    }else{
        return false;
    }
}

bool remover(Item x, Lista *l){
    int elpos = buscar(x, l);
    if(elpos >= 0){
        for (int i = elpos; i < tamanho(l); i++) {
            l->item[i] = l->item[i + 1];
        }
        l->tamanho--;
        return true;
    }else{
        return false;
    }

}

bool inserirNaPos(Item item, int i, Lista *l)
{
    // A posicao tem que estar entre 0 e MAX-1 e ate o tamanho atual
    if ((tamanho(l) >= MAX) || (i < 0) || (i > tamanho(l)))
        return false; // lista cheia ou indice invalido

    // Se for inserido no meio, e necessario abrir espaco para o item
    for (int j = tamanho(l); j > i; j--)
        l->item[j] = l->item[j-1];

    // Coloca o item em um espaco vago e ajusta o tamanho
    l->item[i] = item;
    l->tamanho++;
    return true;
}



Item exibirItem(int posicao, Lista *l){
    return l->item[posicao];
}

void exibirLista(Lista *l){
    printf("[");
    for(int i = 0; i < l->tamanho; i++){
        printf("%d", l->item[i]);
        if(i + 1 < tamanho(l)){
            printf(", ");
        }
    }
    printf("]");
}

void limpar(Lista *l){
    l->tamanho = 0;
}

void destruir(Lista *l){
    free(l);
}

