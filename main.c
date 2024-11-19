#include <stdio.h>
#include <stdlib.h>

//definicion de arvhivos
FILE * archivoAsignaturas;
FILE * registroNotas;

//variable global para saber cantidad de estudiantes
int NUMERO_ESTUDIANTES=8;

//estructura de registro de notas de estudiante
struct registroEstudiante {
    char cedula[15];
    char nombre[50];

};

//estructura de registro de notas de estudiante
struct registroNotas {
    int año;
    int semestre;
    char codigoAsignatura[6][6];
    char notas[6];
};

//estructura de registro para asignaciones
//1 1 7987 - 5 CALCULO I
struct registroAsignaturas {
    int semestre;
    int añoAcademico;
    char codigoAsignatura[6];
    int creditos;
    char status;
    char nombreAsignatura[50];
};

//leer archivo de asignaturas
void leerArchivoAsignatura(struct registroAsignaturas asignaturas[59]){
    int contador = 0;
    printf("Lectura de asignaturas **************\n");
    archivoAsignaturas = fopen("asignaturas.txt", "r");

    // while(!(feof(archivoAignaturas)))
    while(contador<58){
        //ESTO ES PARA IMPRIMIR TODAS LAS ASIGNATURAS
        fscanf(archivoAsignaturas, "%d %d %s %c %d %[^\n]\n", 
            &asignaturas[contador].añoAcademico, 
            &asignaturas[contador].semestre, 
            asignaturas[contador].codigoAsignatura,
            &asignaturas[contador].status,
            &asignaturas[contador].creditos,
            asignaturas[contador].nombreAsignatura);
        // printf("%d %d %s %c %d %s\n", 
        //     asignaturas[contador].añoAcademico, 
        //     asignaturas[contador].semestre, 
        //     asignaturas[contador].codigoAsignatura,
        //     asignaturas[contador].status,
        //     asignaturas[contador].creditos,
        //     asignaturas[contador].nombreAsignatura);
        contador++;
    }
    //getch();
    fclose(archivoAsignaturas);
}

// 04-0860-001276 ABAD TORRES,  FELICITA VICTORIA
// 2023 1
// 7987 C
// 0855 A
// 0741 B
// 8353 A
// 0742 C
// 0744 C
// 2023 2
// 7988 C
// 8322 C
// 0743 B
// 8361 A
// 0608 B
// 1392 C
// 2024 0
// 1263 A
// 1274 A
// 2024 1
// 0709 C
// 8362 B
// 8319 C
// 1394 B
// 0745 A
// 0592 C

//Leer datos del archivo
void leerArchivoNotas(struct registroNotas notas[8][4], struct registroEstudiante estudiantes[8]){
    int contadorEstudiante = 0;
    int auxiliarSemestre = 0;
    registroNotas = fopen("registroNotas.txt", "r");
    printf("Lectura de datos de notas ****** \n");

    registroNotas = fopen("registroNotas.txt", "r");

    while(contadorEstudiante<8){

        //lee los datos de un estudiante
        fscanf(registroNotas, "%s %[^\n]\n", estudiantes[contadorEstudiante].cedula, estudiantes[contadorEstudiante].nombre);
        printf("%s %s \n", estudiantes[contadorEstudiante].cedula, estudiantes[contadorEstudiante].nombre);

        //lee los datos del semestre
        for(int i=0; i<4; i++){
            fscanf(registroNotas, "%d %c \n", notas[contadorEstudiante][i].año, notas[contadorEstudiante][i].semestre);
            printf("%d %c \n", notas[contadorEstudiante][i].año, notas[contadorEstudiante][i].semestre);

            //verificacion si es verano
            if(notas[contadorEstudiante][i].semestre==0){
                auxiliarSemestre=2;
            }else{
                auxiliarSemestre=6;
            }

            //lectura de notas
            for(int i=0; i<4; i++){
                fscanf(registroNotas, "%d %c \n", notas[contadorEstudiante][i].año, notas[contadorEstudiante][i].semestre);
                printf("%d %c \n", notas[contadorEstudiante][i].año, notas[contadorEstudiante][i].semestre);
        }

        contadorEstudiante++;
    }
    //getch();
    fclose(registroNotas);
}

//funcion principal main
int main () {
    //defincion de variables
    struct registroEstudiante estudiantes[8];
    struct registroNotas notas[8][4];
    struct registroAsignaturas asignaturas[59];
    
    //prueba de cooncepto
    printf("Inicio del semestral \n");

    //lectura de archivos 
    leerArchivoAsignatura(asignaturas);

    //lectura de notas
    leerArchivoNotas(notas, estudiantes);

    return 0;
}