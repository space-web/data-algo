/*
Ingresar números enteros y generar un árbol binario de búsqueda. Mostrarlo en Orden. 
Mostrar la cantidad de nodos hojas impares y la cantidad de nodos múltiplos de la raíz.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct arbol
{
    int dato;
    struct arbol *izq;
    struct arbol *der;
}treenode;


void insertar (treenode **hoja,int elem)
{
    int numero=elem;
    if (elem==-1)
        return;
    if (*hoja==NULL)
    {
        //creo la hoja vacia
        (*hoja)=(treenode*)malloc(sizeof(treenode));
        (*hoja)->dato=elem;
        (*hoja)->der=NULL;
        (*hoja)->izq=NULL;
    }else{
        if (numero>(*hoja)->dato)
        {
            insertar (&(*hoja)->der,elem);
        }
        else
        {
            insertar (&(*hoja)->izq,elem);
        }
    }
    return;
}
void crear (treenode **hoja,int *raiz)
{
    int numero;

    printf ("ingrese numero\n");
    scanf ("%d",&numero);
    *raiz=numero;
    while (numero!=-1)
    {

        insertar(&(*hoja),numero);
        printf ("ingrese numero\n");
        scanf ("%d",&numero);
    }
}


void mostrar (treenode *hoja,int *cont,int *raiz,int *cant)
{
    if (hoja!=NULL)
    {
        mostrar(hoja->izq,cont,raiz,cant);
        printf("%d ",hoja->dato);
        mostrar(hoja->der,cont,raiz,cant);
        //cantidad de nodos hojas impares
        if(hoja->izq==NULL && hoja->der==NULL && hoja->dato%2!=0){
            *cont=*cont+1;
        }
        //cantidad de nodos múltiplos de la raíz
        if(hoja->dato%*raiz==0 && hoja->dato!=*raiz){
            *cant=*cant+1;
        }

    }
    return;
}


int main ()
{
    int cont=0,cant=0,raiz;
    printf ("arboles\n");
    treenode* arbol=NULL;

    crear (&arbol,&raiz);
    printf ("**************\n");
    printf ("mostrar arbol\n");
    printf ("***************\n");

    mostrar (arbol,&cont,&raiz,&cant);
    printf("\nLa cantidad de nodos hojas impares:%d\n",cont);
    printf("\ncantidad de nodos múltiplos de la raíz:%d",cant);
    return 0;
}
