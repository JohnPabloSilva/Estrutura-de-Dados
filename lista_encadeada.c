#include <stdio.h>
#include <stdlib.h>

typedef struct no{ //Criando a estrutura do nó tipificando a mesma, como uma classe em Python
    int valor; //Que tipo de dados teremos na estrutura e será apontado
    struct no *prox; //A vaŕiável do tipo ponteiro que aponta para o possível proxímo elemento
}lista; //O nome que seŕa dado à estrutura

lista *criar_lista() { //Criando a lista que tem não tem um ponteiro para ela mesma no inicio
    return NULL;
}

lista *criar_no(int valor){
    lista *novo = (lista*) malloc(sizeof(lista)) ; //Criando um ponteiro com base no ttamanho da estrutura nó(lista) e adequando para o novo ponteiro
    novo->valor = valor;    //Dentro de novo, uma estrutura nó(lista),é atribuido o valor para a 1ª parte do bloco
    novo->prox = NULL;  //O ponteiro é anulado, visto que a nova estrutura está sendo adicionada no fim da lista de estruturas
    return novo;    //Retorna o novo nó
}

lista *inserir(lista *l, int valor){ //Inserindo um novo nó no inicio da lista
    lista *novo = criar_no(valor); //Criado um novo nó com base no "valor", dando a este novo nó um endereço
    novo->prox = l; //O ponteiro do nó novo recebe o endereço do proxímo elemento, pois está sendo incrementado no inicio da lista
    return novo; //Retorna o novo nó
}

void imprimir(lista *l){ //Função para imprimir a estrutura lista
    lista *aux = l; //aux recebe o endereço do primeiro nó na lista
    while (aux!=NULL)   //SE o prox do nó for nulo, então chegou-se ao final na lista
    {
        printf("%d ", aux->valor);  //Imprimindo o valor que está no nó
        aux = aux -> prox;  //Passando o aux para o prox (endereço do proxímo nó)
        printf("\n");
    }
}

int main(){
    lista *le = criar_lista();
    le = inserir(le, 1);
    le = inserir(le, 2);
    le = inserir(le, 3);
    le = inserir(le, 4);
    le = inserir(le, 5);
    
    imprimir(le);

    return 0;
}
