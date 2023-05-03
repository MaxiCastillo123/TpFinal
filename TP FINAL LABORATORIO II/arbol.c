#include <stdio.h>
#include <stdlib.h>

#include "arbol.h"



nodoArbol * inicArbol ()
{
    return NULL;
}

nodoArbol * crearNodoArbol (stCliente dato)
{

    nodoArbol *nuevo = (nodoArbol*)malloc(sizeof(nodoArbol));
    nuevo->dato= dato;
    nuevo->der=NULL;
    nuevo->izq=NULL;
    nuevo->listaDeConsumos = inicLista();

    return nuevo;
}

nodoArbol *agregarArbol (nodoArbol *arbol, stCliente dato) /// agrega en orden por id
{

    if (!arbol)
    {
        arbol = crearNodoArbol(dato);
    }
    else
    {
        if (dato.idCliente > arbol->dato.idCliente)
        {
            arbol->der=agregarArbol(arbol->der, dato);
        }
        else
        {
            arbol->izq=agregarArbol(arbol->izq, dato);
        }
    }

    return arbol;
}



void preOrden (nodoArbol *arbol)
{
    if (arbol)
    {

        muestraUnCliente(arbol->dato);
        mostrarLista(arbol->listaDeConsumos);
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
}


void inOrden (nodoArbol *arbol)
{
    if (arbol)
    {
        inOrden(arbol->izq);
        muestraUnCliente(arbol->dato);
        mostrarLista(arbol->listaDeConsumos);
        inOrden(arbol->der);
    }
}


void postOrden (nodoArbol *arbol)
{
    if (arbol)
    {

        postOrden(arbol->izq);
        postOrden(arbol->der);
        muestraUnCliente(arbol->dato);
        mostrarLista(arbol->listaDeConsumos);
    }
}

nodoArbol *buscarNodoArbol (nodoArbol *arbol, int id) /// busca por id
{
    nodoArbol *buscado=NULL;
    if (arbol)
    {
        if (arbol->dato.idCliente == id)
        {
            buscado=arbol;
        }
        else
        {
            if(id < arbol->dato.idCliente )
            {
                buscado = buscarNodoArbol(arbol->izq, id);
            }
            else
            {
                buscado = buscarNodoArbol(arbol->der, id);
            }
        }
    }
    return buscado;
}



nodoArbol *borrarNodoArbol (nodoArbol *arbol, int id) /// funcion borrar nodo
{
    if(arbol)
    {
        if (arbol->dato.idCliente == id)
        {
            if (arbol->izq)
            {
                nodoArbol *masDer = nodoMasDerecho(arbol->izq);
                arbol->dato=masDer->dato;
                arbol->listaDeConsumos = masDer->listaDeConsumos;
                arbol->izq=borrarNodoArbol(arbol->izq, masDer->dato.idCliente);
            }
            else if (arbol->der)
            {
                nodoArbol *masIzq = nodoMasIzquierdo(arbol->der);
                arbol->dato = masIzq->dato;
                arbol->listaDeConsumos = masIzq->listaDeConsumos;
                arbol->der=borrarNodoArbol(arbol->der, masIzq->dato.idCliente);
            }
            else
            {
                free(arbol);
                arbol=NULL;
            }
        }
        else if (id > arbol->dato.idCliente)
        {
            arbol->der = borrarNodoArbol(arbol->der, id);
        }
        else if (id < arbol->dato.idCliente)
        {
            arbol->izq = borrarNodoArbol(arbol->izq, id);
        }
    }
    return arbol;
}

nodoArbol *nodoMasDerecho(nodoArbol *arbol)
{
    nodoArbol *masDerecho=arbol;
    if(arbol)
    {
        if (arbol->der)
        {
            masDerecho=nodoMasDerecho(arbol->der);
        }
    }
    return masDerecho;
}


nodoArbol *nodoMasIzquierdo(nodoArbol *arbol)
{
    nodoArbol *masIzquierdo=arbol;
    if(arbol)
    {
        if (arbol->izq)
        {
            masIzquierdo=nodoMasIzquierdo(arbol->izq);
        }
    }
    return masIzquierdo;
}

/**PARA CONSULTARLE A SERGIO
nodoArbol *borrarNodoArbolMejorada (nodoArbol *arbol, int id)
{
    if(arbol)
    {
        nodoArbol*buscado = buscarNodoArbol(arbol, id);
        if (buscado)
        {
            if (buscado->izq)
            {
                nodoArbol *masDer = nodoMasDerecho(buscado->izq);
                buscado->dato=masDer->dato;
                buscado->listaDeConsumos = masDer->listaDeConsumos;
                buscado->izq=borrarNodoArbol(buscado->izq, masDer->dato.idCliente);
            }
            else if (buscado->der)
            {
                nodoArbol *masIzq = nodoMasIzquierdo(buscado->der);
                buscado->dato = masIzq->dato;
                buscado->listaDeConsumos = masIzq->listaDeConsumos;
                buscado->der=borrarNodoArbol(buscado->der, masIzq->dato.idCliente);
            }
            else
            {
                free(buscado);
                buscado=NULL;
            }
        }
    }
    return arbol;
}*/

nodoArbol *buscarPos (nodoArbol *arbol, int id)  /// busca la posicion en relacion al id para agregar al arbol
{
    nodoArbol *buscado =NULL;
    if (arbol)
    {
        if (id == arbol->dato.idCliente)
        {
            buscado=arbol;
        }
        else
        {
            if (id < arbol->dato.idCliente)
            {
                buscado= buscarPos(arbol->izq, id);
            }
            else
            {
                buscado= buscarPos(arbol->der, id);
            }
        }
    }
    return buscado;
}

nodoArbol *altaConsumosPorFecha (nodoArbol *arbol, stConsumos a)  /// funcion de alta, agregando a la lista de consumos en orden por fecha
{

    nodoArbol *buscado;
    buscado=inicArbol();
    buscado = buscarPos(arbol, a.idCliente);
    if(buscado)
    {
        buscado->listaDeConsumos=agregarEnOrdenPorFecha(buscado->listaDeConsumos, crearNodoNuevo(a));
    }
    return arbol;
}

nodoArbol *altaConsumosPorId (nodoArbol *arbol, stConsumos a)  /// funcion de alta, agregando a la lista de consumos en orden por id
{

    nodoArbol *buscado;
    buscado=inicArbol();
    buscado = buscarPos(arbol, a.idCliente);
    if(buscado)
    {
        buscado->listaDeConsumos=agregarEnOrdenPorId(buscado->listaDeConsumos, crearNodoNuevo(a));
    }
    return arbol;
}

nodoArbol *agregarArbolOrdenApellido (nodoArbol *arbol, stCliente c)  /// agrega al arbol los clientes ordenados por apellido
{

    if (!arbol)
    {
        arbol = crearNodoArbol(c);
    }
    else
    {
        if (strcmpi(c.apellido, arbol->dato.apellido)>0)
        {
            arbol->der=agregarArbolOrdenApellido(arbol->der, c);
        }
        else
        {
            arbol->izq=agregarArbolOrdenApellido(arbol->izq, c);
        }
    }

    return arbol;
}

nodoArbol *agregarArbolNroCliente (nodoArbol *arbol, stCliente dato)  /// agrega al arbol los clientes ordenados por apellido
{

    if (!arbol)
    {
        arbol = crearNodoArbol(dato);
    }
    else
    {
        if (dato.nroCliente > arbol->dato.nroCliente)
        {
            arbol->der=agregarArbolNroCliente(arbol->der, dato);
        }
        else
        {
            arbol->izq=agregarArbolNroCliente(arbol->izq, dato);
        }
    }

    return arbol;
}

nodoArbol* activaConsumo(nodoArbol* arbol, char archivo[]) /// activa un consumo
{
    char dni[10];
    int id;
    int modificado = 0;
    nodoArbol *pos = inicArbol();
    nodoArbol *copia = inicArbol();
    copia= arbol;

    printf("\n Ingrese dni: ");
    fflush(stdin);
    gets(dni);

    id = buscaIdXDni(archivo, dni);
    pos = buscarNodoArbol(copia, id);

    if(pos!= NULL)
    {
        int dia;
        int mes;
        int anio;
        printf("\nDia del consumo a activar:");
        fflush(stdin);
        scanf("%d", &dia);
        printf("\nMes del consumo a activar:");
        fflush(stdin);
        scanf("%d", &mes);
        printf("\nAnio del consumo a activar:");
        fflush(stdin);
        scanf("%d", &anio);
        fflush(stdin);

        nodo* copiaLista = pos->listaDeConsumos;
        while(copiaLista)
        {
            if( copiaLista->dato.dia == dia && copiaLista->dato.mes== mes && copiaLista->dato.anio == anio)
            {
                copiaLista->dato.baja = 0;
                pos->modificado = 1;
                modificado = 1;
                printf("\nConsumo activado con exito.");
            }
            copiaLista=copiaLista->siguiente;
        }
        if(modificado == 0)
        {
            printf("\nEl consumo ingresado no existe o ya se encuentra activo.");
        }
    }
    else
    {
        printf("\nEl cliente no se encuentra en la base de datos");
    }
    return arbol;
}


nodoArbol* eliminarUnConsumo(nodoArbol* arbol, char archivo[]) /// inactiva un consumo
{
    char dni[10];
    int id;
    int modificado = 0;
    nodoArbol *pos = inicArbol();
    nodoArbol *copia = inicArbol();
    copia= arbol;

    printf("\n Ingrese dni: ");
    fflush(stdin);
    gets(dni);

    id = buscaIdXDni(archivo, dni);
    pos = buscarNodoArbol(copia, id);
    if(pos!= NULL)
    {
        int dia;
        int mes;
        int anio;
        printf("\nDia del consumo a inactivar:");
        fflush(stdin);
        scanf("%d", &dia);
        printf("\nMes del consumo a inactivar:");
        fflush(stdin);
        scanf("%d", &mes);
        printf("\nAnio del consumo a inactivar:");
        fflush(stdin);
        scanf("%d", &anio);
        fflush(stdin);

        nodo* copiaLista = pos->listaDeConsumos;

        while(copiaLista)
        {
            if(copiaLista->dato.dia == dia && copiaLista->dato.mes==mes && copiaLista->dato.anio == anio)
            {
                modificado = 1;
                copiaLista->dato.baja = -1;
                pos->modificado = 1;
                printf("\nEl consumo se ha inactivado con exito.");
            }
            copiaLista=copiaLista->siguiente;
        }
        if(modificado == 0)
        {
            printf("\nLa fecha seleccionada no se encuentra en la base de datos.");
        }
    }
    else
    {
        printf("\nEl cliente no se encuentra en la base de datos");
    }

    return arbol;
}

nodoArbol* modificarUnConsumo(nodoArbol* arbol, char archivo[]) /// modifica consumo
{
    char dni[10];
    int id;
    int modificado = 0;
    nodoArbol *pos = inicArbol();
    nodoArbol *copia = inicArbol();
    copia= arbol;

    printf("\n Ingrese dni: ");
    fflush(stdin);
    gets(dni);

    id = buscaIdXDni(archivo, dni);
    pos = buscarNodoArbol(copia, id);

    int cantMB= 0;

    if(pos!= NULL)
    {
        int dia;
        int mes;
        int anio;
        printf("\nDia del consumo a modificar:");
        fflush(stdin);
        scanf("%d", &dia);
        printf("\nMes del consumo a modificar:");
        fflush(stdin);
        scanf("%d", &mes);
        printf("\nAnio del consumo a modificar:");
        fflush(stdin);
        scanf("%d", &anio);
        fflush(stdin);

        nodo* copiaLista = pos->listaDeConsumos;

        while(copiaLista)
        {
            if(copiaLista->dato.dia == dia && copiaLista->dato.mes==mes && copiaLista->dato.anio == anio)
            {
                modificado = 1;
                printf("\nIngrese la cantidad de MB consumidos: \n");
                fflush(stdin);
                scanf("%d", &cantMB);
                copiaLista->dato.datosConsumidos= cantMB;
                pos->modificado = 1;
                printf("\nLa cantidad de MB ha sido actualizada con exito\n.");
            }
            copiaLista=copiaLista->siguiente;
        }
        if(modificado == 0)
        {
            printf("\nLa fecha seleccionada no se encuentra en la base de datos.");
        }
    }
    else
    {
        printf("\nEl cliente no se encuentra en la base de datos");
    }

    return arbol;
}

nodoArbol * modificacionApellidoCliente1(nodoArbol* arbol, char archivo[])///FUNCION PARA LA MODIFICACION DEL APELLIDO DE UN CLIENTE
{
    char dni[10];
    int id;
    nodoArbol *buscado = inicArbol();

    printf("\nIngrese dni: ");
    fflush(stdin);
    gets(dni);

    id = buscaIdXDni(archivo, dni);
    buscado = buscarNodoArbol(arbol, id);

    if(!buscado)
    {
        printf("\nEl cliente no se encuentra en la base de datos.");
    }
    else
    {
        printf("\nApellido actual: %s", buscado->dato.apellido);
        printf("\nIngrese el nuevo apellido: ");
        fflush(stdin);
        gets(buscado->dato.apellido);
        buscado->modificado=1;
        printf("\nEl apellido ha sido modificado con exito\n");
    }
    return arbol;
}

nodoArbol * modificacionNombreClienteArbol(nodoArbol* arbol, char archivo[])///FUNCION PARA LA MODIFICACION DEL NOMBRE DE UN CLIENTE
{
    char dni[10];
    int id;
    nodoArbol *buscado = inicArbol();

    printf("\nIngrese dni: ");
    fflush(stdin);
    gets(dni);

    id = buscaIdXDni(archivo, dni);
    buscado = buscarNodoArbol(arbol, id);

    if(!buscado)
    {
        printf("\nEl cliente no se encuentra en la base de datos.");
    }
    else
    {
        printf("\nNombre actual: %s", buscado->dato.nombre);
        printf("\nIngrese el nuevo nombre: ");
        fflush(stdin);
        gets(buscado->dato.nombre);
        buscado->modificado=1;
        printf("\n El nombre ha sido modificado con exito\n");
    }
    return arbol;
}


nodoArbol* modificacionDniClienteArbol(nodoArbol* arbol, char archivo[]) ///FUNCION PARA LA MODIFICACION DEL DNI DE UN CLIENTE
{
    char dni[10];
    int id;
    int buscaDni=0;
    char dniNuevo[10];
    char opcion = 0;

    nodoArbol *buscado = inicArbol();

    printf("\nIngrese dni: ");
    fflush(stdin);
    gets(dni);

    id = buscaIdXDni(archivo, dni);

    buscado = buscarNodoArbol(arbol, id);

    if(!buscado)
    {
        printf("\nEl cliente no se encuentra en la base de datos.");
    }
    else
    {
        do
        {
            printf("\nEl dni actual es : %s", buscado->dato.dni);
            printf("\nIngrese el nuevo dni: ");
            fflush(stdin);
            gets(dniNuevo);
            buscaDni=comprobacionDni(archivo, dniNuevo);
            if(buscaDni==1)
            {
                printf("\nEl dni ya se encuentra cargado\n");
                printf("\nSi desea salir puede apretar 'n' o cualquier otra tecla para cargar nuevamente el dni");
                scanf("%c", &opcion);

            }
        }
        while(buscaDni == 1 && opcion != 'n');
        if(buscaDni == 0)
        {
            strcpy(buscado->dato.dni,dniNuevo);
            printf("\n El documento ha sido modificado con exito\n");
        }
    }

    return arbol;
}

nodoArbol * modificacionEmailClienteArbol(nodoArbol* arbol, char archivo[])///FUNCION PARA LA MODIFICACION DEL MAIL DE UN CLIENTE
{
    char dni[10];
    int id;
    int flag = 0;

    nodoArbol *buscado = inicArbol();

    printf("\nIngrese dni: ");
    fflush(stdin);
    gets(dni);

    id = buscaIdXDni(archivo, dni);
    buscado = buscarNodoArbol(arbol, id);

    if(!buscado)
    {
        printf("\nEl cliente no se encuentra en la base de datos.");
    }
    else
    {
        while (flag ==0)
        {
            fflush(stdin);
            printf("\nEmail.......: ");
            gets(buscado->dato.email);
            if(strchr(buscado->dato.email,'@') != 0 && strchr(buscado->dato.email,'.') !=0 )
            {
                flag = 1;
            }
            else
            {
                printf("\nIngrese un email correcto...\n");
                system("pause");
            }

        }
        printf("\nEl email ha sido actulizado con exito\n");
        buscado->modificado =1;
    }
    return arbol;
}

nodoArbol * modificacionCeluClienteArbol(nodoArbol* arbol, char archivo[])///FUNCION PARA LA MODIFICACION DEL CELULAR DE UN CLIENTE
{

    char dni[10];
    int id;
    nodoArbol *buscado = inicArbol();

    printf("\nIngrese dni: ");
    fflush(stdin);
    gets(dni);

    id = buscaIdXDni(archivo, dni);
    buscado = buscarNodoArbol(arbol, id);

    if(!buscado)
    {
        printf("\nEl cliente no se encuentra en la base de datos.");
    }
    else
    {
        printf("\nCelular actual: %s", buscado->dato.movil);
        printf("\nIngrese el nuevo numero de celular: ");
        fflush(stdin);
        gets(buscado->dato.movil);
        buscado->modificado=1;
        printf("\n El celular ha sido modificado con exito\n");
    }
    return arbol;
}

nodoArbol * modificacionDireccionClienteArbol(nodoArbol* arbol, char archivo[])///FUNCION PARA LA MODIFICACION DE DIRECCION DE UN CLIENTE
{

    char dni[10];
    int id;
    nodoArbol *buscado = inicArbol();

    printf("\nIngrese dni: ");
    fflush(stdin);
    gets(dni);

    id = buscaIdXDni(archivo, dni);
    buscado = buscarNodoArbol(arbol, id);

    if(!buscado)
    {
        printf("\nEl cliente no se encuentra en la base de datos.");
    }
    else
    {
        printf("\nDomicilio actual: %s", buscado->dato.domicilio);
        printf("\nIngrese el nuevo domicilio: ");
        fflush(stdin);
        gets(buscado->dato.domicilio);
        buscado->modificado=1;
        printf("\nEl domicilio ha sido modificado con exito\n");
    }
    return arbol;
}

nodoArbol * CambioDeTitularidadClienteArbol(nodoArbol* arbol, char archivo[])///FUNCION PARA LA MODIFICACION TODO DE UN CLIENTE
{
    char dni[10];
    int id;
    int existe = 1;
    nodoArbol *buscado = inicArbol();

    printf("\nIngrese dni: ");
    fflush(stdin);
    gets(dni);

    id = buscaIdXDni(archivo, dni);
    buscado = buscarNodoArbol(arbol, id);

    if(!buscado)
    {
        printf("\nEl cliente no se encuentra en la base de datos.");
    }
    else
    {
        printf("\nIngrese los datos del nuevo titular: ");
        printf("\nNombre: ");
        fflush(stdin);
        gets(buscado->dato.nombre);
        printf("\nApellido: ");
        fflush(stdin);
        gets(buscado->dato.apellido);
        while(existe == 1)///COMPROBACION DEL DNI EXISTE= 1 EL DNI YA SE ENCUENTRA UTILIZADO =0 NO EXISTE EL DNI EN LA BASE DE DATOS
        {
            printf("\nIngrese el nuevo DNI: ");
            fflush(stdin);
            gets(dni);

            existe = comprobacionDni(archivo, dni);

            if(existe == 1)
            {
                printf("\nEl cliente ya existe, ingrese otro dni\n");
            }
            else
            {
                strcpy(buscado->dato.dni,dni);
                printf("\nNo se ha encontrado al cliente, prosiga con la carga\n");
                existe = 0;
            }
        }
        existe = 1;
        printf("\nDomicilio: ");
        fflush(stdin);
        gets(buscado->dato.domicilio);
        printf("\nNumero de celular: ");
        fflush(stdin);
        gets(buscado->dato.movil);
        while (existe == 1)///COMPROBACION DEL EMAIL EXISTE= 1 EL EMAIL ESTA MAL ESCRITO =0 EL EMAIL ESTA BIEN ESCRITO
        {
            fflush(stdin);
            printf("\nEmail.......: ");
            gets(buscado->dato.email);
            if(strchr(buscado->dato.email,'@') != 0 && strchr(buscado->dato.email,'.') !=0 )
            {
                existe = 0;
            }
            else
            {
                printf("\nIngrese un email correcto...\n");
                system("pause");
            }

        }
        buscado->modificado=1;
        printf("\n Se ha realizado con exito el cambio de titularidad\n");
    }
    return arbol;
}


nodoArbol* darDeBajaUnCliente(nodoArbol* arbol, char archivo[]) /// Da de baja un cliente
{
    char dni[10];
    int id;
    nodoArbol *pos = inicArbol();
    nodoArbol *copia = inicArbol();
    copia= arbol;

    printf("\n Ingrese dni: ");
    fflush(stdin);
    gets(dni);

    id = buscaIdXDni(archivo, dni);
    pos = buscarNodoArbol(copia, id);

    if(pos!= NULL)
    {
        pos->dato.eliminado=1;
        pos->modificado=1;
        printf("\nEl cliente ha sido dado de baja");
    }
    else
    {
        printf("\nEl cliente no se encuentra en la base de datos");
    }

    return arbol;
}

nodoArbol* altaDeUnClienteEnArbol(nodoArbol* arbol, char archivo[]) /// da de alta a un cliente que habia sido dado de baja
{
    char dni[10];
    int id;
    nodoArbol *pos = inicArbol();
    nodoArbol *copia = inicArbol();
    copia= arbol;

    printf("\n Ingrese dni: ");
    fflush(stdin);
    gets(dni);

    id = buscaIdXDni(archivo, dni);
    pos = buscarNodoArbol(copia, id);

    if(pos!= NULL)
    {
        pos->dato.eliminado=0;
        pos->modificado=1;
        printf("\nEl cliente ha sido dado de alta nuevamente");
    }
    else
    {
        printf("\nEl cliente no se encuentra en la base de datos");
    }

    return arbol;
}
