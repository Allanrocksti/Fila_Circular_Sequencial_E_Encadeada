#include <stdio.h>
#include <stdlib.h>
#define MAX 5

void limpa_tela(){
    system("pause");
    system("cls");
}

typedef struct elementos{

    char nome_pessoa[256];

}t_elemento;

typedef struct fila{

    t_elemento vetor[MAX];
    int inicio;
    int fim;
    int quant_elementos;

}t_fila;

t_fila criar_t_fila(){

    t_fila fila;

    fila.inicio = 0;
    fila.fim = -1;
    fila.quant_elementos = 0;

    return fila;

}

int isCheia(t_fila *fila){
    return (fila->quant_elementos == MAX);
}

void print_fila_ordem(t_fila *fila){

    int i, contador = 0;
    
    printf("Ordem da fila: \n\n");

    if(isCheia(fila)){
        printf("%d - %s\n", contador+1, fila->vetor[(fila->inicio)++].nome_pessoa);
        contador++;
    }
    
    for (i = fila->inicio; i != (fila->fim + 1) % MAX; i = (i + 1) % MAX){
        printf("%d - %s\n", contador+1, fila->vetor[i].nome_pessoa);
        contador++;
    }

    printf("\n");

}

int inserir(t_fila *fila, t_elemento valor){
    
    if(isCheia(fila))
        return 0;

    (fila->quant_elementos)++;
    fila->fim = (fila->fim + 1) % MAX;
    fila->vetor[fila->fim] = valor;

    return 1;

}

t_elemento remover(t_fila *fila){

    t_elemento valor = { "" };

    valor = fila->vetor[fila->inicio];
    fila->vetor[fila->inicio].nome_pessoa[0] = '\0';
    (fila->quant_elementos)--;
    fila->inicio = (fila->inicio + 1) % MAX;

    return valor;

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

// função para retirar 3 pessoas
void sair_3(t_fila *fila){

    int i;

    for(i = 0; i < 3; i++){
        printf("%s Saiu!\n\n", fila->vetor[fila->inicio].nome_pessoa);
        remover(fila);
        print_fila_ordem(fila);
    }

}

int main(){

    t_elemento temp;
    t_fila fila = criar_t_fila();

    entrar_4(&fila, temp);
    limpa_tela();

    print_fila_ordem(&fila);
    limpa_tela();

    sair_3(&fila);
    limpa_tela();

    entrar_4(&fila, temp);
    limpa_tela();

    print_fila_ordem(&fila);
    limpa_tela();

    return 0;
}