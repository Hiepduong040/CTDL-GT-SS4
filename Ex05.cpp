#include <stdio.h>
#include <stdlib.h>

// dinh nghia cau truc node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// ham tao 1 node moi
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Khong the cap phat bo nho\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// ham chen node vao vi tri xac dinh
Node* insertAtPosition(Node* head, int value, int position) {
    Node* newNode = createNode(value);

    if (position == 0) { // Neu chen o vi tri dau tien
        newNode->next = head;
        return newNode;
    }

    Node* temp = head;
    int index = 0;

    // Duyet danh sach de tim vi tri can chen
    while (temp != NULL && index < position - 1) {
        temp = temp->next;
        index++;
    }

    if (temp == NULL) { // Vi tri vuot qua do dai danh sach
        printf("Vi tri nam ngoai pham vi danh sach\n");
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

// ham in danh sach lien ket
void printList(Node* head) {
    if (head == NULL) {
        printf("Danh sach trong\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;

    // Tao danh sach lien ket ban dau
    head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);

    // Hien thi danh sach ban dau
    printf("Danh sach ban dau: ");
    printList(head);

    // Chen node vao vi tri xac dinh
    int value, position;
    printf("Nhap gia tri can chen: ");
    scanf("%d", &value);
    printf("Nhap vi tri can chen: ");
    scanf("%d", &position);

    head = insertAtPosition(head, value, position);

    // Hien thi danh sach sau khi chen
    printf("Danh sach sau khi chen: ");
    printList(head);

    return 0;
}

