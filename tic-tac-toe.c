#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    char gato[3][3];

    int i, j, band = 1, count = 0, turn = 1;

    // Inicializar la matriz con caracteres individuales
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            gato[i][j] = '-';
        }
    }

    while(band == 1 && count < 9) {
        // Imprimir la matriz
        printf("\n");
        for(i = 0; i < 3; i++) {
            for(j = 0; j < 3; j++) {
                if(j == 0)
                    printf("[ %c ", gato[i][j]);
                else if(j == 1)
                    printf("| %c ", gato[i][j]);
                else
                    printf("| %c ]\n", gato[i][j]);
            }
        }

        // Mostrar turno actual
        if(turn == 1) {
            printf("\nTurno del Jugador X\n");
            printf("Introduce una posicion del 1 al 9: ");
        } else {
            printf("\nTurno del Jugador O\n");
            printf("Introduce una posicion del 1 al 9: ");
        }

        int posicion;
        scanf("%d", &posicion);

        int cordY = (posicion - 1) / 3;
        int cordX = (posicion - 1) % 3;

        // Actualizar la posicion correctamente
        if(gato[cordY][cordX] == '-' && turn == 1)
            gato[cordY][cordX] = 'X';
        else if(gato[cordY][cordX] == '-' && turn == -1)
            gato[cordY][cordX] = 'O';

        // Verificar ganador horizontalmente
        for(i = 0; i < 3; i++) {
            if(gato[i][0] == 'X' && gato[i][1] == 'X' && gato[i][2] == 'X') {
                printf("\nEl jugador X es el ganador!\n");
                band = 0;
                break;
            }
            if(gato[i][0] == 'O' && gato[i][1] == 'O' && gato[i][2] == 'O') {
                printf("\nEl jugador O es el ganador!\n");
                band = 0;
                break;
            }
        }

        // Verificar ganador verticalmente
        for(i = 0; i < 3; i++) {
            if(gato[0][i] == 'X' && gato[1][i] == 'X' && gato[2][i] == 'X') {
                printf("\nEl jugador X es el ganador!\n");
                band = 0;
                break;
            }
            if(gato[0][i] == 'O' && gato[1][i] == 'O' && gato[2][i] == 'O') {
                printf("\nEl jugador O es el ganador!\n");
                band = 0;
                break;
            }
        }

        // Verificar diagonales
        if((gato[0][0] == 'X' && gato[1][1] == 'X' && gato[2][2] == 'X') ||
           (gato[0][2] == 'X' && gato[1][1] == 'X' && gato[2][0] == 'X')) {
            printf("\nEl jugador X es el ganador!\n");
            band = 0;
        }
        else if((gato[0][0] == 'O' && gato[1][1] == 'O' && gato[2][2] == 'O') ||
                (gato[0][2] == 'O' && gato[1][1] == 'O' && gato[2][0] == 'O')) {
            printf("\nEl jugador O es el ganador!\n");
            band = 0;
        }

        if(band == 0)
            break;

        count++;
        turn *= -1;
    }

    return 0;
}
