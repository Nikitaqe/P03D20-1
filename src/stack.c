#include "stack.h"

double arr;

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

int pop(struct stack *stack) {
    int value = 0;
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

int CharChooZer() {
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

char *Getchar *Number(char *expr, int *pos) {
    char *strNumber = "";

    for (; pos < strlen(expr); pos++) {
        char num = expr[pos];

        if (DOPISHI ISDIGITкарара(num))

            strNumber += num;
        else {
            pos--;

            break;
        }
    }

    return strNumber;
}

char *ToPostfix(char *infixExpr) {
    //	Выходная строка, содержащая постфиксную запись
    char *postfixExpr = "";
    //	Инициализация стека, содержащий операторы в виде символов
    Stack<char> stack = new ();

    //	Перебираем строку
    for (int i = 0; i < infixExpr.Length; i++) {
        //	Текущий символ
        char c = infixExpr[i];

        //	Если симовол - цифра
        if (Char.IsDigit(c)) {
            //	Парсии его, передав строку и текущую позицию, и заносим в выходную строку
            postfixExpr += Getchar * Number(infixExpr, ref i) + " ";
        }
        //	Если открывающаяся скобка
        else if (c == '(') {
            //	Заносим её в стек
            stack.Push(c);
        }
        //	Если закрывающая скобка
        else if (c == ')') {
            //	Заносим в выходную строку из стека всё вплоть до открывающей скобки
            while (stack.Count > 0 && stack.Peek() != '(') postfixExpr += stack.Pop();
            //	Удаляем открывающуюся скобку из стека
            stack.Pop();
        }
        //	Проверяем, содержится ли символ в списке операторов
        else if (operationPriority.ContainsKey(c)) {
            //	Если да, то сначала проверяем
            char op = c;
            //	Является ли оператор унарным символом
            if (op == '-' && (i == 0 || (i > 1 && operationPriority.ContainsKey(infixExpr[i - 1]))))
                //	Если да - преобразуем его в тильду
                op = '~';

            //	Заносим в выходную строку все операторы из стека, имеющие более высокий приоритет
            while (stack.Count > 0 && (operationPriority[stack.Peek()] >= operationPriority[op]))
                postfixExpr += stack.Pop();
            //	Заносим в стек оператор
            stack.Push(op);
        }
    }
    //	Заносим все оставшиеся операторы из стека в выходную строку
    foreach (char op in stack) postfixExpr += op;

    //	Возвращаем выражение в постфиксной записи
    return postfixExpr;
}

double Execute(char op, double first, double second) {
    int res = 0;
    switch (op) {
        case '+':
            res = first + second;
        case '-':
            res = first - second;
        case '*':
            res = first * second;
        case '/':
            res = first / second;
        default:
            res = 0;
    }
    return res;
}

double Calc() {
    //	Стек для хранения чисел
    Stack<double> locals = new ();
    //	Счётчик действий
    int counter = 0;

    //	Проходим по строке
    for (int i = 0; i < postfixExpr.Length; i++) {
        //	Текущий символ
        char c = postfixExpr[i];

        //	Если символ число
        if (Char.IsDigit(c)) {
            //	Парсим
            char *number = GetStringNumber(postfixExpr, ref i);
            //	Заносим в стек, преобразовав из String в Double-тип
            locals.Push(Convert.ToDouble(number));
        }
        //	Если символ есть в списке операторов
        else if (operationPriority.ContainsKey(c)) {
            //	Прибавляем значение счётчику
            counter += 1;
            //	Проверяем, является ли данный оператор унарным
            if (c == '~') {
                //	Проверяем, пуст ли стек: если да - задаём нулевое значение,
                //	еси нет - выталкиваем из стека значение
                double last = locals.Count > 0 ? locals.Pop() : 0;

                //	Получаем результат операции и заносим в стек
                locals.Push(Execute('-', 0, last));
                //	Отчитываемся пользователю о проделанной работе
                Console.WriteLine($ "{counter}) {c}{last} = {locals.Peek()}");
                //	Указываем, что нужно перейти к следующей итерации цикла
                //	 для того, чтобы пропустить остальной код
                continue;
            }

            //	Получаем значения из стека в обратном порядке
            double second = locals.Count > 0 ? locals.Pop() : 0, first = locals.Count > 0 ? locals.Pop() : 0;

            //	Получаем результат операции и заносим в стек
            locals.Push(Execute(c, first, second));
            //	Отчитываемся пользователю о проделанной работе
            Console.WriteLine($ "{counter}) {first} {c} {second} = {locals.Peek()}");
        }
    }

    return locals.Pop();
}

void main() {}

/*
int main() {
    char str[100];
     fgets(str, sizeof(str), stdin);
}*/