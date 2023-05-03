
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Estetica.h"
#include "Clientes.h"
#include "Consumos.h"
#include "Menu.h"

#include "arbol.h"

#define CLIENTE "Clientes.dat"
#define CONSUMO "Consumos.dat"




void menu1()
{
    int valor1;
    int valor2;
    int valor3;
    int valor4;
    int valor5;
    int valor6;
    int valor7;
    int valor8;
    do
    {

        system("cls");
        color(15);
        printf("\n       Menu de opciones con cual desea trabajar ?\n\n");
        printf("\n       1 - Clientes\n");
        printf("\n       2 - Consumos\n");
        printf("\n       3 - Imprimir factura\n");
        printf("\n       0 - Salir\n");
        printf("\n\n       Ingrese una opcion\n\n       ");
        color(15);
        bannerRecuadro();
        valor1=getch();
        int validos=0;
        nodoArbol *arbol = inicArbol(); /// variable agregada para mostrar los arboles
        stCliente lista1[100];
        stConsumos lista2[10000];
        switch(valor1)
        {
        case 49:
            do
            {
                system("cls");
                color(15);
                printf("\n       CLIENTES\n\n");
                printf("\n       1 - Alta de clientes\n");
                printf("\n       2 - Baja de cliente \n");
                printf("\n       3 - Alta de cliente inactivos\n");
                printf("\n       4 - Modificacion de datos\n");
                printf("\n       5 - Listados de Clientes\n");
                printf("\n       6 - Borrar Nodo de Cliente\n");
                printf("\n       0 - Volver menu anterior\n");
                printf("\n\n       Ingrese una opcion\n\n       ");
                color(15);
                bannerRecuadro();
                valor2=getch();
                switch(valor2)
                {
                case 49:
                    color(15);
                    printf("\n\t\n\tALTA DE CLIENTES\n\n");
                    color(15);

                    cargaArchivoCliente(CLIENTE);
                    getch();
                    break;
                case 54:
                    color(15);
                    printf("\n\t\n\tELIMINAR NODO DE CLIENTE\n\n");
                    color(15);

                    arbol = inicArbol();
                    validos = pasarArchivoClientes2Arreglo(CLIENTE, lista1, 10000);
                    arbol = arrayToArbol(lista1, 0, validos-1);
                    arbol = pasarArchivoConsumos2ArbolDeListasPorId(CONSUMO, arbol);

                    arbol=borrarNodoAdl(arbol);

                    pasajeListaAArchi(arbol, CONSUMO);
                    pasajeArbol2Archi(arbol, CLIENTE);

                    getch();
                    break;
                case 50:
                    color(15);
                    printf("\n\t\n\tBAJA DE CLIENTES\n\n");
                    color(15);
                    arbol = inicArbol();
                    validos = pasarArchivoClientes2Arreglo(CLIENTE, lista1, 10000);
                    arbol = arrayToArbol(lista1, 0, validos-1);
                    arbol= darDeBajaUnCliente(arbol,CLIENTE);
                    pasajeArbol2Archi(arbol,CLIENTE);

                    getch();
                    break;
                case 51:
                    color(15);
                    printf("\n\t\n\tALTA DE CLIENTE INACTIVOS\n\n");
                    color(15);
                    arbol = inicArbol();
                    validos = pasarArchivoClientes2Arreglo(CLIENTE, lista1, 10000);
                    arbol = arrayToArbol(lista1, 0, validos-1);
                    arbol= altaDeUnClienteEnArbol(arbol,CLIENTE);
                    pasajeArbol2Archi(arbol,CLIENTE);
                    getch();
                    break;
                case 52:
                    do
                    {
                        system("cls");
                        color(15);
                        printf("\n       MODIFICACION DE DATOS\n\n");
                        printf("\n       1 - Cambio titularidad\n");
                        printf("\n       2 - Nombre\n");
                        printf("\n       3 - Apellido\n");
                        printf("\n       4 - Dni\n");
                        printf("\n       5 - Email\n");
                        printf("\n       6 - Domiciilo\n");
                        printf("\n       7 - Movil\n");
                        printf("\n       0 - Volver menu anterior\n");
                        printf("\n\n       Ingrese una opcion\n\n       ");
                        color(15);
                        bannerRecuadro();
                        valor3=getch();
                        switch(valor3)
                        {
                        case 49:
                            color(15);
                            printf("\n\t\n\tCAMBIO DE TITULARIDAD\n\n");
                            color(15);

                            arbol = inicArbol();
                            validos = pasarArchivoClientes2Arreglo(CLIENTE, lista1, 10000);
                            arbol = arrayToArbol(lista1, 0, validos-1);
                            arbol = CambioDeTitularidadClienteArbol(arbol, CLIENTE);
                            pasajeArbol2Archi(arbol,CLIENTE);
                            getch();
                            break;
                        case 50:
                            color(15);
                            printf("\n\t\n\tNOMBRE\n\n");
                            color(15);

                            arbol = inicArbol();
                            validos = pasarArchivoClientes2Arreglo(CLIENTE, lista1, 10000);
                            arbol = arrayToArbol(lista1, 0, validos-1);
                            arbol = modificacionNombreClienteArbol(arbol, CLIENTE);
                            pasajeArbol2Archi(arbol,CLIENTE);
                            getch();
                            break;
                        case 51:
                            color(15);
                            printf("\n\t\n\tAPELLIDO\n\n");
                            color(15);

                            arbol = inicArbol();
                            validos = pasarArchivoClientes2Arreglo(CLIENTE, lista1, 10000);
                            arbol = arrayToArbol(lista1, 0, validos-1);
                            arbol = modificacionApellidoCliente1(arbol, CLIENTE);
                            pasajeArbol2Archi(arbol,CLIENTE);
                            getch();
                            break;
                        case 52:
                            color(15);
                            printf("\n\t\n\tDNI\n\n");
                            color(15);

                            arbol = inicArbol();
                            validos = pasarArchivoClientes2Arreglo(CLIENTE, lista1, 10000);
                            arbol = arrayToArbol(lista1, 0, validos-1);
                            arbol = modificacionDniClienteArbol(arbol, CLIENTE);
                            pasajeArbol2Archi(arbol,CLIENTE);
                            getch();
                            break;
                        case 53:
                            color(15);
                            printf("\n\t\n\tEMAIL\n\n");
                            color(15);

                            arbol = inicArbol();
                            validos = pasarArchivoClientes2Arreglo(CLIENTE, lista1, 10000);
                            arbol = arrayToArbol(lista1, 0, validos-1);
                            arbol = modificacionEmailClienteArbol(arbol, CLIENTE);
                            pasajeArbol2Archi(arbol,CLIENTE);
                            getch();
                            break;
                        case 54:
                            color(15);
                            printf("\n\t\n\tDOMICILIO\n\n");
                            color(15);

                            arbol = inicArbol();
                            validos = pasarArchivoClientes2Arreglo(CLIENTE, lista1, 10000);
                            arbol = arrayToArbol(lista1, 0, validos-1);
                            arbol = modificacionDireccionClienteArbol(arbol, CLIENTE);
                            pasajeArbol2Archi(arbol,CLIENTE);
                            getch();
                            break;
                        case 55:
                            color(15);
                            printf("\n\t\n\tMOVIL\n\n");
                            color(15);

                            arbol = inicArbol();
                            validos = pasarArchivoClientes2Arreglo(CLIENTE, lista1, 10000);
                            arbol = arrayToArbol(lista1, 0, validos-1);
                            arbol = modificacionCeluClienteArbol(arbol, CLIENTE);
                            pasajeArbol2Archi(arbol,CLIENTE);
                            getch();
                            break;
                        case 48:
                            break;
                        default:
                            color(4);
                            printf("\n\n\tSelecciono la opcion incorrecta\n",valor1);
                            color(15);
                            Sleep(350);
                            break;
                        }
                    }
                    while(valor3!=48);

                case 53:
                    do
                    {
                        system("cls");
                        color(15);
                        printf("\n       LISTADOS DE CLIENTES\n\n");
                        printf("\n       1 - Mostrar clientes\n");
                        printf("\n       2 - Ordenar clientes por Apellido\n");
                        printf("\n       3 - Ordenar clientes por Numero de cliente\n");
                        printf("\n       0 - Volver menu anterior\n");
                        printf("\n\n       Ingrese una opcion\n\n       ");
                        color(15);
                        bannerRecuadro();
                        valor4=getch();
                        switch(valor4)
                        {
                        case 49:
                            color(15);
                            printf("\n\t\n\tMOSTRANDO CLIENTES\n\n");
                            color(15);
                            arbol = inicArbol();
                            validos = pasarArchivoClientes2Arreglo(CLIENTE, lista1, 10000);
                            arbol = arrayToArbol(lista1, 0, validos-1);
                            inOrden(arbol);
                            getch();
                            break;
                        case 50:
                            color(15);
                            printf("\n\t\n\tLISTADO ORDENADO POR APELLIDO\n\n");
                            color(15);

                            arbol = inicArbol();
                            arbol = pasarArchivoCliente2ArbolApellido(CLIENTE, arbol); /// muestra clientes ordenados por apellido con el arbol
                            inOrden(arbol);

                            getch();
                            break;
                        case 51:
                            color(15);
                            printf("\n\t\n\tLISTADO ORDENADO POR NUMERO DE CLIENTE\n\n");
                            color(15);

                            arbol = inicArbol();
                            arbol = pasarArchivoCliente2ArbolNroCliente(CLIENTE, arbol); /// muestra clientes ordenados por nro de cliente con el arbol
                            inOrden(arbol);
                            getch();
                            break;
                        }
                    case 48:
                        break;
                    default:
                        color(4);
                        printf("\n\n\tSelecciono la opcion incorrecta\n",valor1);
                        color(15);
                        Sleep(350);
                        break;
                    }
                    while(valor4!=48);
                }
            }
            while(valor2!=48);

            break;
        case 50:
            do
            {
                system("cls");
                color(15);
                printf("\n       CONSUMOS\n\n");
                printf("\n       1 - Alta de Consumo\n");
                printf("\n       2 - Baja de Consumo\n");
                printf("\n       3 - Alta de Consumo inactivo\n");
                printf("\n       4 - Modificacion de Consumo\n");
                printf("\n       5 - Listados de consumo\n");
                printf("\n       0 - Volver menu anterior\n");
                printf("\n\n       Ingrese una opcion\n\n       ");
                color(15);
                bannerRecuadro();
                valor5=getch();
                switch(valor5)
                {
                case 49:
                    do
                    {
                        system("cls");
                        color(15);
                        printf("\n       ALTA DE CONSUMO\n\n");
                        printf("\n       1 - Carga manual\n");
                        printf("\n       2 - Carga automatica\n");
                        printf("\n       0 - Volver menu anterior\n");
                        printf("\n\n       Ingrese una opcion\n\n       ");
                        color(15);
                        bannerRecuadro();

                        valor6=getch();
                        switch(valor6)
                        {
                        case 49:
                            color(15);
                            printf("\n\t\n\tCARGA MANUAL\n\n");
                            color(15);

                            cargaArchivoConsumosFinal(CONSUMO,CLIENTE);
                            getch();
                            break;
                        case 50:
                            color(15);
                            printf("\n\t\n\tCARGA AUTOMATICA\n\n");
                            color(15);

                            cargaArchivoConsumosRandom(CONSUMO,CLIENTE);

                            getch();
                            break;
                        case 48:
                            break;
                        default:
                            color(4);
                            printf("\n\n\tSelecciono la opcion incorrecta\n",valor1);
                            color(15);
                            Sleep(350);
                            break;
                        }
                    }

                    while(valor6!=48);

                    break;
                case 50:
                    color(15);
                    printf("\n\t\n\tBAJA DE CONSUMO\n\n");
                    color(15);
                    arbol = inicArbol();
                    validos = pasarArchivoClientes2Arreglo(CLIENTE, lista1, 10000);
                    arbol = arrayToArbol(lista1, 0, validos-1);
                    arbol=pasarArchivoConsumos2ArbolDeListasPorId(CONSUMO, arbol);
                    arbol = eliminarUnConsumo(arbol,CLIENTE);
                    pasajeListaAArchi(arbol, CONSUMO);
                    getch();
                    break;
                case 51:
                    color(15);
                    printf("\n\t\n\tALTA DE CONSUMO INACTIVO\n\n");
                    color(15);
                    arbol = inicArbol();
                    validos = pasarArchivoClientes2Arreglo(CLIENTE, lista1, 10000);
                    arbol = arrayToArbol(lista1, 0, validos-1);
                    arbol=pasarArchivoConsumos2ArbolDeListasPorId(CONSUMO, arbol);
                    arbol = activaConsumo(arbol,CLIENTE);
                    pasajeListaAArchi(arbol, CONSUMO);
                    getch();
                    break;
                case 52:
                    color(15);
                    printf("\n\t\n\tMODIFICACION DE CONSUMO\n\n");
                    color(15);
                    arbol = inicArbol();
                    validos = pasarArchivoClientes2Arreglo(CLIENTE, lista1, 10000);
                    arbol = arrayToArbol(lista1, 0, validos-1);
                    arbol=pasarArchivoConsumos2ArbolDeListasPorId(CONSUMO, arbol);
                    arbol = modificarUnConsumo(arbol,CLIENTE);
                    pasajeListaAArchi(arbol, CONSUMO);
                    getch();
                    break;
                case 53:
                    do
                    {
                        system("cls");
                        color(15);
                        printf("\n       LISTADOS DE CONSUMO\n\n");
                        printf("\n       1 - Id de consumo\n");
                        printf("\n       2 - Fecha\n");
                        printf("\n       0 - Volver al menu anterior\n");
                        printf("\n\n       Ingrese una opcion\n\n       ");
                        color(15);
                        bannerRecuadro();
                        valor6=getch();
                        switch(valor6)
                        {
                        case 49:
                            color(15);
                            printf("\n\t\n\tLISTADOS DE CONSUMO ORDENADO POR ID CONSUMO\n\n");
                            color(15);
                            arbol = inicArbol();
                            validos = pasarArchivoClientes2Arreglo(CLIENTE, lista2, 10000); /// muestra los consumos por cliente ordenados por id con arbol de listas
                            arbol=arrayToArbol(lista2, 0, validos -1);
                            arbol = pasarArchivoConsumos2ArbolDeListasPorId(CONSUMO, arbol);
                            inOrden(arbol);
                            getch();
                            break;
                        case 50:
                            color(15);
                            printf("\n\t\n\tLISTADOS DE CONSUMO ORDENADO POR FECHA\n\n");
                            color(15);
                            arbol = inicArbol();
                            validos = pasarArchivoClientes2Arreglo(CLIENTE, lista2, 10000); /// muestra los consumos por cliente ordenados por fecha con arbol de listas
                            arbol=arrayToArbol(lista2, 0, validos -1);
                            arbol= pasarArchivoConsumos2ArbolDeListasPorFecha(CONSUMO, arbol);
                            inOrden(arbol);
                            getch();
                            break;
                        case 48:
                            break;
                        default:
                            color(4);
                            printf("\n\n\tSelecciono la opcion incorrecta\n",valor1);
                            color(15);
                            Sleep(350);
                            break;
                        }
                    }
                    while(valor6!=48);
                    break;
                case 48:
                    break;
                default:
                    color(4);
                    printf("\n\n\tSelecciono la opcion incorrecta\n",valor1);
                    color(15);
                    Sleep(350);
                    break;
                }
            }

            while(valor5!=48);
            break;

        case 51:
            color(15);
            printf("\n\t\n\tIMPRIMIR FACTURA\n\n");
            color(15);
            arbol = inicArbol();
            validos = pasarArchivoClientes2Arreglo(CLIENTE, lista1, 10000);
            arbol = arrayToArbol(lista1, 0, validos-1);
            arbol= pasarArchivoConsumos2ArbolDeListasPorFecha(CONSUMO, arbol);
            mostrarFacturaXArbol(arbol, CLIENTE);
            getch();
            break;

        case 48:
        default:
            color(4);
            printf("\n\n\tChau\n",valor1);
            color(15);
            Sleep(350);
            break;
        }


    }
    while(valor1!=48);

}
