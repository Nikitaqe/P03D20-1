// t.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// функция CharChooZer
int CharChooZer(char op) {
    int priority = 0;
    switch (op) {
        case '(':
            priority = 0;
            break;
        case '+':
        case '-':
            priority = 1;
            break;
        case '*':
        case '/':
            priority = 2;
            break;
        case '^':
            priority = 3;
            break;
        case '~':
            priority = 4;
            break;
        default:
            priority = -1;
    }
    return priority;
}

// функция isDigit
void isDigit(char *input) {
    if ((*input >= '0' && *input <= '9') || *input == '.') {
        char *num_str = malloc(20 * sizeof(char));
        int num_len = 0;
        while ((*input >= '0' && *input <= '9') || *input == '.') {
            num_str[num_len++] = *input;
            input++;
        }
        num_str[num_len] = '\0';
        printf("Digit: %s\n", num_str);
        free(num_str);
    }
}

// функция res
int res(char *str) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (CharChooZer(str[i]) < 0) {
            isDigit(&str[i]);
        }
    }
    return 0;
}

int main() {
    // тестирование функций
    char str[] = "123+456*789";
    printf("Input: %s\n", str);
    res(str);
    return 0;
}