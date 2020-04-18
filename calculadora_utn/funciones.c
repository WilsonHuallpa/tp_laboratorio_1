#include<stdio.h>

int menuUsuario(float a , float b){
    int opcion;
    printf("MENU DE OPCIONES\n\n");
    printf("\n1.Ingresar 1re operando(A = %.2f)", a);
    printf("\n2.Ingresar 2do operando(B = %.2f)", b);
    printf("\n3.Calcular todas las operaciones");
    printf("\n4.Informar resultados");
    printf("\n5.Salir");
    printf("\n\nDigite su opcion (1 al 5): ");
    scanf("%d",&opcion);
    return opcion;
}
float pedirnum(char msj[]){
    float num;
    printf("%s: ", msj);
    scanf("%f",&num);
    return num;
}

void operaciones(float a , float b){
    printf("a) Calcular la suma (%.2f + %.2f) \n",a,b);
    printf("b) Calcular la resta (%.2f - %.2f) \n",a,b);
    printf("c) Calcular la division (%.2f / %.2f) \n",a,b);
    printf("d) Calcular la multiplicacion (%.2f * %.2f) \n",a,b);
    printf("e) Calcular el factorial (%.2f) y (%.2f) \n",a,b);
}

float sumar(float numero_a, float numero_b){
    float r;
    r = numero_a + numero_b;
    return r;
}

float restar(float numero_a, float numero_b){
    float r;
    r = numero_a - numero_b;
    return r;
}

float dividir( float numero_a, float numero_b){
    float r;
        r = numero_a / numero_b;

    return r;
}
float multiplicar(float numero_a, float numero_b){
    float r;
        r = numero_a * numero_b;
    return r;
}



int factorial(float numero){
    int fac = 1;
    int truncar = (int)numero;
        for( ; truncar > 0 ; truncar--){
            fac = fac * truncar;
        }
    return fac;
}

