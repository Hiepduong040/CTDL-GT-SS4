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

// ham them phan tu vao cuoi danh sach lien ket
Node* addToTail(Node* head, int value) {
    Node* newNode = createNode(value);
    if (head == NULL) {
        return newNode; // Neu danh sach rong, node moi la head
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next; // Di chuyen den cuoi danh sach
    }
    temp->next = newNode; // Gan node moi vao cuoi
    return head;
}

// ham tim kiem phan tu trong danh sach lien ket
int searchElement(Node* head, int value) {
    int index = 0;
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == value) {
            return index; // Tra ve vi tri neu tim thay
        }
        temp = temp->next;
        index++;
    }
    return -1; // Neu khong tim thay
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
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    Node* head = NULL;

    // nhap n phan tu vao danh sach
    for (int i = 0; i < n; i++) {
        int value;
        printf("Nhap gia tri phan tu thu %d: ", i + 1);
        scanf("%d", &value);
        head = addToTail(head, value);
    }

    // hien thi danh sach sau khi nhap
    printf("Danh sach sau khi nhap: ");
    printList(head);

    // nhap gia tri can tim
    int searchValue;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &searchValue);

    // tim kiem gia tri
    int result = searchElement(head, searchValue);
    if (result != -1) {
        printf("Tim thay gia tri %d o vi tri: %d\n", searchValue, result);
    } else {
        printf("Khong tim thay gia tri %d\n", searchValue);
    }

    return 0;
}

