#include <stdio.h>
#include <stdlib.h>

//definicion de arvhivos
FILE * archivoAsignaturas;
FILE * registroNotas;

//variable global para saber cantidad de estudiantes
int NUMERO_ESTUDIANTES=8;

//estructura de registro de notas de estudiante
struct registroEstudiante {
    int cedula;
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
            &asignaturas[contador].codigoAsignatura,
            &asignaturas[contador].status,
            &asignaturas[contador].creditos,
            asignaturas[contador].nombreAsignatura);
        printf("%d %d %s %c %d %s\n", 
            asignaturas[contador].añoAcademico, 
            asignaturas[contador].semestre, 
            asignaturas[contador].codigoAsignatura,
            asignaturas[contador].status,
            asignaturas[contador].creditos,
            asignaturas[contador].nombreAsignatura);
        contador++;
    }
    //getch();
    fclose(archivoAsignaturas);
}

//Leer datos del archivo
void leerArchivoNotas(){
    // registroNotas = fopen("registroNotas.txt", "r");
    // printf("Lectura de datos \n");

    // registroNotas = fopen("registroNotas.txt", "r");

    // while(!(feof(registroNotas)))
    // {
    //     fscanf(registroNotas, "%d %d %c %s\n", &codAs,&creditos,&status,descripcion);
    //     printf("%d %d %c %s\n",codAs,creditos,status,descripcion);
    // }
    // getch();
    // fclose(registroNotas);
}

//FUNCION PARA CALCULAR EL INDICE
void calcularIndice(int creditos){
    char A, B, C, D, F;
    int puntos, indice, valor = 0, nota = 0;
    int totalCreditos = 0;
    //PARA QUE LA VARIABLE VALOR TENGA SU NÚMERO
    if(nota == A)
        valor = valor + 3;
        else if(nota == B)
            valor = valor + 2;
            else if(nota == C)
                valor = valor + 1;
                else if(nota == D || nota == F)
                    valor = 0;
    //FORMULAS PARA CALCULAR TODO
    puntos = valor * creditos;
    //FALTA HACER EL CICLO DE REPETICIÓN PARA EL TOTAL DE CREDITOS
    indice = puntos/totalCreditos;
}


//funcion principal main
int main () {
    //defincion de variables
    //struct registroEstudiante estudiantes[8];
    //struct registroNotas notas[8];
    struct registroAsignaturas asignaturas[59];
    
    //prueba de cooncepto
    printf("Inicio del semestral \n");

    //lectura de archivos 
    leerArchivoAsignatura(asignaturas);

    return 0;
}