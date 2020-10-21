#ifndef ESERVICIO_H_INCLUDED
#define ESERVICIO_H_INCLUDED

typedef struct
{
    int idServicio;//comienza en 20000
    char descripcionServicio[25];
    int precio;
}eServicio;

#endif // ESERVICIO_H_INCLUDED

void iniciarServicios(eServicio servicios[], int tam);

int listarServicios(eServicio servicios[],int tam);

void mostrarServicio(eServicio servicios);
