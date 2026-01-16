#include <stdio.h>

#define N 12

void imprimirTablero(char t[N][N]) {
    int i, j;
    printf("\nTablero del jugador:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%c ", t[i][j]);
        }
        printf("\n");
    }
}

void pedirYColocarBarco(char t[N][N], int tam, int numeroBarco) {
    int fila, columna, i;
    char orientacion;
    int valido;

    while (1) {
        printf("\n== Coloca BARCO %d (tamano %d) ==\n", numeroBarco, tam);

        printf("Ingresa la fila inicial (0 a %d): ", N - 1);
        scanf("%d", &fila);

        printf("Ingresa la columna inicial (0 a %d): ", N - 1);
        scanf("%d", &columna);

        printf("Orientacion (H = horizontal, V = vertical): ");
        scanf(" %c", &orientacion);

        // aceptar minusculas
        if (orientacion >= 'a' && orientacion <= 'z') {
            orientacion = orientacion - ('a' - 'A');
        }

        // validar rango
        if (fila < 0 || fila >= N || columna < 0 || columna >= N) {
            printf("❌ Fuera del tablero.\n");
            continue;
        }

        // validar que no se salga
        if (orientacion == 'H' && columna + tam - 1 >= N) {
            printf("❌ No cabe horizontal.\n");
            continue;
        }
        if (orientacion == 'V' && fila + tam - 1 >= N) {
            printf("❌ No cabe vertical.\n");
            continue;
        }
        if (orientacion != 'H' && orientacion != 'V') {
            printf("❌ Orientacion invalida. Usa H o V.\n");
            continue;
        }

        // validar superposicion
        valido = 1;
        if (orientacion == 'H') {
            for (i = 0; i < tam; i++) {
                if (t[fila][columna + i] != 'A') { valido = 0; break; }
            }
        } else {
            for (i = 0; i < tam; i++) {
                if (t[fila + i][columna] != 'A') { valido = 0; break; }
            }
        }

        if (!valido) {
            printf("❌ Hay un barco en esa zona. Intenta otra posicion.\n");
            continue;
        }

        // colocar barco
        if (orientacion == 'H') {
            for (i = 0; i < tam; i++) t[fila][columna + i] = 'B';
        } else {
            for (i = 0; i < tam; i++) t[fila + i][columna] = 'B';
        }

        break;
    }
}

int main(void) {
    char tablero[N][N];
    int i, j;
    int num = 1;

    // llenar con agua
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) tablero[i][j] = 'A';
    }

    // colocar varios barcos (ejemplo)
    pedirYColocarBarco(tablero, 4, num++); // barco grande
    imprimirTablero(tablero);

    pedirYColocarBarco(tablero, 3, num++); // barco mediano
    imprimirTablero(tablero);

    pedirYColocarBarco(tablero, 2, num++); // barco pequeño
    imprimirTablero(tablero);

    pedirYColocarBarco(tablero, 2, num++); // otro pequeño
    imprimirTablero(tablero);

    return 0;
}