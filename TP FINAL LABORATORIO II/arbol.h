#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED


#include "Clientes.h"
#include "listas.h"
#include <string.h>



typedef struct nodoArbol{
    stCliente dato;
    int modificado;
     struct nodoArbol *izq;
     struct nodoArbol *der;
     nodo * listaDeConsumos;
}nodoArbol;



nodoArbol * inicArbol ();
nodoArbol * crearNodoArbol (stCliente dato);
nodoArbol *agregarArbol (nodoArbol *arbol, stCliente dato);
void preOrden (nodoArbol *arbol);
void inOrden (nodoArbol *arbol);
void postOrden (nodoArbol *arbol);
nodoArbol *buscarNodoArbol (nodoArbol *arbol, int id);
nodoArbol *borrarNodoArbol (nodoArbol *arbol, int id);
nodoArbol *nodoMasDerecho(nodoArbol *arbol);
nodoArbol *nodoMasIzquierdo(nodoArbol *arbol);
nodoArbol *borrarNodoArbolMejorada (nodoArbol *arbol, int id);

nodoArbol *buscarPos (nodoArbol *arbol, int id);
nodoArbol *agregarArbolOrdenApellido (nodoArbol *arbol, stCliente dato);
nodoArbol *agregarArbolNroCliente (nodoArbol *arbol, stCliente dato);
nodoArbol *altaConsumosPorFecha (nodoArbol *arbol, stConsumos a);
nodoArbol *altaConsumosPorId (nodoArbol *arbol, stConsumos a);
nodoArbol* eliminarUnConsumo(nodoArbol* arbol, char archivo[]);
nodoArbol* activaConsumo(nodoArbol* arbol, char archivo[]);
nodoArbol* modificarUnConsumo(nodoArbol* arbol, char archivo[]);
nodoArbol * modificacionApellidoCliente1(nodoArbol* arbol, char archivo[]);
nodoArbol* modificacionNombreClienteArbol(nodoArbol* arbol, char archivo[]);
nodoArbol* modificacionDniClienteArbol(nodoArbol* arbol, char archivo[]);
nodoArbol* modificacionEmailClienteArbol(nodoArbol* arbol, char archivo[]);
nodoArbol* modificacionCeluClienteArbol(nodoArbol* arbol, char archivo[]);
nodoArbol * modificacionDireccionClienteArbol(nodoArbol* arbol, char archivo[]);
nodoArbol * CambioDeTitularidadClienteArbol(nodoArbol* arbol, char archivo[]);
nodoArbol* darDeBajaUnCliente(nodoArbol* arbol, char archivo[]);
nodoArbol* altaDeUnClienteEnArbol(nodoArbol* arbol, char archivo[]);








#endif // ARBOL_H_INCLUDED
