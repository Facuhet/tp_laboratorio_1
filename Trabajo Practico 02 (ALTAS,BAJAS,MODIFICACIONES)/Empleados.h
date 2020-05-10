#include <stdio.h>

typedef struct{

    int id;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    int vacio;

}Empleados;

/** \brief Se encarga de iniciar la variable VACIO de la estructura Empleados en LIBRE
 *
 * \param Estructura de array que contiene la variable vacio.
 * \param Variable tipo entero que se encarga de darle cierta cantidad de iteraciones
 * \param Variable tipo entero que se encarga de asignarle a la variable VACIO de la estructura el valor LIBRE
 * \return VOID
 *
 */
void InicializarListado(Empleados [], int , int );
/** \brief Muestra una serie de opciones a modo de menu
 *
 * \return Retorna la opciones selecciona a modo de entero
 *
 */
int OpcionesMenu();
/** \brief Se encarga de hacer de menu principal conteniendo otras funciones para sus procesos.
 *
 * \param Tipo Estructura array que se encarga de pasarle a las demas funciones el contenido.
 * \param Tipo entero usado para pasarle a las demas funciones la cantidad de iteraciones.
 * \param Tipo entero encargado de pasarle a las demas funciones el valor OCUPADO para la variable VACIO en la estructura.
 * \param Tipo entero encargado de pasarle a las demas funciones el valor LIBRE para la variable VACIO en la estructura.
 * \return Retorna opcion seleccionada del menu.
 *
 */
int Menu(Empleados [], int, int, int);

/** \brief Funcion encargada de asignarle valor a las variables de la estructura.
 *
 * \return Estructura cargada de datos.
 *
 */
Empleados CargarEmpleado();

/** \brief Muestra un empleado.
*
*
**/
void MostrarEmpleado(Empleados );
/** \brief Carga listado de empleados
*
* \param array de estructura.
* \param Entero encargado de darle una cierta cantidad de iteracion.
* \param Entero que funciona como bandera de la variable VACIO para saber si esta OCUPADA
* \param Entero que funciona como bandera de la variable VACIO para saber si esta LIBRE
* \return Un valor entero que actua como bandera, para saber si se puede seguir cargando empleados.
*/
int CargarListadoEmpleados(Empleados [], int, int, int);

int DarDeBajaEmpleados(Empleados [], int, int, int);

/** \brief Muestra el listado de empleados.
*
* \param Array de estructura que contiene las variables para ser mostradas.
* \param Entero para asignar cierta cantidad de iteraciones.
* \param Actua de bandera para saber si el array esta cargado para poder mostrarlo.
* \return Retorna un valor que actua como bandera para saber si hay datos cargados para ser mostrados.
*/
int MostrarListadoEmpleados(Empleados [], int, int);

int OrdenarPorApellido_Sector(Empleados [], int );

int GetEmpleadoSalarioSuperior(Empleados [], int , int );

int ContadorEmpleadosIngresados(Empleados [], int , int );

float TotalSalario(Empleados [], int , int );

float GetPromedioSalario(Empleados [], int, int);


