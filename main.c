﻿#include <stdio.h>
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
    int codigoAsignatura[6];
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
    char nombreAsignatura[50];
};

//leer archivo de asignaturas
void leerArchivoAsignatura(struct registroAsignaturas asignaturas[59]){
    int contador = 0;
    //printf("Lectura de asignaturas **************\n");
    archivoAsignaturas = fopen("asignaturas.txt", "r");

    // while(!(feof(archivoAignaturas)))
    while(contador<58){
        //ESTO ES PARA IMPRIMIR TODAS LAS ASIGNATURAS
        fscanf(archivoAsignaturas, "%d %d %d %c %d %[^\n]\n", 
            &asignaturas[contador].añoAcademico, 
            &asignaturas[contador].semestre, 
            &asignaturas[contador].codigoAsignatura,
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

//Leer datos del archivo
void leerArchivoNotas(struct registroNotas notas[8][4], struct registroEstudiante estudiantes[8]){
    int contadorEstudiante = 0;
    int auxiliarSemestre = 0;
    registroNotas = fopen("registroNotas.txt", "r");
    //printf("Lectura de datos de notas ****** \n");

    registroNotas = fopen("registroNotas.txt", "r");

    while(contadorEstudiante<8){

        //lee los datos de un estudiante
        fscanf(registroNotas, "%s %[^\n]\n", estudiantes[contadorEstudiante].cedula, estudiantes[contadorEstudiante].nombre);
        // printf("%s %s \n", estudiantes[contadorEstudiante].cedula, estudiantes[contadorEstudiante].nombre);

        //lee los datos del semestre
        for(int i=0; i<4; i++){ 
            fscanf(registroNotas, "%d %d \n", &notas[contadorEstudiante][i].año, &notas[contadorEstudiante][i].semestre);
            // printf("%d %d \n", notas[contadorEstudiante][i].año, notas[contadorEstudiante][i].semestre);

            //verificacion si es verano
            if(notas[contadorEstudiante][i].semestre==0){
                auxiliarSemestre=2;
                // printf("Es un verano ******* \n");
            }else{
                auxiliarSemestre=6;
                // printf("Es un semestre ******* \n");
            }

            //lectura de notas
            for(int j=0; j<auxiliarSemestre; j++){  //auxiliarSemestre
                fscanf(registroNotas, "%d %c \n", 
                    &notas[contadorEstudiante][i].codigoAsignatura[j], 
                    &notas[contadorEstudiante][i].notas[j]
                );
                // printf("%d %c \n", 
                //     notas[contadorEstudiante][i].codigoAsignatura[j], 
                //     notas[contadorEstudiante][i].notas[j]
                // );
            }
        }
        contadorEstudiante++;
    }
    //getch();
    fclose(registroNotas);
    }


//Funcion para calcular los puntos totales por asignacion
int sumatoriaPuntos(char notas[6], int creditos[6]){
    //printf("Sumatoria ***** \n");
    int sumatoria=0;

    //Verificacion de la nota para la sumatoria
    for(int i = 0; i < 6; i ++){
        // printf("Nota: %c \n", notas[i]);
        // printf("Creditos: %d \n", creditos[i]);
        if(notas[i] == 'A'){
            // printf("Entra en A con %c \n", notas[i]);
            sumatoria = sumatoria + (3 * creditos[i]);
        }
            else if(notas[i] == 'B'){
                sumatoria = sumatoria + (2 * creditos[i]);
            }
                else if(notas[i] == 'C'){
                    sumatoria = sumatoria + (1 * creditos[i]);
                }
                    else {
                        sumatoria += 0;
                    }
    }
    // printf("Sumatoria: %d \n", sumatoria);
    return sumatoria;
}

//funcion para calcular un vector de creditos
void calcularCreditos(struct registroAsignaturas asignaturas[59], struct registroNotas notas[8][4], int vectorCreditos[8][4][6]){
    //printf("Calculo de total de creditos de un semestre ***************** \n");
    int creditos=0, contador=0, estudiante=0, auxiliar=0;
    //ciclo para estudiante
    for(estudiante = 0; estudiante<8 ; estudiante++){
        //Ciclo para semestre
        for(int semestre = 0; semestre < 4; semestre++){
            //ciclo para asignatura
            if(notas[8][4].semestre==0){
                auxiliar=2;
            }else{
                auxiliar=6;
            }
            for (int i = 0; i < 6; i++){
                if(notas[estudiante][semestre].codigoAsignatura[i]!=0){
                    // printf("%s \n", codigoAsignaturas[i]);
                    while (contador < 59){
                        if(asignaturas[contador].codigoAsignatura==notas[estudiante][semestre].codigoAsignatura[i]){
                            //printf("bingo ******** \n");
                            //printf("%s %d %d \n",asignaturas[contador].nombreAsignatura, asignaturas[contador].codigoAsignatura, asignaturas[contador].creditos);
                            vectorCreditos[estudiante][semestre][i] = asignaturas[contador].creditos;
                            contador=59;
                        }
                        contador++;
                    }
                    contador=0;
                }
                //parche
                // if(vectorCreditos[estudiante][semestre][i]>90){
                //     printf("Prueba********** \n");
                //     printf("vector de creditos: %d \n", vectorCreditos[estudiante][semestre][i]);
                //     printf("Codigo en Asignatura: %d \n", asignaturas[contador].codigoAsignatura);
                //     printf("codigo en notas: %d \n", notas[estudiante][semestre].codigoAsignatura[i]);
                //     printf("Creditos en asignatura: %d \n", asignaturas[contador].creditos);
                //     printf("estudiante : %d, semestre: %d, i que seria la materia: %d, contador de asignatura : %d\n",
                //         estudiante, 
                //         semestre, 
                //         i, contador
                //     );
                //     //vectorCreditos[estudiante][semestre][i] = 6;
                // }
            }
        }
    }
}

//sumatoria de creditos
int sumatoriaCreditos(int vectorCreditos[6]){
    int sumatoria = 0;
    for(int i = 0; i < 6; i++){
        sumatoria += vectorCreditos[i];
    }
    return sumatoria;
}

//mensajes
void mensjes(struct registroNotas notas[4], int condicionales){
    int contadorF = 0;
    int contadorD = 0;

    for(int i=0; i<4; i++){
        for(int j=0; j<6; j++){
            
            if(notas[i].notas[j]=='F'){
                contadorF++;
            }
            if(notas[i].notas[j]=='D'){
                contadorD++;
            }
        }
    }

    if(contadorF>0){
        printf("HA OBTENIDO F COMO CALIFICACIÓN, RECUERDE QUE SI TIENE 3 Fs CONSECUTIVAS, DEBE CAMBIARSE A UNA CARRERA DONDE NO EXISTA ESTE CÓDIGO \n\n");
    }
    if(contadorD>0){
        printf("HA OBTENIDO D COMO CALIFICACIÓN, RECUERDE QUE TIENE TRES OPCIONES: \n"); 
        printf("1.	SI LA MATERIA ES FUNDAMENTAL, DEBE REPETIR LA MISMA. \n"); 
        printf("2.	SI LA MATERIA NO ES FUNDAMENTAL Y LA HA RECIBIDO UN SOLA VEZ, PUEDE DEJARLA ASÍ \n"); 
        printf("3.	SI LA MATERIA NO ES FUNDAMENTAL PERO HA OBTENIDO UNA F PREVIA, DEBE REPETIR LA MISMA YA QUE UNA D NO TAPA UNA F \n\n"); 
    }

    if(condicionales>=3){
        printf("SU SITUACIÓN ES CRÍTICA, YA QUE DEBE HACER CAMBIO DE CARRERA, PORQUE HA ALCANZADO 3 CONDICIONALES \n\n"); 
    }else{
        if(condicionales>=2){
            printf("TIENE UNA CONDICIONAL, TRATE DE SUBIR EL ÍNDICE ACADÉMICO.  ESTÁ A TIEMPO \n\n"); 
        }else{
            printf("HA ALCANZADO 2 CONDICIONALES, ES RECOMENDABLE MATRICULAR MATERIAS CON D y F PARA SUBIR EL ÍNDICE\n\n"); 
        }
    }
}

void imprimirEncabezado() {
    printf("\t        UNIVERSIDAD TECNOLÓGICA DE PANAMÁ\n");
    printf("\t\t   CENTRO REGIONAL DE CHIRIQUÍ\n"); 
    printf("\tFACULTAD DE INGENIERÍA DE SISTEMAS COMPUTACIONALES\n");
    printf("\tLICENCIATURA EN IGENIERÍA DE SISTEMAS Y COMPUTACIÓN\n\n");
    printf("\t\t   REPORTE ACADÉMICO DE ESTUDIANTES\n\n"); 
    printf("NOMBRE DEL ESTUDIANTE: Kelidy Jimenez Miranda     GRUPO: 2IL112\n");
    printf("CÉDULA DEL ESTUDIANTE: 4-830-283\n\n");
}

//funcion principal main
int main () {
    //defincion de variables
    struct registroEstudiante estudiantes[8];
    struct registroNotas notas[8][4];
    struct registroAsignaturas asignaturas[59];
    int vectorCreditos[8][4][6]={0}, totalCreditos[8][4], totalPuntos[8][4], puntos=0, creditos=0, condicional=0;
    float indice[8][4];
    
    //lectura de archivos 
    leerArchivoAsignatura(asignaturas);

    //lectura de notas
    leerArchivoNotas(notas, estudiantes);

    //Calcular total de creditos
    calcularCreditos(asignaturas, notas, vectorCreditos);
    //ENcabezado    
    imprimirEncabezado();

    //Impresion de datos
    for(int i=0; i<8;i++){

        //datos del estuante
        printf("%s\n", estudiantes[i].cedula);
        printf("%s\n", estudiantes[i].nombre);

        //Imprimir los datos
        //encabezado
        printf("%12s %10s %10s %10s %10s %10s \n", "Año lectivo", "Semestre", "Puntos", "Total/Cr", "Índice", "Condicional");
        for(int j=0; j<4; j++){
            //creditos
            creditos += sumatoriaCreditos(vectorCreditos[i][j]);

            //puntos del semestre
            puntos += sumatoriaPuntos(notas[i][j].notas, vectorCreditos[i][j]);

            //indice
            indice[i][j] = (float)puntos/(float)creditos;

            //Condicionales
            if(indice[i][j]<1.00){
                condicional++;
            }

            printf("%7d %10d %14d %7d %11.2f %7d \n", 
                notas[i][j].año, 
                j,  
                puntos, 
                creditos, 
                indice[i][j], 
                condicional
            );
        }

        printf("\n");
        mensjes(notas[i], condicional);
        puntos=0;
        creditos=0;
        condicional=0;
        printf("\n\n");

    }

    return 0;
}