/*
Dado un árbol binario de búsqueda, la cantidad de elementos múltiplos de la raíz. 
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct arbol
{
    int dato;
    struct arbol *izq;
    struct arbol *der;
}treenode;

void mostrar (treenode *hoja,int *raiz, int *cont)
{
    if (hoja!=NULL)
    {
        mostrar(hoja->izq,raiz,cont);
        printf("%d ",hoja->dato);
        mostrar(hoja->der,raiz,cont);
        if(hoja->dato%*raiz==0 && hoja->dato!=*raiz){
            *cont+=1;
        }

    }
    return;
}


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

int main ()
{
    int raiz=0,cont=0;
    printf ("arboles\n");
    treenode* arbol=NULL;

    crear(&arbol,&raiz);
    printf ("**************\n");
    printf ("mostrar arbol\n");
    printf ("***************\n");

    mostrar(arbol,&raiz,&cont);
    printf("\nCantidad de elementos multiplos de la raiz:%d",cont);


    return 0;
}