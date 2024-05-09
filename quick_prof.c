void imprimi_vetor(int vetor_imprimido[], int tamanho)
 {   //Função para imprimir o vetor com base no seu tamanho e tipo(int, float, char)
    int i;
    for(i=0; i < tamanho; i++)
    {
        printf("  %d  ", vetor_imprimido[i]); //Cada elemento é imprimido na tela um ao lado do outro
    }
    printf("\n"); //Quebra de linha para que não haja confusão com outros prints
 }

void troca(int vetor_a_ser_trocado[], int posicao_errada, int posicao_certa)
{   //Troca elementos de um vetor, criando uma variável auxiliar para armazenar uma das posições que
    //será trocado
    int aux = vetor_a_ser_trocado[posicao_errada];
    vetor_a_ser_trocado[posicao_errada] = vetor_a_ser_trocado[posicao_certa];
    vetor_a_ser_trocado[posicao_certa] = aux;
}

int particiona(int inicio, int fim, int A[]){
    int pivo, i, j;
    pivo = A[fim];
    printf("\nInicio = %d", inicio);
    printf("\nFim = %d", fim);
    //código em C para mudar a cor do pivo
    printf("\033[1;33m");
    printf("\n\nPivo = %d", pivo);
    printf("\033[0m");
    
    j = inicio; //j é a posição do pivo
    for (i = inicio; i<fim;i++){
        if ( A[i] < pivo){
                troca(A,i,j);
                printf("\n\tTroca A[%d] = %d com A[%d] = %d", i, A[i], j, A[j]);
                j = j + 1;
        }
    }
    A[fim] = A[j];
    A[j] = pivo;
    return j;
}

void quickSort(int inicio, int fim, int A[]){
    int pos_pivo;
    if (inicio < fim){
        pos_pivo = particiona(inicio, fim, A);
        quickSort(inicio, pos_pivo-1, A);
        quickSort(pos_pivo+1,fim, A);
    }
}

void carregaVetor(int A[], int n){
    for ( int i = 0; i<n;i++){
        A[i] = rand()%n;
    }
}

int main()
{   int *A,
         n;
    printf("\nQuantos valores?");
    scanf("%d",&n);
    A = (int*)malloc(sizeof(int)*n);
    
    carregaVetor(A, n);    
    imprimi_vetor(A,n);
    quickSort( 0, n-1,A);
    imprimi_vetor(A,n);
    return 0;
}
