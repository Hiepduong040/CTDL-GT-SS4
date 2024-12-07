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
        // Neu danh sach rong, node moi la head
        return newNode;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next; // Di chuyen den cuoi danh sach
    }
    temp->next = newNode; // Gan node moi vao cuoi
    return head;
}

// ham xoa phan tu dau danh sach
Node* deleteHead(Node* head) {
    if (head == NULL) {
        printf("Danh sach rong, khong the xoa\n");
        return NULL;
    }
    Node* temp = head; // Luu lai node dau de giai phong bo nho
    head = head->next; // Di chuyen head toi node ke tiep
    free(temp); // Giai phong node dau
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

    // xoa phan tu dau danh sach
    head = deleteHead(head);

    // hien thi danh sach sau khi xoa
    printf("Danh sach sau khi xoa phan tu dau: ");
    printList(head);

    return 0;
}

