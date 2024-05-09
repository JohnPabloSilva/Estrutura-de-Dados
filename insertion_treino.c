#include <stdio.h>

void imprimi_vetor(int vetor_imprimido[], int tamanho)
{
    int i;
    for(i=0; i<tamanho; i++)
        printf("%d ", vetor_imprimido[i]);
}

void insertion(int vetor_desordenado[], int tamanho)
{   //Coloca em ordem um vetor desordenado de forma que o menor elemento é colocado na posição certa 
    //e os restantes são "empurrados" para frente.
    // v = [2, 1, 3, -1]
    // v = [-1, 1, 3, 2] aqui o elemento "-1" é colocado na posição 0, pois é o menor elemento do vetor
    // v = [-1, 2, 1, 3]  o "2" é colocado na posição 1, "empurrando" "1" e "3" para a direita
    //lembrando que se trata de um exemplo, aconteceria muitos passos anteriores que alteraria as posições dos elementos
    //Esse metódo no melhor caso tem N de complexidade e no pior N^2
    //Ele é estável
    //Capaz de ordenar dados em tempo real
    int i, j, aux;
    for (i=1; i<tamanho; i++)
    {
        aux = vetor_desordenado[i];
        for (j=i; (j>0) && (aux < vetor_desordenado[j-1]); j--)
        {
            printf("%d <- %d ", vetor_desordenado[j], vetor_desordenado[j-1]);
            vetor_desordenado[j] = vetor_desordenado[j-1];
            printf(" - Dentro do for JJJ %d\n", j);
            imprimi_vetor(vetor_desordenado, tamanho);
            printf("\n ----------\n");
        }
        vetor_desordenado[j] = aux;
        printf("%d <- %d - na posicao %d ", vetor_desordenado[j], aux, j);
        printf("Mais externo no III i=%d\n", i);
        imprimi_vetor(vetor_desordenado, tamanho);
        printf("\n ---------\n");
    }
}

int main(){
    int vetor[4] = {3, 4, 1, 2};
    insertion(vetor, 4);
    return 0;
}