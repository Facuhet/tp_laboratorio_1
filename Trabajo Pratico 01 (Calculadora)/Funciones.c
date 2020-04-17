#include <stdio.h>
#include <stdlib.h>

int Menu()
{
    int opcion;

    printf("1-Ingresar 1er operando\n");
    printf("2-Ingresar 2do operando\n");
    printf("3-Calcular todas las operaciones\n");
    printf("4-Informar resultados\n");
    printf("5-Salir\n");
    printf("Ingrese su opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

int getInt(char mensaje[])
{
    int numero;

    printf("%s",mensaje);
    scanf("%d",&numero);

    return numero;
}

int Suma(int numeroUno,int numeroDos)
{
    return numeroUno+numeroDos;
}

int Resta(int numeroUno, int numeroDos)
{
    return numeroUno-numeroDos;
}

float Division(int numeroUno, int numeroDos)
{
    return (float)numeroUno/numeroDos;
}

int Multiplicacion(int numeroUno, int numeroDos)
{
    return numeroUno * numeroDos;
}

double Factorial(int numero)
{
    double factorial = 1;
    int i;

    if(numero == 0)
    {
        return 0;
    }
    else
    {
        for(i = numero; i > 1; i--)
        {
            factorial*=i;
        }
    }
    return factorial;
}
