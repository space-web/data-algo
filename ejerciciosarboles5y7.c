/*
cantidad de nodos hojas divisores de la raíz.

cantidad de nodos impares con dos hijos.*/
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




void mostrar (treenode *hoja,int *cont,int *raiz,int *cont2)
{
    if (hoja!=NULL)
    {
        mostrar(hoja->izq,cont,raiz,cont2);
        printf("%d ",hoja->dato);
        mostrar(hoja->der,cont,raiz,cont2);
        //cantidad de nodos hojas divisores de la raíz
        if(hoja->izq==NULL && hoja->der==NULL && *raiz%hoja->dato==0 && hoja->dato!=*raiz){
            *cont=*cont+1;
        }
        //cantidad de nodos impares con dos hijos
        if(hoja->dato%2!=0 && hoja->izq!=NULL && hoja->der!=NULL){
            *cont2=*cont2+1;
        }

    }
    return;
}
int main ()
{
    int cont=0,raiz=0,cont2=0,divisor=0;
    printf ("arboles\n");
    treenode* arbol=NULL;

    crear (&arbol,&raiz);
    printf ("**************\n");
    printf ("mostrar arbol\n");
    printf ("***************\n");

    mostrar (arbol,&cont,&raiz,&cont2);
    printf("\ncantidad de nodos hojas divisores de la raíz:%d",cont);
    printf("\ncantidad de nodos impares con dos hijos:%d",cont2);

    return 0;
}