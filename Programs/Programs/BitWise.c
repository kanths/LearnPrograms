//
//  BitWise.c
//  cplusplus
//
//  Created by Srikanth Vanama on 1/20/17.
//  Copyright © 2017 Srikanth Vanama. All rights reserved.
//


#include <stdio.h>

void convertdecimaltobinary(int n)
{
    int remainder;
    
    while(n!=0)
    {
        remainder = n%2;
        n = n/2;
        printf("%d",remainder);
    }
    printf("\n");
    
}

int addnums(int x,int y)
{
    while(y!=0)
    {
        int carry = x & y;
        x = x ^y;
        y = carry << 1;
    }
    return x;
}

void multiply(int m,int n)
{
    int result=0;
    int i;
    for (i=0;i<n;i++)
    {
        result = addnums(result,m);
    }
    printf("sum is %d",result);
}



int main()
{
    int m=9, n=3;
    convertdecimaltobinary(m);
    multiply(m,n);
    
    
    unsigned int i = 123456;
    char *c = (char*)&i;
    printf ("\n*c is: 0x%x\n", *c);

    if (*c)
        printf("\nLittle endian");
    else
        printf("\nBig endian");
    
    
    return 0;
    
}

