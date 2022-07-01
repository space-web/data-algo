/*
Escribir la función necesaria para calcular la cantidad de elementos múltiplos del
último número ingresado a la pila. Si no hubiera ningún número mostrar una
leyenda.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define CANT 5



typedef struct tiponodo
{
	int dato;

    struct tiponodo *siguiente;
}nodo;

void mostrar (nodo aux,int ultimo,int *cant)

{
     	printf("%d \n", aux.dato);
     	if(aux.dato%ultimo==0){
     	    *cant=*cant+1;
     	}
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


   int i,num,ultimo=0,cant=0;
   nodo* p=NULL;


   for(i=0; i<CANT; i++)
   {
   	printf("Ingrese un numero \n");
   	scanf("%d",&num);
    apilar(&p, crear_nodo(num));
   }
    ultimo=num;


   printf("\nVamos a desapilar todo\n");
	while(p!=NULL)
   {
    	mostrar(desapilar(&p),ultimo,&cant);
   }
   if(cant>0){
       printf("\ncantidad de elementos múltiplos del último número ingresado a la pila:%d\n",cant);
   }
   else{
       printf("\nNo hay numeros multiplos del ultimo numero.\n");
   }
   

   return 0;
}

