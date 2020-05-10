#include "Empleado.h"
#include <string.h>

void InicializarListado(Empleados listadoEmpleado[], int tam, int valorLibre)
{
    int i;

    for(i = 0; i<tam; i++)
    {
        listadoEmpleado[i].vacio = valorLibre;
    }
}

Empleados CargarEmpleado()
{
    Empleados empleado;

    printf("Introduce el NOMBRE: ");
    fflush(stdin);
    fgets(empleado.nombre,51,stdin);
    empleado.nombre[strlen(empleado.nombre)-1] = '\0';

    printf("Introduce EL APELLIDO: ");
    fflush(stdin);
    fgets(empleado.apellido,51,stdin);
    empleado.apellido[strlen(empleado.apellido)-1] = '\0';

    printf("Ingrese SALARIO: ");
    scanf("%f",&empleado.salario);

    printf("Ingrese SECTOR: ");
    scanf("%d",&empleado.sector);

    return empleado;
}

void MostrarEmpleado(Empleados empleado)
{
    printf("ID:%5d  NOMBRE:%12s APELLIDO:%12s  SALARIO:%6.3f  SECTOR:%2d \n",empleado.id,
                                      empleado.nombre,
                                      empleado.apellido,
                                      empleado.salario,
                                      empleado.sector);
}

Empleados BuscarEmpleadoPorID(Empleados listadoEmpleados[], int tam, int valorOcupado)
{
    int i;
    int auxId;
    Empleados auxEmpleado;

    printf("Ingrese el ID del empleado que busca: ");
    scanf("%d",&auxId);

    for(i = 0; i<tam; i++)
    {
        if(listadoEmpleados[i].vacio == valorOcupado && listadoEmpleados[i].id == auxId)
        {
            auxEmpleado = listadoEmpleados[i];
        }
    }
    return auxEmpleado;
}

int CargarListadoEmpleados(Empleados listadoEmpleados[], int tam, int valorOcupado, int valorLibre)
{
    int i;
    int valorDeRetorno = 0;

    for(i = 0; i<tam; i++)
    {
        if(listadoEmpleados[i].vacio == valorOcupado)
        {
            continue;
        }
        else
        {
            if(listadoEmpleados[i].vacio == valorLibre)
            {
            valorDeRetorno = 1;
            listadoEmpleados[i] = CargarEmpleado();
            listadoEmpleados[i].id = i+100;
            listadoEmpleados[i].vacio = valorOcupado;
            break;
            }
        }
    }

    return valorDeRetorno;
}

int MostrarListadoEmpleados(Empleados listadoEmpleados[], int tam, int valorOcupado)
{
    int i;
    int valorDeRetorno = 0;

    for(i = 0; i<tam; i++)
    {
        if(listadoEmpleados[i].vacio == valorOcupado)
        {
            MostrarEmpleado(listadoEmpleados[i]);
            valorDeRetorno = 1;
        }
    }
    return valorDeRetorno;
}

int OrdenarPorApellido_Sector(Empleados listadoEmpleados[], int tam)
{
    int i;
    int j;
    int valorDeRetorno = 0;
    Empleados auxEmpleado;

    for(i = 0; i<tam-1; i++)
    {
        for(j = i; j<tam; j++)
        {
            if(strcmp(listadoEmpleados[i].apellido, listadoEmpleados[j].apellido) > 0)
            {
                auxEmpleado = listadoEmpleados[i];
                listadoEmpleados[i] = listadoEmpleados[j];
                listadoEmpleados[j] = auxEmpleado;
            }
            else
            {
                if(strcmp(listadoEmpleados[i].apellido, listadoEmpleados[j].apellido) == 0)
                {
                    if(listadoEmpleados[i].sector > listadoEmpleados[j].sector)
                    {
                        auxEmpleado = listadoEmpleados[i];
                        listadoEmpleados[i] = listadoEmpleados[j];
                        listadoEmpleados[j] = auxEmpleado;
                        valorDeRetorno = 1;
                    }
                }
            }
        }
    }
    return valorDeRetorno;
}

int ModificarEmpleados(Empleados listadoEmpleados[], int tam, int valorOcupado)
{
    Empleados empleado;

    empleado = BuscarEmpleadoPorID(listadoEmpleados, tam, valorOcupado);
    int opcion;
    int valorDeRetorno = 0;

    if(empleado.vacio == valorOcupado)
    {
        do
        {
            printf("¿Que desea modificar?\n");
            MostrarEmpleado(empleado);
            printf("1-NOMBRE \n2-APELLIDO \n3-SALARIO \n4-SECTOR \n5-SALIR.");
            scanf("%d",&opcion);

            switch(opcion)
            {
                case 1:
                    printf("Ingrese nuevo nombre: ");
                    fflush(stdin);
                    fgets(empleado.nombre,51,stdin);
                    empleado.nombre[strlen(empleado.nombre)-1] = '\0';
                    valorDeRetorno = 1;
                break;

                case 2:
                    printf("Ingrese nuevo apellido: ");
                    fflush(stdin);
                    fgets(empleado.apellido,51,stdin);
                    empleado.apellido[strlen(empleado.apellido)-1] = '\0';
                    valorDeRetorno = 1;
                break;

                case 3:
                    printf("Ingrese nuevo salario: ");
                    scanf("%f",&empleado.salario);
                    valorDeRetorno = 1;
                break;

                case 4:
                    printf("Ingrese nuevo sector: ");
                    scanf("%d",&empleado.sector);
                    valorDeRetorno = 1;
                break;

                case 5:
                break;
            }
        }while(opcion != 5);
    }

    return valorDeRetorno;
}

int DarDeBajaEmpleados(Empleados listadoEmpleados[], int tam, int valorOcupado, int valorLibre)
{
    Empleados auxEmpleado;
    char opcion[3];
    int valorDeRetorno = 0;

    auxEmpleado = BuscarEmpleadoPorID(listadoEmpleados, tam, valorOcupado);

    if(auxEmpleado.vacio == valorOcupado)
    {
        do{
            MostrarEmpleado(auxEmpleado);
            printf("¿Desea dar de baja a este empleado? (SI / NO): ");
            scanf("%s",opcion);
            strcpy(opcion, strlwr(opcion));

        }while(strcmp(opcion, "si") != 0 &&strcmp(opcion, "no") != 0);

        if(strcmp (opcion, "si") == 0)
        {
            for(int i = 0; i<tam; i ++)
            {
                if(listadoEmpleados[i].id != auxEmpleado.id)
                {
                    continue;
                }
                else
                {
                    listadoEmpleados[i].vacio = valorLibre;
                    valorDeRetorno = 1;
                }
            }
        }
        else
        {
            valorDeRetorno = 2;
        }

    }
    return valorDeRetorno;
}

int GetEmpleadoSalarioSuperior(Empleados listadoEmpleados[], int tam, int valorOcupado)
{
    int i;
    int contador = 0;
    float promedio = GetPromedioSalario(listadoEmpleados, tam, valorOcupado);

    for(i = 0; i<tam; i++)
    {
        if(listadoEmpleados[i].salario > promedio)
        {
            contador++;
        }
    }
    return contador;
}


float TotalSalario(Empleados listadoEmpleados[], int tam, int valorOcupado)
{
    int i;
    float total = 0;

    for(i = 0; i<tam; i++)
    {
        if(listadoEmpleados[i].vacio == valorOcupado)
        {
            total += listadoEmpleados[i].salario;
        }
    }
    return total;
}

int ContadorEmpleadosIngresados(Empleados listadoEmpleados[], int tam, int valorOcupado)
{
    int i;
    int contador = 0;

    for(i = 0; i<tam; i++)
    {
        if(listadoEmpleados[i].vacio == valorOcupado)
        {
            contador++;
        }
    }
    return contador;
}

float GetPromedioSalario(Empleados listadoEmpleados[], int tam, int valorOcupado)
{
    float salarioTotal = TotalSalario(listadoEmpleados, tam, valorOcupado);
    int cantidadEmpleados = ContadorEmpleadosIngresados(listadoEmpleados, tam, valorOcupado);

    return salarioTotal/cantidadEmpleados;
}

int OpcionesMenu()
{
    int opcion;

    printf("1-DAR DE ALTA A UN EMPLEADO.\n");
    printf("2-MODIFICAR EMPLEADO.\n");
    printf("3-DAR DE BAJA A UN EMPLEADO.\n");
    printf("4-INFORMAR. \n");
    printf("5-SALIR.\n");
    printf("Ingrese su opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

int Menu(Empleados listadoEmpleados[], int tam, int valorOcupado, int valorLibre)
{
    int opcion;
    int funcionRetorno;

    float promedio = GetPromedioSalario(listadoEmpleados, tam, valorOcupado);
    float totalSalario = TotalSalario(listadoEmpleados, tam, valorOcupado);
    int empleadosMayorPromedio = GetEmpleadoSalarioSuperior(listadoEmpleados, tam, valorOcupado);

    opcion = OpcionesMenu();

    switch(opcion)
    {
        case 1:
            funcionRetorno = CargarListadoEmpleados(listadoEmpleados, tam, valorOcupado, valorLibre);
            {
                if(funcionRetorno == 1)
                {
                    printf("EMPLEADO CARGADO CON EXITO. \n");
                }
                else
                {
                    printf("NO HAY MAS ESPACIO PARA DAR DE ALTA. \n");
                }
            }
        break;

        case 2:
            funcionRetorno = ModificarEmpleados(listadoEmpleados, tam, valorOcupado);
            if(funcionRetorno != 1)
            {
                printf("Empleado no encontrado. \n");
            }
            else
            {
                printf("Modificacion de empleado exitosa. \n");
            }

        break;

        case 3:
            funcionRetorno = DarDeBajaEmpleados(listadoEmpleados, tam, valorOcupado, valorLibre);
            switch(funcionRetorno)
            {
                case 0:
                    printf("No se encontro al empleado. \n");
                break;

                case 1:
                    printf("Empleado dado de baja con exito. \n");
                break;

                case 2:
                    printf("Dada de baja cancelada. \n");
                break;
            }
        break;

        case 4:
            do
            {
                printf("1 - Listado de los empleados ordenados alfabeticamente por apellido y sector. \n");
                printf("2 - Total y promedio de los salarios, y cuantos superan el salario promedio. \n");
                printf("3 - SALIR. \n");
                printf("Ingrese opcion: ");
                scanf("%d",&opcion);

            }while(opcion > 3 || opcion < 1);

            switch(opcion)
            {
                case 1:
                    OrdenarPorApellido_Sector(listadoEmpleados, tam);
                    funcionRetorno = MostrarListadoEmpleados(listadoEmpleados, tam, valorOcupado);
                break;

                case 2:
                    promedio = GetPromedioSalario(listadoEmpleados, tam, valorOcupado);
                    printf("Total de salarios: %.3f \n",totalSalario);
                    printf("PROMEDIO: %.3f \n",promedio);
                    printf("Empleados que superan el promedio: %d \n",empleadosMayorPromedio);
                break;

                case 3:
                break;
            }

        break;

        case 5:
        break;
    }
    return opcion;
}
