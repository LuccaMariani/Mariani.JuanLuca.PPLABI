#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

//
//
//
//ESTRUCTURAS
typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int idTipo; // comienza en 1000
    char descripcionTipo[20];
}eTipo;

typedef struct
{
    int idColor;// comienza en 1000
    char nombreColor[20];
}eColor;

typedef struct
{
    int idMoto;
    char marca[20];
    eTipo tipo; //validar
    eColor color;//validar
    int cilindrada;
    int isEmpty;// si =1 esta vacio
}eMoto;

//int id moto
//char marca
// eTipo tipo
// eColor color
//int cilindrada
//int isEmpty

typedef struct
{
    int idServicio;//comienza en 20000
    char descripcionServicio[25];
    int precio;
}eServicio;

typedef struct
{
    int idTrabajo;// auto incremental
    eMoto moto;
    eServicio servicio;
    eFecha fechaTrabajo;
}eTrabajo;
//
//
//FUNCIONES
//
//
void menu();
int listarMotos(eMoto motos[],int tam, eTipo tipos[], eColor colores[], int tam_t, int tam_c);

void mostrarMoto(eMoto motos, eTipo tipos[], eColor colores[], int tam_t, int tam_c);

int altaMotos(eMoto motos[], int tam, int proximoIdMoto, eTipo tipos[]);

int buscarLugarLibre(eMoto motos[],int tam);
int validacionCadenaCaracteres(char cadenaCaracteres[]);

int harcodearTiposColoresServicios(eTipo tipos[], eColor colores[], eServicio servicios[], int tam_t, int tam_c, int tam_s);

int initMotos(eMoto motos[], int tam);

void cargarColoryTipo( eTipo tipos[], eColor colores[], char colorAux[], char tipoAux[], int idC, int idT, int tam_c, int tam_t);

int listarTipos(eTipo tipos[], int tam);
void mostrarTipo(eTipo tipos);

int bajaMotos(eMoto motos[],int tam, eTipo tipos[], eColor colores[], int tam_t, int tam_c);


#endif // PERSONA_H_INCLUDED
#define ASC 0
#define DESC 1
