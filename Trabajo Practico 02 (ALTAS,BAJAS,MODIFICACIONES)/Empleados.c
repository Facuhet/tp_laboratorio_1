#include "Empleados.h"
#define CANT_ELEMENTOS 5
#define VACIO 0
#define OCUPADO 1

void initEmployees(Employee listado[], int tam)
{
    int i;
    for(i = 0; i<tam; i++)
    {
        listado[i].isEmpty = VACIO;
    }
}

int BuscarLibre(Employee listado[], int tam)
{
    int i;
    int indice;

    for(i = 0; i<tam; i++)
    {
        indice = -1;

        if(listado[i].isEmpty == VACIO)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int BuscarOcupado(Employee listado[], int tam)
{
    int i;
    int valorRetorno;

    for(i = 0; i<tam; i++)
    {
        valorRetorno = 0;

        if(listado[i].isEmpty == OCUPADO)
        {
            valorRetorno = 1;
            break;
        }
    }
    return valorRetorno;
}

int AddEmployees(Employee listadoEmpleados[], int tam, int idEmpleado, char nombre[], char apellido[], float salario, int sector)
{
    int indiceEncontrado;
    int todoOk = 0;

    indiceEncontrado = BuscarLibre(listadoEmpleados, tam);

    if(indiceEncontrado != -1)
    {
        listadoEmpleados[indiceEncontrado].id = idEmpleado;
        strcpy(listadoEmpleados[indiceEncontrado].name, nombre);
        strcpy(listadoEmpleados[indiceEncontrado].lastName, apellido);
        listadoEmpleados[indiceEncontrado].salary = salario;
        listadoEmpleados[indiceEncontrado].sector = sector;
        listadoEmpleados[indiceEncontrado].isEmpty = OCUPADO;
        todoOk = 1;
    }
    else
    {
        printf("NO HAY ESPACIO PARA CARGAR EMPLEADOS. \n");
    }

    return todoOk;
}

void MostrarEmpleado(Employee miEmpleado)
{
    printf("ID: %2d - Apellido: %5s - Nombre: %5s - Salario: %5.3f - Sector: %2d \n", miEmpleado.id,
                                    miEmpleado.lastName,
                                    miEmpleado.name,
                                    miEmpleado.salary,
                                    miEmpleado.sector);
}

void MostrarListaEmpleados(Employee listadoEmpleados[], int tam)
{
    int i;

    for(i = 0; i<tam; i++)
    {
        if(listadoEmpleados[i].isEmpty == OCUPADO)
        {
            MostrarEmpleado(listadoEmpleados[i]);
        }
    }
}


void OrdenarPor_Apellido_AZ_Sector(Employee listadoEmpleados[], int tam)
{
    int i;
    int j;
    Employee auxEmpleado;

    for(i = 0; i<tam-1; i++)
    {
        for(j = i; j<tam; j++)
        {
            if((strcmp(listadoEmpleados[i].lastName, listadoEmpleados[j].lastName) > 0 || strcmp(listadoEmpleados[i].lastName, listadoEmpleados[j].lastName) == 0 )&& listadoEmpleados[i].sector > listadoEmpleados[j].sector)
            {
                auxEmpleado = listadoEmpleados[i];
                listadoEmpleados[i] = listadoEmpleados[j];
                listadoEmpleados[j] = auxEmpleado;
            }
        }
    }
}

void getString(char mensaje[], char string[])
{
    int validacion;

    do
    {
        printf("%s",mensaje);
        fflush(stdin);
        fgets(string, 51, stdin);
        string[strlen(string)-1] = '\0';

        validacion = ValidarNombre_Apellido(string);

    }while(validacion == 0);

    strlwr(string);
    string[0] = toupper(string[0]);

}

int ValidarNombre_Apellido(char string[])
{
    int i;

    for(i = 0; i<strlen(string); i++)
    {
        if(!( (string[i] >= 65 && string[i] <= 90) || (string[i] >= 97 && string[i] <= 122) ))
        {
            printf("Por favor ingrese solo LETRAS y SIN ESPACIOS. \n ");
            return 0;
        }
    }
    return 1;
}

int getSector(char mensaje[])
{
    char entero[3];
    int validacion;
    int numeroValido;

    do
    {
        printf("%s",mensaje);
        scanf("%s",entero);

        validacion = ValidarEntero(entero);

    }while(validacion == 0);

    numeroValido = atoi(entero);

    return numeroValido;
}

int ValidarEntero(char entero[])
{
    int i;

    for(i = 0; i<strlen(entero); i++)
    {
        if(!(isdigit(entero[i])))
        {
            printf("Ingresa solo numeros. \n");
            return 0;
        }
    }
    return 1;
}

float getSalario(char mensaje[])
{
    float salario;

    printf("%s",mensaje);
    scanf("%f",&salario);

    return salario;
}

int ContadorEmpleadosCargados(Employee listado[], int tam)
{
    int i;
    int contador;

    contador = 0;

    for(i=0; i<tam; i++)
    {
        if(listado[i].isEmpty == OCUPADO)
        {
            contador++;
        }
    }

    return contador;
}

float SumaSalario(Employee listado[], int tam)
{
    int i;
    float SumaDeSalario;

    SumaDeSalario = 0;

    for(i=0; i<tam; i++)
    {
        if(listado[i].isEmpty == OCUPADO)
        {
            SumaDeSalario+= listado[i].salary;
        }
    }

    return SumaDeSalario;
}

float PromedioSalario(float sumaSalario, int cantidadEmpleados)
{
    return sumaSalario/cantidadEmpleados;
}


int MostrarEmpleadoSuperiorAlPromedio(Employee listado[], int tam)
{
    int i;
    int valorRetorno;

    valorRetorno = 0;

    float promedio;

    promedio = PromedioSalario(SumaSalario(listado, tam), ContadorEmpleadosCargados(listado, tam) );

    for(i=0; i<tam; i++)
    {
        if(listado[i].salary > promedio && listado[i].isEmpty == OCUPADO)
        {
            MostrarEmpleado(listado[i]);
            valorRetorno = 1;
        }
    }
    return valorRetorno;
}

int FindEmployeeById(Employee listado[], int tam)
{
    int i;
    int id;

    printf("\n-----------EMPLEADOS DISPONIBLES-----------\n\n");
    MostrarListaEmpleados(listado, tam);
    printf("\n-----------EMPLEADOS DISPONIBLES-----------\n");
    printf("Ingrese ID del EMPLEADO: ");
    scanf("%d",&id);

    for(i=0; i<tam; i++)
    {

        if(id == listado[i].id && listado[i].isEmpty == OCUPADO)
        {
            printf("\nEmpleado encontrado. \n\n");
            return i;
            break;
        }
    }
    return -1;
}

int ModifyEmployees(Employee listado[], int tam)
{
    int id;
    int opcion;

    id = FindEmployeeById(listado, tam);

    if(id == -1)
    {
        return id;
    }
    else
    {
        do
        {
            MostrarEmpleado(listado[id]);
            printf("Empleado encontrado.\n ¿Que desea modificar?\n");
            printf("1-Nombre. \n");
            printf("2-Apellido. \n");
            printf("3-Salario. \n");
            printf("4-Sector. \n");
            printf("5-SALIR. \n");
            printf("Ingrese opcion: ");
            scanf("%d",&opcion);

            switch(opcion)
            {
                case 1:
                    getString("Ingrese nuevo NOMBRE:", listado[id].name);
                break;

                case 2:
                    getString("Ingrese nuevo APELLIDO: ",listado[id].lastName);
                break;

                case 3:
                    listado[id].salary = (float)getSalario("Ingrese nuevo SALARIO: ");
                break;

                case 4:
                    listado[id].sector = getSector("Ingrese nuevo SECTOR: ");
                break;

                case 5:
                break;
            }

            system("pause");
            system("cls");

        }while(opcion != 5);
    }
    return 0;
}

int RemoveEmployees(Employee listado[], int tam)
{
    int id;
    char opcion[3];

    id = FindEmployeeById(listado, tam);

    if(id == -1)
    {
        return -1;
    }
    else
    {
        do
        {
            printf("¿Desea dar de baja a este empleado? \n");
            MostrarEmpleado(listado[id]);
            printf("SI / NO \n");
            getString("Ingrese opcion: ", opcion);

        }while(strcmp(opcion, "Si") != 0 && strcmp(opcion, "No") != 0);

        if(strcmp(opcion, "Si") == 0 )
        {
            listado[id].isEmpty = VACIO;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}

int OpcionesMenu()
{
    char opcion[3];
    int opcionValidada;
    printf("\n1.ALTAS EMPLEADO. \n");
    printf("2.MODIFCAR EMPLEADO. \n");
    printf("3.BAJAS EMPLEADO. \n");
    printf("4.INFORMAR. \n");
    printf("5.SALIR \n");
    printf("Ingrese OPCION: ");
    scanf("%s",opcion);

    ValidarEntero(opcion);
    opcionValidada = atoi(opcion);

    return opcionValidada;
}

int Menu(void)
{
    Employee listadoEmpleados[CANT_ELEMENTOS];
    initEmployees(listadoEmpleados, CANT_ELEMENTOS);

    int opcion;
    int funcionRetorno;

    int id = 100;
    char name[51];
    char lastName[51];
    float salario;
    int sector;

    int empleadoCargado;

        do
        {
            opcion = OpcionesMenu();

        empleadoCargado = BuscarOcupado(listadoEmpleados, CANT_ELEMENTOS);

            switch(opcion)
            {
                case 1:

                        getString("Ingrese nombre: ",name);
                        getString("Ingrese apellido: ",lastName);

                        salario = getSalario("Ingrese salario: ");
                        sector = getSector("Ingrese sector: ");

                        if(AddEmployees(listadoEmpleados, CANT_ELEMENTOS, id, name, lastName, salario, sector))
                        {
                            id++;
                        }
                break;

                case 2:

                    if(empleadoCargado == 1)
                    {
                        funcionRetorno = ModifyEmployees(listadoEmpleados, CANT_ELEMENTOS);
                        if(funcionRetorno == -1)
                        {
                            printf("No se encontro al empleado.\n");
                        }
                    }
                    else
                    {
                        printf("NO HAY EMPLEADOS CARGADOS, CARGUE EMPLEADOS PRIMERO. \n");
                    }

                break;

                case 3:

                    if(empleadoCargado == 1)
                    {
                        funcionRetorno = RemoveEmployees(listadoEmpleados, CANT_ELEMENTOS);
                        if(funcionRetorno == -1)
                        {
                            printf("No se encontro al empleado. \n");
                        }
                        else if(funcionRetorno == 0)
                        {
                            printf("Eliminacion cancelada. \n");
                        }
                        else
                        {
                            printf("Dado de baja con exito. \n");
                        }
                    }
                    else
                    {
                        printf("NO HAY EMPLEADOS CARGADOS, CARGUE EMPLEADOS PRIMERO. \n");
                    }

                break;

                case 4:

                    if(empleadoCargado == 1)
                    {
                        do
                        {
                            printf("\n1-Listar empleados alfabeticamente por apellido y sector. \n");
                            printf("\n2-Mostrar total y promedio de los salarios, empleados que superan el promedio. \n");
                            printf("Ingrese opcion: ");
                            scanf("%d",&opcion);
                            system("cls");
                        }while(opcion > 2 || opcion < 1);

                        switch(opcion)
                        {
                            case 1:
                                OrdenarPor_Apellido_AZ_Sector(listadoEmpleados, CANT_ELEMENTOS);
                                MostrarListaEmpleados(listadoEmpleados, CANT_ELEMENTOS);
                            break;

                            case 2:
                                printf("Total SALARIO: %5.3f || Promedio SALARIO: %5.3f \n",SumaSalario(listadoEmpleados, CANT_ELEMENTOS),PromedioSalario(SumaSalario(listadoEmpleados, CANT_ELEMENTOS), ContadorEmpleadosCargados(listadoEmpleados, CANT_ELEMENTOS
                                                                                                                                                                                                                                   )));

                                printf("\n Empleados que superan el PROMEDIO de SALARIO \n");
                                funcionRetorno = MostrarEmpleadoSuperiorAlPromedio(listadoEmpleados, CANT_ELEMENTOS);
                                if(funcionRetorno != 1)
                                {
                                    printf("NO HAY EMPLEADOS QUE SUPEREN EL PROMEDIO. \n");
                                }
                            break;
                        }
                    }
                    else
                    {
                        printf("NO HAY EMPLEADOS CARGADOS, CARGUE EMPLEADOS PRIMERO. \n");
                    }

                break;

                case 5:
                break;
            }

            system("pause");
            system("cls");
        }while(opcion != 5);

    return 0;
}

