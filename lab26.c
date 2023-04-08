#include <stdio.h>
#include <stdlib.h>

// Определяем структуру узла списка
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Функция создания нового узла списка
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Функция вставки нового узла в упорядоченный по возрастанию список
void insertNode(Node** head, int data) {
    Node* newNode = createNode(data);
    Node* current = *head;

    // Если список пуст или новый элемент меньше первого элемента, то вставляем новый элемент в начало списка
    if (*head == NULL || (*head)->data >= data) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // Иначе ищем место вставки нового элемента в отсортированный список
    while (current->next != NULL && current->next->data < data) {
        current = current->next;
    }

    // Вставляем новый элемент
    newNode->next = current->next;
    current->next = newNode;
}

// Функция вывода списка на экран
void printList(Node* head) {
    printf("List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Основная функция программы
int main() {
    Node* head = NULL;

    // Вставляем элементы в упорядоченный по возрастанию список
    insertNode(&head, 5);
    insertNode(&head, 1);
      printList(head);

    insertNode(&head, 7);
  printList(head);

    insertNode(&head, 3);
  printList(head);
  insertNode(&head, 3);
  printList(head);
    insertNode(&head, 9);

    // Выводим список на экран
    printList(head);

    return 0;
}
