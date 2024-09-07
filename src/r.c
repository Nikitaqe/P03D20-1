#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double *arr[1];

struct node {
    char *value;
    struct node *next;
};

struct stack {
    struct node *first;
    struct node *last;
};

struct stack *init() {
    struct stack *stack = malloc(sizeof(struct stack));
    stack->first = NULL;
    stack->last = NULL;
    return stack;
}

void push(struct stack *stack, char *new_value) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->value = new_value;
    new_node->next = NULL;
    if (NULL == stack->first) {
        stack->first = new_node;
    } else {
        new_node->next = stack->last;
    }
    stack->last = new_node;
}

char *pop(struct stack *stack) {
    char *value = NULL;
    if (stack->last != NULL) {
        struct node *last_node = stack->last;
        value = last_node->value;
        stack->last = last_node->next;
        free(last_node);
    }
    return value;
}

void destroy(struct stack *stack) {
    struct node *cur_node = stack->last;
    struct node *next_node = NULL;
    while (NULL != cur_node) {
        next_node = cur_node->next;
        free(cur_node);
        cur_node = next_node;
    }
    free(stack);
}

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

int getNum(char *str) {
    int i = 0;
    int test = strchr(str, '.');
    while (str != '\0') {
        if (test == NULL) {
            arr = realloc(arr, sizeof(int));
            arr[i] = atoi(str);
            i++;
        } else {
            char *nstr = str;
            char *tstr;
            double d = 0;
            tstr = nstr;
            d = strtod(nstr, &nstr);
            if (d == 0 && tstr == nstr) break;
        }
    }
}

void res(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (CharChooZer(str[i]) < 0) {
            getNum(str);
        } else {
            push();
        }
    }
}

int main() {
    char expr[100];
    fgets(expr, sizeof(expr), stdin);

    res(expr);
    return 0;
}

/*
sin -> s
cos - c
tan - t
ctg - C
sqrt - S
ln - l
*/