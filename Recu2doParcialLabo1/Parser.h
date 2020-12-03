/** \brief Parsea los datos de las bicicletas desde el archivo pFile (modo texto).
 *
 * \param FILE* pFile
 * \param pArrayListeBicicleta LinkedList*
 * \return int
 *
 */
int parser_eBicicletaFromText(FILE* pFile , LinkedList* pArrayListeBicicleta);

/** \brief Guarda los datos de las bicicletas en el archivo pFile (modo texto).
 *
 * \param pFile FILE*
 * \param pArrayListeBicicleta LinkedList*
 * \return int
 *
 */
int parser_saveeBicicletaAsText(FILE* pFile , LinkedList* pArrayListeBicicleta);
