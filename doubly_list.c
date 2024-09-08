// #include<stdio.h>
// #include<stdlib.h>
// struct node{
//     int data;
//     struct node *prev;
//     struct node *next;
// };

// //insert at beginning
// void insert_beg(struct node **start,struct node **end,int value){
//     struct node *newnode=(struct node*)malloc(sizeof(struct node));
//     newnode->data=value;
//     if(*start==NULL){
//         newnode->next=NULL;
//         newnode->prev=NULL;
//         *start=newnode;
//         *end=newnode;
//     }else{
//         newnode->next = (*start);
//         (*start)->prev=newnode;
//         newnode->prev=NULL;
//         *start=newnode;
//     }
// }

// //insert at ending
// void insert_end(struct node** start ,struct node** end ,int value){
//     struct node *newnode=(struct node*)malloc(sizeof(struct node));
//     newnode->data=value;
//     if(*start==NULL){
//         newnode->next=NULL;
//         newnode->prev=NULL;
//         *start=newnode;
//         *end=newnode;
//     }
//     newnode->prev=*end;
//     (*end)->next=newnode;
//     newnode->next=NULL;
//     *end=newnode;
// }

// //insert at the position
// void insert_pos(struct node **start,struct node **end,int pos,int value){
//     struct node *newnode=(struct node*)malloc(sizeof(struct node));
//     newnode->data=value;
//     int i=1;
//     struct node *p=(*start);
//     while(i!=pos-1){
//         p=p->next;
//         i++;
//     }
//     newnode->next=p->next;
//     newnode->next->prev=newnode;
//     newnode->prev=p;
//     p->next=newnode;
// }

// //for display the linked list
// void display(struct node *start){
//     struct node *current=start;
//     while(current!=NULL){
//         printf("%d ", current -> data);
//         current=current->next;
//     }
// }
// int main(){
//     struct node *start,*end;
//     start=NULL,end=NULL;
//     int n,value,pos;
//     scanf("%d",&n);
//     for(int i = 0 ;i < n;++i){
//         scanf("%d",&value);
//         //insert_beg(&start,&end,value);
//         insert_end(&start,&end,value);
//     }
//     printf("Enter the position for inserting element: ");
//     scanf("%d",&pos);
//     printf("Enter the element: ");
//     scanf("%d", &value );
//     //insert_pos(&start,&end,pos,value);
//     printf("\nThe Linked list: ");
//     display(start);
// }







// deletion in doubly linked list

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    char data[100];
    struct node* next;
    struct node *prev;
};
void insert_node(struct node **start,struct node **end,char* value){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    strcpy(newnode->data,value);
    if(*start==NULL){
        newnode->prev=NULL;
        newnode->next=NULL;
        *start=newnode;
        *end=newnode;
    }
    newnode->prev=(*end);
    (*end)->next=newnode;
    newnode->next=NULL;
    *end=newnode;
}

// deletion from beginning
// void delete_beg(struct node **start,struct node **end){
//     struct node *temp=(*start);
//     *start=temp->next;
//     (*start)->prev=NULL;
//     free(temp);
// }

// deletion from the ending
// void delete_end(struct node** start , struct node** end ){
//     struct node *temp=(*end);
//     *end=temp->prev;
//     (*end)->next=NULL;
//     free(temp);
// }

// deletion from the specific position
void delete_pos(struct node **start,struct node **end,int pos){
    struct node *p=(*start);
    int i=1;
    while(i!=pos-1){
        p=p->next;
        i++;
    }
    struct node *temp;
    temp=p->next;
    p->next=temp->next;
    temp->next->prev=p;
    free(temp);
}

// display the linked list
void display(struct node *start){
    struct node *current=start;
    while(current!=NULL){
        printf("%s ", current -> data);
        current=current->next;
    }
}
int main(){
    struct node *start,*end;
    start=NULL,end=NULL;
    int n;
    char value[100];
    printf ("enter number of nodes :");
    scanf("%d",&n);
    for (int i = 1; i <= n; ++i){
        scanf("%s",value);
        insert_node(&start,&end,value);
    }
    printf("The linked list are: ");
    display(start);
    //delete_beg(&start,&end);
    //delete_end(&start,&end);
    int pos;
    printf("\nEnter a postion to be deleted:");
    scanf("%d",&pos);
    delete_pos(&start,&end,pos);
    printf("\nThe linked list after deletion: ");
    display(start);

}


