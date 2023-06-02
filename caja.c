#include <stdio.h>

#define MAX_DIAS 31

void ingresarMovimientos(float movimientos[], int* numMovimientos) {
    int dia;
    char codigo;
    float monto;

    printf("Ingrese los datos de los movimientos de fondos:\n");
    printf("Dia del mes (1 a 31): ");
    scanf("%d", &dia);
    printf("Codigo de Movimiento ('I' para ingreso, 'E' para egreso): ");
    scanf(" %c", &codigo);
    printf("Monto en pesos del movimiento: ");
    scanf("%f", &monto);

    movimientos[dia - 1] += (codigo == 'I') ? monto : -monto;
    (*numMovimientos)++;
}

void evaluarCobranzas(float movimientos[], int numMovimientos, float saldoInicial) {
    float saldoCaja[MAX_DIAS];
    float saldoFinal;
    int i;

    saldoCaja[0] = saldoInicial + movimientos[0];
    saldoFinal = saldoCaja[0];

    for (i = 1; i < numMovimientos; i++) {
        saldoCaja[i] = saldoCaja[i - 1] + movimientos[i];
        saldoFinal = saldoCaja[i];
    }

    printf("Evaluacion de Cobranzas en RRHH:\n");

    for (i = 0; i < numMovimientos; i++) {
        printf("Dia %d - Saldo de Caja: %.2f\n", i + 1, saldoCaja[i]);
    }

    printf("Saldo final de Caja del mes: %.2f\n", saldoFinal);
}

int main() {
    int opcion, numMovimientos = 0;
    float movimientos[MAX_DIAS] = {0};
    float saldoInicial;

    do {
        printf("MENU\n");
        printf("1 - Ingresar datos de Movimientos de Fondos\n");
        printf("2 - Evaluacion de Cobranzas en RRHH\n");
        printf("3 - Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                ingresarMovimientos(movimientos, &numMovimientos);
                break;
            case 2:
                printf("Ingrese el Saldo Inicial de Caja: ");
                scanf("%f", &saldoInicial);
                evaluarCobranzas(movimientos, numMovimientos, saldoInicial);
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
