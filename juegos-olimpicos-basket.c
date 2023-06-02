#include <stdio.h>

#define MAX_JUGADORES 50

typedef struct {
    int numeroCamiseta;
    char posicion;
    int tirosZonaAnotados;
    int tirosFueraZonaAnotados;
    int tirosLibresAnotados;
} Jugador;

void ingresarPuntajeContrario(int* puntajeContrario) {
    printf("Ingrese el puntaje del equipo contrario: ");
    scanf("%d", puntajeContrario);
}

void ingresarDatosJugador(Jugador* jugador, int* numJugadores, int* numerosCamiseta, char* posiciones, int* puntajes) {
    printf("Ingrese los datos del jugador:\n");
    printf("Número de camiseta: ");
    scanf("%d", &(jugador->numeroCamiseta));
    printf("Posición en la cancha ('b' para base, 'p' para pilar, 'd' para defensor): ");
    scanf(" %c", &(jugador->posicion));
    printf("Tiros en zona anotados: ");
    scanf("%d", &(jugador->tirosZonaAnotados));
    printf("Tiros fuera de zona anotados: ");
    scanf("%d", &(jugador->tirosFueraZonaAnotados));
    printf("Tiros libres anotados: ");
    scanf("%d", &(jugador->tirosLibresAnotados));

    numerosCamiseta[*numJugadores] = jugador->numeroCamiseta;
    posiciones[*numJugadores] = jugador->posicion;
    puntajes[*numJugadores] = (jugador->tirosZonaAnotados * 2) + (jugador->tirosFueraZonaAnotados * 3) + jugador->tirosLibresAnotados;

    (*numJugadores)++;
}

void evaluarPartido(int* numerosCamiseta, char* posiciones, int* puntajes, int numJugadores, int puntajeContrario) {
    int i;
    int puntajeTotal = 0;
    int maximoPuntaje = 0;
    int indiceMaximoPuntaje = 0;

    printf("Resultados del partido:\n");

    // Contadores para cada posición
    int contadorBase = 0;
    int contadorPilar = 0;
    int contadorDefensor = 0;

    for (i = 0; i < numJugadores; i++) {
        puntajeTotal += puntajes[i];

        switch (posiciones[i]) {
            case 'b':
                contadorBase++;
                break;
            case 'p':
                contadorPilar++;
                break;
            case 'd':
                contadorDefensor++;
                break;
        }

        if (puntajes[i] > maximoPuntaje) {
            maximoPuntaje = puntajes[i];
            indiceMaximoPuntaje = i;
        }
    }

    printf("Cantidad de jugadores en cada posición:\n");
    printf("Base: %d\n", contadorBase);
    printf("Pilar: %d\n", contadorPilar);
    printf("Defensor: %d\n", contadorDefensor);

    printf("Número de camiseta con mayor puntaje: %d\n", numerosCamiseta[indiceMaximoPuntaje]);

    printf("Puntaje total de la Selección Argentina: %d\n", puntajeTotal);
    if (puntajeTotal > puntajeContrario) {
        printf("La Selección Argentina ganó el partido.\n");
    } else if (puntajeTotal < puntajeContrario) {
        printf("La Selección Argentina perdió el partido.\n");
    } else {
        printf("El partido terminó en empate.\n");
    }
}

int main() {
    int opcion;
    int puntajeContrario = 0;
    Jugador jugadores[MAX_JUGADORES];
    int numJugadores = 0;
    int numerosCamiseta[MAX_JUGADORES];
    char posiciones[MAX_JUGADORES];
    int puntajes[MAX_JUGADORES];

    do {
        printf("MENU\n");
        printf("1 - Ingresar puntaje final del equipo contrario\n");
        printf("2 - Ingresar datos de jugadores de la selección argentina\n");
        printf("3 - Evaluación del partido\n");
        printf("4 - Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                ingresarPuntajeContrario(&puntajeContrario);
                break;
            case 2: {
                Jugador jugador;
                ingresarDatosJugador(&jugador, &numJugadores, numerosCamiseta, posiciones, puntajes);
                jugadores[numJugadores - 1] = jugador;
                break;
            }
            case 3:
                evaluarPartido(numerosCamiseta, posiciones, puntajes, numJugadores, puntajeContrario);
                break;
            case 4:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción inválida. Por favor, ingrese una opción válida.\n");
                break;
        }

        printf("\n");
    } while (opcion != 4);

    return 0;
}

