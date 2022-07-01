/*Crear una pila con la siguiente información:
 num: numero entero.
 siguiente: puntero al próximo elemento de la pila.
Desarrollar una función que permita mostrar la sumatoria de números
mayores al primer elemento ingresado en la pila. Si no hubiera ningún
número mostrar una leyenda.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define CANT 4

typedef struct tiponodo
{
	int dato;

    struct tiponodo *siguiente;
}nodo;

void mostrar (nodo aux,int primero,int *sum,int *cont)

{
        if(aux.dato>primero){
            *sum=*sum+aux.dato;
            *cont=*cont+1;
        }
     	printf("%d \n", aux.dato);
}

nodo* crear_nodo(int dato )
{
   nodo* u;
   u = (nodo *)malloc(sizeof(nodo));
   u->dato = dato;

   u->siguiente = NULL;

   return u;
}

void apilar(nodo** p, nodo* u)
{
    printf("apilar_nodo\n");


  	u->siguiente = *p;
	*p = u;
}

nodo desapilar(nodo** p)
{
	nodo* aux;
    nodo datos;

	datos=**p;

	aux=*p;

	*p=(*p)->siguiente;
	free(aux);

    return datos;
}

int main()
{


    int i,num,primero=0,sum=0,cont=0;
    nodo* p=NULL;

    printf("Ingrese un numero: \n");
   	scanf("%d",&num);
    primero=num;
    for(i=0; i<CANT; i++)
   {
   	printf("Ingrese un numero: \n");
   	scanf("%d",&num);
    
   	apilar(&p, crear_nodo(num));
   }


    printf("\nVamos a desapilar todo\n");
	while(p!=NULL)
   {
        mostrar(desapilar(&p),primero,&sum,&cont);
   }
   printf("La suma es:%d",sum);
   if(cont==0){
      printf("\nNo hay ningun numero.\n"); 
   }
   
   return 0;
}
