#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "eColor.h"
#include "eTipo.h"
#include "eMoto.h"


int validacionCadenaCaracteres(char cadenaCaracteres[])
{

    int encontrarNumero = 0;
    int len = strlen(cadenaCaracteres);

    for(int i=0; i<len; i++)
    {
        if(0==isalpha(cadenaCaracteres[i]))
        {
            encontrarNumero = 1;
            break;
        }
    }
    return encontrarNumero; // devuelve 1 si encuentra un numero, 0 si no.
}


int validacionIdMotoExiste(eMoto motos[], int idMoto, int tam)
{

    int retorno= 1;

    for(int i=0; i<tam;i++)
    {
        if(motos[i].idMoto==idMoto)
        {
            retorno=0;
            //printf("Encontro letra");
            break;
        }
    }
    return retorno;
}

int validacionCadenaEnteros(char cadenaNumeros[])
{

    int encontrarLetra = 0;
    int len = strlen(cadenaNumeros);

    for(int i=0; i<len;i++)
    {
        if(cadenaNumeros[i]<'0'||cadenaNumeros[i]>'9')
        {
            encontrarLetra=1;
            //printf("Encontro letra");
            break;
        }
    }
    return encontrarLetra;
}

int validacionIdColorExiste(eColor colores[],int tam, int id)
{
    int retorno=1;
    if(id!=1)
    {
        for(int i = 0; i < tam ; i++)
        {
            if(colores[i].idColor == id)
            {
                retorno=0;
                break;
            }
        }
    }

    return retorno;
}

int validacionIdTipoExiste(eTipo tipos[],int tam, int id)
{
    int retorno=1;
    if(id!=1 && id!=2)
    {
        for(int i = 0; i < tam ; i++)
        {
            if(tipos[i].idTipo == id)
            {
                retorno=0;
                break;
            }
        }
    }

    return retorno;
}

int validacionIdServicioExiste(eServicio servicios[],int tam, int id)
{
    int retorno=1;
    if(id!=1)
    {
        for(int i = 0; i < tam ; i++)
        {
            if(servicios[i].idServicio == id)
            {
                retorno=0;
                break;
            }
        }
    }

    return retorno;
}

int validacionIdClienteExiste(eCliente clientes[],int tam, int id)
{
    int retorno=1;
    if(id!=1)
    {
        for(int i = 0; i < tam ; i++)
        {
            if(clientes[i].id == id)
            {
                retorno=0;
                break;
            }
        }
    }

    return retorno;
}

int validacionCilindradaExiste(int cilindrada)
{
    int retorno=1;

    if(cilindrada==50 || cilindrada==125 || cilindrada==500 || cilindrada==600 || cilindrada==750)
    {
        retorno=0;
    }

    return retorno;
}



