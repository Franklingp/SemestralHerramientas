#include <stdio.h>
#include <stdlib.h>

//variable global para saber cantidad de estudiantes
int NUMERO_ESTUDIANTES=8;

//estructura de registro de notas de estudiante
struct registroEstudiante {
    int cedula;
    char nombre;

};

//estructura de registro de notas de estudiante
struct registroNotas {
    int año;
    int semestre;
    int codigoAsignacion[6];
    char notas[6];
};

//Leer datos del archivo
void leerDatosArchivo(){
    printf("Lectura de datos \n");
    FILE *registroNotas;

    registroNotas = fopen("registroNotas.txt", "r");

    while(!(feof(registroNotas)))
    {
        fscanf(registroNotas, "%d %d %c %s\n", &codAs,&creditos,&status,descripcion);
        printf("%d %d %c %s\n",codAs,creditos,status,descripcion);
    }
    getch();
    fclose(fptArchivo);
}

//funcion principal main
void main () {
    //defincion de variables
    struct registroEstudiante estudiantes[8];
    struct registroNotas notas[8];

    //deficion de archivos 
    //FILE *registroNotas;

    
    //prueba de cooncepto
    printf("Inicio del semestral \n");
}