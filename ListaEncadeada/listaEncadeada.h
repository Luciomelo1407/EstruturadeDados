
typedef int Item;

typedef struct estrutura{
    Item item;
    struct estrutura *prox; 
}No;

typedef struct {
    No* cabeca;
    int tamanho;
}Lista;

