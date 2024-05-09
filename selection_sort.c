#include <stdio.h>

void imprimi_vetor(int vetor_a_imprimir[], int tamanho)
{   //Imprimi o vetor
    int i;
    for(i=0; i < tamanho; i++)
        printf("%d ", vetor_a_imprimir[i]);
    printf("\n");
}

void troca(int vetor_a_ser_trocado[], int posicao_errada, int posicao_certa)
{   //Troca elementos de um vetor, criando uma variável auxiliar para armazenar uma das posições que
    //será trocado
    int aux = vetor_a_ser_trocado[posicao_errada];
    vetor_a_ser_trocado[posicao_errada] = vetor_a_ser_trocado[posicao_certa];
    vetor_a_ser_trocado[posicao_certa] = aux;
}

void selection_sort(int vetor_desordenado[], int tamanho)
{   /*Esse metódo faz com que o menor elemento do vetor seja colocado no primeiro elemento e o segundo
    menor elemento seja colocado na segunda posição do vetor. Ex:
    vetor = [2, 3, -1, 1], o menor elemento é -1, logo ele será trocado com 2, ou seja -1 vai para v[0] e 2 para v[2]
    vetor = [-1, 3, 2, 1]
    
    Logo se trata de um metódo de ordenação de complexidade de N^2 e estável*/
   int i, j, menor;
   for(i=0; i < tamanho - 1; i++)
   {
    menor = i;  //Assumindo que o menor valor (desordenado) já está na posição certa
    for(j=i+1; j < tamanho; j++)
    {
        if(vetor_desordenado[j] < vetor_desordenado[menor])
            menor = j; //Alterando a posição menor elemento
    }
    if (menor != i) //Caso seja diferentes, quer dizer que o menor elemento está em uma posição diferente de i
        troca(vetor_desordenado, i, menor); //Trocando os elementos de posição
   } 
}

int main(){
    int vetor[4] = {2, -1, 3 ,1};
    imprimi_vetor(vetor, 4);
    selection_sort(vetor, 4);
    imprimi_vetor(vetor, 4);
    return 0;
}