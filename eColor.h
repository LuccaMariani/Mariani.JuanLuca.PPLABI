#ifndef ECOLOR_H_INCLUDED
#define ECOLOR_H_INCLUDED

typedef struct
{
    int idColor;// comienza en 1000
    char nombreColor[20];
}eColor;


#endif // ECOLOR_H_INCLUDED

//void cargarColoryTipo(eTipo tipos[], eColor colores[], char colorAux[], char tipoAux[], int idC, int idT, int tam_c, int tam_t);

//int harcodearTiposColoresServicios(eTipo tipos[], eColor colores[], eServicio servicios[], int tam_t, int tam_c, int tam_s);

void iniciarColores(eColor colores[], int tam);

int listarColores(eColor colores[],int tam);

void mostrarColor(eColor colores);
