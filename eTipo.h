#ifndef ETIPO_H_INCLUDED
#define ETIPO_H_INCLUDED

typedef struct
{
    int idTipo; // comienza en 1000
    char descripcionTipo[20];
}eTipo;


#endif // ETIPO_H_INCLUDED

void iniciarTipos(eTipo tipos[], int tam);

int listarTipos(eTipo tipos[], int tam);

void mostrarTipo(eTipo tipos);
