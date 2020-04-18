#include<stdio.h>
#include<stdlib.h>
#include"funciones.h"
int main() {
    int opc , r_fact1, r_fact2;
    float a = 0;
    float b = 0;
    float r_sum, r_res, r_divi, r_mul;
    int operacionactualizada = 0 ;
    do {
        opc = menuUsuario(a , b);
        switch(opc) {
            case 1 : a = pedirnum("Ingresar 1re operando");
                     operacionactualizada = 0;
                     system("cls");
                     break;
            case 2 :
                     b = pedirnum("Ingresar 2do operando");
                     operacionactualizada = 0;
                     system("cls");
                     break;

            case 3 : operaciones(a,b);
                     r_sum = sumar( a , b);
                     r_res = restar(a, b);
                     r_mul = multiplicar(a, b);
                     r_fact1 = factorial(a);
                     r_fact2 = factorial(b);
                     r_divi = dividir(a, b);
                     operacionactualizada = 1;
                     system("pause");
                     system("cls");
                     break;

            case 4 :if (operacionactualizada == 1){
                        printf("a) El resultado de %.2f+%.2f es: %.2f \n",a, b,r_sum);
                        printf("b) El resultado de %.2f-%.2f es : %.2f \n",a ,b, r_res);
                        if(b != 0) {
                            printf("c) El resultado de %.2f/%.2f es: %.2f \n",a ,b ,r_divi);
                        }else {
                            printf("c) No es posible dividir por cero\n");
                        }
                        printf("d) El resultado de %.2f*%.2f es: %.2f \n",a ,b ,r_mul);
                        printf("e) El factorial de %.0f es: %d y El factorial de %.0f es: %d\n",a ,r_fact1 ,b ,r_fact2);
                        system("pause");
                        system("cls");
                    }else{
                        printf("PRIMERO INGRESE LA OPCION 3 PARA CALCULAR\n");
                        system("pause");
                        system("cls");
                    }
                    break;

            case 5 :printf(" Vuelva pronto!\n");
                    break;

            default:printf("-----------------------Opcion invalida ---------------------\n");
                    system("pause");
                    system("cls");
                    break;
        }
    }while(opc != 5);
return 0;
}

