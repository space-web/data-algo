/*Crear y Mostrar un árbol binario de búsqueda.
 Escribir las funciones necesarias para calcular y luego mostrar:
a) Cantidad de los elementos pares con un hijo.
b) Mínimo elemento impar del árbol. 
*/
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



void mostrar (treenode *hoja,int *cont, int *min, int *max, int *raiz)
{
    if (hoja!=NULL)
    {
        mostrar(hoja->izq,cont,min,max,raiz);
        printf("%d ",hoja->dato);
        mostrar(hoja->der,cont,min,max,raiz);
        //Cantidad de los elementos pares con un hijo.
        if((hoja->izq==NULL && hoja->der!=NULL && hoja->dato%2==0)||(hoja->izq!=NULL && hoja->der==NULL && hoja->dato%2==0)){
            *cont=*cont+1;
        }
        if(hoja->dato>*max){
            *max=hoja->dato;
        }
        // Mínimo elemento impar del árbol.
        if(hoja->dato<*max && hoja->dato%2!=0 && hoja->dato!=*raiz){
            printf("\ndato:%d,min:%d\n",hoja->dato,*min);
            *min=hoja->dato;
            printf("nuevo min:%d\n",*min);
        }

    }
    return;
}
int main ()
{
    int cont=0,min=0,max=0,raiz;
    printf ("arboles\n");
    treenode* arbol=NULL;

    crear (&arbol,&raiz);
    printf ("**************\n");
    printf ("mostrar arbol\n");
    printf ("***************\n");

    mostrar (arbol,&cont,&min,&max,&raiz);
    printf("\nCantidad de los elementos pares con un hijo:%d\n",cont);
    printf("\nMínimo elemento impar del árbol:%d\n",min);
    return 0;
}