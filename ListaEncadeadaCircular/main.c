#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "ListaEncCircular.h"

int main(){

    Lista l;
    
    inicializa(&l);
    mostraLista(&l);
    printf("\n");
    inserir(1,&l);
    inserir(2,&l);
    mostraLista(&l);
    printf("\n%d\n", procurar(&l,1));
    printf("%d",retornaDaPos(&l,0));
    inserirNaPos(&l,5,0);
    mostraLista(&l);
    limpar(&l);
    mostraLista(&l);




    return 0;
}