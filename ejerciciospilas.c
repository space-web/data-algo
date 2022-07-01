/*La cantidad de números múltiplos de 3.
El promedio de aquellos números divisores de 4
La sumatoria de aquellos números múltiplos del primer elemento ingresado a la pila.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct tiponodo
{
	int dato;

    struct tiponodo *siguiente;
}nodo;

void mostrar (nodo aux,int *cont,float *cont2,float *sum,int *sum2,int *primero,int *max,int *posicion, int *pos,int *min,int *pos2)

{
    //cantidad de números múltiplos de 3
 
    printf("%d \n", aux.dato);
     *posicion+=1;
     printf("pos:%d\n",*posicion);
    if(aux.dato%3==0){
        *cont=*cont+1;
    }
    //promedio de aquellos números divisores de 4
    if(4%aux.dato==0){
        *sum=*sum+aux.dato;
        *cont2=*cont2+1;
    }
    //sumatoria de aquellos números múltiplos del primer elemento ingresado a la pila
    if(aux.dato%*primero==0){
        *sum2=*sum2+aux.dato;
    }
    //El número máximo y su posición en la pila
    if(aux.dato>*max){
        *max=aux.dato;
        *pos=*posicion;
    }
    //El número mínimo y su posición en la pila
    if(aux.dato<*min){
        *min=aux.dato;
        *pos2=*posicion;
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


    int i,num,cont=0,sum2=0,primero=0,max,posicion=0,pos=0,min,pos2;
    float sum=0,cont2=0;
    nodo* p=NULL;
    printf("Ingrese un numero \n");
   	scanf("%d",&num);
   	primero=num;
   	max=num;
   	min=num;
    while(num!=-1)
    {
        apilar(&p, crear_nodo(num));
   	    printf("Ingrese un numero \n");
   	    scanf("%d",&num);
    }


    printf("\nVamos a desapilar todo\n");
	while(p!=NULL)
    {
    	mostrar(desapilar(&p),&cont,&cont2,&sum,&sum2,&primero,&max,&posicion,&pos,&min,&pos2);
    }
    printf("\ncant de multiplos de 3: %d",cont);
    printf("\npromedio de divisores de 4: %f",sum/cont2);
    printf("\nsumatoria de los numeros multiplos del primer nro: %d",sum2);
    printf("\nmax num: %d posicion: %d",max,pos);
    printf("\nmin num: %d posicion: %d",min,pos2);

    return 0;
}

