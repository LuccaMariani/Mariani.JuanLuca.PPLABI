#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "dataStore.h"

#include "eColor.h"
#include "eFecha.h"
#include "eMoto.h"
#include "eServicio.h"
#include "eTipo.h"
#include "eTrabajo.h"
#include "validaciones.h"

#define TAM 20
#define TAM_T 4
#define TAM_C 5
#define TAM_S 4
#define TAM_CL 5

void menu();

int main()
{
    system("cls");

    char seguir = 1;
    char confirma;

    int proximoId=1000;
    int proximoIdTrabajo=2000;

    int opcion;

    eMoto motos[TAM];
    eTipo tipos[TAM_T];
    eColor colores[TAM_C];
    eTrabajo trabajos[TAM];
    eServicio servicios[TAM_S];
    eCliente clientes[TAM_CL];


    //inicia todo el array en la estructura de motos, como vacio
    inicializacion(motos, TAM, colores, TAM_C, tipos, TAM_T,  servicios, TAM_S);
    initTrabajos(trabajos,TAM);
    inicializarClientes( clientes, TAM_CL);

    system("pause");
    while(seguir)
    {
    system("cls");
    menu();

    printf("\n> Ingrese opcion: ");
    fflush(stdin);
    opcion = tolower(getchar());

        switch(opcion)
        {
        case 'a':
            //A.	ALTA MOTO
            if(altaMotos(motos, TAM, colores, TAM_C, tipos, TAM_T, proximoId, clientes, TAM_CL)==1)
            {
                proximoId++;
            }
            break;
        case 'b':
            //B.	MODIFICAR MOTO
            modificarMotos(motos, TAM, colores, TAM_C, tipos, TAM_T, proximoId, clientes, TAM_CL);
            break;
        case 'c':
            //C.	BAJA MOTO
            bajaMotos(motos,TAM, tipos, colores, TAM_T, TAM_C, clientes, TAM_CL);
            break;
        case 'd':
            //D.	LISTAR MOTOS
            listarMotos(motos,TAM, tipos, colores, TAM_T, TAM_C, clientes, TAM_CL);
            break;
        case 'e':
            //E.	LISTAR TIPOS
            listarTipos(tipos, TAM_T);
            break;
        case 'f':
            //F.	LISTAR COLORES
            listarColores( colores, TAM_C);
            break;
        case 'g':
            //G.	LISTAR SERVICIOS
            listarServicios( servicios, TAM_S);
            break;
        case 'h':
            //H.	ALTA TRABAJO
            if(altaTrabajo( motos, tipos, colores, servicios, trabajos, TAM, TAM_T, TAM_S, TAM_C, proximoIdTrabajo, clientes, TAM_CL)==1)
            {
                proximoIdTrabajo++;
            }
            break;
        case 'i':
            //I.	LISTAR TRABAJOS
            mostrarTrabajos(motos,trabajos,TAM,servicios,TAM_S);
            break;
        case '1':
            mostrarColorSeleccionado( motos, tipos, colores,  TAM,  TAM_C,  TAM_T);
            break;
        case '2':
            listarTipoSeleccionado( motos, tipos, colores,  TAM,  TAM_C,  TAM_T);
            break;
        case '3':
            motosMayorCilindrada( motos, tipos, colores, TAM, TAM_T, TAM_C, clientes, TAM_CL);
            break;
        case '4':
            mostrarMotosXtipos( motos, TAM,  tipos,  colores,  TAM_T,  TAM_C);
            break;
        case '5':
            contadorColoryTipo( motos, TAM, colores, TAM_C, tipos, TAM_T);
            break;
        case '6':
            colorMasElegido(motos, TAM, colores, TAM_C);
            break;

        case 'j':
            listarClientes(clientes, TAM_CL);

            printf("Confirma salida?: (s = Si) (n = No)");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
            if(confirma == 's')
            {
                seguir = 0;
            }
            break;
        default:
            printf("Opcion invalida!!!\n");
        }
        printf("\n");
        system("pause");
    }
    return 0;
}

void menu()
{
    printf(" *SERVICE MOTOS*\n \n");
    printf(" a. ALTA MOTO         \n");
    printf(" b. MODIFICAR MOTO    \n");
    printf(" c. BAJA MOTO         \n");
    printf(" d. LISTAR MOTOS      \n");
    printf(" e. LISTAR TIPOS      \n");
    printf(" f. LISTAR COLORES    \n");
    printf(" g. LISTAR SERVICIOS  \n");
    printf(" h. ALTA TRABAJO      \n");
    printf(" i. LISTAR TRABAJOS   \n\n");
    printf(" 1) Mostrar las motos del color seleccionado por el usuario.\n");
    printf(" 2) Mostrar las motos de un tipo seleccionado.\n");
    printf(" 3) Informar la o las motos de mayor cilindrada.\n");
    printf(" 4) Mostrar un listado de las motos separadas por tipo.\n");
    printf(" 5) Elegir un color y un tipo y contar cuantas motos hay de ese color y ese tipo.\n");
    printf(" 6) Mostrar el o los colores más elegidos por los clientes.\n\n");
    printf(" j. CERRAR            \n");

    return;
}
