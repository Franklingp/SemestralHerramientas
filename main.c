#include <stdio.h>
#include <stdlib.h>

//funciones hello world
void helloWorld(){
    printf("Hello world \n");
}

//funcion principal main
int main () {
    int numero;
    //prueba de cooncepto
    helloWorld();
    printf("Ingrese un numero: \n");
    scanf(" %d, &numero");
    numero ++;
    return 0;
}