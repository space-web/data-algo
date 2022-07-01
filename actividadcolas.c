/* Desarrollar un programa en C que permita cargar un cola de n números enteros. 
Calcular y mostrar (en una función y no en el programa principal) la sumatoria 
de los elementos en posición par de la cola. (se considera que el primer que entra
está en la posición uno y así sucesivamente).*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define CANT 4




typedef struct tiponodo
{
	int dato;

    struct tiponodo *siguiente;
}nodo;

void mostrar (nodo aux)
{
  	printf("%d \n", aux.dato);
}

nodo* crear_nodo(int dato)
{
   nodo* u;
   u = (nodo *)malloc(sizeof(nodo));

   u->dato = dato;

   u->siguiente = NULL;

   return u;
}

void acolar(nodo** p,nodo** u, nodo *q,int *sum,int *posicion)
{
   printf("acolar_nodo\n");
	if(*p==NULL)
    *p = *u = q; /*porque hay uno solo*/
   else
   {
    	(*u)->siguiente = q;
    	(*u) = q;
   }
   
  	*posicion=*posicion+1;
  	if(*posicion%2==0){
  	    *sum=*sum+q->dato;
  	}
}

nodo desacolar(nodo** inicio)
{
	nodo* aux;
   nodo datos;

	datos=**inicio;

	aux=*inicio;

	*inicio=(*inicio)->siguiente;
	free(aux);

    return datos;
}

int main()
{

   int i,num,sum=0,posicion=0;
   nodo* p=NULL;
   nodo* u=NULL;

   for(i=0; i<CANT; i++)
   {
       printf("Ingrese un numero");
       scanf("%d",&num);
        acolar(&p, &u, crear_nodo(num),&sum,&posicion);

   }
    printf("\nsuma:%d\n",sum);

   printf("\nVamos a desacolar todo\n");
	while(p!=NULL)
   {
    	mostrar(desacolar(&p));
   }
   return 0;
}

