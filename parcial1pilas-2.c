/*Crear una pila con la siguiente información:
 num: numero entero.
 siguiente: puntero al próximo elemento de la pila.
Desarrollar una función que permita mostrar la sumatoria de números
mayores al primer elemento ingresado en la pila. Si no hubiera ningún
número mostrar una leyenda.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct tiponodo
{
	int num;

    struct tiponodo *siguiente;
}nodo;

void mostrar (nodo aux, int *primero, int *sum)
{
    if(aux.num>*primero){
        *sum+=aux.num;
    }
    printf("%d \n", aux.num);
}


nodo* crear_nodo(int num )
{
   nodo* u;
   u = (nodo *)malloc(sizeof(nodo));
   u->num = num;

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


    int num, primero=0,sum=0;
    nodo* p=NULL;

    printf("Ingresar numero: ");
    scanf("%d",&num);
    primero=num;
    
    while(num!=0){
        apilar(&p, crear_nodo(num));
        printf("\nIngresar numero: ");
        scanf("%d",&num);
    }

    printf("\nVamos a desapilar todo\n");
	while(p!=NULL)
    {
        mostrar(desapilar(&p),&primero,&sum);
    }

    printf("\nLa suma de los elementos mayores al primer elemento es: %d", sum);
   
    return 0;
}
