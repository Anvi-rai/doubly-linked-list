#include <stdio.h>
#include <stdlib.h>

// Define a structure for a doubly linked list node
struct Node {
    int data;  // Change this data type as needed
    struct Node* next;
    struct Node* prev;
};

// Define a structure for a doubly linked list-based stack
struct Stack {
    struct Node* top;
};

// Function to create an empty stack
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

// Function to push an item onto the stack
void push(struct Stack* stack, int data) {  // Change the data type as needed
    // Allocate memory for a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    // Set the data of the new node
    newNode->data = data;

    // Adjust pointers for the new node
    newNode->next = stack->top;
    newNode->prev = NULL;

    // If the stack is not empty, adjust the previous pointer of the current top node
    if (!isEmpty(stack)) {
        stack->top->prev = newNode;
    }

    // Make the new node the top of the stack
    stack->top = newNode;
}

// Function to pop an item from the stack
int pop(struct Stack* stack) {
    // Check if the stack is empty
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1; // Return -1 for an empty stack
    }

    // Get the data of the top node
    int data = stack->top->data;

    // Save the reference to the top node
    struct Node* temp = stack->top;

    // Move the top pointer to the next node
    stack->top = stack->top->next;

    // If the new top is not null, adjust its previous pointer
    if (stack->top != NULL) {
        stack->top->prev = NULL;
    }

    // Free the memory of the popped node
    free(temp);

    return data;
}

// Function to display the elements of the stack
void displayStack(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack: ");
    struct Node* current = stack->top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to free the memory used by the stack
void destroyStack(struct Stack* stack) {
    while (!isEmpty(stack)) {
        pop(stack);
    }
    free(stack);
}

int main() {
    // Create a stack
    struct Stack* stack = createStack();

    // Push elements onto the stack
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    // Display the stack
    displayStack(stack);

    // Pop elements from the stack
    int popped1 = pop(stack);
    int popped2 = pop(stack);

    // Display the popped elements
    printf("Popped elements: %d, %d\n", popped1, popped2);

    // Display the updated stack
    displayStack(stack);

    // Free the memory used by the stack
    destroyStack(stack);

    return 0;
}

