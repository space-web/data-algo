/*
Dada una lista ordenada en forma ascendente y dos números enteros, eliminar todos los números de la lista entre dichos números. Si no es posible, aclararlo.
*/
#include <stdio.h>
#include <stdlib.h>


typedef struct lista{
	int num;
	struct lista *sig;
 }nodo;


void crear (nodo *p)
{
    scanf("%d",&p->num);

    if (p->num==0)
        p->sig=NULL;
    else
	{
        p->sig=(nodo*)malloc(sizeof(nodo));
        crear(p->sig);

	}
	return;
}

void mostrar (nodo *p)
{
    if (p->sig !=NULL)
	{
        printf("%d\n",p->num);
        mostrar(p->sig);
	}
	return;
}
nodo* eliminar1(nodo* p, int num1, int num2, int *cont)
{
    nodo *aux;
    while((p->num>num1 && p->num<num2) || (p->num>num2 && p->num<num1))//condicion de eliminacion
    {
        aux=p->sig;
        free(p);
        *cont+=1;
        p=aux;

    }
    return p;
}
void eliminar2(nodo* p,int num1, int num2,int *cont)
{
    nodo *aux;
    while(p->sig!=NULL&& p->sig->sig!=NULL)
    {
        if((p->sig->num>num1 && p->sig->num<num2) || (p->sig->num>num2 && p->sig->num<num1))//condicion de eliminacion
        {
            aux=p->sig->sig;
            free(p->sig);
            *cont+=1;
            p->sig=aux;
        }
        else
        {
            p=p->sig;
        }
    }

}

int main()
{
    int num1,num2,cont=0;
    nodo *p=NULL;
    p=(nodo*)malloc(sizeof(nodo));
    printf("Ingresar numero 1:");
    scanf("%d",&num1);
    printf("\nIngresar numero 2:");
    scanf("%d",&num2);
    crear(p);
    mostrar(p);
    eliminar1(p,num1,num2,&cont);
    eliminar2(p,num1,num2,&cont);
    if(cont>0){
        printf("\nLista con eliminaciones:\n");
        mostrar(p);
    }
    if(cont==0){
        printf("\nNo es posible eliminar numeros.");
    }
    
    return 0;
}
