#include <stdio.h>
#include <stdbool.h>

#define NUM_CLASES 4
#define NUM_HORARIOS 5

//struct de las clases
struct Clase {
    char nombre[20];
    int cupo;
};

int main() {
    struct Clase clases[NUM_CLASES] = {
        {"Top Ride", 0},
        {"Zumba", 0},
        {"Entretenimiento", 0},
        {"Abdominales", 0}
    };

    int asistencia[NUM_CLASES][NUM_HORARIOS] = {0};

    bool horarios_sin_clase[NUM_HORARIOS] = {true};
    bool clases_sin_alumnos[NUM_CLASES] = {true};

    int ganancia = 0;

    printf("BIENVENIDO AL GIMNASIO VIRTUAL! \n");
    printf("HAY CLASES DE TIPO TOP RIDE, ZUMBA, ENTRETENIMIENTO Y ABDOMINALES.");
    printf("\n");
    printf("LA CANTIDAD MAXIMA PARA CADA CUPO ES DE 5 INCLUSIVE Y NO SE PERMITE INGRESAR NUMEROS CON COMA.");
	printf("\n");
	printf("\n");
    

    // Ingreso de cupo de cada clase
    for (int i = 0; i < NUM_CLASES; i++) {
        printf("Ingrese el cupo para la clase %s: ", clases[i].nombre);
        scanf("%d", &clases[i].cupo);
    }

    // Registro de asistencia
    for (int horario = 0; horario < NUM_HORARIOS; horario++) {
        printf("Horario %d\n", horario + 1);
        bool horario_sin_clase = true;
        for (int clase = 0; clase < NUM_CLASES; clase++) {
            printf("Ingrese la cantidad de alumnos para la clase %s: ", clases[clase].nombre);
            int cantidad_alumnos;
            scanf("%d", &cantidad_alumnos);

            if (cantidad_alumnos > clases[clase].cupo) {
                printf("La clase ha alcanzado su cupo maximo!\n");
            } else {
                asistencia[clase][horario] = cantidad_alumnos;
                if (cantidad_alumnos > 0) {
                    horarios_sin_clase[horario] = false;
                    horario_sin_clase = false;
                    clases_sin_alumnos[clase] = false;
                    ganancia += (horario == 2) ? 700 : (horario < 2) ? (700 * 0.8) : (700 * 1.15);
                }
            }
        }
        if (horario_sin_clase) {
            printf("No se dicto ninguna clase en este horario por falta de gente.\n");
        }
        printf("\n");
    }

    // Informe de clases sin personas
    printf("Clases en las que no concurrio ningun alumno:\n");
    bool todas_clases_con_alumnos = true;
    for (int clase = 0; clase < NUM_CLASES; clase++) {
        if (clases_sin_alumnos[clase]) {
            printf("- %s\n", clases[clase].nombre);
            todas_clases_con_alumnos = false;
        }
    }
    if (todas_clases_con_alumnos) {
        printf("Todas las clases tienen al menos un alumno.\n");
    }
    printf("\n");

    // Informe de horarios sin clases
    printf("Horarios en los que no se dicto ninguna clase:\n");
    bool todos_horarios_con_clases = true;
    for (int horario = 0; horario < NUM_HORARIOS; horario++) {
        if (horarios_sin_clase[horario]) {
            printf("- Horario %d\n", horario + 1);
            todos_horarios_con_clases = false;
        }
    }
    if (todos_horarios_con_clases) {
        printf("Todos los horarios tienen al menos una clase.\n");
    }
    printf("\n");

    //Informe de cantidad de personas que concurrieron a cada clase
    printf("Cantidad de personas que concurrieron a cada clase:\n");
    for (int clase = 0; clase < NUM_CLASES; clase++) {
        int total_asistencia = 0;
        for (int horario = 0; horario < NUM_HORARIOS; horario++) {
            total_asistencia += asistencia[clase][horario];
        }
        printf("- %s: %d\n", clases[clase].nombre, total_asistencia);
    }
    printf("\n");

    // Informe de ganancia obtenida en el día
    printf("Ganancia obtenida en el dia: $%d\n", ganancia);
    printf("\n");

    return 0;
}

