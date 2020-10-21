#ifndef ECLIENTE_H_INCLUDED
#define ECLIENTE_H_INCLUDED

typedef struct
{
    int id;
    char nombre[15];
    char sexo;
}eCliente;

#endif // ECLIENTE_H_INCLUDED

void inicializarClientes(eCliente clientes[], int tam);

int listarClientes(eCliente clientes[],int tam);

void mostrarCliente(eCliente clientes);
