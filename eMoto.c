#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "eMoto.h"

#include "eColor.h"
#include "eTipo.h"
#include "eServicio.h"

#include "validaciones.h"

#include "dataStore.h"


int inicializacion(eMoto motos[], int tam, eColor colores[], int tam_c, eTipo tipos[], int tam_t, eServicio servicios[], int tam_s)
{

    int error=1;
    if(motos != NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            motos[i].isEmpty=1;
            motos[i].cilindrada=0;
            colores[i].idColor=1;
            tipos[i].idTipo=1;
            servicios[i].idServicio=1;
        }

        iniciarColores(colores, tam_c);
        iniciarTipos(tipos, tam_t);
        iniciarServicios(servicios, tam_s);
        error=0;
    }

    return error;
}


void mostrarMoto(eMoto motos, eTipo tipos[], eColor colores[], int tam_t, int tam_c, eCliente clientes[], int tam_cl)
{
    char tipoAux[15];
    char colorAux[10];
    char clienteAux[15];

    for(int i=0; i<tam_c; i++)
    {
        if(motos.idColor==colores[i].idColor)
        {
            strcpy(colorAux, colores[i].nombreColor);
            break;
        }
    }

    for(int j=0; j<tam_t; j++)
    {
        if(motos.idTipo==tipos[j].idTipo)
        {
            strcpy(tipoAux, tipos[j].descripcionTipo);
            break;
        }
    }

    for(int e=0; e<tam_cl; e++)
    {
        if(motos.clientes.id==clientes[e].id)
        {
            strcpy(clienteAux, clientes[e].nombre);
            break;
        }
    }

    printf("    %5d      %12s  %15s   %10s       %3d         %10s\n", motos.idMoto, motos.marca, tipoAux, colorAux, motos.cilindrada, clienteAux);
}


int listarMotos(eMoto motos[], int tam, eTipo tipos[], eColor colores[], int tam_t, int tam_c, eCliente clientes[],int tam_cl)
{

    int hayMotos=0;
    for(int i=0; i<tam; i++)
    {
        if(motos[i].isEmpty == 0)
        {
            hayMotos=1;
        }
    }

    if(motos != NULL && tam > 0 && hayMotos==1)
    {
        printf("\n- Listar Motos\n\n");
        printf("    ID MOTO           MARCA             TIPO        COLOR     CILINDRADA       CLIENTE\n");
        printf("---------------------------------------------------------------------------------------\n");
        for(int i=0; i<tam; i++ )
        {
            if(motos[i].isEmpty == 0)
            {
                mostrarMoto(motos[i], tipos, colores, tam_t, tam_c, clientes, tam_cl);
            }
        }

    }
    else
    {
        printf("\n- No hay motos en la lista. Tiene que dar una de Alta primero.\n");
    }

    return hayMotos;
}


int altaMotos(eMoto motos[], int tam, eColor colores[], int tam_c, eTipo tipos[], int tam_t, int proximoIdMoto, eCliente clientes[],int tam_cl)
{
    int error=-1;
    int retorno;

    eMoto nuevaMoto;

    if(motos != NULL && tam > 0 && proximoIdMoto > 0 )
    {
        retorno = buscarLugarLibre(motos,tam);

        if(retorno == -1)
        {
            printf("Error, el sistema esta completo.\n");
        }
        else
        {
            system("cls");
            printf("   ***ALTA MOTO***\n\n");

            //int id moto
            printf("\n> El Id Moto sera: %d",proximoIdMoto);
            nuevaMoto.idMoto=proximoIdMoto;

            //char marca
            printf("\n\n> Ingrese la Marca: ");
            fflush(stdin);
            gets(nuevaMoto.marca);

            while(validacionCadenaCaracteres(nuevaMoto.marca))
            {
                printf("- Re ingrese la marca sin numeros.\n");
                printf("> Marca: ");
                fflush(stdin);
                gets(nuevaMoto.marca);
            }

            //int id tipo
            listarTipos(tipos, tam_t);
            printf("\n> ID Tipo de moto: ");
            fflush(stdin);
            scanf("%d",&nuevaMoto.idTipo);

            while(1==validacionIdTipoExiste(tipos,tam_t, nuevaMoto.idTipo))
            {
                printf("- Ese ID de Tipo no existe.\n");
                printf("\n> ID Tipo de moto: ");
                fflush(stdin);
                scanf("%d",&nuevaMoto.idTipo);;
            }


            //int id color
            listarColores(colores, tam_c);
            printf("\n> ID Color de moto: ");
            fflush(stdin);
            scanf("%d",&nuevaMoto.idColor);

            while(1==validacionIdColorExiste(colores,tam_c, nuevaMoto.idColor))
            {
                printf("- Ese ID de Color, no existe.\n");
                printf("\n> Re ingrese ID Color de moto: ");
                fflush(stdin);
                scanf("%d",&nuevaMoto.idColor);
            }

            //int cilindrada
            printf("\n- Ingrese la cilindrada de la moto. ");
            printf("\nEstas pueden ser 50, 125, 500, 600, 750. \n");
            printf("\n> Cilindrada: ");
            fflush(stdin);
            scanf("%d",&nuevaMoto.cilindrada);

            while(1==validacionCilindradaExiste(nuevaMoto.cilindrada))
            {
                printf("\n- Re ingrese la cilindrada de la moto. ");
                printf("\n> Cilindrada: ");
                fflush(stdin);
                scanf("%d",&nuevaMoto.cilindrada);
            }

            //ESTRUCTURA CLIENTE
            printf("\n- Ingrese el cliente de la moto. ");
            listarClientes( clientes, tam_cl);

            printf("\n> Id Cliente: ");
            fflush(stdin);
            scanf("%d",&nuevaMoto.clientes.id);

            while(1==validacionIdClienteExiste(clientes, tam_cl, nuevaMoto.clientes.id))
            {
                printf("\n- Re ingrese el cliente de la moto. ");
                printf("\n> Id Cliente: ");
                fflush(stdin);
                scanf("%d",&nuevaMoto.clientes.id);
            }

            nuevaMoto.isEmpty=0;

            motos[retorno]=nuevaMoto;

            error=1;
        }

    }

    return error;
}

int modificarMotos(eMoto motos[], int tam, eColor colores[], int tam_c, eTipo tipos[], int tam_t, int proximoIdMoto, eCliente clientes[],int tam_cl)
{

    int error=-1;
    int retorno;
    int opcionModificar=0;

    int id;
    int bandera=0;

    eMoto nuevaMoto;

    if(motos != NULL && tam > 0 && proximoIdMoto > 0 )
    {
        retorno = buscarLugarLibre(motos,tam);

        if(retorno == -1)
        {
            printf("Error, el sistema esta completo.\n");
        }
        else
        {
            system("cls");
            printf("   ***MODIFICAR MOTO***\n\n");

            listarMotos(motos, tam, tipos, colores, tam_t, tam_c, clientes, tam_cl);

            printf("\n> Ingrese Id de la moto a modificar: ");
            scanf("%d", &id);
            retorno = buscarIdMoto(motos, tam, id);

            if(retorno==-1)
            {
                printf("- No existe una moto con ese Id\n\n");
            }
            else
            {
                nuevaMoto=motos[retorno];

                while(bandera==0)
                {
                    printf("\n- Ingrese la opcion a modificar de esta moto:\n");

                    printf("    ID MOTO         MARCA           TIPO          COLOR     CILINDRADA\n");

                    mostrarMoto(motos[retorno], tipos, colores, tam_t, tam_c, clientes, tam_cl);

                    printf("\n1) Color\n2) Cilindrada \n3) Guardar cambios y volver a Menu.\n>");
                    fflush(stdin);
                    scanf("%d", &opcionModificar);

                    switch(opcionModificar)
                    {

                        case 1:
                            listarColores(colores, tam_c);
                            printf("\n> ID Color de moto: ");
                            fflush(stdin);
                            scanf("%d",&nuevaMoto.idColor);

                            while(1==validacionIdColorExiste(colores,tam_c, nuevaMoto.idColor))
                            {
                                printf("- Ese ID de Color, no existe.\n");
                                printf("\n> Re ingrese ID Color de moto: ");
                                fflush(stdin);
                                scanf("%d",&nuevaMoto.idColor);
                            }
                            motos[retorno]=nuevaMoto;
                            break;
                        case 2:
                            printf("\n- Ingrese la cilindrada de la moto. ");
                            printf("\nEstas pueden ser 50, 125, 500, 600, 750. \n");
                            printf("\n> Cilindrada: ");
                            fflush(stdin);
                            scanf("%d",&nuevaMoto.cilindrada);

                            while(validacionCilindradaExiste(nuevaMoto.cilindrada))
                            {
                                printf("\n- Re ingrese la cilindrada de la moto. ");
                                printf("\n> Cilindrada: ");
                                fflush(stdin);
                                scanf("%d",&nuevaMoto.cilindrada);
                            }
                            motos[retorno]=nuevaMoto;
                            break;
                        case 3:
                            nuevaMoto.isEmpty=0;
                            error=1;
                            bandera=1;
                            break;
                        default:
                            printf("\n-Opcion Incorrecta.");
                            break;
                    }
                    //adentro while
                }
                //afuera while
            }
        }
    }

    return error;
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



int bajaMotos(eMoto motos[],int tam, eTipo tipos[], eColor colores[], int tam_t, int tam_c, eCliente clientes[],int tam_cl)
{
    int error=1;
    int retorno;
    int id;
    int confirmacion;
    int hayMotos=0;

    system("cls");
    printf("   ***BAJA MOTO***\n\n");
    hayMotos=listarMotos(motos,tam, tipos, colores, tam_t, tam_c, clientes, tam_cl);

    if(motos !=NULL && tam >0 && hayMotos==1)
    {

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

            ///mostrarMoto(motos[retorno], tipos[retorno], colores[retorno], tam_t, tam_c);

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


///1//////////
int mostrarColorSeleccionado(eMoto motos[],eTipo tipos[],eColor colores[], int tam, int tam_c, int tam_t)
{
    int error=1;
    int hayMotos=0;

    int auxIdColor;
    char colorAux[10];


    for(int i=0; i<tam; i++)
    {
        if(motos[i].isEmpty == 0)
        {
            hayMotos=1;
        }
    }

    if(motos!= NULL && tam > 0 && hayMotos==1)
    {

        listarColores(colores, tam_c);
        printf("\n> Elija el ID del Color de moto: ");
        fflush(stdin);
        scanf("%d",&auxIdColor);

        while(1==validacionIdColorExiste(colores,tam_c, auxIdColor))
        {
            printf("- Ese ID de Color, no existe.\n");
            printf("\n> Re ingrese ID Color de moto: ");
            fflush(stdin);
            scanf("%d",&auxIdColor);
        }


        for(int i=0; i<tam_c; i++)
        {
            if(auxIdColor==colores[i].idColor)
            {
                strcpy(colorAux, colores[i].nombreColor);
                break;
            }
        }

        printf("- Listado de motos color %5s .\n\n", colorAux);
        printf("      Id             Marca        Tipo        Cilindrada\n");
        printf(" ---------------------------------------------------------\n");
        for(int i =0 ; i < tam ; i++)
        {
            if(motos[i].isEmpty==0 && motos[i].idColor==auxIdColor)
            {
                mostrarMotoSinColor(motos[i],tipos,tam_t);
                error=0;
            }
        }
    }
    else
    {
        printf("\n- No hay motos en la lista. Tiene que dar una de Alta primero.\n");
    }

    return error;
}

void mostrarMotoSinColor(eMoto motos, eTipo tipos[], int tam_t)
{
    char tipoAux[15];

    for(int j=0; j<tam_t; j++)
    {
        if(motos.idTipo==tipos[j].idTipo)
        {
            strcpy(tipoAux, tipos[j].descripcionTipo);
            break;
        }
    }

    printf("    %5d      %12s  %15s     %3d\n", motos.idMoto, motos.marca, tipoAux, motos.cilindrada);
}


///2/////////////////////////////////////////////
int listarTipoSeleccionado(eMoto motos[],eTipo tipos[],eColor colores[], int tam, int tam_c, int tam_t)
{
    int error=1;
    int auxIdTipo;
    char tipoAux[10];

    if(motos!= NULL && tam > 0)
    {
        listarTipos(tipos, tam_t);
        printf("\n> ID Tipo de moto: ");
        fflush(stdin);
        scanf("%d",&auxIdTipo);

        while(1==validacionIdTipoExiste(tipos,tam_t, auxIdTipo))
        {
            printf("- Ese ID de Tipo no existe.\n");
            printf("\n> ID Tipo de moto: ");
            fflush(stdin);
            scanf("%d",&auxIdTipo);

        }

        for(int i=0; i<tam_t; i++)
        {
            if(auxIdTipo==tipos[i].idTipo)
            {
                strcpy(tipoAux, tipos[i].descripcionTipo);
                break;
            }
        }

        printf("- Listado de motos color %5s .\n\n", tipoAux);
        printf("      Id             Marca        Color    Cilindrada \n");
        printf(" -----------------------------------------------------------------\n");
        for(int i =0 ; i < tam ; i++)
        {
            if(motos[i].isEmpty==0 && motos[i].idTipo==auxIdTipo)
            {
                mostrarMotoSinTipo(motos[i],colores,tam_c);
                error=0;
            }
        }
    }
    else
    {
        printf("\n- No hay motos en la lista. Tiene que dar una de Alta primero.\n");
    }

    return error;
}

void mostrarMotoSinTipo(eMoto motos, eColor colores[], int tam_c)
{
    char colorAux[15];

    for(int i=0; i<tam_c; i++)
    {
        if(motos.idColor==colores[i].idColor)
        {
            strcpy(colorAux, colores[i].nombreColor);
            break;
        }
    }

    printf("    %5d      %12s  %15s     %3d\n", motos.idMoto, motos.marca, colorAux, motos.cilindrada);
}



///3/////////////////
int motosMayorCilindrada(eMoto motos[], eTipo tipos[], eColor colores[], int tam, int tam_t, int tam_c, eCliente clientes[], int tam_cl)
{
    int error=1;
    int mayor;
    int flag=1;

    if(motos!= NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(flag==1)
            {
                mayor=motos[i].cilindrada;
            }
            if(motos[i].cilindrada>=mayor)
            {
                mayor=motos[i].cilindrada;
                error=0;
                flag=0;
            }
        }

        printf("Las motos con mayor cilindrada son:");
        for(int i=0; i<tam; i++)
        {
            if(motos[i].cilindrada==mayor)
            {
                mostrarMoto(motos[i], tipos, colores, tam_t, tam_c, clientes, tam_cl);
            }
            error=0;
        }
    }

    return error;
}



///4/////////////////
int mostrarMotosXtipos(eMoto motos[], int tam, eTipo tipos[], eColor colores[], int tam_t, int tam_c)
{

    int hayMotos=0;

    for(int i=0; i<tam; i++)
    {
        if(motos[i].isEmpty == 0)
        {
            hayMotos=1;
        }
    }

    if(motos != NULL && tam > 0 && hayMotos==1)
    {
        printf("\n- Listar Motos por tipos\n\n");


        printf("            | ID MOTO            MARCA           COLOR     CILINDRADA\n");
        printf("-----------------------------------------------------------------------\n");
        printf(" ENDURO     |\n");
        for(int i=0; i<tam; i++)
        {
            if(motos[i].isEmpty == 0 && motos[i].idTipo==1001)
            {
                mostrarMotoTipo(motos[i], tipos, colores, tam_t, tam_c);
            }
        }
        printf("-----------------------------------------------------------------------\n");
        printf(" CHOPERAS   |\n");
        for(int i=0; i<tam; i++)
        {
            if(motos[i].isEmpty == 0 && motos[i].idTipo==1002)
            {
                mostrarMotoTipo(motos[i], tipos, colores, tam_t, tam_c);
            }
        }
        printf("-----------------------------------------------------------------------\n");
        printf(" SCOOTER    |\n");
        for(int i=0; i<tam; i++)
        {
            if(motos[i].isEmpty == 0 && motos[i].idTipo==1003)
            {
                mostrarMotoTipo(motos[i], tipos, colores, tam_t, tam_c);
            }
        }
        printf("-----------------------------------------------------------------------\n");
        printf(" CICLOMOTOR |\n");
        for(int i=0; i<tam; i++)
        {
            if(motos[i].isEmpty == 0 && motos[i].idTipo==1004)
            {
                mostrarMotoTipo(motos[i], tipos, colores, tam_t, tam_c);
            }
        }

    }
    else
    {
        printf("\n- No hay motos en la lista. Tiene que dar una de Alta primero.\n");
    }

    return hayMotos;
}

void mostrarMotoTipo(eMoto motos, eTipo tipos[], eColor colores[], int tam_t, int tam_c)
{
    char colorAux[15];

    for(int i=0; i<tam_c; i++)
    {
        if(motos.idColor==colores[i].idColor)
        {
            strcpy(colorAux, colores[i].nombreColor);
            break;
        }
    }

    printf("            |  %5d      %12s  %14s     %3d\n", motos.idMoto, motos.marca, colorAux, motos.cilindrada);
}


///6/////////////////
int colorMasElegido(eMoto motos[],int tam,eColor colores[],int tam_c)
{
    int error=1;
    int contadores[tam_c];
    int idBuscado;
    int mayor;
    int flag=0;
    int hayMotos=0;

    if(motos!= NULL && colores!=NULL && tam > 0 && tam_c > 0 )
    {
        for(int i=0; i<tam; i++)
        {
            if(motos[i].isEmpty == 0)
            {
                hayMotos=1;
            }
        }

        if(hayMotos==1)
        {
            for(int d=0; d<tam_c; d++)
            {
                contadores[d]=0;
                idBuscado=colores[d].idColor;

                for(int p=0; p<tam; p++)
                {
                    if(motos[p].isEmpty==0 && motos[p].idColor==idBuscado)
                    {
                        contadores[d]++;
                    }
                }
            }


            for(int i=0; i<tam_c; i++)
            {
                if(contadores[i]>mayor || flag==0)
                {
                    mayor=contadores[i];
                    flag=1;
                }
            }

            printf("\n- El o los colores mas elegidos son: \n\n");

            for(int i=0; i<tam; i++)
            {
                if(contadores[i]==mayor)
                {
                    printf("- %s \n",colores[i].nombreColor);
                    break;
                }
            }
            error=0;
        }
        else
        {
            printf("\n- No hay motos en la lista. Tiene que dar una de Alta primero.\n");
        }
    }
    return error;
}

///5/////////////////
int contadorColoryTipo(eMoto motos[], int tam, eColor colores[], int tam_c, eTipo tipos[], int tam_t)
{
    int contadorColor=0;
    int contadorTipo=0;

    char colorAux[15];
    char tipoAux[15];

    eMoto nuevaMoto;

    int hayMotos=0;

    for(int i=0; i<tam; i++)
    {
        if(motos[i].isEmpty == 0)
        {
            hayMotos=1;
        }
    }

    if(hayMotos==1)
    {
        //int id tipo
        listarTipos(tipos, tam_t);

        printf("\n> ID Tipo de moto: ");
        fflush(stdin);
        scanf("%d",&nuevaMoto.idTipo);

        while(1==validacionIdTipoExiste(tipos,tam_t, nuevaMoto.idTipo))
        {
            printf("- Ese ID de Tipo no existe.\n");
            printf("\n> ID Tipo de moto: ");
            fflush(stdin);
            scanf("%d",&nuevaMoto.idTipo);;
        }

        //int id color
        listarColores(colores, tam_c);

        printf("\n> ID Color de moto: ");
        fflush(stdin);
        scanf("%d",&nuevaMoto.idColor);

        while(1==validacionIdColorExiste(colores,tam_c, nuevaMoto.idColor))
        {
            printf("- Ese ID de Color, no existe.\n");
            printf("\n> Re ingrese ID Color de moto: ");
            fflush(stdin);
            scanf("%d",&nuevaMoto.idColor);
        }

        ///##########################################
        for(int i=0; i<tam; i++)
        {
            if(motos[i].idTipo ==nuevaMoto.idTipo)
            {
                contadorTipo++;
            }

            if(motos[i].idColor ==nuevaMoto.idColor)
            {
                contadorColor++;
            }
        }

        ///##########################################
        for(int i=0; i<tam_c; i++)
        {
            if(nuevaMoto.idColor==colores[i].idColor)
            {
                strcpy(colorAux, colores[i].nombreColor);
                break;
            }
        }

        for(int j=0; j<tam_t; j++)
        {
            if(nuevaMoto.idTipo==tipos[j].idTipo)
            {
                strcpy(tipoAux, tipos[j].descripcionTipo);
                break;
            }
        }

        printf("\n- Hay %d %5s y %d moto/s color %5s.\n", contadorTipo, tipoAux, contadorColor, colorAux);
    }
    else
    {
        printf("\n- No hay motos en la lista. Tiene que dar una de Alta primero.\n");
    }

    return 1;
}

