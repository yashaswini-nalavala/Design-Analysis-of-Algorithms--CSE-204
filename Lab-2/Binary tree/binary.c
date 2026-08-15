#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

struct Node* minNode(struct Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct Node* delete(struct Node* root, int data) {
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = delete(root->left, data);
    else if (data > root->data)
        root->right = delete(root->right, data);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }

        if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = minNode(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }

    return root;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, data, n, i;

    while (1) {
        printf("\n\n1. Create BST");
        printf("\n2. Insert");
        printf("\n3. Delete");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                root = NULL;
                printf("Enter number of nodes: ");
                scanf("%d", &n);

                printf("Enter elements: ");
                for (i = 0; i < n; i++) {
                    scanf("%d", &data);
                    root = insert(root, data);
                }
                printf("BST created.");
                break;

            case 2:
                printf("Enter element to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                printf("Element inserted.");
                break;

            case 3:
                printf("Enter element to delete: ");
                scanf("%d", &data);
                root = delete(root, data);
                printf("Element deleted if present.");
                break;

            case 4:
                printf("Inorder: ");
                inorder(root);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice.");
        }
    }

    return 0;
}