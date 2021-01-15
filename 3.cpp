#include <stdio.h>
#include <stdlib.h>
struct Node{
    int num;
    Node *next; 

} *head, *tail;

Node *createNode(int num){
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->num = num;
    temp->next = NULL;
    return temp;
}
void pushTail(int num) {
  Node *temp = createNode(num);
  if(!head) 
  { 
    head = tail = temp;
  } else 
  { 
    tail->next = temp; 
    tail = temp; 
  }
}

int findmid(Node *head, int x) { 
    Node * current = head;
    int temp = 0;
    while(current != NULL) 
    { 
        if(temp == x)
        {
            return current->num;
        } 
        current = current->next; 
        temp++;
    } 
}


int main()
{
	int data,angka;
	scanf("%d", &data);
	for(int i = 0; i < data; i++){
		scanf("%d", &angka);
		pushTail(angka);
	}
	printf("Mid: %d", findmid(head,(data/2)));

	return 0;
}