#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "listaEncadeada.h"

int teste(){
    int *x = NULL;
    x = malloc(sizeof(int)); // com isso retornou 1;
    /*Quando x tem null
            entao o if da false
            ou seja ele verifica se nao 'e null
            */
    if(x){
        return 1;
    }else{
        return 0;
    }
}

void adicionar_item(Lista *l){

    inserir(1,l);
    inserir(2,l);
    inserir(3,l);
    inserir(4,l);

}

void teste_busca(Lista *l){
    printf("\n%d", buscar(3,l));

}

void teste_alterar(Lista *l){
    alterar(10,2,l);
}

void teste_remover(Lista *l){
    if(remover(3, l)){
        printf("deu bom");
    }else{
        printf("deu ruim");
    }
}

int main(){
    Lista l;
    inicializar(&l);
    adicionar_item(&l);
    mostraLista(&l);
    printf("\n");
    mostraDireiro(&l);
    teste_busca(&l);
    printf("\n");
    teste_alterar(&l);
    mostraLista(&l);
    teste_remover(&l);
    printf("\n");
    mostraLista(&l);
    printf("\n%d", l.cabeca->item);

    

    return 0;
}

