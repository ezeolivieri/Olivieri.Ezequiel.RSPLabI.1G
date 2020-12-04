#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LinkedList.h"
#include "Auxiliares.h"
#include "eBicicleta.h"
#include "Controller.h"





/*********************** PROTOTIPOS ***********************/

/** \brief Despliegue de menu principal
 *
 * \return int Opcion ingresada por el usuario
 *
 */
int menu();





/****************** FUNCION MAIN ********************/

int main()
{
    srand(time(NULL));

    int option = 0;
    int estaOrdenado = 0;
    char confirmaSalir = 'N';
    char path[100];
    char tipoAux[200];

    LinkedList* listaBicicletas = ll_newLinkedList();



    do
    {
        system("clear");

        option = menu();

        switch(option)
        {
            case 1:
                system("clear");

                aux_getCadena(path, "Ingrese nombre del archivo: ");

                if( !controller_loadFromText(path, listaBicicletas) )
                {
                    printf("\n\nARCHIVO CARGADO CON EXITO.\n\n");
                }
                else
                {
                    printf("\n\nOCURRIO UN ERROR AL CARGAR EL ARCHIVO.\n\n");
                }
                break;

            case 2:
                system("clear");
                if( !ll_isEmpty(listaBicicletas) )
                {
                    controller_ListeBicicleta(listaBicicletas);
                }
                else
                {
                    printf("\n\nNO HAY INFORMACION CARGADA EN EL SISTEMA\n\n");
                }
                break;

            case 3:
                system("clear");
                if( !ll_isEmpty(listaBicicletas) )
                {
                    controller_MapeBicicleta(listaBicicletas);
                }
                else
                {
                    printf("\n\nNO HAY INFORMACION CARGADA EN EL SISTEMA\n\n");
                }
                break;

            case 4:
                system("clear");
                if( !ll_isEmpty(listaBicicletas) )
                {
                    printf("TIPOS DE BICI: BMX, PLAYERA, MTB, PASEO.\n\n");
                    aux_getCadena(tipoAux, "Ingrese el tipo por el que quiere filtrar: ");

                    controller_FilterAndSaveBicisDeTipo(listaBicicletas, tipoAux);
                }
                else
                {
                    printf("\n\nNO HAY INFORMACION CARGADA EN EL SISTEMA\n\n");
                }
                break;

            case 5:
                system("clear");
                if( !ll_isEmpty(listaBicicletas) )
                {
                    if( !ll_sort( listaBicicletas, eBicicleta_sortByTipoAndTiempo, 0 ) )
                    {
                        controller_ListeBicicleta(listaBicicletas);
                        estaOrdenado = 1;
                    }
                    else
                    {
                        printf("\n\nSE PRODUJO UN ERROR AL INTENTAR ORDENAR\n\n");
                    }
                }
                else
                {
                    printf("\n\nNO HAY INFORMACION CARGADA EN EL SISTEMA\n\n");
                }
                break;

            case 6:
                system("clear");
                if( !ll_isEmpty(listaBicicletas) )
                {
                    if( estaOrdenado )
                    {
                        if( !controller_saveAsText("bicisOrdenadas.csv", listaBicicletas) )
                        {
                            printf("\n\nSE GENERO EL ARCHIVO bicisOrdenadas.csv CORRECTAMENTE.\n\n");
                        }
                        else
                        {
                            printf("\n\nOCURRIO UN ERROR AL CREAR EL ARCHIVO bicisOrdenadas.csv.\n\n");
                        }
                    }
                    else
                    {
                        printf("\n\nTODAVIA NO SE ORDENO LA LISTA DE BICICLETAS ORIGINAL.\n\n");
                    }
                }
                else
                {
                    printf("\n\nNO HAY INFORMACION CARGADA EN EL SISTEMA\n\n");
                }
                break;

            case 7:
                confirmaSalir = aux_getConfirmacion("Seguro que desea salir? (s - si / n - no): ", "Error. Ingrese una opcion valida: ");
                break;

            default:
                printf("\n\n OPCION INCORRECTA! \n\n");
                break;
        }

        if( option != 7 )
        {
            system("read -p 'Press Enter to continue...' var");
        }

    } while( confirmaSalir != 'S' );

    return 0;
}





/*******************************
            FUNCIONES
 *******************************/

int menu()
{
    int opcion;

    printf("\n");
    printf("                    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("                    ~~~~~~     MENU PRINCIPAL    ~~~~~~\n");
    printf("                    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n");

    printf("                    1) Cargar archivo.\n");
    printf("                    2) Imprimir lista.\n");
    printf("                    3) Asignar tiempos.\n");
    printf("                    4) Filtrar por tipo.\n");
    printf("                    5) Mostrar posiciones.\n");
    printf("                    6) Guardar posiciones.\n\n");

    printf("                    7) Salir.\n\n");

    printf("                    Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

