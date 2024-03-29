#include <stdio.h>
#include <stdlib.h>

int** alocamat (int x, int y){
    int** matriz=(int**) calloc(x,sizeof(int*));
    int i;
    for(i=0;i<x;i++){
        matriz[i]=(int *) calloc(y,sizeof(int));
    }
    return matriz;
}

void matriz_preenche(int **matriz, int x, int y){
    int i,j;
    for(i=0;i<x;i++){
        for(j=0;j<y;j++){
            matriz[i][j]=i+j;
        }
    }
}

void matriz_printa(int **matriz, int x, int y){
    int i,j;
    for(i=0;i<x;i++){
        printf("\n");
        for(j=0;j<y;j++){
            printf(" %d |",matriz[i][j]);
        }
    }
}

void realoca_matriz(int **matriz, int x, int y){
    int i,j;
    matriz=(int**) realloc(matriz, x*sizeof(int*));
    for(i=0;i<x;i++){
        matriz[i]=(int*) realloc(matriz[i], y*sizeof(int));
    }


}

void liberamatriz(int **matriz, int x){
    int i;
    for(i=0;i<x;i++){
        free(matriz[i]);
    }
    free(matriz);
}
int main()
{
    int **matriz;
    int x,y;
    printf("\nDigite o valor de i: ");
    scanf("%d", &x);
    printf("\nDigite o valor de j: ");
    scanf("%d", &y);
    matriz=alocamat(x,y);
    matriz_preenche(matriz,x,y);
    realoca_matriz(matriz, x+1 ,y+1);
    matriz_printa(matriz,x+1,y+1);
    liberamatriz(matriz, x+1);
    return 0;
}
