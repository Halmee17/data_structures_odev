#include <stdio.h>
#include <ctype.h>

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int main() {
    char infix[50], stack[50], postfix[50];
    int top = -1, k = 0;

    printf("Infix: ");
    scanf("%s", infix);

    for (int i = 0; infix[i]; i++) {
        char ch = infix[i];

        if (isalnum(ch)) {
            postfix[k++] = ch;
        } else if (ch == '(') {
            stack[++top] = ch;
        } else if (ch == ')') {
            while (top != -1 && stack[top] != '(')
                postfix[k++] = stack[top--];
            top--;
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(ch))
                postfix[k++] = stack[top--];
            stack[++top] = ch;
        }
    }

    while (top != -1)
        postfix[k++] = stack[top--];

    postfix[k] = '\0';
    printf("Postfix: %s\n", postfix);

    return 0;
}
