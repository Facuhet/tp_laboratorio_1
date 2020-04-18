#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

int main()
{
    int numeroA , numeroB,opcion;
    int flagA = 0;
    int flagB = 0;
    int suma, resta, multiplicacion;
    float division;
    double factorialA, factorialB;

    while(opcion != 5)
    {

        if(flagA == 1)
        {
            printf("A = %d\n",numeroA);
        }
        if(flagB == 1)
        {
            printf("B = %d\n",numeroB);
        }

        opcion = Menu();

        switch(opcion)
        {
            case 1:
                numeroA = getInt("Por favor, ingresa el 1er numero: ");
                flagA = 1;
            break;

            case 2:
                numeroB = getInt("Por favor, ingresa el 2do numero: ");
                flagB = 1;
            break;

            case 3:
                if(flagA == 1 && flagB == 1)
                {
                    printf("Calculando las operaciones. . . \n");

                    suma = Suma(numeroA,numeroB);
                    resta = Resta(numeroA,numeroB);

                    if(numeroB != 0)
                    {
                        division = Division(numeroA,numeroB);
                    }

                    multiplicacion = Multiplicacion(numeroA,numeroB);
                    factorialA= Factorial(numeroA);
                    factorialB= Factorial(numeroB);
                }
                else
                {
                    printf("Error, por favor ingrese numeros para calcular \n");
                }

            break;

            case 4:
                if(flagA == 1 && flagB == 1)
                {
                    printf("Mostrando resultados.. : \n");
                    printf("La suma de %d y %d es: %d \n",numeroA,numeroB,suma);
                    printf("La resta de %d y %d es: %d \n",numeroA,numeroB,resta);
                    if(numeroB != 0)
                    {
                        printf("La divison de %d y %d es: %f \n",numeroA,numeroB,division);
                    }
                    else
                    {
                        printf("No se puede dividir por 0 \n");
                    }
                    printf("La multiplicacion de %d y %d es: %d \n",numeroA,numeroB,multiplicacion);
                    if(numeroA > -1)
                    {
                        printf("El factorial de %d es: %.0f \n",numeroA,factorialA);
                    }
                    else
                    {
                        printf("No es posible calcular el factorial de un numero negativo. \n");
                    }
                    if(numeroB > -1)
                    {
                        printf("El factorial de %d es: %.0f \n",numeroB,factorialB);
                    }
                    else
                    {
                        printf("No es posible calcular el factorial de un numero negativo. \n");
                    }
                    flagA = 0;
                    flagB = 0;
                }
                else
                {
                    printf("Error, ingrese numeros para calcular. \n");
                }
            break;

            case 5:
            break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}
