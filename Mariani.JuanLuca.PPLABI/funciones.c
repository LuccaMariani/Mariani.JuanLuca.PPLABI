#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "funciones.h"

#include "dataStore.h"

#define TAM 7

int initMotos(eMoto motos[], int tam)
{
    //      Para indicar que todas las posiciones del array están vacías, esta función pone la bandera
    //      (isEmpty) en TRUE en todas las posiciones del array.
    int error = 1;

    if(motos != NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            motos[i].isEmpty = 1;
        }
        error=0;
    }

    return error; //Retorna 1 si hubo algun error en la ejecucion de la funcion
}


int listarMotos(eMoto motos[], int tam, eTipo tipos[], eColor colores[], int tam_t, int tam_c)
{
    int error=0;


    //hacer un unico listado de las motos por tipo y id
    if(motos != NULL && tam > 0 )
    {

        printf("\n- Listar Motos\n\n");
        printf("    ID MOTO         MARCA           TIPO          COLOR     CILINDRADA\n");
        printf("-----------------------------------------------------------------------\n");
        for(int i=0; i<tam; i++)
        {
            if(motos[i].isEmpty == 0)
            {

                mostrarMoto( motos[i], tipos, colores, tam_t, tam_c);
            }
        }

    }
    return error;
}

void mostrarMoto(eMoto motos, eTipo tipos[], eColor colores[], int tam_t, int tam_c)
{
    char tipoAux[15];
    char colorAux[15];

    cargarColoryTipo(tipos, colores, colorAux, tipoAux, motos.color.idColor, motos.tipo.idTipo, tam_c, tam_t);

    printf("    %5d      %12s   %10s   %10s     %3d\n", motos.idMoto, motos.marca, colorAux, tipoAux, motos.cilindrada);
}

void cargarColoryTipo( eTipo tipos[], eColor colores[], char colorAux[], char tipoAux[], int idC, int idT, int tam_c, int tam_t)
{

    for(int i=0; i<tam_c; i++)
    {
        if(idC==colores[i].idColor)
        {
            strcpy(colorAux, colores[i].nombreColor);
        }
    }
    for(int i=0; i<tam_t; i++)
    {
        if(idT==tipos[i].idTipo)
        {
            strcpy(tipoAux, tipos[i].descripcionTipo);
        }
    }
}


int harcodeMotos(eMoto motos[],int tam,int cant)
{
    int retorno=-1;

    if(motos != NULL && tam > 0 && cant <= tam)
    {
        retorno = 0;
        for(int i=0; i<cant; i++)
        {
            motos[i].idMoto =HidMotos[i];

            strncpy(motos[i].marca,Hmarcas[i], sizeof(motos[i].marca));

            motos[i].tipo.idTipo=HidTipo[i];

            motos[i].color.idColor=HidColores[i];

            motos[i].cilindrada=Hcilindrada[i];

            motos[i].isEmpty=0;

            retorno=1;
        }
    }

    return retorno;
}


int inicializarMotos(eMoto motos[], int tam)
{

    int error = 1;

    if(motos != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            motos[i].isEmpty = 1;

        }
        error=0;
    }

    return error;
}


int altaMotos(eMoto motos[], int tam, int proximoIdMoto, eTipo tipos[])
{

    int error=-1;
    int retorno;

    eMoto nuevaMoto;



    if(motos != NULL && tam > 0 && proximoIdMoto > 0 )
    {
        retorno = buscarLugarLibre(motos,tam);

        if(retorno == -1)
        {
            printf("SISTEMA COMPLETO\n");

        }
        else
        {

            //int id moto
            printf("\n> Id Moto: %d",proximoIdMoto);
            nuevaMoto.idMoto=proximoIdMoto;

            //char marca
            printf("\n> Marca: ");
            fflush(stdin);
            gets(nuevaMoto.marca);
            while(validacionCadenaCaracteres(nuevaMoto.marca))
            {
                printf("- Solo se permiten letras en la marca.\n");
                printf("> Marca: ");
                fflush(stdin);
                gets(nuevaMoto.marca);
            }

            // eTipo tipo

            listarTipos(tipos, 4);
            printf("\n> ID Tipo de moto: ");
            fflush(stdin);
            scanf("%d",&nuevaMoto.tipo.idTipo);


            // eColor color
            //ACA IRIA funcion que imprime el listado de COLOR de motos y sus id
            printf("\n> ID Color de moto: ");
            fflush(stdin);
            scanf("%d",&nuevaMoto.color.idColor);

            //int cilindrada
            printf("\n- Ingrese la cilindrada de la moto. ");
            printf("\nEstas pueden ser 50, 125, 500, 600, 750. ");
            printf("\n> Cilindrada: ");
            printf("\n\nCHEQUEAR QUE ANDE BIEN ESTA VALIDACION\n\n ");
            fflush(stdin);
            scanf("%d",&nuevaMoto.cilindrada);

            nuevaMoto.isEmpty=0;

            motos[retorno]=nuevaMoto;

            error=1;
        }

    }

    return error;
}


int buscarLugarLibre(eMoto motos[],int tam)
{
    int retorno = -1;

    for(int i=0; i<tam; i++)
    {
        if(motos[i].isEmpty)
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}


int validacionCadenaCaracteres(char cadenaCaracteres[])
{
    int i;
    int encontrarNumero = 0;
    int len = strlen(cadenaCaracteres);

    for( i = 0; i < len; i++)
    {
        if(0==isalpha(cadenaCaracteres[i]))
        {
            encontrarNumero = 1;
            break;
        }
    }
    return encontrarNumero; // devuelve 1 si encuentra un numero, 0 si no.
}


int buscarIdMoto(eMoto motos[], int tam, int id)
{
    int retorno;//

    for(int i=0; i<tam; i++)
    {
        if(motos[i].idMoto==id && motos[i].isEmpty==0)
        {
            retorno=i;
            break;
        }
        else
        {
            retorno= -1;
        }
    }
    return retorno;
}


int bajaMotos(eMoto motos[],int tam, eTipo tipos[], eColor colores[], int tam_t, int tam_c)
{
    int error=1;
    int retorno;
    int id;
    int confirmacion;

    if(motos !=NULL && tam >0)
    {
        system("cls");
        printf("- Baja Moto\n\n");

        listarMotos(motos,TAM, tipos, colores, tam_t, tam_c);

        printf("> Ingrese Id de la moto a dar de baja: ");
        scanf("%d", &id);

        retorno = buscarIdMoto(motos, tam, id);

        if(retorno==-1)
        {
            printf("- No existe una moto con ese Id\n\n");
        }
        else
        {
            printf("Confirma la eliminacion de esta moto: \n");

            //mostrarMoto(motos[retorno], tipos[retorno], colores[retorno], tam_t, tam_c);

            printf("(1= Si) (0=No)\n>");
            fflush(stdin);
            scanf("%d", &confirmacion);

            if(confirmacion)
            {
                motos[retorno].isEmpty=1;
                error=0;
            }
        }
    }
    return error;
}

int harcodearTiposColoresServicios(eTipo tipos[], eColor colores[], eServicio servicios[], int tam_t, int tam_c, int tam_s)
{
    int error = -1;

    if(tipos!=NULL && colores!=NULL && servicios!=NULL)
    {
        for(int i =0; i< tam_t; i++)
        {
            tipos[i].idTipo=HidTipo[i];
            strcpy(tipos[i].descripcionTipo, HdescripcionTipo[i]);
        }

        for(int i =0; i< tam_c; i++)
        {
            colores[i].idColor=HidColores[i];
            strcpy(colores[i].nombreColor, Hcolores[i]);
        }

        for(int i =0; i< tam_s; i++)
        {
            servicios[i].idServicio=HidServicios[i];
            strcpy(servicios[i].descripcionServicio, HnombreServicios[i]);
        }

        error=0;
    }
    return error;
}


int listarTipos(eTipo tipos[], int tam)
{
    int error=1;

    if(tipos!= NULL && tam > 0)
    {
        printf("\n- Id correspondiente a cada tipo de moto\n");
        printf("\n    Id   |   Tipo de moto\n");
        printf("\n         |\n");
        for(int i=0; i<tam; i++)
        {
            mostrarTipo(tipos[i]);
        }
        error= 0;
    }

    return error;
}

void mostrarTipo(eTipo tipos)
{

    printf("  %4d   |  %13s\n", tipos.idTipo,tipos.descripcionTipo);
}
