#include "LinkedList.h"

/** \brief Carga los datos de las bicicletas desde el archivo path (modo texto).
 *
 * \param path char*
 * \param pArrayListeBicicleta LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListeBicicleta);

/** \brief Listar bicicletas
 *
 * \param pArrayListeBicicleta LinkedList*
 * \return int
 *
 */
int controller_ListeBicicleta(LinkedList* pArrayListeBicicleta);

/** \brief Guarda los datos de las bicicletas en el archivo path (modo texto).
 *
 * \param path char*
 * \param pArrayListeBicicleta LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListeBicicleta);

/** \brief Setea valores aleatorios entre 50 y 120 al campo tiempo de cada bicicleta en pArrayListeBicicleta
 *
 * \param pArrayListeBicicleta LinkedList*
 * \return void
 *
 */
void controller_MapeBicicleta(LinkedList* pArrayListeBicicleta);

/** \brief Filtra pArrayListeBicicleta por las bicis deL tipo recibido por parametro, y los guarda en un archivo modo texto
 *
 * \param pArrayListeBicicleta LinkedList*
 * \return void
 *
 */
void controller_FilterAndSaveBicisDeTipo(LinkedList* pArrayListeBicicleta, char* tipo);
