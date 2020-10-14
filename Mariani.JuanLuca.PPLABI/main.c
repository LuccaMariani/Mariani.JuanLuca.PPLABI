#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "funciones.h"

#define TAM 10
#define TAM_T 4
#define TAM_C 5
#define TAM_S 44

int main()
{
    system("cls");

    char seguir = 1;
    char confirma;
    int proximoId=1000;

    int opcion;

    eMoto motos[TAM];
    eTipo tipos[TAM_T];
    eColor colores[TAM_C];
    eServicio servicios[TAM_S];

    //inicia todo el array en la estructura de motos, como vacio
    initMotos(motos, TAM);
    harcodearTiposColoresServicios( tipos, colores, servicios,TAM_T, TAM_C, TAM_S);

    //hardcodea un par de motos
    //harcodeMotos(motos,TAM,4);

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
            if(altaMotos(motos, TAM, proximoId, tipos)==1)
            {
                proximoId++;
            }
            break;
        case 'b':
            bajaMotos(motos,TAM, tipos, colores, TAM_T, TAM_C);
            break;
        case 'c':
            listarMotos(motos,TAM, tipos, colores, TAM_T, TAM_C);
            break;
        case 'd':
            listarTipos(tipos, TAM_T);
            break;
        case 'e':

            break;
        case 'f':

            break;
        case 'g':
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
        system("pause");
    }
    return 0;
}

void menu()
{
    printf(" *SERVICE MOTOS*\n");
    printf(" a ALTA MOTO         \n");
    printf(" b BAJA MOTO         \n");
    printf(" c LISTAR MOTOS      \n");
    printf(" d LISTAR TIPOS      \n");
    printf(" e LISTAR COLORES    \n");
    printf(" f LISTAR SERVICIOS  \n");
    printf(" g ALTA TRABAJO      \n");
    printf(" X Salir             \n");
    return;
}
