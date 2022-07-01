/*
Crear una cola con la siguiente información:
 num: numero entero.
 siguiente: puntero al próximo elemento de la cola.
 Escribir una función para calcular el máximo elemento de la cola y en qué posición
está.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define CANT 5


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

void acolar(nodo** p,nodo** u, nodo *q,int *max,int *pos, int *posicion)
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
  	if(q->dato>*max){
  	    *max=q->dato;
  	    *pos=*posicion;
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

   int i,num,max=0,pos=0,posicion=0;
   nodo* p=NULL;
   nodo* u=NULL;

   for(i=0; i<CANT; i++)
   {
       printf("Ingrese un numero");
       scanf("%d",&num);
       if(i==0){
           max=num;
       }
        acolar(&p, &u, crear_nodo(num),&max,&pos,&posicion);

   }
   printf("\nmax val: %d, posicion: %d\n",max,pos);


   printf("\nVamos a desacolar todo\n");
	while(p!=NULL)
   {
    	mostrar(desacolar(&p));
   }
   return 0;
}
