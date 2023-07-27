#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "listaEncadeada.h"

// const char file[] = "C:\\Users\\PC_Beebop\\Desktop\\Atividades EDD\\vscode\\ListaEncadeada\\arquvinho.txt";


void inicializar(Lista *l){
    l->cabeca = NULL;
    l->tamanho = 0;
}

int tamanho(Lista *l){
    return l->tamanho;
}

No* criaNo(Item item, No* prox){
    No* novoNo = malloc(sizeof(No));
    if(novoNo){
        novoNo->item = item;
        novoNo->prox = prox;
        return novoNo;
    }
}

bool inserir(Item item, Lista *l){
    l->cabeca = criaNo(item, l->cabeca);
    if(l->cabeca){
        l->tamanho++;
        return true;
    }
    return false;
}

void mostraLista(Lista *l){
    printf("[");
    No* no = l->cabeca;
    for(int i = 0; i< tamanho(l); i++){
        printf("%d", no->item);
        no = no->prox;
        if(i + 1 < tamanho(l)){
            printf(", ");
            
        }
    }
    printf("]");

}

void mostraDireiro( Lista *l){
    Lista l2;
    inicializar(&l2);
    No* no = l->cabeca;
    
    for(int i = 0; i< tamanho(l); i++){
        inserir(no->item, &l2);
        no = no->prox;
    }
    

    printf("[");
    no = l2.cabeca;
    for(int i = 0; i< tamanho(&l2); i++){
        printf("%d", no->item);
        no = no->prox;
        if(i + 1 < tamanho(&l2)){
            printf(", ");
            
        }
    }
    printf("]");


    
}

int compara(Item x, Item y){
    if(x > y){
        return 1;
    }if(x < y){
        return -1;
    }
    return 0;
}

bool ingual(Item x, Item y){

    if (compara(x,y) == 0){
        return true;
    }
    return false;
}

bool vazia(Lista *l){
    if(tamanho(l) == 0){
        return true;
    }
    return false;
}

int buscar(Item item, Lista *l){
    
    No* no = l->cabeca;

    for(int i = 0; i < tamanho(l); i++){
        if(ingual(item, no->item)){
            return i;
        }
        no = no->prox;
    }

    return -1;

}

bool inserirNaPos(Item item, int pos, Lista *l){
    
    No* no = l->cabeca;

    for(int i = 0; i < pos; i++){
        if(i == pos - 1){
            no->prox = criaNo(item, no->prox);
            l->tamanho ++;
        return true;

        }
        no = no->prox;
    }
    return false;
}

bool alterar(Item item, int pos, Lista *l){
     No* no = l->cabeca;

    for(int i = 0; i <= pos; i++){
        if(i == pos){
            no->item = item;
        return true;

        }
        no = no->prox;
    }
    return false;
}


bool remover(Item item, Lista *l){
    int pos = buscar(item, l);
    printf("\n%d\n", pos);
    if(!(pos < 0)){        
        No* no = l->cabeca;
        No* no2 = l->cabeca;

        for(int i = 0; i<= pos - 1; i++){
            if(i == pos - 2){
                no2 = no->prox;
            }
            no = no->prox;
        }
        no2->prox = no->prox;
        l->tamanho--;
        return true;
        }
    return false;

}

void limpar(Lista *l){
    No* atual = l->cabeca;
    No* prox;
    while(atual){
        prox = atual->prox;
        free(atual);
        atual = prox;
    }
    l->cabeca = NULL;
    l->tamanho = 0;
}

void destruir(Lista *l){
    limpar(l);
    free(l);
}




