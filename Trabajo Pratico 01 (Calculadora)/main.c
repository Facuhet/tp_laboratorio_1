#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

int main()
{
    int numeroA , numeroB,opcion;
    int flagA = 0;
    int flagB = 0;


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

                    Suma(numeroA,numeroB);
                    Resta(numeroA,numeroB);

                    if(numeroB != 0)
                    {
                        Division(numeroA,numeroB);
                    }

                    Multiplicacion(numeroA,numeroB);
                    Factorial(numeroA);
                    Factorial(numeroB);
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
                    printf("La suma de %d y %d es: %d \n",numeroA,numeroB,Suma(numeroA,numeroB));
                    printf("La resta de %d y %d es: %d \n",numeroA,numeroB,Resta(numeroA,numeroB));
                    if(numeroB != 0)
                    {
                        printf("La divison de %d y %d es: %f \n",numeroA,numeroB,Division(numeroA,numeroB));
                    }
                    else
                    {
                        printf("No se puede dividir por 0 \n");
                    }
                    printf("La multiplicacion de %d y %d es: %d \n",numeroA,numeroB,Multiplicacion(numeroA,numeroB));
                    if(numeroA > -1)
                    {
                        printf("El factorial de %d es: %.0f \n",numeroA,Factorial(numeroA));
                    }
                    else
                    {
                        printf("No es posible calcular el factorial de un numero negativo. \n");
                    }
                    if(numeroB > -1)
                    {
                        printf("El factorial de %d es: %.0f \n",numeroB,Factorial(numeroB));
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
