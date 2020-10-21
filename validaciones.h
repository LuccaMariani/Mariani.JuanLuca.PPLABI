#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

#include "eColor.h"
#include "eTipo.h"
#include "eMoto.h"

#endif // VALIDACIONES_H_INCLUDED

int validacionCadenaCaracteres(char cadenaCaracteres[]);

int validacionCadenaEnteros(char cadenaNumeros[]);

int validacionIdColorExiste(eColor colores[],int tam, int id);

int validacionIdTipoExiste(eTipo tipos[],int tam, int id);

int validacionCilindradaExiste(int cilindrada);

int validacionIdMotoExiste(eMoto motos[], int idMoto, int tam);

int validacionIdServicioExiste(eServicio servicios[],int tam, int id);

int validacionIdClienteExiste(eCliente clientes[],int tam, int id);

void mostrarMotoTipo(eMoto motos, eTipo tipos[], eColor colores[], int tam_t, int tam_c);
