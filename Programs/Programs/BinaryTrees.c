//
//  BinaryTrees.c
//  cplusplus
//
//  Created by Srikanth Vanama on 1/18/17.
//  Copyright © 2017 Srikanth Vanama. All rights reserved.
//


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct btnode
{
    int data;
    struct btnode *left;
    struct btnode *right;
    
}btnode;


btnode* insert(struct btnode *node,int value)
{
    
    if(node == NULL)
    {
        btnode *temp = (struct btnode*)malloc(sizeof(struct btnode));
        temp->data = value;
        temp->left = temp->right = NULL;
        return temp;
        
    }
    if(value > node->data) {

        node->right = insert(node->right,value);
    }
    if(value < node->data) {
        
        node->left = insert(node->left,value);
    }

    return node;
    
}


btnode* find(btnode *node,int val)
{
    if(node==NULL)
    {
        return NULL;
    }
    
    if(val > node->data)
    {
        return  find(node->right,val);
    }
    if(val < node->data)
    {
        return find(node->left,val);
    }
    else
    {
        return node;
    }
}


btnode* findmin(btnode *node)
{
    
    if(node==NULL)
    {
        return NULL;
    }
    if(node->left)
        return node->left;
    else
        return node;
    
}


btnode* findmax(btnode *node)
{
    
    if(node==NULL)
    {
        return NULL;
    }
    if(node->right)
        return node->right;
    else
        return node;
    
}


void printinorder(btnode *node)
{
    if(node==NULL)
    {
        return;
    }
    printinorder(node->left);
    printf("%d",node->data);
    printinoder(node->right);
    
}


void printpreorder(btnode *node)
{
    if(node==NULL)
    {
        return;
    }
    printf("%d",node->data);
    printinorder(node->left);
    printinoder(node->right);
    
}

void printpostorder(btnode *node)
{
    if(node==NULL)
    {
        return;
    }
    
    printinorder(node->left);
    printinoder(node->right);
    printf("%d",node->data);
    
}


int main()

{
    btnode *root = NULL;
    
    root = insert(root,5);
    root = insert(root,6);
    printinorder(root);
    
    btnode *temp;
    temp = findmin(root);
    
    temp = findmax(root);

    return 0;
    
}

