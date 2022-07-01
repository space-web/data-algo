#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct alumnos{
    int legajo;
    char nya[30];
    int cant;
    struct alumnos *sig;
}nodoal;

int main(){
    nodoal *p=NULL;
    nodoal *q=NULL;
    p=(nodoal*)malloc(sizeof(nodoal));
    crear(p);
    mostrar(p);
    printf("\nLa cantidad de alumnos con mas de 10 materias aprobadas es: ", recorrer(p));
    q=(nodoal*)malloc(sizeof(noadoal));
    generar(p,q);
    printf("\nLa nueva lista con menos de 3 materias aprobadas es:\n");
    mostrar(q);

}
void crear(nodoal *h){
    printf("Ingrese legajo:");
    scanf("%d",&h->legajo);
    if(h->legajo==0)
        h->sig=NULL;
    else{
        printf("Ingrese nombre y apellido:");
        scanf("%s",h->nya);
        printf("\nIngrese la cantidad de materias aprobadas:");
        scanf("%d",&h->cant);
        h->sig=(nodoal*)malloc(sizeof(nodoal));
        crear(h->sig);
    }
}

void mostrar(nodoal *h){
    if(h->sig!=NULL){
        printf("\n%d",h->legajo);
        printf("\n%s",h->nya);
        printf("\n%d",h->cant);
        mostrar(h->sig);
    }
}

int recorrer(nodoal *h){
    int cont=0;
    while(h->sig!=NULL){
        if(h->cant>10){
            cont+=1;        
        }
        h=h->sig;
    }
    return cont;
}

void generar(nodoal *h, nodoal *q){
    while(h->sig!=NULL){
        if (h->cant<3){
            q->legajo=h->legajo;
            strcpy(q->nya,h->nya);
            q->cant=h->cant;
            q->sig=(nodoal*)malloc(sizeof(nodoal));
            q=q->sig;
        }
        h=h->sig;
    }
}

