#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    int data1;
    struct node *next;
};
struct node *create_list(struct node *head,int ele){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=ele;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
    }else{
        struct node *p=head;
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=newnode;
        return head;
    }
    
}
void display(struct node *head){
    struct node *current=head;
    while(current!=NULL){
        printf("%d ",current->data);
        current=current->next;
    }
}
int main(){
    struct node *head=NULL;
    int n,value;
    printf("How many elements you want to insert: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&value);
        head=create_list(head,value);
    }
    printf("Linked list are: ");
    display(head);
}

