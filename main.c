#include <stdio.h>
#include <stdlib.h>


FILE * archivoAsignaturas;
FILE * registroNotas;
FILE * ProyectoFinal;

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
    archivoAsignaturas = fopen("asignaturas.txt", "r");

    while(contador<58){
        fscanf(archivoAsignaturas, "%d %d %d %c %d %[^\n]\n", 
            &asignaturas[contador].añoAcademico, 
            &asignaturas[contador].semestre, 
            &asignaturas[contador].codigoAsignatura,
            &asignaturas[contador].status,
            &asignaturas[contador].creditos,
            asignaturas[contador].nombreAsignatura);
        contador++;
    }
    fclose(archivoAsignaturas);
}

//Leer datos del archivo
void leerArchivoNotas(struct registroNotas notas[8][4], struct registroEstudiante estudiantes[8]){
    int contadorEstudiante = 0;
    int auxiliarSemestre = 0;
    registroNotas = fopen("registroNotas.txt", "r");

    registroNotas = fopen("registroNotas.txt", "r");

    while(contadorEstudiante<8){

        fscanf(registroNotas, "%s %[^\n]\n", estudiantes[contadorEstudiante].cedula, estudiantes[contadorEstudiante].nombre);

        for(int i=0; i<4; i++){ 
            fscanf(registroNotas, "%d %d \n", &notas[contadorEstudiante][i].año, &notas[contadorEstudiante][i].semestre);

            //verificacion si es verano
            if(notas[contadorEstudiante][i].semestre==0){
                auxiliarSemestre=2;
            }else{
                auxiliarSemestre=6;
            }

            //lectura de notas
            for(int j=0; j<auxiliarSemestre; j++){
                fscanf(registroNotas, "%d %c \n", 
                    &notas[contadorEstudiante][i].codigoAsignatura[j], 
                    &notas[contadorEstudiante][i].notas[j]
                );
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
        if(notas[i] == 'A'){
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
    return sumatoria;
}

//funcion para calcular un vector de creditos
void calcularCreditos(struct registroAsignaturas asignaturas[59], struct registroNotas notas[8][4], int vectorCreditos[8][4][6]){
    int creditos=0, contador=0, estudiante=0, auxiliar=0;
    for(estudiante = 0; estudiante<8 ; estudiante++){
        for(int semestre = 0; semestre < 4; semestre++){
            if(notas[8][4].semestre==0){
                auxiliar=2;
            }else{
                auxiliar=6;
            }
            for (int i = 0; i < 6; i++){
                if(notas[estudiante][semestre].codigoAsignatura[i]!=0){
                    while (contador < 59){
                        if(asignaturas[contador].codigoAsignatura==notas[estudiante][semestre].codigoAsignatura[i]){
                            vectorCreditos[estudiante][semestre][i] = asignaturas[contador].creditos;
                            contador=59;
                        }
                        contador++;
                    }
                    contador=0;
                }
            }
        }
    }
}

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
        fprintf(ProyectoFinal, "HA OBTENIDO F COMO CALIFICACIÓN, RECUERDE QUE SI TIENE 3 Fs CONSECUTIVAS, DEBE CAMBIARSE A UNA CARRERA DONDE NO EXISTA ESTE CÓDIGO \n\n");
    }
    if(contadorD>0){
        fprintf(ProyectoFinal, "HA OBTENIDO D COMO CALIFICACIÓN, RECUERDE QUE TIENE TRES OPCIONES: \n"); 
        fprintf(ProyectoFinal, "1.	SI LA MATERIA ES FUNDAMENTAL, DEBE REPETIR LA MISMA. \n"); 
        fprintf(ProyectoFinal, "2.	SI LA MATERIA NO ES FUNDAMENTAL Y LA HA RECIBIDO UN SOLA VEZ, PUEDE DEJARLA ASÍ \n"); 
        fprintf(ProyectoFinal, "3.	SI LA MATERIA NO ES FUNDAMENTAL PERO HA OBTENIDO UNA F PREVIA, DEBE REPETIR LA MISMA YA QUE UNA D NO TAPA UNA F \n\n"); 
    }

    if(condicionales>=3){
        fprintf(ProyectoFinal, "SU SITUACIÓN ES CRÍTICA, YA QUE DEBE HACER CAMBIO DE CARRERA, PORQUE HA ALCANZADO 3 CONDICIONALES \n\n"); 
    }else{
        if(condicionales>=2){
            fprintf(ProyectoFinal, "HA ALCANZADO 2 CONDICIONALES, ES RECOMENDABLE MATRICULAR MATERIAS CON D y F PARA SUBIR EL ÍNDICE\n\n"); 
        }else if(condicionales>=1){
            fprintf(ProyectoFinal, "TIENE UNA CONDICIONAL, TRATE DE SUBIR EL ÍNDICE ACADÉMICO.  ESTÁ A TIEMPO \n\n"); 
        }
    }
}

void imprimirEncabezado() {
    fprintf(ProyectoFinal, "\t     UNIVERSIDAD TECNOLÓGICA DE PANAMÁ\n");
    fprintf(ProyectoFinal, "\t\t   CENTRO REGIONAL DE CHIRIQUÍ\n"); 
    fprintf(ProyectoFinal, "\tFACULTAD DE INGENIERÍA DE SISTEMAS COMPUTACIONALES\n");
    fprintf(ProyectoFinal, "\tLICENCIATURA EN IGENIERÍA DE SISTEMAS Y COMPUTACIÓN\n\n");
    fprintf(ProyectoFinal, "\t\t   REPORTE ACADÉMICO DE ESTUDIANTES\n\n"); 
    fprintf(ProyectoFinal, "NOMBRE DE LOS ESTUDIANTES: Franklin Pimentel; Samuel Henao     GRUPO: 2IL111\n");
    fprintf(ProyectoFinal, "CÉDULAS: 20-70-8197; 20-14-8312 \n\n");
}

//Numeros romanos
char numerosRomanos(int semestre, char romano[2]){
    if(semestre==0){
        romano[0]='0';
        romano[1]=' ';
    }
    if(semestre==1){
        romano[0]='I';
        romano[1]=' ';
    }
    if(semestre==2){
        romano[0]='I';
        romano[1]='I';
    }
}

int main () {
    struct registroEstudiante estudiantes[8];
    struct registroNotas notas[8][4];
    struct registroAsignaturas asignaturas[59];
    int vectorCreditos[8][4][6]={0}, totalCreditos[8][4], totalPuntos[8][4], puntos=0, creditos=0, condicional=0;
    float indice[8][4];
    char numeroRomano[2];
 
    leerArchivoAsignatura(asignaturas);

    leerArchivoNotas(notas, estudiantes);

    calcularCreditos(asignaturas, notas, vectorCreditos);  
    
    ProyectoFinal = fopen("ProyectoFinal.txt", "w" );
    if (ProyectoFinal == NULL) {
    perror("Error al abrir el archivo ProyectoFinal.txt");
    exit(1);
}
    imprimirEncabezado();

    //Impresion de datos
    for(int i=0; i<8;i++){

        fprintf(ProyectoFinal, "%s\n", estudiantes[i].cedula);
        fprintf(ProyectoFinal, "%s\n", estudiantes[i].nombre);

        fprintf(ProyectoFinal, "%15s %15s %14s %15s %15s %15s \n", "Año lectivo", "Semestre", "Puntos", "Total/Cr", "Índice", "Condicional");
        for(int j=0; j<4; j++){
            creditos += sumatoriaCreditos(vectorCreditos[i][j]);

            puntos += sumatoriaPuntos(notas[i][j].notas, vectorCreditos[i][j]);

            indice[i][j] = (float)puntos/(float)creditos;

            if(indice[i][j]<1.00){
                condicional++;
            }

            numerosRomanos(notas[i][j].semestre, numeroRomano);

            fprintf(ProyectoFinal, "%7d %19s %25d %16d %20.2f %9d \n", 
                notas[i][j].año, 
                numeroRomano,  
                puntos, 
                creditos, 
                indice[i][j], 
                condicional
            );
        }

        fprintf(ProyectoFinal, "\n");
        numeroRomano[0]=' ';
        numeroRomano[1]=' ';
        mensjes(notas[i], condicional);
        puntos=0;
        creditos=0;
        condicional=0;
        fprintf(ProyectoFinal, "\n\n");

    }
    fclose(ProyectoFinal);
    return 0;
}