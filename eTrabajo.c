#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "eTrabajo.h"
#include "eMoto.h"
#include "validaciones.h"


void initTrabajos(eTrabajo trabajos[],int tam)
{
        for(int i=0; i<tam; i++)
        {
            trabajos[i].isEmpty=1;
        }
}



int altaTrabajo( eMoto motos[], eTipo tipos[], eColor colores[],eServicio servicios[], eTrabajo trabajos[], int tam, int tam_t, int tam_s, int tam_c, int id, eCliente clientes[],int tam_cl)
{

    /// int idServicio = 0;
    /// int idMoto;
    int indice;
    int retorno=0;

    eTrabajo nuevoTrabajo;

    indice=buscarLugarLibreTrabajo(trabajos, tam);

    if(motos != NULL && trabajos!=NULL && tam > 0 && id>0)
    {

        if(indice == -1)
        {
            printf("Error, el sistema esta completo.\n");
        }
        else
        {
            nuevoTrabajo.idTrabajo=id;
            system("cls");
            printf("\n     ***ALTA TRABAJO***\n");
            if(1==listarMotos(motos,tam, tipos, colores, tam_t, tam_c, clientes, tam_cl))
            {

                printf("\n> Ingrese un ID moto: ");
                fflush(stdin);
                scanf("%d", &nuevoTrabajo.idMoto);

                while(1==validacionIdMotoExiste(motos, nuevoTrabajo.idMoto, tam))
                {
                    printf("\n> Re ingrese un ID moto: ");
                    fflush(stdin);
                    scanf("%d", &nuevoTrabajo.idMoto);
                }

                listarServicios(servicios, tam_s);

                printf("\n> Ingrese id de Servicio a realizar: ");
                fflush(stdin);
                scanf("%d", &nuevoTrabajo.idServicio);

                while(1==validacionIdServicioExiste(servicios, tam_s, nuevoTrabajo.idServicio))
                {
                    printf("\n> Re ingrese id de Servicio a realizar: ");
                    fflush(stdin);
                    scanf("%d", &nuevoTrabajo.idServicio);
                }

                printf("\n> Ingrese el dia: ");
                scanf("%d", &nuevoTrabajo.fechaTrabajo.dia);
                while(nuevoTrabajo.fechaTrabajo.dia>30 || nuevoTrabajo.fechaTrabajo.dia<1)
                {
                    printf("\n> Re ingrese el dia: ");
                    scanf("%d", &nuevoTrabajo.fechaTrabajo.dia);
                }

                printf("\n> Ingrese el mes: ");
                scanf("%d", &nuevoTrabajo.fechaTrabajo.mes);
                while(nuevoTrabajo.fechaTrabajo.mes>12 || nuevoTrabajo.fechaTrabajo.mes<1)
                {
                    printf("\n> Re ingrese el mes: ");
                    scanf("%d", &nuevoTrabajo.fechaTrabajo.mes);
                }

                while(nuevoTrabajo.fechaTrabajo.anio>2020 || nuevoTrabajo.fechaTrabajo.anio<1)
                {
                    printf("\n> Re ingrese el anio: ");
                    scanf("%d", &nuevoTrabajo.fechaTrabajo.anio);
                }

                nuevoTrabajo.isEmpty=0;

                trabajos[indice]=nuevoTrabajo;

                retorno=1;
            }
            else
            {
                retorno=0;
            }
        }
    }
    return retorno;
}

int buscarLugarLibreTrabajo(eTrabajo trabajos[],int tam)
{
    int retorno = -1;

    for(int i=0; i<tam; i++)
    {
        if(trabajos[i].isEmpty)
        {
            retorno = i;
            break;
        }

    }

    return retorno;
}


int mostrarTrabajos(eMoto motos[],eTrabajo trabajos[], int tam ,eServicio servicios[],int tam_s)
{
    int error = 1;
    int hayTrabajos=0;

    for(int i=0;i< tam;i++)
    {
        if(trabajos[i].isEmpty == 0)
        {
            hayTrabajos= 1;
        }
    }

    if(trabajos != NULL && tam > 0 && hayTrabajos==1 )
    {
        system("cls");
        printf("\n     ***LISTA TRABAJOS***\n");
        printf("\n      ID          Marca          Servicio      Fecha \n");
        printf(" -------------------------------------------------------\n");
        for(int i=0;i < tam;i++)
        {
            if(trabajos[i].isEmpty == 0)
            {
                mostrarTrabajo( trabajos[i], motos[i], servicios, tam, tam_s);
                hayTrabajos= 1;
            }
        }
    }
    else
    {
        printf("\n  No hay trabajos en la lista.\n\n");
        error=0;
    }

    return error;
}


void mostrarTrabajo(eTrabajo trabajo,eMoto motos, eServicio servicio[], int tam_m, int tam_s)
{
    char auxServicio[20];


    for(int j=0; j<tam_m; j++)
    {
        if(trabajo.idServicio==servicio[j].idServicio)
        {
            strcpy(auxServicio, servicio[j].descripcionServicio);
            break;
        }
    }

    printf("    %4d         %4s   %15s     %2d/%2d/%4d\n",trabajo.idTrabajo, motos.marca, auxServicio, trabajo.fechaTrabajo.dia, trabajo.fechaTrabajo.mes, trabajo.fechaTrabajo.anio);//Imprime los datos de la persona segun su posicion en el vector
}

