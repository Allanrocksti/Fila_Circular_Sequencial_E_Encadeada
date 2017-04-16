#include <stdio.h>
#include <stdlib.h>

void limpa_tela(){
    system("pause");
    system("cls");
}

typedef struct elementos{

    char nome_pessoa[256];

}t_elemento;

typedef struct no{

    t_elemento dado;
    struct no *prox;

}t_no;

typedef struct fila{

    t_no *inicio;
    int quant_elementos;
    t_no *final;

}t_fila;

t_fila *criar_cabeca(){

    t_fila *fila = (t_fila*) malloc(sizeof(t_fila));

    if(fila){
        fila->inicio = fila->final = NULL;
        fila->quant_elementos = 0;    
    }

    return fila;

}

t_no *criar_no(){
    t_no *no = (t_no*) malloc(sizeof(t_no));

    if(no)
        no->prox = NULL;

    return no;

}

int isVazia(t_fila *fila){
    return (fila->quant_elementos == 0);
}

void print_fila_ordem(t_fila *fila){

    int i = 0;

    printf("Ordem da fila: \n\n");

    while((fila->inicio) != NULL){
        printf("%d - %s\n", i+1, fila->inicio->dado.nome_pessoa);
        fila->inicio = fila->inicio->prox;
        i++;
    }

    printf("\n");

}

int inserir(t_fila *fila, t_elemento valor){
    
    t_no *novo = criar_no();
    
    if(novo == NULL)
        return 0;

    novo->dado = valor;

    if(isVazia(fila))
        fila->inicio = novo;
    else
        (fila->final)->prox = novo;

    fila->final = novo;
    (fila->quant_elementos)++;
    return 1;

}

// função para adicionar 4 pessoas
void entrar_4(t_fila *fila, t_elemento lista){

    int i;

    for(i = 0; i < 4; i++){

        printf("Digite o nome para entrar na fila: ");
        gets(lista.nome_pessoa);
        inserir(fila, lista);

    }

}

int main(){

    t_elemento temp;
    t_fila *fila = criar_cabeca();

    entrar_4(fila, temp);
    limpa_tela();
    
    print_fila_ordem(fila);
    limpa_tela();
    return 0;
}