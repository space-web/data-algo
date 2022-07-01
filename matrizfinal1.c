/*
Dada una matriz de N*N elementos, la productoria de los elementos de la diagonal principal en forma recursiva
*/
#include <stdio.h>

void ingresar(int mat[][8],int dim){
    int i,j;
    for(i=0;i<dim;i++){
        for(j=0;j<dim;j++){
            printf("Ingrese numero:");
            scanf("%d",&mat[i][j]);
        }
    }
}
void mostrar(int mat[][8], int dim){
    int i,j;
    for(i=0;i<dim;i++){
        printf("\n");
        for(j=0;j<dim;j++){
            printf("%d\t",mat[i][j]);
        }
    }
}

int productoria(int mat[][8],int i){
    if(i==0){
        return 1;
    }
    return productoria(mat,i-1)*mat[i][i];
}
void main(){
    int mat[8][8],dim=0;
    printf("Ingresar dimension de la matriz:");
    scanf("%d",&dim);
    ingresar(mat,dim);
    printf("\n----------------------------------\n");
    mostrar(mat,dim);
    printf("La productoria de la diag. princ. es: %d",productoria(mat,dim-1));
    
    
}