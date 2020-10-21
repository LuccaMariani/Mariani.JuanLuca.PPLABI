#ifndef ETRABAJO_H_INCLUDED
#define ETRABAJO_H_INCLUDED

#include "eFecha.h"
#include "eMoto.h"


typedef struct
{
    int idTrabajo;// auto incremental
    int idMoto;
    int idServicio;
    eFecha fechaTrabajo;
    int isEmpty;
}eTrabajo;

#endif // ETRABAJO_H_INCLUDED

void initTrabajos(eTrabajo trabajos[],int tam);

int buscarLugarLibreTrabajo(eTrabajo trabajos[],int tam);

int altaTrabajo( eMoto motos[], eTipo tipos[], eColor colores[],eServicio servicios[], eTrabajo trabajos[], int tam, int tam_t, int tam_s, int tam_c, int id, eCliente clientes[],int tam_cl);

void mostrarTrabajo(eTrabajo trabajo,eMoto moto, eServicio servicio[], int tam_m, int tam_s);

int mostrarTrabajos(eMoto motos[],eTrabajo trabajos[], int tam ,eServicio servicios[],int tam_s);
