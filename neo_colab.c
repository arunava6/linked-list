// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// // Define a structure for the linked list node
// struct node {
//     char data[100]; // Assuming a maximum string length of 99 characters
//     struct node* next;
// };

// // Function to create and insert a new node at the end of the linked list
// struct node* insert(struct node* head, const char* str) {
//     struct node* newnode = (struct node*)malloc(sizeof(struct node));
//     if (newnode == NULL) {
//         printf("Memory allocation failed.\n");
//         exit(1);
//     }
//     strncpy(newnode->data, str, sizeof(newnode->data));
//     newnode->next = NULL;

//     if (head == NULL) {
//         return newnode; // If the list is empty, newnode becomes the head
//     } else {
//         struct node* current = head;
//         while (current->next != NULL) {
//             current = current->next;
//         }
//         current->next = newnode;
//         return head;
//     }
// }

// // Function to delete the last node from the linked list
// struct node* deleteLastNode(struct node* head) {
//     if (head == NULL) {
//         printf("List is empty. Nothing to delete.\n");
//         return NULL;
//     }

//     if (head->next == NULL) {
//         // If there is only one node in the list, delete it
//         free(head);
//         return NULL;
//     }

//     struct node* current = head;
//     struct node* prev = NULL;
//     while (current->next != NULL) {
//         prev = current;
//         current = current->next;
//     }

//     // Set the next of the second-to-last node to NULL
//     prev->next = NULL;
//     free(current); // Free the memory of the last node

//     return head;
// }

// void display(struct node* head) {
//     struct node* current = head;
//     while (current != NULL) {
//         printf("%s ", current->data);
//         current = current->next;
//     }
// }

// int main() {
//     struct node* head = NULL;
//     char input[100];
//     int n;
//     scanf("%d", &n);

//     for (int i = 0; i < n; i++) {
//         scanf("%s", input);
//         head = insert(head, input);
//     }
//     head = deleteLastNode(head);
//     display(head);
//     while (head != NULL) {
//         struct node* temp = head;
//         head = head->next;
//         free(temp);
//     }

//     return 0;
// }










// add 1 in a list

// #include<stdio.h>
// #include<stdlib.h>
// struct node
// {
//     int data;
//     struct node *next;
// };
// struct node *create_list(struct node *head,int ele){
//     struct node *newnode=(struct node*)malloc(sizeof(struct node));
//     newnode->data=ele;
//     newnode->next=NULL;
//     if(head==NULL){
//         head=newnode;
//     }else{
//         struct node *p=head;
//         while(p->next!=NULL){
//             p=p->next;
//         }
//         p->next=newnode;
//         return head;
//     }
    
// }
// // program for reversing list
// struct node *reverse(struct node *head){
//     struct node *prev=NULL;
//     struct node *p=head;
//     struct node *new;
//     while(p!=NULL){
//         new=p->next;
//         p->next=prev;
//         prev=p;
//         p=new;
//     }
//     return prev;
// }
// struct node *sum(struct node *head){
//     head=reverse(head);
//     struct node *current=head;
//     int carry=1;
//     while(current!=NULL){
//         int total=current->data+carry;
//         current->data=total%10;
//         carry=total/10;
//         if(carry==0)
//         break;
//         current=current->next;
//     }
//     head=reverse(head);
//     if(carry>0){
//         struct node *newnode=(struct node*)malloc(sizeof(struct node));
//         newnode->data =carry;
//         newnode->next=head;
//         head=newnode;
//     }
//     return head;
// }
// void display(struct node *head){
//     struct node *current=head;
//     while(current!=NULL){
//         printf("%d ",current->data);
//         current=current->next;
//     }
// }
// int main(){
//     struct node *head=NULL;
//     int n,value;
//     printf("How many elements you want to insert: ");
//     scanf("%d",&n);
//     for(int i=0;i<n;i++){
//         scanf("%d",&value);
//         head=create_list(head,value);
//     }
//     printf("Linked list are: ");
//     display(head);
//     head=sum(head);
//     printf("\n");
//     display(head);
// }











// program for add two linked from tail to head

// #include<stdio.h>
// #include<stdlib.h>
// struct node
// {
//     int data;
//     struct node *next;
// };
// struct node *create_list(struct node *head,int ele){
//     struct node *newnode=(struct node*)malloc(sizeof(struct node));
//     newnode->data=ele;
//     newnode->next=head;
//     head=newnode;
//     return head;
// }
// struct node *sum(struct node *list1,struct node *list2){
//     struct node *c1=list1;
//     struct node *c2=list2;
//     struct node *result=NULL;
//     int sum,carry=0;
//     while(c1!=NULL && c2!=NULL){
//         sum=carry+c1->data+c2->data;
//         carry=sum/10;
//         sum=sum%10;
//         result=create_list(result,sum);
//         c1=c1->next;
//         c2=c2->next;
//     }
//     while(c1!=NULL){
//         sum=carry+c1->data;
//         carry = sum / 10 ;;
//         sum%=10;
//         result=create_list(result,sum);
//         c1=c1->next;
//     }
//     while(c2!=NULL){
//         sum=carry+c2->data;
//         carry=sum/10;
//         sum%=10;
//         result=create_list(result,sum);
//         c2=c2->next;
//     }
//     if(carry>0){
//         result=create_list(result,carry);
//     }
//     return result;
// }
// void displaylist(struct node *head){
//     if(head==NULL){
//         return;
//     }
//     displaylist(head->next);
//     printf("%d ",head->data);
// }
// void display(struct node *head){
//     struct node *current=head;
//     while(current!=NULL){
//         printf("%d ",current->data);
//         current=current->next;
//     }
// }
// int main(){
//     struct node *list1=NULL;
//     int n,value1;
//     printf("How many elements you want to insert: ");
//     scanf("%d",&n);
//     for(int i=0;i<n;i++){
//         scanf("%d",&value1);
//         list1=create_list(list1,value1);
//     }
//     // displaylist(list1);
//     struct node *list2=NULL;
//     int m,value2;
//     printf("\nHow many elements you want to insert: ");
//     scanf("%d",&m);
//     for(int i=0;i<m;i++){
//         scanf("%d",&value2);
//         list2=create_list(list2,value2);
//     }
//     // displaylist(list2);
//     printf("\n");
//     struct node *head;
//     head=sum(list1,list2);
//     display(head);
//     return 0;
// }








// program for deleting the repeating nodes given by users
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *insert(struct node **head,int value){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    if(*head==NULL){
        *head=newnode;
    }else{
        struct node *p=(*head);
        while(p->next!=NULL){
            p=p->next;
        }
        p->next = newnode ;
    }
    return *head;
}
void deletionoccurance(struct node **head,int del){
    struct node *temp=(*head),*prev;
    while(temp->next!=NULL && temp->data==del){
        *head=temp->next;
        free(temp);
        temp=*head;
    }
    while(temp!=NULL){
        while(temp!=NULL && temp->data!=del){
            prev=temp;
            temp=temp->next;
        }
        if(temp==NULL)
        return;
        temp=prev->next;
        prev->next=temp->next;
        free(temp);
        temp=prev->next;
    }
}
void display(struct node *head){
    struct node *current=head;
    while (current != NULL) {
        printf("%d ", current -> data );
        current=current->next;
    }
}
int main(){
    struct node *head=NULL;
    int n,value,del;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&value);
        head=insert(&head,value);
    }
    printf("Enter the element: ");
    scanf("%d",&del);
    printf("Element before deletion: ");
    display(head);
    deletionoccurance(&head,del);
    printf("\nElement after deletion: ");
    display(head);
}