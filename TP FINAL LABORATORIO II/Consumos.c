#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include "Estetica.h"

#include "Consumos.h"



stConsumos cargaUnConsumoAnioActual()
{

    stConsumos a;
    time_t t =time(NULL);
    struct tm tiempoLocal = *localtime(&t);

    a.anio = tiempoLocal.tm_year + 1900;
    a.mes = rand()%(tiempoLocal.tm_mon+1) +1;
    if(a.mes == tiempoLocal.tm_mon+1)
    {
        a.dia = rand()%(tiempoLocal.tm_mday - 1) + 1;
    }
    else if(a.mes == 1)
    {
        a.dia = rand()%(31 - 1) + 1;
    }
    else if(a.mes == 2 && (a.anio%4 == 0) )
    {
        a.dia = rand()%(29 - 1) + 1;
    }
    else if(a.mes == 2 && (a.anio%4 != 0))
    {
        a.dia = rand()%(28-1)+1;
    }
    else if(a.mes == 3)
    {
        a.dia = rand()%(31 - 1) + 1;
    }
    else if(a.mes == 4)
    {
        a.dia = rand()%(30 - 1) + 1;
    }
    else if(a.mes == 5)
    {
        a.dia = rand()%(31 - 1) + 1;
    }
    else if(a.mes == 6)
    {
        a.dia = rand()%(30 - 1) + 1;
    }
    else if(a.mes == 7)
    {
        a.dia = rand()%(31 - 1) + 1;
    }
    else if(a.mes == 8)
    {
        a.dia = rand()%(31 - 1) + 1;
    }
    else if(a.mes == 9)
    {
        a.dia = rand()%(30 - 1) + 1;
    }
    else if(a.mes == 10)
    {
        a.dia = rand()%(31 - 1) + 1;
    }
    else if(a.mes == 11)
    {
        a.dia = rand()%(30 - 1) + 1;
    }
    else if(a.mes == 12)
    {
        a.dia = rand()%(31 - 1) + 1;
    }
    a.datosConsumidos = rand()%(2000-5)+5;
    a.baja = 0;
    return a;
}
void cargaArchivoConsumosRandom(char nombreArchivoConsumos[], char nombreArchivoClientes[])///CARGA ARCHIVO CONSUMOS RANDOM
{
    stConsumos a;
    stConsumos b;
    static int i = 0;
    i=ultimoIdConsumo(nombreArchivoConsumos);
    int iClientes = 0;
    int pos = 0;
    iClientes = ultimoIdCliente(nombreArchivoClientes);
    int flag = 0;
    int sumarDatos = 0;
    int idConsumo = 0;
    int c= 1;

    FILE *archi = fopen(nombreArchivoConsumos, "r+b");

    if(archi == NULL)
    {
        FILE *archi = fopen(nombreArchivoConsumos, "ab");
        fclose(archi);
        fopen(nombreArchivoConsumos, "r+b");
    }
    if(archi != NULL)
    {

        for(int j = 0; j <30; j++)
        {
            a = cargaUnConsumoAnioActual();
            a.idCliente = rand()%iClientes+1;
            a.id = 0;
            while(flag == 0 && fread(&b,sizeof(stConsumos),1,archi)>0)
            {
                flag = comprobarConsumo2(nombreArchivoConsumos, a);
                if(flag == 1)
                {
                    pos =buscarPosID(nombreArchivoConsumos,a);
                    flag = 1;
                    sumarDatos = obtenerConsumo(nombreArchivoConsumos, a);
                    a.datosConsumidos = a.datosConsumidos + sumarDatos;
                    idConsumo = obtenerIdConsumo(nombreArchivoConsumos,a);
                    a.id = idConsumo;
                    fseek(archi,sizeof(stConsumos)*(pos-1),SEEK_SET);
                }
                else
                {
                    fseek(archi,0,SEEK_END);
                    i++;
                    a.id = i;
                }
            }
            fwrite(&a,sizeof(stConsumos),1,archi);
            flag = 0;
            fclose(archi);
            archi = fopen(nombreArchivoConsumos, "r+b");
        }

        fclose(archi);
    }

}
stConsumos cargaUnConsumo(char nombreArchivo[])/// CARGA UN CONSUMO MANUAL
{

    stConsumos a;
    a.idCliente = busquedaID(nombreArchivo);
    printf("\nIngrese el año de consumo: ");
    scanf("%d", &a.anio);
    printf("Ingrese el mes de consumo: ");
    scanf("%d", &a.mes);

    if(a.mes >12)
    {
        while(a.mes >12)
        {
            printf("\nMes no valido, ingreselo nuevamente: \n");
            scanf("%d", &a.mes);
        }
    }
    printf("Ingrese el dia de consumo: ");
    scanf("%d", &a.dia);

    if(a.dia >29 && a.mes == 2 && (a.anio%4 == 0))
    {
        while(a.dia > 29)
        {
            printf("\nFecha invalida. Valida hasta el 29. Ingresela nuevamente: ");
            scanf("%d", &a.dia);
        }
    }
    else if(a.dia>28 && a.mes == 2 && (a.anio%4 != 0))
    {
        while(a.dia > 28)
        {
            printf("\nFecha invalida. Valida hasta el 28. Ingresela nuevamente: ");
            scanf("%d", &a.dia);
        }
    }
    else if((a.mes == 1|| a.mes == 3 || a.mes == 5|| a.mes == 7|| a.mes == 8|| a.mes == 10|| a.mes == 12 )&& a.dia>31)
    {
        while(a.dia > 31)
        {
            printf("\nFecha invalida. Valida hasta 31. Ingresela nuevamante: ");
            scanf("%d", &a.dia);
        }
    }
    else
    {
        while(a.dia > 30 )
        {
            printf("\nFecha invalida. Valida hasta 30. Ingresela nuevamente: ");
            scanf("%d", &a.dia);
        }
    }
    printf("\nIngrese la cantidad de MB consumidos: ");
    scanf("%d", &a.datosConsumidos);
    a.baja = 0;

    return a;
}
void cargaArchivoConsumosFinal(char nombreArchivoConsumos[], char nombreArchivoClientes[])///CARGA ARCHIVO DE CONSUMOS MANUAL.
{
    stConsumos a;
    stConsumos b;
    static int i = 0;
    i=ultimoIdConsumo(nombreArchivoConsumos);

    int pos = 0;

    int flag = 0;
    int sumarDatos = 0;
    int idConsumo = 0;
    char opcion = 0;

    FILE *archi = fopen(nombreArchivoConsumos, "r+b");
    if(archi == NULL)
    {
        FILE *archi = fopen(nombreArchivoConsumos, "ab");
        fclose(archi);
        archi = fopen(nombreArchivoConsumos, "r+b");
    }
    if(archi != NULL)
    {
        do
        {

            a = cargaUnConsumo(nombreArchivoClientes);
            a.id = 0;
            while(flag == 0 && fread(&b,sizeof(stConsumos),1,archi)>0)
            {
                flag = comprobarConsumo2(nombreArchivoConsumos, a);
                if(flag == 1)
                {
                    pos =buscarPosID(nombreArchivoConsumos,a);
                    flag = 1;
                    sumarDatos = obtenerConsumo(nombreArchivoConsumos, a);
                    a.datosConsumidos = a.datosConsumidos + sumarDatos;
                    idConsumo = obtenerIdConsumo(nombreArchivoConsumos,a);
                    a.id = idConsumo;
                    fseek(archi,sizeof(stConsumos)*(pos-1),SEEK_SET);

                }
                else
                {
                    fseek(archi,0,SEEK_END);
                    i++;
                    a.id = i;
                }
            }
            fwrite(&a,sizeof(stConsumos),1,archi);
            printf("\nDesea seguir cargando consumos? ESC PARA SALIR: ");
            opcion = getch();
            fflush(stdin);
            flag = 0;
            if(opcion !=27)
            {
                fclose(archi);

                archi = fopen(nombreArchivoConsumos, "r+b");

            }
        }
        while(opcion != 27);
        fclose(archi);
    }

}
int comprobarConsumo2(char nombreArchivo[], stConsumos a)///COMPROBAR UN CONSUMO
{

    stConsumos b;
    int flag = 0;
    FILE *archi = fopen(nombreArchivo, "rb");
    if(archi)
    {
        while(flag == 0 && fread(&b,sizeof(stConsumos),1,archi)>0)
        {
            if(a.dia == b.dia && a.mes == b.mes && a.anio == b.anio && a.idCliente == b.idCliente)
            {
                flag = 1;
            }
        }
        fclose(archi);
    }

    return flag;
}
int obtenerConsumo(char nombreArchivo [], stConsumos a)///OBTENER UN CONSUMO
{

    stConsumos b;
    int flag = 0;
    int datosConsumidos = 0;

    FILE *archi = fopen(nombreArchivo, "rb");
    if(archi)
    {
        while(flag == 0 && fread(&b,sizeof(stConsumos),1,archi)>0)
        {
            if(a.dia == b.dia && a.mes == b.mes && a.anio == b.anio && a.idCliente == b.idCliente)
            {
                flag = 1;

            }
        }
        fclose(archi);
    }
    fseek(archi,sizeof(stConsumos)*-1,SEEK_CUR);
    datosConsumidos = b.datosConsumidos;
    return datosConsumidos;
}
int obtenerIdConsumo(char nombreArchivo [], stConsumos a)///OBTENER EL ID DE UN CONSUMO
{

    stConsumos b;
    int flag = 0;
    int idConsumo = 0;

    FILE *archi = fopen(nombreArchivo, "rb");
    if(archi)
    {
        while(flag == 0 && fread(&b,sizeof(stConsumos),1,archi)>0)
        {
            if(a.dia == b.dia && a.mes == b.mes && a.anio == b.anio && a.idCliente == b.idCliente)
            {
                flag = 1;

            }
        }
        fclose(archi);
    }
    fseek(archi,sizeof(stConsumos)*-1,SEEK_CUR);
    idConsumo = b.id;

    return idConsumo;
}

int buscarPosID(char nombreArchivo[], stConsumos b)///OBTENER POSICION DE UN ID DE CONSUMO
{

    stConsumos a;
    int posicion = 0;
    int flag = 0;
    FILE *archi = fopen(nombreArchivo, "rb");
    if(archi)
    {
        while(flag == 0 && fread(&a, sizeof(stConsumos),1,archi)>0)
        {
            if(a.dia == b.dia && a.mes == b.mes && a.anio == b.anio && a.idCliente == b.idCliente)
            {
                flag = 1;
                posicion =ftell(archi)/sizeof(stConsumos);
            }

        }
        fclose(archi);
    }
    return posicion;
}

int busquedaID(char nombreArchivo[])///BUSQUEDA ID CLIENTE
{
    stCliente b = busquedaClientesParaConsumos(nombreArchivo);
    int id = 0;
    stCliente a;

    FILE *archi = fopen(nombreArchivo, "rb");

    if(archi)
    {
        while(fread(&a, sizeof(stCliente),1,archi)>0)
        {
            if(strcmp(a.dni, b.dni) == 0)
            {
                id = a.idCliente;
            }
        }
        fclose(archi);
    }
    return id;
}

int comprobacionDniParaConsumoCliente(char nombreArchivo [], char dni[])///FUNCION PARA COMPARACION DE DNI  DE CLIENTES (RETORNA UNA BANDERA)
{
    stCliente a;
    int flag = 0;
    FILE *archi = fopen(nombreArchivo,"rb");
    if(archi)
    {
        while(fread(&a,sizeof(stCliente),1,archi)>0)
        {
            if(strcmp(a.dni, dni) == 0)
            {
                flag=1;
            }
        }
        fclose(archi);
    }
    return flag;
}

stCliente busquedaClientesParaConsumos(char nombreArchivo[])///FUNCION PARA LA BUSQUEDA DE CLIENTES EN ARCHIVO (RETORNA LA ESTRUCTURA)
{
    stCliente b;
    int flag = 0;
    printf("\nIngrese el dni del cliente: ");
    fflush(stdin);
    gets(b.dni);

    while(flag == 0)
    {
        flag = comprobacionDniParaConsumoCliente(nombreArchivo, b.dni);
        if(flag == 0)
        {
            printf("\nEl cliente no existe, ingrese otro DNI");
            fflush(stdin);
            gets(b.dni);
        }
        else
        {
            printf("\nCliente a sido encontrado");
        }
    }
    return b;
}

int ultimoIdConsumo(char nombreArchivo[])///CONTADOR UNICO E INCREMENTAL DE ID (RETORNA EL ULTIMO ID)
{
    int id = 0;
    stConsumos e;
    FILE *arch = fopen(nombreArchivo, "rb");
    if(arch)
    {
        fseek(arch, -1*sizeof(stConsumos), SEEK_END);
        if(fread(&e, sizeof(stConsumos), 1, arch)>0)
        {
            id = e.id;
        }
        fclose(arch);
    }
    return id;
}

void muestraUnConsumo(stConsumos a)///MUESTRA INDIVIDUAL DE CONSUMO
{
    if(a.baja == 0)
    {
        color(15);
        printf("\n\t========================================");
        printf("\n\tID Consumo:\t\t\t   %4d", a.id);
        printf("\n\tID cliente:\t\t\t     %2d", a.idCliente);
        printf("\n\tFecha del consumo:\t     %2d/%2d/%4d", a.dia,a.mes,a.anio);
        printf("\n\tCantidad de datos consumidos:\t%4d MB", a.datosConsumidos);
        printf("\n\tActivo:\t\t\t\t     Si\n");
        printf("\t========================================\n");
        color(15);
    }
    else
    {
        color(8);
        printf("\n\t========================================");
        printf("\n\tID Consumo:\t\t\t   %4d", a.id);
        printf("\n\tID cliente:\t\t\t     %2d", a.idCliente);
        printf("\n\tFecha del consumo:\t     %2d/%2d/%4d", a.dia,a.mes,a.anio);
        printf("\n\tCantidad de datos consumidos:\t%4d MB", a.datosConsumidos);
        color(4);
        printf("\n\tActivo:\t\t\t\t     No\n");
        color(8);
        printf("\t========================================\n");
        color(15);
    }
}
/*
stConsumos busquedaConsumo()///FUNCION PARA LA BUSQUEDA DE CONSUMOS
{
    stConsumos b;
    printf("\nBusqueda de cliente\n\n");
    printf("Id del cliente        : ");
    scanf("%2d",&b.idCliente);
    printf("Dia del consumo       : ");
    scanf("%2d",&b.dia);
    printf("Mes del consumo       : ");
    scanf("%2d",&b.mes);
    printf("Anio del consumo      : ");
    scanf("%4d",&b.anio);

    return b;
}
*/

