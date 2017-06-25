//
//  LinkedLists.c
//
//  Created by Srikanth Vanama on 1/15/17.
//  Copyright © 2017 Srikanth Vanama. All rights reserved.
//


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    
    int data;
    struct node *next;
};


struct node *head = NULL;
struct node *current = NULL;


int main()

{
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    print_count_list();
    delete(30);
    reverse();
    
    detectloop(head);
    
    print_count_list();
    
    return 0;
}



int insert(int val)
{

    struct node *ptr =  (struct node*)malloc(sizeof(struct node));
    
    if(ptr == NULL)
    {
        return -1;
    }
    
    
    if(head == NULL){
        
        head = current = ptr;
        ptr->data = val;
        ptr->next = NULL;
    }
    else
    {
        ptr->data = val;
        ptr->next = NULL;
        
        current->next = ptr;
        current = ptr;
        
    }

    return 0;

}


int detectloop(struct node *head)
 {
 struct node  *slow_p = head, *fast_p = head;
 
 while (slow_p && fast_p && fast_p->next )
 {
 slow_p = slow_p->next;
 fast_p  = fast_p->next->next;
 if (slow_p == fast_p)
 {
 printf("Found Loop");
 return 1;
 }
 }
 return 0;
 }
 
 
void reverse ()
{
    struct node* prev   = NULL;
    struct node* current = head;
    struct node* tmp;
    while (current != NULL)
    {
        tmp  = current->next;
        current->next = prev;
        prev = current;
        current = tmp;
    }
    head = prev;
}

void print_count_list(void)
{
    int count = 0;
    struct node *ptr;
    
    ptr=head;
    
    while(ptr!=NULL)
    {
        printf(" %d\n",ptr->data);
        ptr = ptr->next;
        count ++;
        
    }
    
    printf("Total count is %d\n", count);
}

void printmiddle()
{
    struct node *slow_ptr = head;
    struct node *fast_ptr = head;
    
    if (head!=NULL)
    {
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
        printf("The middle element is [%d]\n\n", slow_ptr->data);
    }
}


void popStack()
{
    struct node *var=head;
    if(var==head)
    {
        head = head->next;
        free(var);
    }
    else
        printf("\nStack Empty");
}


void pushStack(int value)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=value;
    if (head == NULL)
    {
        head=temp;
        head->next=NULL;
    }
    else
    {
        temp->next=head;
        head=temp;
    }
}


int delete(int num)
{
    struct node *temp, *prev;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->data==num)
        {
            if(temp==head)
            {
                head=temp->next;
                free(temp);
                return 1;
            }
            else
            {
                prev->next=temp->next;
                free(temp);
                return 1;
            }
        }
        else
        {
            prev=temp;
            temp= temp->next;
        }
    }
    return 0;
}



void sort() {
    
    int i, j, k, tempData;
    struct node *current;
    struct node *next;
    
    int size = length();
    k = size ;
    
    for ( i = 0 ; i < size - 1 ; i++, k-- ) {
        current = head;
        next = head->next;
        
        for ( j = 1 ; j < k ; j++ ) {
            
            if ( current->data > next->data ) {
                tempData = current->data;
                current->data = next->data;
                next->data = tempData;

            }
            
            current = current->next;
            next = next->next;
        }
    }
}



void addafter(int num, int loc)
{
    int i;
    struct node *temp,*left,*right;
    right=head;
    for(i=1;i<loc;i++)
    {
        left=right;
        right=right->next;
    }
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=num;
    left->next=temp;
    left=temp;
    left->next=right;
    return;
}



