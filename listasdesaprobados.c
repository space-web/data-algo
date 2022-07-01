/* 

Se ingresan el nombre del curso, la cantidad de alumnos y la cantidad de alumnos aprobados en matematica.

Crear una lista simplemente enlazada con estos datos y mostrarla. La carga de datos finaliza cuando el nombre del curso es igual a "Z"

-Generar una nueva lista con el nombre del curso y el porcentaje de desaprobados en matematica.
-Generar una nueva lista con el nombre del curso y la cantidad de desaprobados en matematica.
-En esta ultima lista generada insertar antes, el nombre del curso y el porcentaje de desaprobados de ese curso.
-Eliminar de la primera lista generada aquellos cursos cuyo porcentaje de aprobacion es mayor al 70%.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista{
	char curso[30];
	float cantalum;
	float cantmat;
	struct lista *sig;
 }nodo;
 
typedef struct lista2{
	char nomcurso[30];
	float des;
	struct lista2 *sig2;
 }nodo2;
 
typedef struct lista3{
	char nomcurso[30];
	float cant;
	struct lista3 *sig;
 }nodo3;



void crear (nodo *p)
{
    char *z = "Z";

    printf("\nIngresar curso:");
    scanf("%s",p->curso);
    if (strcmp(p->curso,z) == 0)
        p->sig=NULL;
    else
	{
	    printf("\nCantidad de alumnos:");
	    scanf("%f",&p->cantalum);
	    printf("\nCant de alumnos aprobados en mat:");
	    scanf("%f",&p->cantmat);
        p->sig=(nodo*)malloc(sizeof(nodo));
        crear (p->sig);

	}
	return;
}

void mostrar (nodo *p)
{
    if (p->sig !=NULL)
	{
	    printf("\nCurso: %s",p->curso);
        printf ("\nCantidad de alumnos: %f",p->cantalum);
        printf("\nCant de alumnos aprobados en mat: %f",p->cantmat);
        mostrar (p->sig);
	}
	return;
}

void generar1(nodo *p, nodo2 *q){
    while(p->sig!=NULL){
        strcpy(q->nomcurso,p->curso);
        q->des=((p->cantalum-p->cantmat)/p->cantalum)*100;
        q->sig2=(nodo2*)malloc(sizeof(nodo2));
        q=q->sig2;
        p=p->sig;
    } 
    q->sig2=NULL;
}

void mostrar2(nodo2 *q)
{
    if (q->sig2 !=NULL)
	{
	    printf("\nCurso: %s",q->nomcurso);
        printf ("\nPorcentaje de desaprobados en matematica: %f",q->des);
        mostrar2(q->sig2);
	}
	return;
}
//Generar una nueva lista con el nombre del curso y la cantidad de desaprobados en matematica.

void generar2(nodo *p, nodo3 *k){
    while(p->sig!=NULL){
        strcpy(k->nomcurso,p->curso);
        k->cant=p->cantalum-p->cantmat;
        k->sig=(nodo3*)malloc(sizeof(nodo3));
        k=k->sig;
        p=p->sig;
    }    
    k->sig=NULL;
}

void mostrar3(nodo3 *k){
    if(k->sig!=NULL){
        printf("\nNombre de Curso: %s",k->nomcurso);
        printf("\nCant de desaprobados en matematica: %f",k->cant);
        mostrar3(k->sig);
    }
}

nodo3* insertar1(nodo3 *k, nodo2 *q)
{
    nodo3 *aux;
    {
        aux=(nodo3*)malloc(sizeof(nodo3));
        strcpy(aux->nomcurso,k->nomcurso);
        aux->cant=q->des;
        aux->sig=k;
        k=aux;
        q=q->sig2;
    }
    return k;
}

void insertar2 (nodo3 *k, nodo2 *q)
{nodo3 *aux;
k=k->sig;
    while(k->sig!=NULL && q->sig2->sig2!=NULL)
    {
        {
            aux=(nodo3 *)malloc(sizeof(nodo3));
            
            strcpy(aux->nomcurso,k->sig->nomcurso);
            aux->cant=q->sig2->des;
            
            aux->sig=k->sig;
            k->sig=aux;
            q=q->sig2;

        }
        k=k->sig->sig;
    }
}

nodo* eliminar1(nodo* p)
{nodo *aux;
    while((p->cantmat*100/p->cantalum)>70)//condicion de eliminacion
    {
        aux=p->sig;
        free(p);
        p=aux;
    }
    return p;
}

void eliminar2(nodo* p)
{nodo *aux;
    while(p->sig!=NULL&& p->sig->sig!=NULL)
    {
        if((p->cantmat*100/p->cantalum)>70)//condicion de eliminacion
        {
            aux=p->sig->sig;
            free(p->sig);
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

    nodo *p=NULL;
    nodo2 *q=NULL;
    nodo3 *k=NULL;
    k=(nodo3*)malloc(sizeof(nodo3));
    q=(nodo2*)malloc(sizeof(nodo2));
    p=(nodo*)malloc(sizeof(nodo));
    
    crear(p);
    mostrar(p);
    printf("\n-----------------\n");
    printf("\nPorcentaje de desaprobados en mat:\n");
    generar1(p,q);
    mostrar2(q);

    printf("\n-----------------\n");
    printf("\nCant de desaprobados:\n");
    generar2(p,k);
    mostrar3(k);

    printf("\n-----------------\n");
    printf("\nLista con inserciones:\n");
    k=insertar1(k,q);
    insertar2(k,q);
    mostrar3(k);
    

   p=eliminar1(p);
    eliminar2(p);
    mostrar(p);

    return 0;
}