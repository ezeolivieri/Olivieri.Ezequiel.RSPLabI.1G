#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Controller.h"
#include "eBicicleta.h"
#include "Parser.h"
#include "Auxiliares.h"

int controller_loadFromText(char* path , LinkedList* pArrayListeBicicleta)
{
    int todoOk = -1;

    FILE* fpArchivo;

    if( path != NULL && pArrayListeBicicleta != NULL )
    {
        fpArchivo = fopen(path, "r");

        if( fpArchivo != NULL )
        {
            if( !parser_eBicicletaFromText(fpArchivo, pArrayListeBicicleta) )
            {
                todoOk = 0;
            }

            fclose(fpArchivo);
        }
        else
        {
            printf("\n\nERROR INTENTANDO ABRIR EL ARCHIVO.\n\n");
        }
    }

    return todoOk;
}

int controller_ListeBicicleta(LinkedList* pArrayListeBicicleta)
{
    int retorno = -1;
    eBicicleta* peBicicletaAux = NULL;
    int arrayLen = ll_len(pArrayListeBicicleta);

    if( pArrayListeBicicleta != NULL )
    {
        printf("\n\n");

        printf("    ###################################################\n");
        printf("    ################## LISTA DE BICIS #################\n");
        printf("    ###################################################\n\n");

        printf("   ID     |   Nombre del dueño  |  Tipo de bici  |  Tiempo  \n");
        printf("------------------------------------------------------------\n\n");

        for( int i=0; i<arrayLen; i++ )
        {
            peBicicletaAux = (eBicicleta*) ll_get(pArrayListeBicicleta, i);

            if( peBicicletaAux != NULL )
            {
                printeBicicleta( peBicicletaAux );
            }
        }

        printf("\n\n");

        retorno = 0;
    }

    return retorno;
}

int controller_saveAsText(char* path , LinkedList* pArrayListeBicicleta)
{
    int retorno = -1;
    FILE* fpArchivo;

    if( pArrayListeBicicleta != NULL && path != NULL)
    {
        fpArchivo = fopen(path, "w");

        if( fpArchivo != NULL )
        {
            if( !parser_saveeBicicletaAsText( fpArchivo, pArrayListeBicicleta ) )
            {
                retorno = 0;
            }

            fclose(fpArchivo);
        }
    }

    return retorno;
}

void controller_MapeBicicleta(LinkedList* pArrayListeBicicleta)
{
    if( pArrayListeBicicleta != NULL )
    {
        ll_map(pArrayListeBicicleta, eBicicleta_updateTiempos);
        printf("\n\n\n    =======> LISTA ACTUALIZADA CON TIEMPOS ACTUALIZADOS <======== \n\n\n");
        controller_ListeBicicleta(pArrayListeBicicleta);
    }
}

void controller_FilterAndSaveBicisDeTipo(LinkedList* pArrayListeBicicleta, char* tipo)
{
    LinkedList* bicisDeTipo = ll_newLinkedList();

    if( pArrayListeBicicleta != NULL && tipo != NULL )
    {
        if( strcmp(tipo, "BMX") == 0 )
        {
            bicisDeTipo = ll_filter(pArrayListeBicicleta, eBicicleta_filterByBmx);

            if( !controller_saveAsText("bicisDeTipoBmx.csv", bicisDeTipo) )
            {
                printf("ARCHIVO bicisDeTipoBmx.csv GENERADO CORRECTAMENTE.\n\n");
            }
            else
            {
                printf("SE PRODUJO UN ERROR GENERANDO EL ARCHIVO bicisDeTipoBmx.csv\n\n");
            }
        }

        if( strcmp(tipo, "PLAYERA") == 0 )
        {
            bicisDeTipo = ll_filter(pArrayListeBicicleta, eBicicleta_filterByPlayera);

            if( !controller_saveAsText("bicisDeTipoPlayera.csv", bicisDeTipo) )
            {
                printf("ARCHIVO bicisDeTipoPlayera.csv GENERADO CORRECTAMENTE.\n\n");
            }
            else
            {
                printf("SE PRODUJO UN ERROR GENERANDO EL ARCHIVO bicisDeTipoPlayera.csv\n\n");
            }
        }

        if( strcmp(tipo, "MTB") == 0 )
        {
            bicisDeTipo = ll_filter(pArrayListeBicicleta, eBicicleta_filterByMtb);

            if( !controller_saveAsText("bicisDeTipoMtb.csv", bicisDeTipo) )
            {
                printf("ARCHIVO bicisDeTipoMtb.csv GENERADO CORRECTAMENTE.\n\n");
            }
            else
            {
                printf("SE PRODUJO UN ERROR GENERANDO EL ARCHIVO bicisDeTipoMtb.csv\n\n");
            }
        }

        if( strcmp(tipo, "PASEO") == 0 )
        {
            bicisDeTipo = ll_filter(pArrayListeBicicleta, eBicicleta_filterByPaseo);

            if( !controller_saveAsText("bicisDeTipoPaseo.csv", bicisDeTipo) )
            {
                printf("ARCHIVO bicisDeTipoPaseo.csv GENERADO CORRECTAMENTE.\n\n");
            }
            else
            {
                printf("SE PRODUJO UN ERROR GENERANDO EL ARCHIVO bicisDeTipoPaseo.csv\n\n");
            }
        }

        printf("\n\n\n");
        controller_ListeBicicleta(bicisDeTipo);
        printf("\n\n\n");
    }
}
