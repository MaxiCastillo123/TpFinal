#ifndef CONSUMOS_H_INCLUDED
#define CONSUMOS_H_INCLUDED
#include "Clientes.h"

typedef struct
{
    int id;
    int idCliente;
    int anio;
    int mes;
    int dia;
    int datosConsumidos;
    int baja;
} stConsumos;


stConsumos cargaUnConsumoAnioActual();
void cargaArchivoConsumosRandom(char nombreArchivoConsumos[], char nombreArchivoClientes[]);
stConsumos cargaUnConsumo(char nombreArchivo[]);
int ultimoIdConsumo(char nombreArchivo[]);
void muestraUnConsumo(stConsumos a);
///stConsumos busquedaConsumo();
void cargaArchivoConsumosFinal(char nombreArchivoConsumos[], char nombreArchivoClientes[]);
int comprobarConsumo2(char nombreArchivo[], stConsumos a);
int obtenerConsumo(char nombreArchivo [], stConsumos a);
int obtenerIdConsumo(char nombreArchivo [], stConsumos a);
int buscarPosID(char nombreArchivo[], stConsumos b);
int busquedaID(char nombreArchivo[]);
stCliente busquedaClientesParaConsumos(char nombreArchivo[]);
int comprobacionDniParaConsumoCliente(char nombreArchivo [], char dni[]);

#endif // CONSUMOS_H_INCLUDED
