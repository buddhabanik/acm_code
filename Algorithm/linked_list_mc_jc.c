#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

struct node{

    int data;
    char *str;
    struct node *next;
};

void print_linked_list(struct node* head)
{
    if( head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct node* cur=head ;

    while( cur != NULL){

        printf("%d ",cur->data);
        cur=cur->next;
    }
    printf("\n");

}

void insert_at_begin(struct node** head, int value)
{
  //  printf("ssaddsa\n");
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next= *head;
    *head=newnode;
    return;
}

void insert_at_end(struct node** head,int value )
{
    if( *head == NULL)
    {
        struct node* cur=(struct node*)malloc(sizeof(struct node));
        cur->data=value;
//        char *c=(char*)malloc( sizeof( strlen(ch) + 5 ) );
////        c=ch;
//        (cur->str=ch);
        cur->next=NULL;
        *head=cur;
        return;
    }
    struct node* cur = *head;

    while( cur->next != NULL)
    {
        cur=cur->next;
    }

    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    cur->next = newnode;

    return;
}


void insert_at_position(struct node** head,int value ,int position)
{
    struct node* cur=*head;

    if(position==1)
        insert_at_begin(head,value);
    int i;
    for(i=3; i<=position; i++)
    {
        cur = cur->next;
    }

//    struct node* cur_after=cur->next;
//    struct node* newnode=(struct node*)malloc(sizeof(struct node));
//    newnode->data=value;
//
//    newnode->next= cur->next ;
//    cur->next = newnode;

    struct node* cur_after=cur->next;
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;

    newnode->next= cur_after ;
    cur->next = newnode;

    return ;
}
void remove_at_last(struct node** head )
{
    struct node* cur=*head ;

    while(cur->next->next != NULL)
    {
        cur=cur->next;
    }
    cur->next=NULL;
    return;
}

void remove_at_begin(struct node** head)
{
    struct node* cur=*head ;
    cur = cur->next;
    *head=cur;
    return;
}

void remove_at_position(struct node** head,int position)
{

    struct node* temp=*head;
    if( temp == NULL)
    {
        printf("list is empty");
        return ;
    }
    int cont=1;


    struct node* cur=NULL;
    while(1)
    {
        if(cont == position || temp->next == NULL)
            break;
        cont++;
        cur=temp;
        temp =temp->next;
    }
    if(temp == NULL)
    {
        printf("out of bound\n");
        return;
    }
    cur->next=temp->next;

    return ;
}

void remove_duplicate_sorted(struct node** head)
{

    struct node* cur=*head;
    struct node* temp;

    while( cur->next != NULL )
    {
        if(cur->data == cur->next->data)
        {

            temp=cur->next;
            free(temp);
            cur->next = cur->next->next;
        }
        else
            cur=cur->next;
    }
    return ;
}


void remove_duplicate(struct node** head)
{
    struct node* temp =*head;
    struct node* cur;
    struct node* temp2;

    while(temp->next != NULL)
    {
        cur=temp;

        while(cur->next != NULL)
        {
            if(temp->data == cur->next->data)
            {
                temp2=cur->next;
                cur->next=cur->next->next;
                free(temp2);
            }
            else
                cur = cur->next;
        }
        temp=temp->next;
    }
    return;
}

int finding_cycle(struct node** head)
{
    if(head != NULL)
        return 0;

    struct node* fast=*head ;
    struct node* second=*head;
    while(second != NULL && fast != NULL && fast->next != NULL )
    {
        second = second->next;
        fast   = fast->next->next;
        if(second == fast)
            return 1;
    }
    return 0;
}

void reverse(struct node** head)
{
    struct node* cur=*head;
    struct node* next;
    struct node* prev=NULL;

    while( cur != NULL)
    {
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }

    *head=prev;
    return;
}

void reverse_print(struct node* head)
{

    if(head->next == NULL)
    {
        printf("%d ",head->data);
        return ;
    }
    else
    {
        reverse_print(head->next);
        printf("%d ",head->data);
        return ;
    }
}

int main()
{
    struct node *head= NULL;
    insert_at_end(&head,10);
    insert_at_end(&head,15);
    insert_at_end(&head,20);
    insert_at_end(&head,25);
    print_linked_list(head);
    remove_at_position(&head,4);

     print_linked_list(head);

    return 0;
}
