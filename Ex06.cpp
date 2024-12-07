#include <stdio.h>
#include <stdlib.h>

// Dinh nghia cau truc node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Ham tao 1 node moi
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

// Ham xoa node tai vi tri xac dinh
Node* deleteAtPosition(Node* head, int position) {
    if (head == NULL) {
        printf("Danh sach trong\n");
        return head;
    }

    if (position == 0) { // Xoa node dau tien
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node* temp = head;
    int index = 0;

    // Duyet den node truoc vi tri can xoa
    while (temp != NULL && index < position - 1) {
        temp = temp->next;
        index++;
    }

    if (temp == NULL || temp->next == NULL) { // Vi tri nam ngoai pham vi danh sach
        printf("Vi tri khong hop le\n");
        return head;
    }

    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);

    return head;
}

// Ham in danh sach lien ket
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
    head->next->next->next = createNode(40);

    // Hien thi danh sach ban dau
    printf("Danh sach ban dau: ");
    printList(head);

    // Xoa node tai vi tri xac dinh
    int position;
    printf("Nhap vi tri can xoa: ");
    scanf("%d", &position);

    head = deleteAtPosition(head, position);

    // Hien thi danh sach sau khi xoa
    printf("Danh sach sau khi xoa: ");
    printList(head);

    return 0;
}

