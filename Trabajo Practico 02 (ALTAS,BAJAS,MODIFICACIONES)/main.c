#include "Empleados.h"
#define CANT_ELEMENTOS 5

int main()
{
    Employee listadoDeEmpleado[CANT_ELEMENTOS];

    initEmployees(listadoDeEmpleado, CANT_ELEMENTOS);

    int opcion;

    while(opcion != 5)
    {
        opcion = Menu(listadoDeEmpleado, CANT_ELEMENTOS);
    }


    return 0;
}
