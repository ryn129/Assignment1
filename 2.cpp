#include<stdio.h>
#include<stdlib.h>

struct Node{
    int num;
    Node *next;
}*head,*tail;

Node *buatNode(int num){
   Node *newNode=(Node*)malloc(sizeof(Node));
   newNode->num=num;
   newNode->next=NULL;
    return newNode;
}

void pushHead(int num){
    Node *temp=buatNode(num);
    if(!head){
    head=tail=temp;
    }
    else{
    temp->next=head;
    head=temp;
    }
}


int minNode(Node* head){  
    Node *current = head;  
    int min;  
      
    if(!head){  
        return 0;  
    }  
    else{  
    min = head->num;  
          
    while(current != NULL){  
            
    if(min > current->num) {  
    min = current->num;  
    } 
    current= current->next;  
    }          
    }  
    return min;
}  
       
int maxNode(Node* head){  
    Node *current = head;  
    int max;  
      
    if(!head){  
    return 0;
    }  
    else{  
          
    max = head->num;  
          
    while(current != NULL){    
    if(max < current->num) {  
    max = current->num;  
    }  
    current = current->next;  
    }               
    }  
    return max;
}  

int main(){
    int data,a,b,angka;
    scanf("%d",&data);getchar();
    for(int i=0;i<data;i++){
    scanf("%d",&angka);getchar();
    pushHead(angka);
    }
    a=minNode(head);
    b=maxNode(head);
    printf("%d",b-a);
    return 0;
}
