#include <stdio.h>
#include <stdlib.h>
struct Node{
    int num;
    Node *next; 

} *head, *tail;

Node *buatNode(int num){
    Node *Nodebaru = (Node*)malloc(sizeof(Node));
    Nodebaru->num = num;
    Nodebaru->next = NULL;
    return Nodebaru;
}

void pushHead(int num){
    Node *temp = buatNode(num);
    if(!head){
    head = tail = temp;
    }
    else{
    temp->next = head;
    head = temp;
    }
}

void RemoveDuplicates(Node *head){
    Node *ptr1, *ptr2, *dup;
    ptr1 = head;
 
    while (ptr1 != NULL && ptr1->next != NULL){
    ptr2 = ptr1;
    while (ptr2->next != NULL){
    if (ptr1->num == ptr2->next->num){
        dup = ptr2->next;
        ptr2->next = ptr2->next->next;
        delete(dup);
        }
        else{
        ptr2 = ptr2->next;
        }
        }
    ptr1 = ptr1->next;
    }
}

void printlinkedlist(){
    Node *curr=head;
    if(!head){
    return;
    } 
    else{
    curr = head;
    while(curr){
        printf("%d ", curr->num);
        curr = curr->next;
        }
    }   
}

int main(){
	int n, temp;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &temp);
		pushHead(temp);
    }
	RemoveDuplicates(head);
	printlinkedlist();
	return 0;
}