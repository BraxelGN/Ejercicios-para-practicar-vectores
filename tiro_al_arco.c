#include <stdio.h>

#define MAX_TIROS 50

void ingresarDatos(int* coordX, int* coordY, int tirosX[], int tirosY[], int* numTiros) {
    printf("Ingrese las coordenadas del tiro al arco\n");
    printf("Coordenada X: ");
    scanf("%d", coordX);
    printf("Coordenada Y: ");
    scanf("%d", coordY);

    tirosX[*numTiros] = *coordX;
    tirosY[*numTiros] = *coordY;

    (*numTiros)++;
}

void evaluarHabilidades(int tirosX[], int tirosY[], int numTiros) {
    int i, goles = 0, afuera = 0;

    printf("Resultados de los tiros al arco:\n");

    for (i = 0; i < numTiros; i++) {
        printf("Tiro %d - Coordenadas: (%d, %d) - ", i + 1, tirosX[i], tirosY[i]);

        if (tirosX[i] >= 0 && tirosX[i] <= 500 && tirosY[i] >= 0 && tirosY[i] <= 250) {
            printf("GOL\n");
            goles++;
        } else {
            printf("AFUERA\n");
            afuera++;
        }
    }

    printf("Cantidad de tiros que resultaron en GOL: %d\n", goles);
    printf("Cantidad de tiros que fueron AFUERA: %d\n", afuera);
}

int main() {
    int opcion, coordX, coordY, numTiros = 0;
    int tirosX[MAX_TIROS];
    int tirosY[MAX_TIROS];

    do {
        printf("MENU\n");
        printf("1 - Ingresar datos de tiros al arco\n");
        printf("2 - Evaluar habilidades del arquero robot\n");
        printf("3 - Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                ingresarDatos(&coordX, &coordY, tirosX, tirosY, &numTiros);
                break;
            case 2:
                evaluarHabilidades(tirosX, tirosY, numTiros);
                break;
            case 3:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion invalida. Por favor, ingrese una opcion valida.\n");
                break;
        }

        printf("\n");
    } while (opcion != 3);

    return 0;
}
