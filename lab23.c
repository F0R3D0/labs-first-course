#include <stdio.h>
#include <stdlib.h>

// Определение структуры для узла двоичного дерева
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Функция для создания нового узла дерева
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Функция для поиска минимального значения в дереве
int findMin(struct node* root) {
    if (root == NULL) {
        return -1; // если дерево пустое, вернуть -1
    }
    else if (root->left == NULL) {
        return root->data; // если левого поддерева нет, то корень - минимальное значение
    }
    else {
        return findMin(root->left); // иначе рекурсивно обойти левое поддерево
    }
}

// Функция для вычисления глубины узла в дереве
int findDepth(struct node* root, int key, int depth) {
    if (root == NULL) {
        return -1; // если дерево пустое, вернуть -1
    }
    else if (root->data == key) {
        return depth; // если нашли узел, вернуть его глубину
    }
    else {
        int leftDepth = findDepth(root->left, key, depth + 1); // рекурсивный вызов для левого поддерева
        if (leftDepth != -1) {
            return leftDepth; // если узел был найден в левом поддереве, вернуть его глубину
        }
        else {
            return findDepth(root->right, key, depth + 1); // иначе рекурсивный вызов для правого поддерева
        }
    }
}

int main() {
    struct node *root = createNode(5);
    root->left = createNode(3);
    root->right = createNode(7);
    root->left->left = createNode(2);
    root->left->right = createNode(4);
    root->right->left = createNode(6);
    root->right->right = createNode(8);

    int min = findMin(root);
    int depth = findDepth(root, min, 0);

    printf("Минимальное значение в дереве: %d\n", min);
    printf("Глубина минимального значения: %d\n", depth);

    return 0;
}