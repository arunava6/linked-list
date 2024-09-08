// insertion of element in the beginning of linked list

// #include<stdio.h>
// #include<stdlib.h>
// struct node{
// 	int data;
// 	struct node *next;
// };
// // function for inserting value int the beginning of list
// struct node* insert(struct node *head,int value){
// 	struct node *newnode=(struct node*)malloc(sizeof(struct node));
// 	if(newnode==NULL){
// 		printf("Memory allocation failed\n");
// 		return head;
// 	}
// 	newnode->data=value;
// 	newnode->next=head;										//for insert at the ending (newnode->next=newnode)
// 	head=newnode;
// 	return head;
// }
// // function for display the linked list
// void display(struct node *head){
// 	struct node *current=head;
// 	while(current!=NULL){
// 		printf("%d ",current->data);
// 		current=current->next;
// 	}
// 	//printf("NULL\n");
// }
// int main(){
// 	struct node *head=NULL;
// 	head=insert(head,3);
// 	head=insert(head,7);
// 	head=insert(head,11);
// 	printf("Linked list: ");
// 	display(head);
// }






// insertion at the end

// #include<stdio.h>
// #include<stdlib.h>
// struct node{
// 	int data;
// 	struct node *next;
// };
// struct node* insertAtend(struct node *head,int value){
// 	struct node *newnode=(struct node*)malloc(sizeof(struct node));
// 	newnode->data=value;
// 	 // This new node is going to be the
//     //  last node, so make next of it as NULL
// 	newnode->next=NULL;
// 	if(head==NULL){
// 		head=newnode;
// 	}else{
// 	struct node *p=head;
// 	// Else traverse till the last node
// 	while(p->next!=NULL){
// 		p=p->next;
// 	}
// 	// Change the next of last node
// 	p->next=newnode;
// 	return head;
// 	}
// }
// void display(struct node *head){
// 	struct node *p=head;
// 	while(p!=NULL){
// 		printf("%d ",p->data);
// 		p=p->next;
// 	}
// }
// int main(){
// 	struct node *head=NULL;
// 	head=insertAtend(head,10);
// 	head=insertAtend(head,20);
// 	head=insertAtend(head,30);
// 	display(head);
// 	return 0;
// }





// insertion at specific position

#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};
struct Node * insertAtpos(struct Node *head, int data, int pos){
    struct Node * newnode = (struct Node *) malloc(sizeof(struct Node));
    struct Node * p = head;
    int i = 1;
 
    while (i!=pos-1)
    {
        p = p->next;
        i++;
    }
    newnode->data = data;
    newnode->next = p->next;
    p->next = newnode;
    return head;
}

void display(struct Node *head){
	struct Node *current=head;
	while(current!=NULL){
		printf("%d ",current->data);
		current=current->next;
	}
}
int main(){
	struct Node *head=NULL;
	struct Node *second;
    struct Node *third;
    struct Node *fourth;
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    head->data=7;
    head->next=second;
    second->data=11;
    second->next=third;
    third->data=41;
    third->next=fourth;
    fourth->data=66;
    fourth->next=NULL;
	printf("The linked list: ");
	display(head);
	head=insertAtpos(head,56,2);
	printf("\nThe linked list after insertion: ");
	display(head);
}
