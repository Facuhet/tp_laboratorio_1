#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

typedef struct{

    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}Employee;

/** \brief To indicate that all position in the array are empty,
 *  this function put the flag (isEmpty) in LIBRE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param tam int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
void initEmployees(Employee [], int);

/** \brief
 *
 * \param list Employee* Pointer to array of employees
 * \param tam int Array length
 * \return
 *
 */
int BuscarLibre(Employee [], int);

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param tam int
 * \param idEmpleado int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 */
int AddEmployees(Employee [], int, int, char [], char [], float, int);
 /** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param tam int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int SortEmployees(Employee [], int, int);
/** \brief Muestra un empleado
 *
 * \param miEmpleado Empleoyee
 *
 */
void MostrarEmpleado(Employee);
/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param tam int
 * \return int
 *
 */
int printEmployees(Employee [], int);
/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param listado Employee*
 * \param tam int
 * \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 *
 */
int ModifyEmployees(Employee [], int);
/** \brief Busca un empleado que contenga en isEmpty el valor OCUPADO
 *
 * \param listado Employee*
 * \param tam int
 * \return
 *
 */
int BuscarOcupado(Employee [], int);

/****************************************************************/

/**
* \brief Muestra un menu y se encarga de obtener un dato
* \return retorna una opcion int
*
*/
int OpcionesMenu(void);

/**
* \brief Menu que funciona como principal, contiene todos los procesos y funciones
* \return 0
*
*/
int Menu(void);

/**
* \brief Obtiene una cadena de caracteres
* \param mensaje[] char (Mensaje mostrado por pantalla)
* \param string[] char
*
*/
void getString(char [], char []);
/**
* \brief Valida una cadena de caracteres
* \param string[] char
* \return retorna 0 si ingresan numeros, 1 si esta todo OK
*
*/
int ValidarNombre_Apellido(char []);

/**
* \brief Valida numeros enteros
* \param entero[] char
* \return retorna 0 si ingresan caracteres que no sean numeros, 1 si esta todo OK
*
*/
int ValidarEntero(char []);
/**
* \brief Obtiene un numero entero
* \param mensaje[] char (Mensaje mostrado por pantalla)
* \return int numero ingresado
*
*/
int getInt(char []);
/**
* \brief Obtiene un numero flotante
* \param mensaje[] char (Mensaje mostrado por pantalla)
* \return float numero ingresado
*
*/
float getFloat(char []);
