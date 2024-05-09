#include<stdio.h>
#include<stdlib.h> // rand()

/*O algoritmo de ordenação ocorre de maneira que se repita muitas vezes,
pois compara elemento por elemento e troca o menor com o maior, o menor para frente
e o maior para trás, tendo uma repetição/complexidade de n^2, pois a repetição acontece uma vez
para cada termo do vetor.
*/
#define N 10

void leVetor(int A[], int n){
    int i;
    for (i=0;i<n;i++)
        A[i] =  rand()%n;
}
void imprime(int vetor[], int n){
    int i;
    printf("\n");
    for (i=0;i<n;i++)
        printf(" %d ",vetor[i]);  
}
void troca(int A[], int i, int j){
    int temp;
    temp = A[j];
    A[j] = A[i];
    A[i] = temp;
}
//Minha versão
void troca_a(int A[], int maior, int menor){
    int temp;
    temp = A[0];
    A[9] = A[maior];
    A[0] = A[menor];
}
//Minha versão
void bolha(int vetor[], int n){
    int i, j, menor;
    menor = vetor[0];
    for ( i = 0; i < n; i++)
    {
        for (j = i;  j < n;j++)
            if (vetor[j] < menor)
                menor = vetor[j];

    }   
}

void bolha(int vetor[], int n){
    int i, j;
    for ( i = 0;i<n-1;i++)
        for (j = 0; j<n-1;j++)
            if (vetor[j]>vetor[j+1])
                troca(vetor, j, j+1);
}
int main(){
    int vetor[N];
    leVetor(vetor, N);
    imprime(vetor, N);
    bolha(vetor, N);
    imprime(vetor, N);
    return 0;
}