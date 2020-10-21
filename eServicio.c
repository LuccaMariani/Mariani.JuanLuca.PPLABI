#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "eServicio.h"
#include "validaciones.h"


void iniciarServicios(eServicio servicios[], int tam)
{
    char HnombreServicios[5][11]={"Limpieza","Ajuste","Balanceo","Cadena"};
    int HprecioServicios[]={250,300,17,190};

    int id = 20000;

    for(int i =0; i<tam; i++)
    {
            servicios[i].idServicio= id;
            strcpy(servicios[i].descripcionServicio, HnombreServicios[i]);
            servicios[i].precio=HprecioServicios[i];
            id ++;
    }

}


int listarServicios(eServicio servicios[],int tam)
{
    int error=1;

    if(servicios!= NULL && tam > 0)
    {
        printf("\n- Id correspondiente a cada servicio de moto\n");
        printf("\n     Id   |   Servicio de moto");
        printf("\n          |\n");
        for(int i = 0;i < tam; i++)
        {
             mostrarServicio(servicios[i]);
        }
         error= 0;
    }

    return error;
}

void mostrarServicio(eServicio servicios)
{

    printf("  %4d   |  %13s\n", servicios.idServicio, servicios.descripcionServicio);
}



