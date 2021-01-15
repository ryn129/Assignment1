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

void pushTail(int num){
  Node *temp = buatNode(num);
  if(!head){ 
  head = tail = temp;
  } 
  else{ 
  tail->next = temp; 
  tail = temp; 
  }
}

int findmid(Node *head, int x){ 
    Node *curr = head;
    int temp = 0;
    while(curr != NULL){ 
    if(temp == x)
    {
    return curr->num;
    } 
    curr = curr->next; 
    temp++;
    } 
}


int main(){
	int data,angka;
	scanf("%d", &data);
	for(int i = 0; i < data; i++){
		scanf("%d", &angka);
		pushTail(angka);
	}
	printf("Mid: %d", findmid(head,(data/2)));

	return 0;
}