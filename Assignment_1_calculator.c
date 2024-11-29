#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define STACK_SIZE 100

// Structure for character stack
typedef struct {
    char items[STACK_SIZE];
    int topIndex;
} CharStack;

// Structure for integer stack
typedef struct {
    int items[STACK_SIZE];
    int topIndex;
} IntStack;

// Functions for character stack
void charStackPush(CharStack *stack, char ch) {
    if (stack->topIndex == STACK_SIZE - 1) return;
    stack->items[++(stack->topIndex)] = ch;
}

char charStackPop(CharStack *stack) {
    if (stack->topIndex == -1) return '\0';
    return stack->items[(stack->topIndex)--];
}

char charStackPeek(CharStack *stack) {
    if (stack->topIndex == -1) return '\0';
    return stack->items[stack->topIndex];
}

int charStackIsEmpty(CharStack *stack) {
    return stack->topIndex == -1;
}

// Functions for integer stack
void intStackPush(IntStack *stack, int value) {
    if (stack->topIndex == STACK_SIZE - 1) return;
    stack->items[++(stack->topIndex)] = value;
}

int intStackPop(IntStack *stack) {
    if (stack->topIndex == -1) return 0; // Default fallback value
    return stack->items[(stack->topIndex)--];
}

// Operator precedence
int getPrecedence(char op) {
   
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;

    }


// Determine if a character is an operator
int isMathOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// check whether Expression is valid or not
int isExpressionValid(const char *expression) {
	int i;
    for (i = 0; expression[i] != '\0'; i++) {
        if (!isdigit(expression[i]) && !isMathOperator(expression[i]) && !isspace(expression[i])) {
            return 0;
        }
    }
    return 1;
}

// Convert infix expression to postfix expression
void convertInfixToPostfix(char *infix, char *postfix) {
    CharStack stack;
    stack.topIndex = -1;
    int infixIdx = 0, postfixIdx = 0;

    while (infix[infixIdx] != '\0') {
        char current = infix[infixIdx];

        if (isspace(current)) {
            infixIdx++;
            continue;
        }

        if (isdigit(current)) {
            while (isdigit(infix[infixIdx])) {
                postfix[postfixIdx++] = infix[infixIdx++];
            }
            postfix[postfixIdx++] = ' ';
        } else if (isMathOperator(current)) {
            while (!charStackIsEmpty(&stack) &&
                   getPrecedence(charStackPeek(&stack)) >= getPrecedence(current)) {
                postfix[postfixIdx++] = charStackPop(&stack);
                postfix[postfixIdx++] = ' ';
            }
            charStackPush(&stack, current);
            infixIdx++;
        }
    }

    while (!charStackIsEmpty(&stack)) {
        postfix[postfixIdx++] = charStackPop(&stack);
        postfix[postfixIdx++] = ' ';
    }

    postfix[postfixIdx] = '\0';
}

// Evaluate a postfix expression
int evaluatePostfixExpression(const char *postfix, int *errorFlag) {
    IntStack stack;
    stack.topIndex=-1;
int i;
    for ( i = 0; postfix[i] != '\0';) {
        char current = postfix[i];

        if (isspace(current)) {
            i++;
            continue;
        }

        if (isdigit(current)) {
            int num = 0;
            while (isdigit(postfix[i])) {
                num = num * 10 + (postfix[i++] - '0');
            }
            intStackPush(&stack, num);
        } else if (isMathOperator(current)) {
            int operand2 = intStackPop(&stack);
            int operand1 = intStackPop(&stack);

            if (current == '/' && operand2 == 0) {
                *errorFlag = 1;
                return 0;
            }

            int result = 0;
            switch (current) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': result = operand1 / operand2; break;
            }

            intStackPush(&stack, result);
        }

        i++;
    }

    return intStackPop(&stack);
}

int main() {
    char infixExpression[STACK_SIZE], postfixExpression[STACK_SIZE];
    int errorFlag = 0;

    printf("Enter a mathematical expression: ");
    fgets(infixExpression, sizeof(infixExpression), stdin);
    infixExpression[strcspn(infixExpression, "\n")] = '\0';

    if (!isExpressionValid(infixExpression)) {
        printf("Error: Invalid input expression.\n");
        return 1;
    }

    convertInfixToPostfix(infixExpression, postfixExpression);
    int result = evaluatePostfixExpression(postfixExpression, &errorFlag);

    if (errorFlag) {
        printf("Error: Division by zero encountered.\n");
    } else {
        printf("The result is: %d\n", result);
    }

    return 0;
}

