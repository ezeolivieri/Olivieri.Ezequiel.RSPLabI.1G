#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "eBicicleta.h"

int parser_eBicicletaFromText(FILE* fpArchivo , LinkedList* pArrayListeBicicleta)
{
    int error = -1;
    char eBicicletaAux[4][200];
    eBicicleta* biciAux = NULL;

    if( pArrayListeBicicleta != NULL && fpArchivo != NULL)
    {
        // LECTURA FANTASMA PARA SALTEAR EL ENCABEZADO
        fscanf(fpArchivo, "%[^,],%[^,],%[^,],%[^\n]\n", eBicicletaAux[0], eBicicletaAux[1], eBicicletaAux[2], eBicicletaAux[3]);

        do
        {
            if( fscanf(fpArchivo, "%[^,],%[^,],%[^,],%[^\n]\n", eBicicletaAux[0], eBicicletaAux[1], eBicicletaAux[2], eBicicletaAux[3]) == 4 )
            {
                biciAux = eBicicleta_newParametros(eBicicletaAux[0], eBicicletaAux[1], eBicicletaAux[2], eBicicletaAux[3]);

                if( biciAux != NULL )
                {
                    ll_add(pArrayListeBicicleta, biciAux);
                }
            }
        }
        while( !feof(fpArchivo) );

        error = 0;
    }

    return error;
}

int parser_saveeBicicletaAsText(FILE* fpArchivo , LinkedList* pArrayListeBicicleta)
{
    int error = -1;
    eBicicleta* peBicicletaAux = NULL;
    int idAux;
    char nombreAux[128];
    char tipoAux[128];
    int tiempoAux;
    int arrayLen = ll_len(pArrayListeBicicleta);

    if( pArrayListeBicicleta != NULL && fpArchivo != NULL)
    {
        for( int i=0; i < arrayLen; i++ )
        {
            peBicicletaAux = (eBicicleta*) ll_get(pArrayListeBicicleta, i);

            if( peBicicletaAux != NULL )
            {
                if( eBicicleta_getId(peBicicletaAux, &idAux) &&
                    eBicicleta_getNombre(peBicicletaAux, nombreAux) &&
                    eBicicleta_getTipo(peBicicletaAux, tipoAux) &&
                    eBicicleta_getTiempo(peBicicletaAux, &tiempoAux) )
                {
                    fprintf(fpArchivo, "%d,%s,%s,%d\n", idAux, nombreAux, tipoAux, tiempoAux);
                }
            }
        }

        error = 0;
    }

    return error;
}
