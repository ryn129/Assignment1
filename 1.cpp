#include <stdio.h>
#include <stdlib.h>

struct Node{
    int num;
    Node *next; 
} *head, *tail, *curr;

Node *buatNode(int num){
    Node *Nodebaru = (Node*)malloc(sizeof(Node));
    Nodebaru->num = num;
    Nodebaru->next = NULL;
    return Nodebaru;
}

void push(Node** head, int num){ 
    Node* node = (Node*) malloc(sizeof(Node)); 
    node->num = num; 
    node->next = *head; 
    *head = node; 
} 

void swap(Node *a,Node *b){ 
    int temp = a->num; 
    a->num = b->num; 
    b->num = temp; 
}

void BubbleSort(Node *head){ 
    int swapped, i; 
    Node *ptr1; 
    Node *lptr = NULL; 
    if (head == NULL){ 
        return; 
    }
    do
    { 
        swapped = 0; 
        ptr1 = head; 
        while (ptr1->next != lptr){ 
            if (ptr1->num < ptr1->next->num){  
            swap(ptr1, ptr1->next); 
             swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
} 

Node* gabung(Node* h1, Node* h2){ 
    if (!h1){
    	return h2; 
	}
    if (!h2){
    	return h1;
	}
    if (h1->num > h2->num){ 
        h1->next = gabung(h1->next, h2); 
        return h1; 
    } 
    else{ 
        h2->next = gabung(h1, h2->next); 
        return h2; 
    } 
} 

void printList(Node* head, int x){
    Node* ptr = head;
    int temp = 0;
    while (ptr){
    	if(temp == x-1){
    		printf("%d", ptr->num);
        	ptr = ptr->next;
		}
        else{
			printf("%d ", ptr->num);
       		ptr = ptr->next;
		}
		temp++;
    }
}

int main(){
	int data1, data2, temp;
	Node* head1 = NULL, *head2 = NULL;
	scanf("%d", &data1);
	for(int i = 0; i < data1; i++){
		scanf("%d",&temp);
		push(&head1,temp);
	}
	scanf("%d", &data2);
	for(int j = 0; j < data2; j++){
		scanf("%d",&temp);
		push(&head2,temp);
	}
    BubbleSort(head1);
	BubbleSort(head2);
	Node* final =gabung(head1, head2);
	printList(final, data1+data2);
	return 0;
}