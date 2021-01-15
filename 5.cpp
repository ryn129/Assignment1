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

int search(Node* head, int flg, int x){ 
    Node* current = head;
    int temp = 0;
    while(current != NULL){ 
        if(temp == flg-x){
            return current->num;
        } 
        current = current->next; 
        temp++;
    } 
    return 0;
}

int main(){
	int data,angka,flg= 0,find;
	scanf("%d", &data);
	for(int i = 0; i <data; i++){	
		scanf("%d", &angka);getchar();
		pushHead(angka);
		flg++;
	}
	scanf("%d", &find);getchar();
	printf("Valuenya adalah adalah %d",search(head,flg,find));
	return 0;
}