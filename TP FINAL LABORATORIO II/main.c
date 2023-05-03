#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include "Estetica.h"
#include "Clientes.h"
#include "Menu.h"
#include "Consumos.h"
#include <string.h>
#include "arbol.h"

#define CLIENTE "Clientes.dat"
#define CONSUMO "Consumos.dat"

#define PRECIOMB 0.32
#define MANTENIMIENTO 1500


#define DIM 1000

int pasarArchivoClientes2Arreglo (char archivo[], stCliente a[], int dim);
nodoArbol* arrayToArbol (stCliente a[], int base, int tope);
nodoArbol *pasarArchivoConsumos2ArbolDeListasPorFecha (char archivo[], nodoArbol *arbol);
nodoArbol *pasarArchivoCliente2ArbolApellido (char archivo[], nodoArbol *arbol);
nodoArbol *pasarArchivoCliente2ArbolNroCliente (char archivo[], nodoArbol *arbol);
nodoArbol *pasarArchivoConsumos2ArbolDeListasPorId (char archivo[], nodoArbol *arbol);
void pasajeListaAArchi(nodoArbol* arbol, char archivo[]);
void lista2Archi(nodoArbol* arbol, FILE* archi);
void pasajeArbol2Archi(nodoArbol* arbol, char archivo[]);
void arbol2Archi(nodoArbol* arbol, FILE* archi);
int buscaIdXDni(char nombreArchivo[], char dni[]);
nodoArbol * borrarNodoAdl (nodoArbol *arbol);
void mostrarFacturaXArbol(nodoArbol* arbol, char archivo[]);



int main()
{
    bannerBienvenida();
    menu1();
    return 0;
}


int pasarArchivoClientes2Arreglo (char archivo[], stCliente a[], int dim)  ///  funcion para pasar al arreglo el archivo de clientes
{
    int i=0;
    stCliente m;
    FILE *archi = fopen(archivo, "rb");
    if (archi)
    {
        while(i<dim && fread(&m, sizeof(stCliente), 1, archi)>0)
        {
            a[i]=m;
            i++;
        }
        fclose(archi);
    }
    return i;
}

nodoArbol* arrayToArbol (stCliente a[], int base, int tope)  /// pasar del arreglo al arbol de forma equilibrada los clientes
{
    int medio;

    nodoArbol *arbol=NULL;

    if(!(base>tope))
    {

        medio=(base+tope)/2;

        arbol=agregarArbol(arbol, a[medio]);

        arbol->izq=arrayToArbol(a,base,medio-1);
        arbol->der=arrayToArbol(a,medio+1,tope);
    }
    return arbol;
}



nodoArbol *pasarArchivoConsumos2ArbolDeListasPorFecha (char archivo[], nodoArbol *arbol)  /// pasar del archivo de consumos al arbol de listas, se usa para mostrar en orden por fecha los consumos
{
    stConsumos a;
    FILE *archi = fopen(archivo, "rb");
    if (archi)
    {
        while(fread(&a, sizeof(stConsumos), 1, archi)>0)
        {
            arbol=altaConsumosPorFecha (arbol, a);
        }

        fclose(archi);
    }
    return arbol;
}

nodoArbol *pasarArchivoConsumos2ArbolDeListasPorId (char archivo[], nodoArbol *arbol)  /// pasar del archivo de consumos al arbol de listas, se usa para mostrar en orden por id los consumos
{
    stConsumos a;
    FILE *archi = fopen(archivo, "rb");
    if (archi)
    {
        while(fread(&a, sizeof(stConsumos), 1, archi)>0)
        {
            arbol=altaConsumosPorId(arbol, a);
        }

        fclose(archi);
    }
    return arbol;
}

nodoArbol *pasarArchivoCliente2ArbolApellido (char archivo[], nodoArbol *arbol)  /// solo se pasa el archivo de cliente al arbol en orden por apellido para la muestra
{
    stCliente c;
    FILE *archi = fopen(archivo, "rb");
    if (archi)
    {
        while(fread(&c, sizeof(stCliente), 1, archi)>0)
        {
            arbol = agregarArbolOrdenApellido(arbol, c);
        }
        fclose(archi);
    }

    return arbol;
}


nodoArbol *pasarArchivoCliente2ArbolNroCliente (char archivo[], nodoArbol *arbol)  ///solo se pasa el archivo de cliente al arbol en orden por nro de cliente para la muestra
{
    stCliente c;
    FILE *archi = fopen(archivo, "rb");
    if (archi)
    {
        while(fread(&c, sizeof(stCliente), 1, archi)>0)
        {
            arbol = agregarArbolNroCliente(arbol, c);
        }
        fclose(archi);
    }

    return arbol;
}

int buscaIdXDni(char nombreArchivo[], char dni[])///FUNCION PARA LA COMPARACION DE DNI. CON -1 NO EXISTE. SINO RETORNA EL ID DEL CLIENTE
{
    int id = -1;
    stCliente a;

    FILE *archi = fopen(nombreArchivo, "rb");

    if(archi)
    {
        while(id == -1 && fread(&a, sizeof(stCliente),1,archi)>0)
        {
            if(strcmp(a.dni, dni) == 0)
            {
                id = a.idCliente ;
            }
        }
        fclose(archi);
    }

    return id;
}

void pasajeListaAArchi(nodoArbol* arbol, char archivo[]){ /// pasa las listas del ADL al archivo de consumo
if(arbol){

FILE* archi = fopen(archivo, "wb");

if(archi){
    lista2Archi(arbol,archi);
    }
    fclose(archi);
}else{
printf("\nNO HABIA ARBOL; NO PASO NADA A NINGUN ARCHIVO");
}
}

void lista2Archi(nodoArbol* arbol, FILE* archi) /// se usa funcion secundaria para la anterior, para pasar puntero file
{

    stConsumos a;
    nodo* copia = inicLista();
        if(arbol)
        {
            copia = arbol->listaDeConsumos;
            while(copia)
            {
                a=copia->dato;
                fwrite(&a,sizeof(stConsumos),1,archi);
                copia=copia->siguiente;
            }
            lista2Archi(arbol->izq, archi);
            lista2Archi(arbol->der, archi);
        }
}

void pasajeArbol2Archi(nodoArbol* arbol, char archivo[]){ /// pasa del arbol (solo estructura con los clientes) al archivo de clientes

if(arbol){
FILE* archi = fopen(archivo, "wb");

if(archi){
    arbol2Archi(arbol,archi);
    }
    fclose(archi);
}else{
printf("\nNO HABIA ARBOL; NO PASO NADA A NINGUN ARCHIVO");
}
}

void arbol2Archi(nodoArbol* arbol, FILE* archi) /// se usa funcion secundaria para la anterior, para pasar puntero file
{
        if(arbol)
        {

            arbol2Archi(arbol->izq, archi);
            fwrite(&arbol->dato,sizeof(stCliente),1,archi);
            arbol2Archi(arbol->der, archi);
        }
}


nodoArbol * borrarNodoAdl (nodoArbol *arbol){ /// contiene la llamada para borrar nodo del arbol
int opcion;
char dni[10];
    printf("\nIngrese el dni a buscar: ");
    fflush(stdin);
    gets(dni);

    int id = buscaIdXDni(CLIENTE, dni);
    if (id !=-1){
        printf("\nCON ESTA ACCION BORRARA AL CLIENTE POR COMPLETO!!!\n");
        printf("\nIngrese pin para borrar o cualquier letra para no hacerlo: ");
        scanf("%d", &opcion);
        if (opcion == 123){
            arbol=borrarNodoArbol(arbol,id);
            printf("\nCliente eliminado\n\n");
        }else{
            printf("\nPin incorrecto\n");
        }
    }else{
        printf("\nEl cliente no se encuentra en la base de datos\n");
    }

return arbol;
}

void mostrarFacturaXArbol(nodoArbol* arbol, char archivo[]){ /// muestra facturacion por periodo (por mes)

  char dni[10];
    int id;
    int existe = 1;
    int mes = 0;
    float costoTotal = 0;
    int datosConsumidos = 0;
    nodoArbol *buscado = inicArbol();

    printf("\nIngrese dni: ");
    fflush(stdin);
    gets(dni);

    id = buscaIdXDni(archivo, dni);
    buscado = buscarNodoArbol(arbol, id);

    if(!buscado)
    {
        printf("\nEl cliente no se encuentra en la base de datos .\n");
        system("pause");
    }else{
        printf("\nQue periodo desea liquidar?: \n");
        scanf("%d",&mes);
        if (mes>12){
            printf("\nEl periodo solicitado es incorrecto\n");
        }else{
        datosConsumidos = acumularLista(buscado->listaDeConsumos, mes);

        costoTotal = (float)datosConsumidos * PRECIOMB + MANTENIMIENTO;

    color(14);
    printf("\n=================================================");
    printf("\nApellido y Nombre..........:%10s, %s", buscado->dato.apellido, buscado->dato.nombre);
    printf("\nNumero de telefono.........:%20s",buscado->dato.movil);
    printf("\nPeriodo de factura.........:%20d",mes);
    printf("\nDatos Consumidos...........:%20d",datosConsumidos);
    printf("\nPrecio por MB..............:%20.2f",PRECIOMB);
    printf("\nPrecio por MANTENIMIENTO...:%20d",MANTENIMIENTO);
    printf("\nTotal......................:%20.2f",costoTotal);
    printf("\n=================================================");
    color(15);

        }
}
}

