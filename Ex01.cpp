#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Không the cap phat bo nho!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

Node* createLinkedList(int n) {
    if (n <= 0) {
        return NULL;
    }

    int value;
    printf("Nhap gia tri cho phan tu : ");
    scanf("%d", &value);

    Node* head = createNode(value);
    Node* current = head;

    for (int i = 2; i <= n; i++) {
        printf("Nhap gia tri cho phan tu %d: ", i);
        scanf("%d", &value);

        current->next = createNode(value);
        current = current->next;
    }

    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n;

    printf("Nhap so luong phan tu t?: ");
    scanf("%d", &n);

    if (n == 0) {
        printf("Danh sach trong\n");
        return 0;
    }

    Node* head = createLinkedList(n);

    printf("Danh sach lien ket: ");
    printList(head);

    freeList(head);

    return 0;
}

