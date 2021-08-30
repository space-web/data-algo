#include <stdio.h>
#include <stdlib.h>

void cargar(int matriz[10][10], int n){
    int i, j;
    for(i=0; i<n; i++)
        for(j=0;j<n;j++){
            printf("\n ingrese un elemento:");
            scanf("%d",&matriz[i][j]);
        }
return;
}

void mostrar(int matriz[10][10], int n){
    int i, j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d \t",matriz[i][j]);
        }
        printf("\n");
    }
    return;
}

void trasponer(int matriz_tras[10][10],int matriz[10][10], int n){
   int i,j;
   for (int i = 0; i < n; i++){ 
      for (int j = 0; j < n; j++){ 
         matriz_tras[j][i] = matriz[i][j];
      }
   }
} 
  
// funcion para chequear si es antisimetrica
void check(int matriz_tras[10][10],int matriz[10][10], int n) 
{ 
    int i,j,cont = 0;
    for (int i = 0; i < n; i++){ 
        for (int j = 0; j < n; j++){
            if (matriz[i][j] == - matriz_tras[i][j])
                cont++; 
        }
    }
    if(cont > 0)
        printf("\n Es antisimetrica.");
    else
        printf("\n no es antisimetrica.");
}
int main()
{
    int matriz[10][10], n;
    int matriz_tras[10][10];
    
    printf("\n Ingrese dimension:");
    scanf("%d", &n);
    
    cargar(matriz,n);
    mostrar(matriz,n);
    trasponer(matriz_tras,matriz, n);
    printf("Matriz traspuesta:\n");
    mostrar(matriz_tras,n);
    check(matriz_tras, matriz,n);
    return 0;

}
