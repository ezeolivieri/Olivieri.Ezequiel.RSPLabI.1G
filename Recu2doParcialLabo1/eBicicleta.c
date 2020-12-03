#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eBicicleta.h"
#include "Controller.h"
#include "aux.h"

eBicicleta* eBicicleta_new()
{
    eBicicleta* nuevaBici = (eBicicleta*) malloc(sizeof(eBicicleta));

    if( nuevaBici != NULL )
    {
        eBicicleta_setId(nuevaBici, 0);
        eBicicleta_setNombre(nuevaBici, "-");
        eBicicleta_setTipo(nuevaBici, "-");
        eBicicleta_setTiempo(nuevaBici, 0);
    }

    return nuevaBici;
}

eBicicleta* eBicicleta_newParametros(char* id, char* name, char* tipo, char* tiempo)
{
    eBicicleta* nuevaBici = eBicicleta_new();

    if( nuevaBici != NULL )
    {
        if( !( eBicicleta_setId(nuevaBici, atoi(id)) &&
               eBicicleta_setNombre(nuevaBici, name) &&
               eBicicleta_setTipo(nuevaBici, tipo) &&
               eBicicleta_setTiempo(nuevaBici, atoi(tiempo)) ) )
        {
            eBicicleta_delete(nuevaBici);
        }

        eBicicleta_setId(nuevaBici, atoi(id));
        eBicicleta_setNombre(nuevaBici, name);
        eBicicleta_setTipo(nuevaBici, tipo);
        eBicicleta_setTiempo(nuevaBici, atoi(tiempo));
    }

    return nuevaBici;
}

void eBicicleta_delete(eBicicleta* this)
{
    free( this );
}

int eBicicleta_setId(eBicicleta* this,int id)
{
    int todoOk = 0;

    if( this != NULL )
    {
        this->id = id;
        todoOk = 1;
    }

    return todoOk;
}
int eBicicleta_getId(eBicicleta* this,int* id)
{
    int todoOk = 0;

    if( this != NULL && id != NULL)
    {
        *id = this->id;
        todoOk = 1;
    }

    return todoOk;
}

int eBicicleta_setNombre(eBicicleta* this,char* nombre)
{
    int todoOk = 0;

    if( this != NULL && nombre != NULL )
    {
        strcpy(this->nombre, nombre);
        todoOk = 1;
    }

    return todoOk;
}
int eBicicleta_getNombre(eBicicleta* this,char* nombre)
{
    int todoOk = 0;

    if( this != NULL && nombre != NULL )
    {
        strcpy(nombre, this->nombre);
        todoOk = 1;
    }

    return todoOk;
}

int eBicicleta_setTipo(eBicicleta* this,char* tipo)
{
    int todoOk = 0;

    if( this != NULL && tipo != NULL )
    {
        strcpy(this->tipo, tipo);
        todoOk = 1;
    }

    return todoOk;
}
int eBicicleta_getTipo(eBicicleta* this,char* tipo)
{
    int todoOk = 0;

    if( this != NULL && tipo != NULL )
    {
        strcpy(tipo, this->tipo);
        todoOk = 1;
    }

    return todoOk;
}

int eBicicleta_setTiempo(eBicicleta* this,int tiempo)
{
    int todoOk = 0;

    if( this != NULL )
    {
        this->tiempo = tiempo;
        todoOk = 1;
    }

    return todoOk;
}
int eBicicleta_getTiempo(eBicicleta* this,int* tiempo)
{
    int todoOk = 0;

    if( this != NULL && tiempo != NULL)
    {
        *tiempo = this->tiempo;
        todoOk = 1;
    }

    return todoOk;
}

int printeBicicleta(eBicicleta* peBicicleta)
{
    int todoOk = 0;
    int idAux;
    char nameAux[900];
    char tipoAux[900];
    int tiempoAux;

    if( peBicicleta != NULL )
    {
        if( eBicicleta_getId(peBicicleta,&idAux) &&
            eBicicleta_getNombre(peBicicleta,nameAux) &&
            eBicicleta_getTipo(peBicicleta,tipoAux) &&
            eBicicleta_getTiempo(peBicicleta, &tiempoAux) )
        {
            printf("%6d %20s    %10s       %10d\n",idAux,nameAux,tipoAux, tiempoAux);
        }
        else
        {
            printf("Error intentando obtener los datos de la bicicleta.\n");
        }

        todoOk = 1;
    }

    return todoOk;
}

void* eBicicleta_updateTiempos(void* peBicicleta)
{
    int tiempoAux;

    if( peBicicleta != NULL )
    {
        tiempoAux = aux_getRandom(50, 120);

        eBicicleta_setTiempo( (eBicicleta*) peBicicleta, tiempoAux );
    }

    return peBicicleta;
}

int eBicicleta_filterByBmx(void* peBicicleta)
{
    char tipoAux[200];

    if( peBicicleta != NULL )
    {
        eBicicleta_getTipo( (eBicicleta*) peBicicleta, tipoAux );

        if( strcmp(tipoAux, "BMX") == 0 )
        {
            return 1;
        }
    }

    return 0;
}

int eBicicleta_filterByPlayera(void* peBicicleta)
{
    char tipoAux[200];

    if( peBicicleta != NULL )
    {
        eBicicleta_getTipo( (eBicicleta*) peBicicleta, tipoAux );

        if( strcmp(tipoAux, "PLAYERA") == 0 )
        {
            return 1;
        }
    }

    return 0;
}

int eBicicleta_filterByMtb(void* peBicicleta)
{
    char tipoAux[200];

    if( peBicicleta != NULL )
    {
        eBicicleta_getTipo( (eBicicleta*) peBicicleta, tipoAux );

        if( strcmp(tipoAux, "MTB") == 0 )
        {
            return 1;
        }
    }

    return 0;
}

int eBicicleta_filterByPaseo(void* peBicicleta)
{
    char tipoAux[200];

    if( peBicicleta != NULL )
    {
        eBicicleta_getTipo( (eBicicleta*) peBicicleta, tipoAux );

        if( strcmp(tipoAux, "PASEO") == 0 )
        {
            return 1;
        }
    }

    return 0;
}

int eBicicleta_sortByTipoAndTiempo(void* peBicicletaUno, void* peBicicletaDos)
{
    int retorno = 0;
    int tiempoAuxUno;
    int tiempoAuxDos;
    char tipoAuxUno[200];
    char tipoAuxDos[200];

    if( peBicicletaUno != NULL && peBicicletaDos != NULL )
    {
        eBicicleta_getTipo( (eBicicleta*) peBicicletaUno, tipoAuxUno );
        eBicicleta_getTipo( (eBicicleta*) peBicicletaDos, tipoAuxDos );

        eBicicleta_getTiempo( (eBicicleta*) peBicicletaUno, &tiempoAuxUno );
        eBicicleta_getTiempo( (eBicicleta*) peBicicletaDos, &tiempoAuxDos );

        if( strcmp(tipoAuxDos, tipoAuxUno) > 0 )
        {
            retorno = 1;
        }
        else
        {
            if( strcmp(tipoAuxUno, tipoAuxDos) == 0 )
            {
                if( tiempoAuxDos > tiempoAuxUno )
                {
                    retorno = 1;
                }
                else
                {
                    retorno = -1;
                }
            }
            else
            {
                retorno = -1;
            }
        }
    }

    return retorno;
}
