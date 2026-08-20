#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* top = NULL;
void push(int value);
int pop();
int peek();
void display();
int isEmpty();

int main() {
    int choice, value;

    printf("--- Stack Operations Using Linked List ---\n");
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                value = pop();
                if (value != -1) {
                    printf("Popped element: %d\n", value);
                }
                break;
            case 3:
                value = peek();
                if (value != -1) {
                    printf("Top element: %d\n", value);
                }
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program...\n");
                // Free remaining memory before exiting
                while (!isEmpty()) {
                    pop();
                }
                exit(0);
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }
    return 0;
}
int isEmpty() {
    return top == NULL;
}

void push(int value) {
    
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    
    if (newNode == NULL) {
        printf("Stack Overflow! Cannot push %d (Out of memory).\n", value);
        return;
    }
    
    newNode->data = value;      
    newNode->next = top;       
    top = newNode;             
    printf("%d successfully pushed to stack.\n", value);
}
int pop() {
    if (isEmpty()) {
        printf("Stack Underflow! The stack is empty.\n");
        return -1; 
    }
    
    struct Node* temp = top;   
    int poppedValue = top->data; 
    top = top->next;            
    free(temp);               
    return poppedValue;
}
int peek() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return -1;
    }
    return top->data;
}
void display() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return;
    }
    
    struct Node* temp = top;
    printf("Stack elements (Top -> Bottom):\n");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}