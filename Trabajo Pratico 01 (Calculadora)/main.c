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
            printf("\nA = %d\n",numeroA);
        }
        if(flagB == 1)
        {
            printf("B = %d\n",numeroB);
        }

        printf("1-Ingresar 1er operando\n");
        printf("2-Ingresar 2do operando\n");
        printf("3-Calcular todas las operaciones\n");
        printf("4-Informar resultados\n");
        printf("5-Salir\n");
        printf("Ingrese su opcion: ");
        scanf("%d",&opcion);
        system("cls");

        switch(opcion)
        {
            case 1:
                printf("Ingrese 1er operando: ");
                scanf("%d",&numeroA);
                flagA = 1;
            break;

            case 2:
                printf("Ingrese 2do operando: ");
                scanf("%d",&numeroB);
                flagB = 1;
            break;

            case 3:
                if(flagA == 1 && flagB == 1)
                {
                    printf("Calculos listos. \n");
                    Suma(numeroA,numeroB);
                    Resta(numeroA,numeroB);
                    Division(numeroA,numeroB);
                    Multiplicacion(numeroA,numeroB);
                    Factorial(numeroA);
                    Factorial(numeroB);
                }
                else
                {
                    printf("Error. Ingrese los numeros para calcular. \n");
                }


                system("pause");

            break;

            case 4:

                if(flagA == 1 && flagB == 1)
                {

                    printf("La suma es : %d\n",Suma(numeroA,numeroB));
                    printf("La resta es : %d\n",Resta(numeroA,numeroB));

                    if(numeroB == 0)
                    {
                        printf("No se puede dividir por 0 \n");
                    }
                    else
                    {
                        printf("La division es : %f \n",Division(numeroA,numeroB));
                    }

                    printf("La multiplicacion es: %d \n",Multiplicacion(numeroA,numeroB));
                    printf("El factorial de %d es : %d \n",numeroA,Factorial(numeroA));
                    printf("El factorial de %d es : %d \n",numeroB,Factorial(numeroB));
                }
                else
                {
                    printf("Error. Ingrese los numeros para calcular.\n");
                }
                    system("pause");
                break;

                case 5:
                break;
        }
        system("cls");

    }
    return 0;

}
