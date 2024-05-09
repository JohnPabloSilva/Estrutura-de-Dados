 #include <stdio.h>
 #include <stdlib.h>
 #include <math.h>
 
 void imprimi_vetor(int vetor_imprimido[], int tamanho)
 {   //Função para imprimir o vetor com base no seu tamanho e tipo(int, float, char)
    int i;
    for(i=0; i < tamanho; i++)
    {
        printf("  %d  ", vetor_imprimido[i]); //Cada elemento é imprimido na tela um ao lado do outro
    }
    printf("\n"); //Quebra de linha para que não haja confusão com outros prints
 }

 void Intercala(int *vetor,int inicio_vetor, int meio_vetor, int fim_vetor)
 {  //A função que organiza o vetor 
    int *vetor_temporario, pos_vetor1, pos_vetor2, tamanho, i, j, k;
    //É dado o vetor_temporario é apenas um endereço que aceita valores inteiros 
    //pos_vetor1 e pos_vetor2 são referentes as posições que indicam o inicio e o meio do vetor respectivamente (divisão)
    int fim1 = 0, fim2 = 0; //Variáveis de controle que indicam o fim da primeira e segunda metade respectivamente

    tamanho = fim_vetor-inicio_vetor+1; //Tamanho do vetor
    pos_vetor1 = inicio_vetor; //Inicio do vetor
    pos_vetor2 = meio_vetor+1; //Fim do vetor
    
    vetor_temporario = (int *) malloc(tamanho*sizeof(int)); 
    // tipo de variável, alocamento(tamanho do vetor original x tamanho de um elemento do tipo inteiro)
    //Criando o vetor temporario alocando memória de acordo com o tamanho do vetor original

    if(vetor_temporario != NULL)   //Se o alocamento funcionou então realiza os seguintes comandos
    {
        for(i=0; i < tamanho; i++) //Um loop que percorre o vetor por inteiro
        {
            if (!fim1 && !fim2) //Se nenhuma das variáveis de posição (pos_vetor1 e pos_vetor2) chegou ao seu limite 
            {
                if(vetor[pos_vetor1] < vetor[pos_vetor2]) //Se o vetor na posição mais a ESQUERDA é menor do que na
                                                          //o elemento mais a DIREITA
                    vetor_temporario[i] = vetor[pos_vetor1++]; //Coloca o elemento na posição certa do vetor temporario
                                                               //e incrementa na posição após isso para prosseguir 
                                                               //Para assim a posição "andar" dentro da primeira metade
                                                               //do vetor
                else
                    vetor_temporario[i] = vetor[pos_vetor2++]; //Caso o elemento na posição da DIREITA seja maior
                                                               //do que o elemento mais a ESQUERDA
                if (pos_vetor1 > meio_vetor) //Caso a variável passe da 1ª metade do vetor, encerra as comparações
                    fim1 = 1;
                if (pos_vetor2 > fim_vetor) //Caso a variável passe da 2ª metade do vetor, encerra as comparações
                    fim2 = 1;
            }
            else
            {
                if(!fim1)   //Caso a primeira metade tenha chegado ao final
                    vetor_temporario[i] = vetor[pos_vetor1++];  //Copiar o restante do vetor para o vetor temporario
                else    //Poderia ser um "if(!fim2)" pois se chegou a este ponto é porque algumas dos "pos" ultrapassou
                        //seus resptivos limites
                    vetor_temporario[i] = vetor[pos_vetor2++]; //copia o restante do vetor para o vetor temporario
            }
        }
        for(j=0, k=inicio_vetor; j<tamanho; j++, k++) //Copia o vetor temporario para o vetor original, isso já ordenado
            vetor[k] = vetor_temporario[j];
    }

    free(vetor_temporario); //libera a memória ocupada pelo vetor temporario
 }
 
 void MergeSort(int *vetor_sort, int inicio_vetor, int fim_vetor)
 {/*Função que intercala um vetor, isto é, ele recebe um vetor, a posição de inicio e fim do mesmo
    para assim dividi-lo e "criar" outros dois vetores, que serão organizados com base na seu valores. Ex:
    vetor = [4, 2, 1, 3]
    [4, 2] e [3, 1], após isso 
    [4], [2] e [3], [1] - isso acontece graças à sua recursividade
    Depois que a divisão chega ao fim, os valores são unidos de novo, mas dessa vez em ordem
    [2, 4] e [1, 3] após isso
    [1, 2, 3, 4]*/
    int meio_vetor;
    if(inicio_vetor < fim_vetor)
    {
        meio_vetor = floor((inicio_vetor+fim_vetor)/2); //Descobrindo o meio do vetor
        MergeSort(vetor_sort, inicio_vetor, meio_vetor); //Dividindo o vetor que resta na parte esquerda "Faz o L"
        MergeSort(vetor_sort, meio_vetor+1, fim_vetor); //Divindo o vetor que resta na parte da direita
        Intercala(vetor_sort, inicio_vetor, meio_vetor, fim_vetor); //Ordenando o vetor, por exemplo [2, 4]
    }
 }

 int main()
 {
    int vetor[7] = {3, 1, 2, 0, -2, 4, 5};
    imprimi_vetor(vetor, 7);
    MergeSort(vetor, 0, 6);
    imprimi_vetor(vetor, 7);
    return 0;
 }