
  Testing.c
  cplusplus

  Created by Srikanth Vanama on 1/21/17.
  Copyright © 2017 Srikanth Vanama. All rights reserved.



#include <stdio.h>

int main()
{
    char stk[100],exp[100]= "(((()))))";
    int top,i;
    
    
    top = -1;
    
    
    for(i=0; exp[i] != '\0'; i++)
    {
        
        if( exp[i]=='(' || exp[i] =='[' || exp[i] == '{' )
        {
            top++;
            stk[top]= exp[i];
        }
        else if ( exp[i] == ')' )
        {
            if( stk[top] == '(' )
                top--;
            else
            {
                printf("Unbalanced exp");
                exit(0);
            }
        }
        
        
    } // for
    
    if( top == -1 )
    {
        printf("\nExp is balanced\n");
    }
    else
    {
        printf("\nExp is not balanced\n");
    }
    
    return 0;
} // main

