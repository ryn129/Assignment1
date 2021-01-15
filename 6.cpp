#include<stdio.h>
#include<stdlib.h>

struct Node{
    int num;
    Node *next;
}*head,*tail;

Node *buatNode(int num){
    Node *Nodebaru=(Node*)malloc(sizeof(Node));
    Nodebaru->num=num;
    Nodebaru->next=NULL;

    return Nodebaru;
}

void pushTail(int num) {
  Node *temp = buatNode(num);
  if(!head) 
  { 
    head = tail = temp;
  } else 
  { 
    tail->next = temp; 
    tail = temp; 
  }
}

void swap(struct Node *a, struct Node *b) 
{ 
    int temp = a->num; 
    a->num = b->num; 
    b->num = temp; 
} 
void bubbleSort(struct Node *head) 
{ 
    int swapped, i; 
    struct Node *ptr1; 
    struct Node *lptr = NULL; 
    if (head == NULL) 
        return; 
    do
    { 
        swapped = 0; 
        ptr1 = head; 
        while (ptr1->next != lptr) 
        { 
            if (ptr1->num < ptr1->next->num) 
            {  
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
} 


void printlinkedlist(){
    Node *curr=head;
    if(!head)
    {
        return;
    } else
    {
        curr = head;
        while(curr)
        {
            printf("%d ", curr->num);
            curr = curr->next;
        }
    }   
}

int main(){

    int data,angka,a;
    scanf("%d",&data);getchar();
    for(int i=0;i<data;i++){
    scanf("%d",&angka);getchar();
    pushTail(angka);
    }
    bubbleSort(head);
    printlinkedlist();
    return 0;
}
