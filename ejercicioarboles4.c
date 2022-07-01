/*Diseñar una función que, dado un árbol binario de búsqueda, calcule el promedio de
aquellos nodos múltiplos de la raíz.*/
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

void crear (treenode **hoja, int *raiz)
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

void mostrar (treenode *hoja,int *sum,int *raiz,int *cont)
{
    if (hoja!=NULL)
    {
        mostrar(hoja->izq,sum,raiz,cont);
        printf("%d ",hoja->dato);
        mostrar(hoja->der,sum,raiz,cont);
        //calcule el promedio de aquellos nodos múltiplos de la raíz
        if(hoja->dato%*raiz==0 && hoja->dato!=*raiz){
            *sum=*sum+hoja->dato;
            *cont=*cont+1;
        }
        

    }
    return;
}
int main ()
{
    int raiz=0;
    int sum=0,cont=0;
    float promedio=0;
    printf ("arboles\n");
    treenode* arbol=NULL;

    crear (&arbol,&raiz);
    printf ("**************\n");
    printf ("mostrar arbol\n");
    printf ("***************\n");

    mostrar(arbol,&sum,&raiz,&cont);
    promedio=sum/cont;
    printf("\npromedio de nodos múltiplos de la raíz:%f",promedio);

    return 0;
}