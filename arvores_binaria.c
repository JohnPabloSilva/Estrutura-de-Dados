#include<stdio.h>
#include<stdlib.h>

//Árvores binárias

typedef struct no{
    int valor;
    struct no *esq;
    struct no *dir;
}ABB;

ABB *cria_no(int valor){
    ABB *novo;
    novo = (ABB*)malloc(sizeof(ABB));
    if (novo == NULL){
        printf("\nFALHA DE MEMORIA");
        exit(1);
    }
    novo -> valor = valor;
    novo -> esq = NULL;
    novo -> dir = NULL;
    return novo;
}
ABB *insere(ABB *raiz, int valor){
    ABB *aux = raiz, *novo;
    if(raiz == NULL) {
        raiz = cria_no(valor);
    }
    else{
        if (valor <= raiz -> valor)
            raiz -> esq = insere(raiz->esq, valor);
        else
            raiz -> dir = insere(raiz->dir, valor);

    }
    return raiz;
}

//Caminhos em árvores binárias
void ordemCentral(ABB *raiz){ //Esquerda -> raiz -> direita
    if (raiz != NULL){
        ordemCentral(raiz -> esq); //Visita a árvore da esquerda
        printf("\n%d", raiz -> valor);
        ordemCentral(raiz -> dir);
    }
}
//
void posOrdem(ABB *raiz){
    if (raiz != NULL){
        posOrdem(raiz -> dir);
        printf("\n%d", raiz -> valor);
        posOrdem(raiz -> esq);
    }
}

void preOrdem(ABB *raiz){
    if (raiz != NULL){
            printf("\n%d", raiz -> valor);
            preOrdem(raiz->esq);
            preOrdem(raiz->dir);
    }
}



int contaFolha(ABB *raiz){
    if (raiz == NULL){
        return 0;
    }
    else {
        if(raiz->esq == NULL && raiz->dir == NULL)
            return 1;
        else
            return contaFolha(raiz -> esq) + contaFolha(raiz -> dir);
    }
}


ABB *menorValorNaABB(ABB * raiz) {
        ABB *atual = raiz;
        while (atual && atual -> esq != NULL){
            atual = atual -> esq;
        }
    return atual;
}

ABB *excluir(ABB *raiz, int valor){
    // Funciona apenas para raízes com um só filho (acho que o professor vai fazer o resto
    if (raiz == NULL)
    {
        return raiz;
    }
    if (valor < raiz -> valor){ //Caso o valor passado seja menor que o elemento se "anda" para a esquerda
        raiz -> esq = excluir(raiz -> esq, valor); //Usando recursividade para andar para a esquerda sucessivamente
    }
    else
    {
        if (valor > raiz -> valor)
        {
            raiz -> dir = excluir(raiz -> dir, valor); // Andando pra direita com recursividade
        }
        else  //Já está no lugar certo, pois não se encaixa em nenhuma condição anterior
        {
            if (raiz -> esq == NULL) {
                ABB *temp = raiz -> esq;
                free(raiz);
                return temp;
            }
            else {
                if (raiz -> dir == NULL) {
                    ABB *temp = raiz -> esq;
                    free(raiz);
                    return temp;
                }
            }
        }
    }
    return raiz;
}

int maximo(int a, int b){
    if (a > b)
        return a;
    else
        return b;
    }


int altura(ABB *raiz){
    if (raiz == NULL)
        return 0;
    else {
        return maximo(altura(raiz->esq), altura(raiz -> dir)) + 1;
    }
}

int balanceada(ABB *raiz){
    if (raiz == NULL)
        return 1;
    else{
        if (abs(altura(raiz->esq) - altura(raiz->dir)) <= 1)
            return (balanceada(raiz->esq) && balanceada(raiz->dir));
        else
            return 0;
    }
}

int ContaFilhoUnico(ABB *raiz){
    //Analisa se algum nó tem filho único
    if(raiz==NULL) //Caso a raiz seja vazia
        return 0;
    if ((raiz -> esq!=NULL || raiz -> dir !=NULL ) && !(raiz -> esq !=NULL && raiz -> dir != NULL)) //Gambiarra pra usar o "ou exclusivo", caso seja verdadeiro, a raiz não possui filho único
        return ContaFilhoUnico(raiz->esq) + ContaFilhoUnico(raiz->dir) + 1; //Prosseguindo para os outros nós
    else
        return ContaFilhoUnico(raiz->esq) + ContaFilhoUnico(raiz->dir); //Esse nó pode ter outros DOIS filhos ou NENHUM
}

int ContaDoisFilhos(ABB *raiz){
    //Analisa se algum nó tem dois filhoos
    if(raiz==NULL) //Caso a raiz seja vazia
        return 0;
    if (raiz -> esq !=NULL && raiz -> dir != NULL) //Gambiarra pra usar o "ou exclusivo", caso seja verdadeiro, a raiz não possui dois filhos
        return ContaDoisFilhos(raiz->esq) + ContaDoisFilhos(raiz->dir) + 1; //Prosseguindo para os outros nós e adicionando um
    else
        return ContaDoisFilhos(raiz->esq) + ContaDoisFilhos(raiz->dir);
}

int somaABB(ABB *raiz){ //Soma todos os valores dos nós
    if (raiz == NULL)
        return 0;
    else
        return somaABB(raiz->esq) + somaABB(raiz->dir) + (raiz->valor);
}

int main(void){
    ABB *raiz = NULL;

    raiz = insere(raiz, 7);
    raiz = insere(raiz, 3);
    raiz = insere(raiz, 10);
    raiz = insere(raiz, 9);
    raiz = insere(raiz, 8);

    printf("\nPre-Ordem");
    preOrdem(raiz);

    printf("\nOrdem Central");
    ordemCentral(raiz);

    int folhas = contaFolha(raiz);

    printf("\nQuantidade de folhas na arvore %d", folhas);
    printf("\nA altura da arvore e %d", altura(raiz));

    excluir(raiz, 8);

    printf("\nNova ordem central");
    ordemCentral(raiz);

    printf("\nPos-Ordem");
    posOrdem(raiz);

    printf("\nConta filho unico");
    printf("\n%d", ContaFilhoUnico(raiz));

    printf("\nConta filho duplo");
    printf("\n%d", ContaDoisFilhos(raiz));

    printf("\nSomando a arvore");
    printf("\n%d", somaABB(raiz));
    }

