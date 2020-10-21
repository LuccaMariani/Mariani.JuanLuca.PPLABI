#ifndef EMOTO_H_INCLUDED
#define EMOTO_H_INCLUDED

#include "eColor.h"
#include "eTipo.h"
#include "eServicio.h"
#include "eCliente.h"
typedef struct
{
    int idMoto;
    char marca[20];
    int idTipo; //validar
    int idColor;//validar
    int cilindrada;//validar
    int isEmpty;// si =1 esta vacio
    eCliente clientes;
}eMoto;

#endif // EMOTO_H_INCLUDED

int inicializacion(eMoto motos[], int tam, eColor colores[], int tam_c, eTipo tipos[], int tam_t, eServicio servicios[], int tam_s);

int listarMotos(eMoto motos[],int tam, eTipo tipos[], eColor colores[], int tam_t, int tam_c, eCliente clientes[],int tam_cl);

int modificarMotos(eMoto motos[], int tam, eColor colores[], int tam_c, eTipo tipos[], int tam_t, int proximoIdMot, eCliente clientes[],int tam_cl);

void mostrarMoto(eMoto motos, eTipo tipos[], eColor colores[], int tam_t, int tam_c, eCliente clientes[], int tam_cl);

int altaMotos(eMoto motos[], int tam, eColor colores[], int tam_c, eTipo tipos[], int tam_t, int proximoIdMoto, eCliente clientes[],int tam_cl);

int buscarLugarLibre(eMoto motos[],int tam);

int bajaMotos(eMoto motos[],int tam, eTipo tipos[], eColor colores[], int tam_t, int tam_c, eCliente clientes[],int tam_cl);

int buscarIdMoto(eMoto motos[], int tam, int id);


//1
int mostrarColorSeleccionado(eMoto motos[],eTipo tipos[],eColor colores[], int tam, int tam_c, int tam_t);
void mostrarMotoSinColor(eMoto motos, eTipo tipos[], int tam_t);

//2
int listarTipoSeleccionado(eMoto motos[],eTipo tipos[],eColor colores[], int tam, int tam_c, int tam_t);
void mostrarMotoSinTipo(eMoto motos, eColor colores[], int tam_c);

//3
int motosMayorCilindrada(eMoto motos[], eTipo tipos[], eColor colores[], int tam, int tam_t, int tam_c, eCliente clientes[], int tam_cl);

//4
int mostrarMotosXtipos(eMoto motos[], int tam, eTipo tipos[], eColor colores[], int tam_t, int tam_c);

//5
int contadorColoryTipo(eMoto motos[], int tam, eColor colores[], int tam_c, eTipo tipos[], int tam_t);

//6
int colorMasElegido(eMoto motos[],int tam,eColor colores[],int tam_c);
