#include<stdio.h>
#include<stdlib.h>

struct ListNode{
	int data;
	struct ListNode *next;
};

void Push(struct ListNode **head_p, int data);
void PrintStack(struct ListNode *head);

int main(void){
	struct ListNode **head_p;
	struct ListNode *head;
	head_p = &head;
	head = NULL;

	Push(head_p, 2);
	Push(head_p, 4);
	PrintStack(head);

	return 0;
}

void Push(struct ListNode **head_p, int data){
	struct ListNode *newNode;
	newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
	if(!newNode){
		printf("MemoryError!\n");
	}else{
		newNode->data = data;
		newNode->next = *head_p;
		*head_p = newNode;
	}
}

void PrintStack(struct ListNode *head){
	struct ListNode *current;
	current = head;
	if(!current){
		printf("There is no stack\n");
		return;
	}
	while(current != NULL){
		printf("%d\n", current->data);
		current = current->next;
	}
}
