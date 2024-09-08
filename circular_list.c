// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>
// struct node{
//     char data[100];
//     struct node *next;
// };

// insert at beginning
// void insert_beg(struct node **head,char *value){
//     struct node *newnode=(struct node*)malloc(sizeof(struct node));
//     strcpy(newnode->data,value);
//     if(*head==NULL){
//         newnode->next=newnode;
//         *head=newnode;
//     }
//     struct node *p=(*head)->next;
//     while((p)->next!=*head){
//         p=p->next;
//     }
//     p->next=newnode;
//     newnode->next=*head;
//     *head=newnode;
// }

// insert at ending
// void insert_end(struct node** head ,char *value){
//     struct node *newnode=(struct node*)malloc(sizeof(struct node));
//     strcpy(newnode->data,value);
//     if(*head==NULL){
//         newnode->next=newnode;
//         *head = newnode ;
//     }
//     struct node *p=(*head)->next;
//     while(p->next!=(*head)){
//         p=p->next;
//     }
//     p->next=newnode;
//     newnode->next=(*head);
// }
// void display(struct node *head){
//     struct node *current=head;
//     do{
//         printf("%s ",current->data);
//         current=current->next;
//     }while(current!=head);
// }
// int main(){
//     struct node *head=NULL;
//     int n;
//     scanf("%d",&n);
//     char value[100];
//     for(int i=0;i<n;i++){
//         scanf("%s",value);
//         //insert_beg(&head,value);
//         insert_end(&head,value);
//     }
//     printf("The linked list are: ");
//     display(head);
// }











// deletion in circular linked list

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    char data[100];
    struct node *next;
};
//insert at ending
void insert_end(struct node** head ,char *value){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    strcpy(newnode->data,value);
    if(*head==NULL){
        newnode->next=newnode;
        *head = newnode ;
    }
    struct node *p=(*head)->next;
    while(p->next!=(*head)){
        p=p->next;
    }
    p->next=newnode;
    newnode->next=(*head);
}

// deletion from the beginning
// void delete_beg (struct node **head){
//     struct node *temp=(*head);
//     struct node *p=(*head)->next;
//     while(p->next!=(*head)){
//         p=p->next;
//     }
//     *head=temp->next;
//     p->next=(*head);
//     free(temp);
// }

// deletion from the ending
void delete_end(struct node **head){
    struct node *ptr=(*head)->next;
    while(ptr->next->next!=(*head)){
        ptr=ptr->next;
    }
    struct node *temp;
    temp=ptr->next;
    ptr->next=*head;
    free(temp);
}

// display the circular linked list
void display (struct node* head) {
    struct node *current=head;
    do{
        printf("%s ",current->data);
        current=current->next;
    }while(current!=head);
}
int main(){
        struct node *head=NULL;
    int n;
    scanf("%d",&n);
    char value[100];
    for(int i=0;i<n;i++){
        scanf("%s",value);
        insert_end(&head,value);
    }
    printf("The circular linked list: ");
    display(head);
    //delete_beg(&head);
    delete_end(&head);
    printf("\n The circular linked list after deletion: ");
    display(head);
}