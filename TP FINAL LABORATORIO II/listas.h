#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED

#include "Consumos.h"

typedef struct nodo{
 stConsumos dato;
 int modificado;
 struct nodo *siguiente;
}nodo;


nodo *inicLista ();
nodo *crearNodoNuevo (stConsumos dato);
void mostrarUnNodo (nodo *n);
void mostrarLista (nodo*lista);
nodo *agregarAlPrincipio (nodo*lista , nodo*nuevo);
nodo *agregarAlFinal (nodo *lista, nodo*nuevo);


int comprobarFecha (nodo *lista, nodo *nueva);
nodo *agregarEnOrdenPorFecha (nodo *lista, nodo *nuevo);
nodo *agregarEnOrdenPorId (nodo *lista, nodo *nuevo);

int acumularLista(nodo* lista, int mes);

#endif // LISTAS_H_INCLUDED
