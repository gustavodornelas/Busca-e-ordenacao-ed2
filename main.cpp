#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

#define MAX_SIZE 100000

char menu (){

    char m;

    system("cls");
    printf ("\t\tMenu\n");
    printf ("Digite 'A' para criar um novo vetor.\n");
    printf ("Digite 'B' para ordenar o vetor.\n");
    printf ("Digite 'C' para Buscar um valor no vetor.\n");
    printf ("Digite 'E' para sair.\n");
    printf ("Opcao: ");

    scanf (" %c", &m);
    m = toupper(m);

    if (m == 'B'){
        system("cls");
        printf("Digite 'Q' para ordenar o vetor por Quick Sort.\n");
        printf("Digite 'M' para ordenar o vetor por Merge Sort.\n");
        printf ("Opcao: ");
        scanf (" %c", &m);
        m = toupper(m);
    }
    else if (m == 'C'){
        system ("cls");
        printf ("Digite 'S' para busca Sequencial.\n");
        printf ("Digite 'B' para busca Binaria.\n");
        printf ("Opcao: ");
        scanf (" %c", &m);
        m = toupper(m);
    }

    return m;
}

void troca (int v[], int a, int b){
    int aux = v[a];
    v[a] = v[b];
    v[b] = aux;
}

int particiona(int v[], int s, int e){

    int pivot = v[s];
    int i = s;

    for (int j = s + 1; j <= e; j++){
        if (v[j] <= pivot){
            i++;
            troca (v, i, j);
        }
    }

    troca(v, s, i);
    return i;
}

int quickSort(int v[], int s, int e){ //s = posição inicial  e = posição final

    if (s < e){
    int p = particiona(v, s, e);
        quickSort(v, s, p - 1);
        quickSort(v, p + 1, e);
    }

}

void merge (int v[], int s, int m, int e){

    int temp[(e - s) + 1];
    int i = s;      //inicio do vetor da esquerda
    int j = m+1;    //inicio do vetor da direita
    int k = 0;      //inicio do vetor temporario

    while (i <= m && j <= e){
        if (v[i] < v[j]){
            temp[k++] = v[i++];
        }else{
            temp[k++] = v[j++];
        }
    }

    for (; i <= m; i++, k++){
        temp[k] = v[i];
    }

    for (; j <= e; j++, k++){
        temp[k] = v[j];
    }

    for (i = s, k = 0; i <= e; i++, k++){
        v[i] = temp[k];
    }
}

void mergeSort (int v[], int s, int e){

    if (s < e){
        int m = (s+e) / 2;
        mergeSort (v, s, m);
        mergeSort (v, m + 1, e);
        merge (v, s, m, e); //Aqui é a logica da conquista
    }
}

int buscaSequencial(int v[], int n, int x){

    for (int i = 0; i < n; i++){
        if (v[i] == x){
            return i;
        }
    }

    return -1;
}

int buscaBinaria(int v[], int n, int x){

    int s = 0, e = n - 1;

    while (s <= e){
        int m = (s + e) / 2;

        if (x == v[m]){
            return m;
        }else if (x > v[m]){
            s = m + 1;
        }else if (x < v[m]){
            e = m - 1;
        }
    }

    return -1;
}

void criaVetor(int v[], int n){

    for (int i=0; i < n; i++){
        v[i] = rand();
    }

}

void imprimeVetor(int v[], int n){

    printf("Posicao\tvalor\n\n");

    for (int i = 0; i < n; i++){
        printf("%d\t%d\n",i, v[i]);
    }

    printf("\n");
}

int main (){

    char opcao;
    int vetor[MAX_SIZE];
    int quantidade;
    bool A = false; //Valida se opção A foi escolhida e vetor criado
    bool B = false; //Valida se opção B foi criada e vetor ordenado

    do{
        opcao = menu();

        system("cls");

        switch(opcao){

        case 'A':
            printf("Digite o tamanho do vetor(1 / 100.000): ");
            scanf("%d", &quantidade);

            if (quantidade > 1 && quantidade <= MAX_SIZE){
                criaVetor(vetor, quantidade);
                imprimeVetor(vetor, quantidade);
                A = true;  //Vetor Criado
                B = false; //Vetor não Ordenado
            }else{
                printf("Tamanho do vetor invalido!\n");
            }

            system("pause");
            break;

        case 'Q':
            if (A){ //Verifica se vetor foi criado
                quickSort(vetor, 0, quantidade - 1);
                system("cls");
                imprimeVetor(vetor, quantidade);

                system("pause");
                B = true; //Vetor Organizado
            }else{
                printf("Favor criar o vetor!\n");
                system("pause");
            }
            break;

        case 'M':
            if (A){ //Verifica se vetor foi criado
                mergeSort(vetor, 0, quantidade - 1);
                system("cls");
                imprimeVetor(vetor, quantidade);

                system("pause");
                B = true;  //Vetor Organizado
            }else{
                printf("Favor criar o vetor!\n");
                system("pause");
            }
            break;

        case 'S':
            if (A){ //Verifica se vetor foi criado
                int busca;
                printf ("Digite um valor numerico: ");
                scanf ("%d", &busca);

                int i = buscaSequencial(vetor, quantidade, busca);

                if (i != -1){
                    printf ("%d esta na %d Posicao do vetor\n", vetor[i], i);
                }else{
                    printf("%d nao encontrado no vetor!\n", busca);
                }
                system("pause");

            }else{
                printf("Favor criar o vetor!\n");
                system("pause");
            }
            break;
        case 'B':
            if (A){ //Verifica se vetor foi criado
                if(B){ //Verifica se vetor foi ordenado
                    int busca;
                    printf ("Digite um valor numerico: ");
                    scanf ("%d", &busca);

                    int i = buscaBinaria(vetor, quantidade, busca);

                    if (i != -1){
                        printf ("%d esta na %d Posicao do vetor\n", vetor[i], i);
                    }else{
                        printf("%d nao encontrado no vetor!\n", busca);
                    }
                    system("pause");
                }else{
                    printf("Favor ordenar o vetor!\n");
                    system("pause");
                }

            }else{
                printf("Favor criar o vetor!\n");
                system("pause");
            }
            break;

        case 'E':
            printf("Encerrando Sistema!\n");
            break;

        default:
            printf("Opcao invalida!\n");
            system("pause");
            break;
        }
    }while(opcao != 'E');


    return 0;
}
