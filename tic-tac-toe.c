/*
    Intgrantes: {

    }
    fecha: 21/02/2025
    tema: Matrices
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

main() {
    char gato[3][3];

    int i, j, band = 1, count = 0, turn = 1;
    int X = 'X', O = 'O';
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            gato[i][j] = '-';
        }
    }

    while(band == 1 && count < 9) {
        int posicion, cordY, cordX;

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

        if(turn == 1) {
            printf("\nTurno 1\n");
            printf("Introduce una posiscion del 1 al 9: ");
        } else {
            printf("Turno 2\n");
            printf("Introduce una posiscion del 1 al 9: ");
        }

        scanf("%d", &posicion);

        cordY = (posicion - 1) / 3;
        cordX = (posicion - 1) % 3;

        if(gato[cordY][cordX] == '-' && turn == 1)
            gato[cordY][cordX] = 'X';
        else if(gato[cordY][cordX] == '-' && turn == -1)
            gato[cordY][cordX] = 'O';
        else {
            printf("\nEsa posicion ya esta definida, intenta denuevo\n");
            count--;
        }

        for(i = 0; i < 3; i++) {
            if(gato[i][0] == X && gato[i][1] == X && gato[i][2] == X) {
                printf("\nEl jugador 1 es el ganador");
                band = 0;
                printf("\nfirst point\n");
                break;
            }

            if(gato[i][0] == O && gato[i][1] == O && gato[i][2] == O) {
                printf("\nEl jugador 2 es el ganador");
                band = 0;
                printf("\nfirst point\n");
                break;
            }

        }

        for(i = 0; i < 3; i++) {
            if(gato[0][i] == X && gato[1][i] == X && gato[2][i] == X) {
                printf("\nEl jugador 1 es el ganador");
                band = 0;
                printf("\nsecond point\n");
                break;
            }

            if(gato[0][i] == O && gato[1][i] == O && gato[2][i] == O) {
                printf("\nEl jugador 2 es el ganador");
                band = 0;
                printf("\nsecond point\n");
                break;
            }
        }

        if (gato[0][0] == X && gato[1][1] == X && gato[2][2] == X) {
            printf("\nEl jugador 1 es el ganador");
            band = 0;
            printf("\nthird point\n");
            break;
        }

        if (gato[0][0] == O && gato[1][1] == O && gato[2][2] == O) {
            printf("\nEl jugador 2 es el ganador");
            band = 0;
            printf("\nthird point\n");
            break;
        }

        if (gato[0][2] == X && gato[1][1] == X && gato[2][0] == X) {
            printf("\nEl jugador 1 es el ganador");
            band = 0;
            printf("\nfourth point\n");
            break;
        }

        if (gato[0][2] == O && gato[1][1] == O && gato[2][0] == O) {
            printf("\nEl jugador 2 es el ganador");
            band = 0;
            printf("\nfourth point\n");
            break;
        }

        if(band == 0)
            break;

        count++;
        turn = turn * -1;
    }

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

    getch();
    return 0;
}
