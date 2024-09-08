#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * next;
};
// inserting element at beginning
struct node * insertAtbegin(struct node *head,int value){
    // allocating memory for nodes
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("Memomry is not allocated");
    }
    newnode->data=value;
    newnode->next=head;
    head=newnode;
    return head;
}

// inserting element at the end
struct node *insertAtend(struct node * head,int value){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
    }
    struct node *p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=newnode;
    return head;
}
// traversing all the nodes in the linked list
void display(struct node *head){
    struct node * ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}

//  1.function for sum of all elements
void sum(struct node *head){
    struct node *ptr=head;
    int sum=0;
    while(ptr!=NULL){
        sum=sum+ptr->data;
        ptr=ptr->next;
    }
    printf("\nThe sum of all nodes in the linked list is: %d",sum);
}

// 2. find out the number whuch is greater than 5 and count them
void count(struct node * head){
    struct node * ptr=head;
    int count=0;
    while(ptr!=NULL){
        if(ptr->data>5){
            count=count+1;
        }
        ptr=ptr->next;
    }
    printf("\nThe frequency of greater nodes than 5 is: %d",count);
}

// 3. find out the minimum node and maximum node
void check_max(struct node *head){
    struct node *ptr=head;
    int max=ptr->data;
    int min=ptr->data;
    ptr=ptr->next;
    while(ptr!=NULL){
        if(ptr->data>max){
            max=ptr->data;
        }else if(ptr->data<min){
            min=ptr->data;
        }
        ptr=ptr->next;
    }
    printf("\nThe maximum node is %d",max);
    printf("\nThe minimum node is %d",min);
}

// 4.searching of element from the linked list
void search(struct node *head){
    struct node *ptr=head;
    int target;
    printf("\nEnter the node you want to search: ");
    scanf("%d",&target);
    int temp=0;
    struct node *addr;
    while(ptr!=NULL){
        if(ptr->data==target){
            temp=1;
            addr=ptr->next;
        }
        ptr=ptr->next;
    }
    if(temp!=0){
        printf("The node %d is found in the linked list",target);
    }else{
        printf("The node is not found in the linked list");
    }
}
int main(){
    struct node *head;
    head=NULL;
    head=insertAtbegin(head,15);
    head=insertAtbegin(head,2);
    head=insertAtbegin(head,4);
    head=insertAtend(head,90);
    head=insertAtend(head,55);
    head=insertAtend(head,40);
    printf("The linked list are: ");
    display(head);
    sum(head);
    count(head);
    check_max(head);
    search(head);
    return 0;
}
