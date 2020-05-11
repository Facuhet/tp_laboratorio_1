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

void initEmployees(Employee [], int);

int BuscarLibre(Employee [], int);

int AddEmployees(Employee [], int, int, char [], char [], float, int);

void MostrarEmpleado(Employee);

void MostrarListaEmpleados(Employee [], int);

int ModifyEmployees(Employee [], int);

int BuscarOcupado(Employee [], int);

/****************************************************************/

int OpcionesMenu();

int Menu(void);

void getString(char [], char []);

int ValidarNombre_Apellido(char []);

int ValidarEntero(char []);

int getSector(char []);

float getSalario(char []);
