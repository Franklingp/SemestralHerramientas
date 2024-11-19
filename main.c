#include <stdio.h>
#include <stdlib.h>

//definicion de arvhivos
FILE * archivoAignaturas;
FILE * registroNotas;

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

//estructura de registro para asignaciones
//1 1 7987 - 5 CALCULO I
struct registroAsignaturas {
    int semestre;
    int añoAcademico;
    int codigoAsignatura;
    int creditos;
    char status;
    char nombreAsignatura[15];
};

//leer archivo de asignaturas
void leerArchivoAsignatura(struct registroAsignaturas asignaturas[59]){
    int contador = 0;
    printf("Lectura de asignaturas **************\n");
    archivoAignaturas = fopen("asignaturas.txt", "r");

    // while(!(feof(archivoAignaturas)))
    while(contador<58)
    {
        //1 1 7987 - 5 CALCULO I
        fscanf(archivoAignaturas, "%d %d %d %c %d %c\n", 
            &asignaturas[contador].añoAcademico, 
            &asignaturas[contador].semestre, 
            &asignaturas[contador].codigoAsignatura,
            &asignaturas[contador].status,
            &asignaturas[contador].creditos,
            &asignaturas[contador].nombreAsignatura);
        printf("%d %d %d %c %d %s\n", 
            asignaturas[contador].añoAcademico, 
            asignaturas[contador].semestre, 
            asignaturas[contador].codigoAsignatura,
            asignaturas[contador].status,
            asignaturas[contador].creditos,
            asignaturas[contador].nombreAsignatura);
        contador++;
    }
    //getch();
    fclose(registroNotas);
}

//Leer datos del archivo
void leerArchivoNotas(){
    registroNotas = fopen("registroNotas.txt", "r");
    printf("Lectura de datos \n");

    registroNotas = fopen("registroNotas.txt", "r");

    // while(!(feof(registroNotas)))
    // {
    //     fscanf(registroNotas, "%d %d %c %s\n", &codAs,&creditos,&status,descripcion);
    //     printf("%d %d %c %s\n",codAs,creditos,status,descripcion);
    // }
    // getch();
    // fclose(registroNotas);
}

//funcion principal main
int main () {
    //defincion de variables
    struct registroEstudiante estudiantes[8];
    struct registroNotas notas[8];
    struct registroAsignaturas asignaturas[59];
    
    //prueba de cooncepto
    printf("Inicio del semestral \n");

    //lectura de archivos 
    leerArchivoAsignatura(asignaturas);

    return 0;
}