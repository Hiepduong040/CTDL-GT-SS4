#include<stdio.h>
 #include<stdlib.h>
 
// dinh nghia not Node
typedef struct Node{
	int data; // phan du lieu cua node 
	struct Node* next;  // con tro tro den nut tiep theo  
} Node; 


// tao 1 Node moi:
Node* createNode(int value){
	// cap phat bo nho 
	Node * newNode = (Node*) malloc(sizeof(Node));
	// gan data cho node 
	newNode->data = value;
	// gan phan link
	newNode-> next = NULL;
	return newNode;  
	  
} 
 
 // them 1 phan tu vao dau list
 void insertAtHead( Node** head, int value){
 	// tao node moi
	Node* newNode = createNode(value);
	// tro node mo cho head
	newNode-> next = *head;
	// cap nhat head tro den node moi
	*head = newNode;
	
 } 
 
 //them 1 phan tu vao vi tri bat ky
 
 void insertElement(Node** head, int value, int position){
 	Node* newNode = createNode(value);
	if(position == 0){
  		newNode -> next = *head ;
  		*head = newNode; 
	  	return; 
  	} 
	Node* temp = *head;
  	for(int i; i < position - 1 && temp != NULL; i++){
  		temp = temp -> next; 
   }
   newNode -> next = temp;
   temp -> next = newNode;	 
	
 } 
 
 
 // them 1 phan tu vao cuoi danh sach
 void insertEnd(Node** head, int value){
 	// tao node moi 
	Node* newNode = createNode(value);
	if(*head == NULL){
		*head = newNode;
		return; 
	}
	Node* temp = *head;
	while(temp -> next != NULL){
		temp = temp -> next;
	
	} 
		temp -> next = newNode ;
	 
 } 
 
 
// duyet danh sach - khi lay ra de dung thi chi can *, khi can thay doi thi dung ** 
void printList(Node* head){
	Node* temp = head;
	while(temp!= NULL){
		
		printf("%d ", temp->data);
//		printf("%d", *temp);
		temp = temp->next ;
	} 
	printf(" --->NULL") ;
} 

 
 
  
int main(){
	Node* head = NULL;
	int value; 
	do{
		printf("==================MENU====================\n"); 
		printf(".1 them phan tu vao dau :\n");
		printf(".2 Xem danh sach :\n");
		printf(".3 Them phan tu vao cuoi danh sach\n ");
		printf(".4 Them phan tu tai vi tri bat ky\n ");
		printf(".5 Thoat\n ");
		printf(". ");
		int choice;
		scanf("%d", &choice); 
		switch (choice){
			case 1:
				// Them mot phan tu vao dau danh sach
				printf("Moi ban nhap phan tu vao dau :");
				int value; 
				scanf("%d", &value);
				insertAtHead(&head, value);
				break; 
			case 2: 
				// in ra 
				printf("Danh sach ne \n");
				printList(head);
				break;
			case 3: 
				printf("Moi ban nhap 1 phan tu vao cuoi danh sach");
				scanf("%d", &value);
				insertEnd(&head, value);
			case 4:
				printf("Moi ban nhap vao vi tri can them");
				int position; 
				scanf("%d",&position);
				printf("Nhap vao gia tri can them"); 
				scanf("%d", &value);
				insertElement(&head, value, position);
				break; 
			case 5: 
				exit(0); 
			default:
				printf("vui long chon lai nhe"); 
		} 
	
	} while(1==1); 
	return 0;
	 
} 

// khoi tao Node

// Them phan tu vao dau dnah sach 
