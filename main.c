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
            fscanf(registroNotas, "%d %d \n", &notas[contadorEstudiante][i].año, &notas[contadorEstudiante][i].semestre);
            printf("%d %d \n", notas[contadorEstudiante][i].año, notas[contadorEstudiante][i].semestre);

            //verificacion si es verano
            if(notas[contadorEstudiante][i].semestre==0){
                auxiliarSemestre=2;
                printf("Es un verano ******* \n");
            }else{
                auxiliarSemestre=6;
                printf("Es un semestre ******* \n");
            }

            //lectura de notas
            for(int j=0; j<auxiliarSemestre; j++){  //auxiliarSemestre
                fscanf(registroNotas, "%s %c \n", 
                    notas[contadorEstudiante][i].codigoAsignatura[j], 
                    &notas[contadorEstudiante][i].notas[j]
                );
                printf("%s %c \n", 
                    notas[contadorEstudiante][i].codigoAsignatura[j], 
                    notas[contadorEstudiante][i].notas[j]
                );
            }
        }
        contadorEstudiante++;
    }
    //getch();
    fclose(registroNotas);
    }

//FUNCION PARA CALCULAR EL INDICE
void calcularIndice(int creditos[6], int totalCreditos)
{
    char nota[6]={0};
    int puntos[6] ={0}, valor[6]={0};
    int totalPuntos = 0;
    float indice = 0;
    //PARA QUE LA VARIABLE VALOR TENGA SU NÚMERO
    for(int i = 0; i < 6; i ++){
        printf("Ingrese su nota: ");
        scanf(" %c", &nota[i]);
        if(nota[i] == 'A'){
            valor[i] = valor[i] + 3;
        }
            else if(nota[i] == 'B'){
                valor[i] = valor[i] + 2;
            }
                else if(nota[i] == 'C'){
                    valor[i] = valor[i] + 1;
                }
                    else if(nota[i] == 'D' || nota[i] == 'F'){
                        valor[i] = 0;
                    }
    }
    //FORMULAS PARA CALCULAR TODO
    for(int i = 0; i < 6; i ++){
        puntos[i] = valor[i] * creditos[i];
        totalPuntos = totalPuntos + puntos[i];
    }
    //FALTA HACER EL CICLO DE REPETICIÓN PARA EL TOTAL DE CREDITOS
    indice = totalPuntos/(float)totalCreditos;
    printf("Sus puntos son : %d\n", totalPuntos);
    printf("Sus creditos son: %d\n", totalCreditos);
    printf("Su indice es de : %.2f\n", indice);
}


//funcion principal main
int main () {
    //defincion de variables
    struct registroEstudiante estudiantes[8];
    struct registroNotas notas[8][4];
    struct registroAsignaturas asignaturas[59];
    
    //prueba de cooncepto
    //printf("Inicio del semestral \n");

    //lectura de archivos 
    leerArchivoAsignatura(asignaturas);

    //lectura de notas
    leerArchivoNotas(notas, estudiantes);

    //calcular el incide
    // calcularIndice(creditos, totalCreditos);

    return 0;
}