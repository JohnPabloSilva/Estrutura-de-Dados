#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *ante;
    struct no *prox;
}lista_c;

lista_c *criar_lista_c(){
    return NULL;
}

lista_c *criar_no(int valor){
    lista_c *novo = (lista_c*)malloc(sizeof(lista_c));
    novo -> valor = valor;
    novo -> prox = NULL;
    novo -> ante = NULL;

    return novo;
}

lista_c *inserir(lista_c *lc, int valor){

    lista_c *novo = criar_no(valor);

    if(lc){
        novo -> prox = lc -> ante;
        novo -> ante = lc;
        lc -> ante -> prox = novo;
        lc -> ante = novo;
        return lc;
    }
    else{
        return novo;
    }
}

void imprimir_c(lista_c *lc){
    lista_c *aux = lc -> prox;
    lista_c *inicio = lc;
    printf("%d", inicio -> valor);
    while (inicio != aux -> prox)
    {
        printf("%d ", aux -> valor);
        aux = aux -> prox;
    }
}

int main(){
    lista_c *minha_lista = criar_lista_c();
    minha_lista = inserir(minha_lista, 5);
    minha_lista = inserir(minha_lista, 4);
    imprimir_c(minha_lista);
    return 0;
}
