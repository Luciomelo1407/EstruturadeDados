#include <stdio.h>
#include "ListaSequencial.h"

// Imprime na tela o status da lista
void imprimirStatus(Lista *l)
{
    printf("Tamanho = %d\n", tamanho(l));
    exibirLista(l);
    printf("\n");
}

// Testa a insercao de valores na lista
void testarInserir(Lista *l)
{
    printf("=> Teste de Inserir\n");
    int qtd;
    printf("Quantos itens deseja guardar na lista? ");
    fflush(stdin);
    scanf("%d", &qtd);

    Item item;
    for (int i = 0; i < qtd; i++)
    {
        printf("Digite o valor para a posicao [%d]: ", i);
        fflush(stdin);
        scanf("%d", &item);
        inserir(item, l);
    }

    imprimirStatus(l);
}

// Testa a insercao de valores na lista escolhendo a posicao
void testarInserirNaPos(Lista *l)
{
    printf("=> Teste de InserirNaPos\n");
    int qtd;
    printf("Quantos itens deseja inserir na lista? ");
    scanf("%d", &qtd);

    Item item;
    for (int i = 0; i < qtd; i++)
    {
        printf("Digite a posicao de insercao (de 0 a %d): ", tamanho(l));
        int p;
        scanf("%d", &p);

        printf("Digite o valor para a posicao [%d]: ", p);
        scanf("%d", &item);
        if (inserirNaPos(item, p, l))
            printf("Insercao com sucesso\n");
        else
            printf("Erro na insercao\n");

        imprimirStatus(l);
    }

}


// Testa a busca de valores na lista
void testarBuscar(Lista *l)
{
    // Testa a busca por um valor existente
    printf("=> Teste de Busca\n");
    printf("Digite o valor que deseja buscar: ");
    Item item;
    scanf("%d", &item);
    int pos = buscar(item, l);
    if (pos >= 0)
        printf("Achou na posicao: %d\n", pos);
    else
        printf("Nao achou o item na lista\n");

    // Testa a busca por uma posicao existente
    printf("Digite a posicao que deseja acessar (ou -1 para sair): ");
    int p;
    scanf("%d", &p);
    while (p != -1)
    {
        Item item = enesimo(p, l);
        printf("Achou na posicao[%d] o valor: %d\n", p, item);
        // Leitura da proxima posicao a ser acessada
        printf("Digite a posicao que deseja acessar (ou -1 para sair): ");
        scanf("%d", &p);
    }

}

// Testa a alteracao de um valor numa posicao
void testarAlterar(Lista *l)
{
    printf("=> Teste da Alteracao\n");
    int p;
    printf("Digite a posicao que deseja alterar (ou -1 para sair): ");
    scanf("%d", &p);
    while (p != -1)
    {
        // Leitura do novo valor
        printf("Digite o NOVO valor para a posicao [%d]: ", p);
        Item item;
        scanf("%d", &item);
        if (alterar(item, p, l))
            printf("Alterou com sucesso\n");
        else
            printf("Erro na alteracao\n");

        imprimirStatus(l);

        // Leitura da proxima posicao a ser acessada
        printf("Digite a posicao que deseja alterar (ou -1 para sair): ");
        scanf("%d", &p);
    }
}


int main() {
    Lista l;

    inicializa(&l);
    testarInserir(&l);
    testarInserirNaPos(&l);
    testarBuscar(&l);
    testarAlterar(&l);
    destruir(&l);
    imprimirStatus(&l);

    getchar();


    return 0;
}
