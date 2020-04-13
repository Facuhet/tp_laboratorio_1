#include <stdio.h>
#include <stdlib.h>

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

int Factorial(int numero)
{
    int factorial = 1;
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
