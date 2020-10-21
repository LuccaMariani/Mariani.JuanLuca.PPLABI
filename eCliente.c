#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "eCliente.h"
#include "dataStore.h"


void inicializarClientes(eCliente clientes[], int tam)
{
    char hnombreClientes [10][15] ={"Josefa","Sol","Pepe","Hernan","Juan"};
    int hidClientes=100;
    char hSexoClientes [10]={'f','f','m','m','m'};

    for(int i =0;i<tam ;i++)
    {
        clientes[i].id = hidClientes;
        clientes[i].sexo = hSexoClientes[i];
        strcpy(clientes[i].nombre , hnombreClientes[i]);
        hidClientes++;
    }
}


int listarClientes(eCliente clientes[],int tam)
{
    int error=1;

    if(clientes!= NULL && tam > 0)
    {
        printf("\n- Id correspondiente al id del cliente.\n");
        printf("\n    Id   |       Nombre  |   Sexo");
        printf("\n         |               |\n");
        for(int i = 0;i < tam; i++)
        {
             mostrarCliente(clientes[i]);
        }
         error= 0;
    }

    return error;
}

void mostrarCliente(eCliente clientes)
{

    printf("  %4d   |  %11s  |    %c\n", clientes.id, clientes.nombre, clientes.sexo);
}
