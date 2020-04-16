/*


*/
#include<stdio.h>
#include<stdlib.h>
#include"funciones.h"
int main()//FUNCIOIN PRINCIPAL
{
int opc , r_fact1, r_fact2;
float a, b, r_sum, r_res, r_divi, r_mul;
    do{
     //MENU DE OPCIONES
    opc = menuUsuario("MENU DE OPCIONES\n\n \n1.Ingresar 1re operando \n2.Ingresar 2do operando \n3.Calcular todas las operaciones\n4.Informar resultados\n5.salir\n\nDigite su opcion (1 al 5):  ");
    //COMPARAMOS LA OPC Y LA ASIGMOS SU FUNCION
    switch(opc)
    {
        case 1 : printf("ingresar 1re operando: ");
                 scanf("%f",&a);
                 system("pause");
                 system("cls");
                 break;
        case 2 :
                 printf("ingresar 2re operando: ");
                 scanf("%f",&b);
                 system("pause");
                 system("cls");
                 break;
        case 3 : printf("a) Calcular la suma (%.2f + %.2f) \n",a,b);
                 printf("b) Calcular la resta (%.2f - %.2f) \n",a,b);
                 printf("c) Calcular la division (%.2f / %.2f) \n",a,b);
                 printf("d) Calcular la multiplicacion (%.2f * %.2f) \n",a,b);
                 printf("e) Calcular el factorial (%.2f) y (%.2f) \n",a,b);
                 system("pause");
                 system("cls");
                 break;
        case 4 :
                r_sum = sumar( a , b);
                printf("a) El resultado de %.2f+%.2f es: %.2f \n",a, b,r_sum);
                r_res = restar(a, b);
                printf("b) El resultado de %.2f-%.2f es : %.2f \n",a ,b, r_res);
                r_divi = dividir(a, b);
                if (dividir(a,b) != 0){
                    printf("c) El resultado de %.2f/%.2f es: %.2f \n",a ,b ,r_divi);
                }else{
                    printf("c) No es posible dividir por cero\n");
                }
                r_mul = multiplicar(a, b);
                printf("d) El resultado de %.2f*%.2f es: %.2f \n",a ,b ,r_mul);
                r_fact1 = factorial(a);
                r_fact2 = factorial(b);
                printf("e) El factorial de %.2f es: %d y El factorial de %.2f es: %d\n",a ,r_fact1, b, r_fact2);
                system("pause");
                system("cls");
                break;
        case 5 :
                printf(" Vuelva pronto!\n");
                break;
        default:
                printf("-----------------------Opcion invalida ---------------------\n");
                system("pause");
                system("cls");
                break;
                }
      }while(opc != 5);
    return 0;
}

