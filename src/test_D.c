#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Function to check if a character is an operator
int isOperator(char c) { return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^'); }

int isOperand(char c, char *infix, int i) {  //проерка на вхождение оператора в выражение
    return ((c == 's' && i + 2 < (int)strlen(infix) && infix[i + 1] == 'i' && infix[i + 2] == 'n') ||
            (c == 'c' && i + 2 < (int)strlen(infix) && infix[i + 1] == 'o' && infix[i + 2] == 's') ||
            (c == 't' && i + 2 < (int)strlen(infix) && infix[i + 1] == 'a' && infix[i + 2] == 'n') ||
            (c == 'c' && i + 2 < (int)strlen(infix) && infix[i + 1] == 't' && infix[i + 2] == 'g') ||
            (c == 's' && i + 2 < (int)strlen(infix) && infix[i + 1] == 'q' && infix[i + 2] == 'r' &&
             infix[i + 3] == 't') ||
            (c == 'l' && i + 2 < (int)strlen(infix) && infix[i + 1] == 'n'));
}

char res_char(char *infix, int i, char c) {  //возвращение результатов сокращенно
    char res = '0';
    if (c == 's' && i + 2 < (int)strlen(infix) && infix[i + 1] == 'i' && infix[i + 2] == 'n') {
        res = 's';
    } else if (c == 'c' && i + 2 < (int)strlen(infix) && infix[i + 1] == 'o' && infix[i + 2] == 's') {
        res = 'c';
    } else if (c == 't' && i + 2 < (int)strlen(infix) && infix[i + 1] == 'a' && infix[i + 2] == 'n') {
        res = 't';
    } else if (c == 'c' && i + 2 < (int)strlen(infix) && infix[i + 1] == 't' && infix[i + 2] == 'g') {
        res = 'C';
    } else if (c == 's' && i + 3 < (int)strlen(infix) && infix[i + 1] == 'q' && infix[i + 2] == 'r' &&
               infix[i + 3] == 't') {
        res = 'S';
    } else if (c == 'l' && i + 1 < (int)strlen(infix) && infix[i + 1] == 'n') {
        res = 'l';
    } else {
        res = c;
    }
    return res;
}

// Function to get the precedence of an operator
int getPrecedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}

// Function to convert infix to postfix
void convertToPostfix(char *infix, char *postfix) {
    int i, j = 0, top = -1;
    char stack[MAX_SIZE] = {'0'}, num[MAX_SIZE];
    for (i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];
        if (c == ' ') continue;
        if (c == 'x') {
            postfix[j++] = 'x';
            postfix[j++] = ' ';
            continue;
        }
        if ((c >= '0' && c <= '9') || c == '-') {
            int k = 0;
            if (c == '-') {
                num[k++] = c;
                c = infix[++i];
            }
            while (c >= '0' && c <= '9') {
                num[k++] = c;
                c = infix[++i];
            }
            num[k] = '\0';
            for (int l = 0; l < k; l++) postfix[j++] = num[l];
            postfix[j++] = ' ';
            i--;  // откатываемся на предыдущий символ
        } else if (isOperator(c) || isOperand(c, infix, i)) {
            while (top != -1 && isOperator(stack[top]) && getPrecedence(stack[top]) >= getPrecedence(c)) {
                postfix[j++] = stack[top--];
                postfix[j++] = ' ';
            }
            char res = res_char(infix, i, c);
            if (res != '0') {
                stack[++top] = res;
                i++;
            }
        } else if (c == '(') {
            stack[++top] = c;
        } else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = stack[top--];
                postfix[j++] = ' ';
            }
            if (top != -1 && stack[top] == '(') top--;
        }
    }
    while (top != -1) {
        postfix[j++] = stack[top--];
        postfix[j++] = ' ';
    }
    postfix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    printf("Enter an infix expression: ");
    fgets(infix, MAX_SIZE, stdin);

    convertToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}