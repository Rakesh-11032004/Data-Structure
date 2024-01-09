#include <stdio.h>
#include <stdlib.h>


#define MAX_SIZE 10


struct Stack {
    int array[MAX_SIZE];
    int top;
};


void initialize(struct Stack *stack) {
    stack->top = -1;
}


int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}


int isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}



void push(struct Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow! Cannot push %d\n", value);
        return;
    }

    stack->array[++stack->top] = value;
    printf("%d pushed to the stack\n", value);
}


int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow! Cannot pop from an empty stack\n");
        return -1; 
    }

    return stack->array[stack->top--];
}


int peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty, cannot peek\n");
        return -1; 
    }

    return stack->array[stack->top];
}


void display(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

int main() {
    struct Stack myStack;
    initialize(&myStack);

    int choice, value;


    do {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(&myStack, value);
                break;

            case 2:
                value = pop(&myStack);
                if (value != -1)
                    printf("Popped value: %d\n", value);
                break;

            case 3:
                value = peek(&myStack);
                if (value != -1)
                    printf("Peeked value: %d\n", value);
                break;

            case 4:
                display(&myStack);
                break;

            case 5:
                printf("Exiting the program\n");
                break;

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}
