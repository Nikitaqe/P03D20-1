#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "lib.h"

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    printf("Enter an infix expression: ");
    fgets(infix, MAX_SIZE, stdin);

    convertToPostfix(infix, postfix);
    int token_count;
    int n = 0;
    int m = 0;
    double array[n][m];
    double dif = 4 * M_PI / (NUM_STEPS - 1);
    int print[25][80] = {0};
    for (int i = 0; i < NUM_STEPS; i++) {
        array[i][0] = i * dif;
        Token *tokens = parse_expression(postfix, &token_count, i * dif);
        array[i][1] = calculate_expression(tokens, token_count);
        printf("x = %d, y = %d\n", (int)(array[i][0] * 6.3), (int)(array[i][1] * 12.5 + 12));
        if (array[i][1] <= 1 && array[i][1] >= -1) {
            print[(int)(array[i][1] * 12.5 + 12)][(int)(array[i][0] * 6.3)] = 1;
        }
        free(tokens);
    }

    for (int i = 24; i >= 0; i--) {
        for (int j = 0; j < 80; j++) {
            if (print[i][j] == 1) {
                printf("*");
            } else {
                printf(".");
            }
            if (j == 79) {
                printf("\n");
            }
        }
    }
    printf("Postfix expression: %s\n", postfix);

    return 0;
}


/*
    char expression[100];
    printf("Введите выражение в польской нотации: ");
    fgets(expression, sizeof(expression), stdin);
    int token_count;
    int n = 0;
    int m = 0;
    double array[n][m];
    double dif = 4 * M_PI / (NUM_STEPS - 1);
    int print[25][80] = {0};
    for (int i = 0; i < NUM_STEPS; i++) {
        array[i][0] = i * dif;
        Token *tokens = parse_expression(expression, &token_count, i * dif);
        // printf("jasvdm,asd\n");
        array[i][1] = calculate_expression(tokens, token_count);
        // printf("jasvdm,asd\n");
        printf("x = %d, y = %d\n", (int)(array[i][0] * 6.3), (int)(array[i][1] * 12.5 + 12));
        if (array[i][1] <= 1 && array[i][1] >= -1) {
            print[(int)(array[i][1] * 12.5 + 12)][(int)(array[i][0] * 6.3)] = 1;
        }
        free(tokens);
    }

    for (int i = 24; i >= 0; i--) {
        for (int j = 0; j < 80; j++) {
            if (print[i][j] == 1) {
                printf("*");
            } else {
                printf(".");
            }
            if (j == 79) {
                printf("\n");
            }
        }
    }
    return 0;



*/