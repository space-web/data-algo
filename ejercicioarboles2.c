/*a) El elemento maximo del arbol

b) Cantidad de nodos con dos hijos divisores de la raiz

c) Promedio de nodos con un valor par con un sólo hijo.*/
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

void crear (treenode **hoja,int *raiz,int *max)
{
    int numero;

    printf ("ingrese numero\n");
    scanf ("%d",&numero);
    *raiz=numero;
    *max=*raiz;
    while (numero!=-1)
    {

        insertar(&(*hoja),numero);
        printf ("ingrese numero\n");
        scanf ("%d",&numero);
    }
}

void mostrar (treenode *hoja,int *raiz,int *max,int *cont,int *cont2, int *sum)
{
    if (hoja!=NULL)
    {
        mostrar(hoja->izq,raiz,max,cont,cont2,sum);
        printf("%d ",hoja->dato);
        mostrar(hoja->der,raiz,max,cont,cont2,sum);
        //El elemento maximo del arbol
        if(hoja->dato>*max){
            *max=hoja->dato;
        }
        //Cantidad de nodos con dos hijos divisores de la raiz
        if(hoja->izq!=NULL && hoja->der!=NULL && *raiz%hoja->dato==0 && hoja->dato!=*raiz){
            *cont=*cont+1;
        }
        //Promedio de nodos con un valor par con un sólo hijo
        if((hoja->izq!=NULL && hoja->der==NULL && hoja->dato%2==0)||(hoja->izq==NULL && hoja->der!=NULL && hoja->dato%2==0)){
            *sum=*sum+hoja->dato;
            *cont2=*cont2+1;
        }
    }
    return;
}
int main ()
{
    int raiz,max=0,cont=0,cont2=0,sum=0;
    printf ("arboles\n");
    treenode* arbol=NULL;

    crear (&arbol,&raiz,&max);
    printf ("**************\n");
    printf ("mostrar arbol\n");
    printf ("***************\n");

    mostrar (arbol,&raiz,&max,&cont,&cont2,&sum);
    printf("\nelemento maximo del arbol:%d\n",max);
    printf("\nCantidad de nodos con dos hijos divisores de la raiz:%d\n",cont);
    printf("Promedio de nodos con un valor par con un sólo hijo:%d",sum/cont2);
    return 0;
}
