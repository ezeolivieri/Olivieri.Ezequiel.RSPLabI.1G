#ifndef EBICICLETA_H_INCLUDED
#define EBICICLETA_H_INCLUDED

typedef struct
{
    int id;
    char nombre[150];
    char tipo[150];
    int tiempo;
} eBicicleta;

eBicicleta* eBicicleta_new();
eBicicleta* eBicicleta_newParametros(char* id, char* name, char* tipo, char* tiempo);
void eBicicleta_delete(eBicicleta* this);

// GETTERS Y SETTERS
int eBicicleta_setId(eBicicleta* this,int id);
int eBicicleta_getId(eBicicleta* this,int* id);
int eBicicleta_setNombre(eBicicleta* this,char* nombre);
int eBicicleta_getNombre(eBicicleta* this,char* nombre);
int eBicicleta_setTipo(eBicicleta* this,char* tipo);
int eBicicleta_getTipo(eBicicleta* this,char* tipo);
int eBicicleta_setTiempo(eBicicleta* this,int tiempo);
int eBicicleta_getTiempo(eBicicleta* this,int* tiempo);

int printeBicicleta(eBicicleta* eBicicleta);


/** \brief Setea el campo tiempo de peBicicleta con valores aleatorios entre 50 y 120
 *
 * \param peBicicleta void*
 * \return void*
 *
 */
void* eBicicleta_updateTiempos(void* peBicicleta);

/** \brief Retorna 1 si es una bici de tipo bmx o 0 si no lo es
 *
 * \param peBicicleta void*
 * \return int
 *
 */
int eBicicleta_filterByBmx(void* peBicicleta);

/** \brief Retorna 1 si es una bici de tipo playera o 0 si no lo es
 *
 * \param peBicicleta void*
 * \return int
 *
 */
int eBicicleta_filterByPlayera(void* peBicicleta);

/** \brief Retorna 1 si es una bici de tipo mtb o 0 si no lo es
 *
 * \param peBicicleta void*
 * \return int
 *
 */
int eBicicleta_filterByMtb(void* peBicicleta);

/** \brief Retorna 1 si es una bici de tipo paseo o 0 si no lo es
 *
 * \param peBicicleta void*
 * \return int
 *
 */
int eBicicleta_filterByPaseo(void* peBicicleta);

/** \brief Ordena entre dos bicicletas por sus campos tipo y tiempo
 *
 * \param peBicicletaUno void*
 * \param peBicicletaDos void*
 * \return int
 *
 */
int eBicicleta_sortByTipoAndTiempo(void* peBicicletaUno, void* peBicicletaDos);

#endif // EBICICLETA_H_INCLUDED
