#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

typedef struct
{
    int idCliente;
    int nroCliente;
    char nombre[30];
    char apellido[30];
    char dni[10];
    char email[50];
    char domicilio[45];
    char movil [12];
    int eliminado;
} stCliente;

int busquedaDNI(char nombreArchivo[]);
int comprobacionDni(char nombreArchivo [], char dni[]); /// ver si no se repite
int ultimoIdCliente(char nombreArchivo[]);
stCliente busquedaClientes();
stCliente cargaUnCliente();
//void altaClienteInactivo(char nombreArchivo[]);
//void bajaDeCliente(char nombreArchivo[]);
void cargaArchivoCliente(char nombreArchivo[]);
void muestraUnCliente(stCliente a);


#endif // CLIENTES_H_INCLUDED
