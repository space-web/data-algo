/******************************************************************************
Suma de diagonal principal de una matrix recursively.
*******************************************************************************/
#include <stdio.h>

void cargar_matriz(int mat[][8], int dim){
    int i,j;
    for(i=0;i<dim;i++){
        printf("\n");
        for(j=0;j<dim;j++){
            printf("\nIngrese num:");
            scanf("%d",&mat[i][j]);
        }
    }
}

void mostrar_matriz(int mat[][8], int dim){
    int i,j;
    for(i=0;i<dim;i++){
        printf("\n");
        for(j=0;j<dim;j++){
            printf("%d\t",mat[i][j]);
        }
    }
}

int diagonal(int mat[][8], int i){
    if(i==0){
        return mat[i][i];
    }
    printf("\ni=%d",i);
    printf("\nval:%d",mat[i][i]);
    return diagonal(mat,i-1)+mat[i][i];
    
}

int main()
{
    int mat[8][8], dim;
    
    printf("Ingresar dimension de la matriz:");
    scanf("%d",&dim);
    cargar_matriz(mat,dim);
    printf("\n--------------------------------\n");
    printf("Matriz ingresada:\n");
    mostrar_matriz(mat,dim);
    printf("\ndim:%d",dim);
    printf("\nSuma de la diagonal principal:%d",diagonal(mat,dim-1));

    return 0;
}
