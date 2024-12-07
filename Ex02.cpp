#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Khong the cap phat bo nho");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

Node* addToHead(Node* head, int value) {
    Node* newNode = createNode(value);
    newNode->next = head;
    return newNode;
}

Node* addToTail(Node* head, int value) {  
    Node* newNode = createNode(value);
    if (head == NULL) {
        return newNode;  
    }
    
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;  
    }
    temp->next = newNode;  
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

int main() {
    int n;
    printf("Nhap n phan tu: ");
    scanf("%d", &n);
    
    Node* head = NULL;
    for (int i = 0; i < n; i++) {
        int value;
        printf("Nhap gia tri cua phan tu thu %d: ", i + 1);
        scanf("%d", &value);
        head = addToTail(head, value);  
    }
    
    printf("Danh sach sau khi nhap la: ");
    printList(head);
    
    int newValue;
    printf("Nhap gia tri can chen vao dau danh sach: ");
    scanf("%d", &newValue);
    head = addToHead(head, newValue);  
    
    printf("Danh sach sau khi chen la: ");
    printList(head);
    
    return 0;
}
