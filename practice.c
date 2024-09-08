#include<stdio.h>
#include<stdlib.h>
// structure of node
struct node{
    int data;
    struct node *prev;
    struct node *next;
};
//create node
void create_node(struct node **start,struct node **end,int value){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    if(*start==NULL){
        newnode->prev=NULL;
        newnode->next=NULL;
        *start=newnode;
        *end=newnode;
    }else{
        newnode->prev=(*end);
        (*end)->next=newnode;
        newnode->next=NULL;
        *end=newnode;
    }
}
// Insert at beggining of the doubly linked list
void insert_beg(struct node **start,struct node **end,int value){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    if(*start==NULL){
        newnode->prev=NULL;
        newnode->next=NULL;
        *start=newnode;
        *end=newnode;
    }else{
        newnode->next=*start;
        (*start)->prev=newnode;
        newnode->prev=NULL;
        *start=newnode;
    }
}
// delete from the end in doubly linked list
void delete_end(struct node **end){
    struct node *temp=(*end);
    *end=(*end)->prev;
    (*end)->next=NULL;
    free(temp);
}
void display(struct node *start){
    struct node *current=start;
    while(current!=NULL){
        printf("%d ",current->data);
        current=current->next;
    }
    printf("\n");
}
int main(){
    struct node *start=NULL, *end=NULL;                 // empty address node
    create_node(&start,&end,3);
    create_node(&start,&end,1);
    create_node(&start,&end,5);
    create_node(&start,&end,9);
    display(start);
    insert_beg(&start,&end,10);
    display(start);
    delete_end(&end);
    display(start);
}




