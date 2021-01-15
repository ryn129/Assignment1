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

void pushHead(int num){
    Node *temp = createNode(num);
    if(!head) 
    {
        head = tail = temp;
    } else
    {
        temp->next = head;
        head = temp;
    }
}

void removeDuplicates(Node *head)
{
    Node *ptr1, *ptr2, *dup;
    ptr1 = head;
 
    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;
        while (ptr2->next != NULL)
        {
            if (ptr1->num == ptr2->next->num)
            {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete(dup);
            }
            else
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
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

int main()
{
	int n, temp;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		pushHead(temp);
    }
	removeDuplicates(head);
	printlinkedlist();
	return 0;
}