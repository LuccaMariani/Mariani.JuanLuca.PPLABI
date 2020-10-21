#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#include "eColor.h"
#include "dataStore.h"

//#include "validaciones.h

void iniciarColores(eColor colores[], int tam)
{
    char Hcolores[6][11]={"Gris","Negro","Blanco","Azul","Rojo"};
    int id = 10000;

    for(int i =0; i<tam; i++)
    {
            colores[i].idColor= id;
            strcpy(colores[i].nombreColor, Hcolores[i]);
            id ++;
    }
}


int listarColores(eColor colores[],int tam)
{
    int error=1;

    if(colores!= NULL && tam > 0)
    {
        printf("\n- Id correspondiente a cada color de moto.\n");
        printf("\n     Id   |   Color de moto");
        printf("\n          |\n");
        for(int i = 0;i < tam; i++)
        {
             mostrarColor(colores[i]);
        }
         error= 0;
    }

    return error;
}

void mostrarColor(eColor colores)
{

    printf("  %4d   |  %13s\n", colores.idColor, colores.nombreColor);
}



