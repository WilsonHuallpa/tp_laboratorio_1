#include<stdio.h>
//DESARROLLO DE LA FUNCIONES
int menuUsuario(char texto[])
{
    int opcion;
    printf("%s", texto);
    scanf("%d",&opcion);

    return opcion;
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

    if (numero_a != 0 || numero_b != 0)
        {
        r = numero_a / (float)numero_b;
       }
        else{
            r = 0 ;
            }
    return r;
}
float multiplicar(float numero_a, float numero_b){
    float r;
        r = numero_a * numero_b;
    return r;
}
int factorial(float numero)
{
    int fac = 1;

    for(numero ; numero> 0 ; numero--){
        fac = fac * numero;
    }
    return fac;

}
