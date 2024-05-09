#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *ante;
    struct no *prox;
}lista_d;

lista_d *criar_lista_d(){
    return NULL;
}

lista_d *criar_no_duplo(int valor){
    lista_d *novo = (lista_d*)malloc(sizeof(lista_d));
    novo->valor = valor;
    novo->prox = NULL;
    novo->ante = NULL;

    return novo;
}

lista_d *inserir_duplo(lista_d *ld, int valor){
    lista_d *novo = criar_no_duplo(valor);

    if (novo == NULL){
        printf("\nFalha na alocação de memória");
        exit(1);
    }
    if (ld != NULL){
        novo->prox = ld;
        ld->ante = novo;
    }
    return novo;
}


lista_d *excluir(lista_d *ld, int valor){
    lista_d *aux = ld, *ante = NULL;
    while (aux!=NULL && aux->valor != valor)
    {
        ante = aux;
        aux = aux -> prox;
    }
    if (aux->ante != NULL){
        if (ante == NULL){ //Caso o elemento que queremos excluir seja o primeiro nó
            ld = aux->prox;
            ld -> ante = NULL;
        }
    
        else{   //Caso não seja o primeiro elemento
        aux -> prox -> ante = aux -> ante;
        aux -> ante -> prox = aux -> prox;
         }
    }
    free(aux);

    return ld;

}

void imprimir(lista_d *ld){
  lista_d *aux = ld; // cria um nó auxiliar para percorrer a lista
  while(aux!=NULL){
    printf("%d ", aux->valor); // imprime o valor do nó
    aux = aux->prox;           // o nó auxiliar aponta para o próximo nó
  }
  printf("\n");
}

int main(){
    lista_d *ld = criar_lista_d();
    ld = inserir_duplo(ld, 1);
    ld = inserir_duplo(ld, 2);
    ld = inserir_duplo(ld, 3);
    ld = inserir_duplo(ld, 4);
    ld = inserir_duplo(ld, 5);
    imprimir(ld);
    ld = excluir(ld, 3);
    imprimir(ld);

    return 0;
}
