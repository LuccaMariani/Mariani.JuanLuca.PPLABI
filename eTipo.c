#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "eTipo.h"
#include "dataStore.h"
#include "validaciones.h"

void iniciarTipos(eTipo tipos[], int tam)
{
    char HdescripcionTipo[5][11]={"Enduro","Chopera","Scooter","Ciclomotor"};
    int id = 1000;
    for(int i=0; i<tam ; i++)
    {
            tipos[i].idTipo= id;
            strcpy(tipos[i].descripcionTipo, HdescripcionTipo[i]);
            id++;

    }

}

int listarTipos(eTipo tipos[], int tam)
{
    int error=1;

    if(tipos!= NULL && tam > 0)
    {
        printf("\n- Id correspondiente a cada tipo de moto.\n");
        printf("\n    Id   |   Tipo de moto");
        printf("\n         |\n");
        for(int i=0; i<tam; i++)
        {
            mostrarTipo(tipos[i]);
        }
        error= 0;
    }

    return error;
}


void mostrarTipo(eTipo tipos)
{

    printf("  %4d   |  %13s\n", tipos.idTipo,tipos.descripcionTipo);
}
