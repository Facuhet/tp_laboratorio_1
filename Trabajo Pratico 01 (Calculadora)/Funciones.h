/**
* \brief Muestra un menu.
* \return Devuelve el valor de la opcion elegida dentro del menu
**/
int Menu();
/**
* \brief Pide un numero
* \param El mensaje que se muestra por pantalla
* \return El numero que se ingreso
*
*/
int getInt(char mensaje[]);
/** \brief Suma los numeros ingresados
 *
 * \param Primer numero ingresado
 * \param Segundo numero ingresado
 * \return Retorna la suma de los numeros
 *
 */
int Suma(int,int);

/** \brief Resta los numeros ingresados
 *
 * \param Primer numero ingresado
 * \param Segundo numero ingresado
 * \return Retorna la resta de los numeros
 *
 */
int Resta(int,int);

/** \brief Divide los numeros ingresados
 *
 * \param Primer numero ingresado
 * \param Segundo numero ingresado
 * \return Retorna la division de los numeros
 *
 */
float Division(int,int);

/** \brief Multiplica los numeros ingresados
 *
 * \param Primer numero ingresado
 * \param Segundo numero ingresado
 * \return Retorna el producto de los numeros
 *
 */
int Multiplicacion(int,int);

/** \brief Calcula el factorial del numero ingresado
 *
 * \param Numero ingresado
 * \return Retorna el factorial del numero
 *
 */
double Factorial(int);
