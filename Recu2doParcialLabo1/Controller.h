#include "LinkedList.h"

/** \brief Carga los datos de los paises desde el archivo path (modo texto).
 *
 * \param path char*
 * \param pArrayListeBicicleta LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListeBicicleta);

/** \brief Listar paises
 *
 * \param pArrayListeBicicleta LinkedList*
 * \return int
 *
 */
int controller_ListeBicicleta(LinkedList* pArrayListeBicicleta);

/** \brief Guarda los datos de los paises en el archivo path (modo texto).
 *
 * \param path char*
 * \param pArrayListeBicicleta LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListeBicicleta);

/** \brief Setea valores random en los campos: infectados, muertos, recuperados de cada pais en pArrayListeBicicleta
 *
 * \param pArrayListeBicicleta LinkedList*
 * \return void
 *
 */
void controller_MapeBicicleta(LinkedList* pArrayListeBicicleta);

/** \brief Filtra pArrayListeBicicleta por las bicis de tipo, y los guarda en un archivo tipo.csv
 *
 * \param pArrayListeBicicleta LinkedList*
 * \return void
 *
 */
void controller_FilterAndSaveBicisDeTipo(LinkedList* pArrayListeBicicleta, char* tipo);
