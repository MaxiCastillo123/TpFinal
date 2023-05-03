#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listas.h"


nodo *inicLista ()
{
    return NULL;
}

nodo *crearNodoNuevo (stConsumos dato)
{
    nodo *nuevo =(nodo*)malloc(sizeof(nodo));
    nuevo->dato=dato;
    nuevo->siguiente=NULL;
    return nuevo;
}

void mostrarUnNodo (nodo *n)
{
    muestraUnConsumo (n->dato);
}

void mostrarLista (nodo*lista)
{
    while(lista!=NULL)
    {
        mostrarUnNodo(lista);
        lista=lista->siguiente;
    }
}


nodo *agregarAlPrincipio (nodo*lista, nodo*nuevo)
{
    if (lista==NULL)
    {
        lista=nuevo;
    }
    else
    {
        nuevo->siguiente=lista;
        lista=nuevo;
    }
    return lista;
}

nodo *agregarAlFinal (nodo *lista, nodo*nuevo)
{
    if (lista==NULL)
    {
        lista=nuevo;
    }
    else
    {
        nodo *copia=lista;

        while(copia->siguiente!=NULL)
        {
            copia=copia->siguiente;
        }
        copia->siguiente=nuevo;
    }
    return lista;
}


int comprobarFecha (nodo *lista, nodo *nueva)  /// retorna 0 si lista actual es menor. 1 si nuevo es menor
{
    int respuesta=0;
    if (lista->dato.anio > nueva->dato.anio)
    {
        respuesta = 1;
    }
    else if(lista->dato.mes >nueva->dato.mes && lista->dato.anio == nueva->dato.anio)
    {
        respuesta = 1;
    }
    else if(lista->dato.dia > nueva->dato.dia && lista->dato.mes == nueva->dato.mes && lista->dato.anio == nueva->dato.anio)
    {
        respuesta = 1;
    }

    return respuesta;
}

nodo *agregarEnOrdenPorFecha (nodo *lista, nodo *nuevo)
{
    if (lista == NULL || comprobarFecha(lista, nuevo) == 1 )
    {
        nuevo->siguiente = lista;
        lista = nuevo;
    }
    else
    {
        nodo*copia=lista->siguiente;
        nodo*anterior=lista;
        while(copia!=NULL && comprobarFecha(copia, nuevo) == 0)
        {
            anterior=copia;
            copia=copia->siguiente;
        }
        nuevo->siguiente=copia;
        anterior->siguiente=nuevo;
    }
    return lista;
}

nodo *agregarEnOrdenPorId (nodo *lista, nodo *nuevo)
{
    if(lista ==NULL || nuevo->dato.id < lista->dato.id)
    {
        nuevo->siguiente = lista;
        lista = nuevo;
    }
    else
    {
        nodo*copia=lista->siguiente;
        nodo*anterior=lista;
        while(copia!=NULL && nuevo->dato.id > lista->dato.id)
        {
            anterior=copia;
            copia=copia->siguiente;
        }
        nuevo->siguiente=copia;
        anterior->siguiente=nuevo;
    }
    return lista;
}

int acumularLista(nodo* lista, int mes) /// acumula para la facturacion
{
    int acumulador = 0;

    while(lista)
    {
        if(lista->dato.mes==mes)
        {
            acumulador = acumulador + lista->dato.datosConsumidos;
        }
        lista = lista->siguiente;
    }
    return acumulador;
}
