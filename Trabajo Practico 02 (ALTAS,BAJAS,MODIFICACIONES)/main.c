#include <stdlib.h>
#include "Empleado.h"
#define CANT_ELEMENTOS 5
#define OCUPADO 0
#define LIBRE 1

int main()
{
    int opcion;

    Empleados listadoDeEmpleado[CANT_ELEMENTOS] = { {100, "Facundo","Santoro",25.500,1},
                                                    {101, "Pablo","Sanchez",30.500,3},
                                                    {102, "Ana","Sanchez",30.500,6} };

    InicializarListado(listadoDeEmpleado, CANT_ELEMENTOS, LIBRE);

    listadoDeEmpleado[0].vacio = OCUPADO;
    listadoDeEmpleado[1].vacio = OCUPADO;
    listadoDeEmpleado[2].vacio = OCUPADO;

    do
    {
        opcion = Menu(listadoDeEmpleado, CANT_ELEMENTOS, OCUPADO, LIBRE);
        system("pause");
        system("cls");

    }while(opcion != 6);

    return 0;
}
