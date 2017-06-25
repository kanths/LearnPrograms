//
//  strings.c
//  cplusplus
//
//  Created by Srikanth Vanama on 1/22/17.
//  Copyright © 2017 Srikanth Vanama. All rights reserved.
//

#include <stdio.h>
#include <string.h>

void reverse_string(char *a,int length)
{
    
    printf("\ngot a as %s",a);
    printf("\ngot i as %d",length);


    char temp;
    
    for(int i=0;i<length/2;i++)
    {
        temp=a[i];
        a[i]=a[length-1-i];
        a[length-1-i]=temp;
    }
    
    printf("\nreversed string is %s\n\n\n\n",a);
    
}

//http://www.geeksforgeeks.org/reverse-words-in-a-given-string/

void reverse_words(char *a)
{
    int length=strlen(a);
    int i =0,j=0;
    
    char temp;
    
    for(int i=0;i<length/2;i++)
    {
        temp=a[i];
        a[i]=a[length-1-i];
        a[length-1-i]=temp;
    }

    
    while(1)
    {
        printf("\na[i] is %c",a[i]);
        if(a[i] == ' ' || a[i]  == '\0')
        {
            reverse_string(a[i],j);
            j=0;
        }
        if(a[i] == '\0')
        {
            break;
        }
        ++i;
        ++j;
    }
    
    //printf("\n123reversed string is %s",a);

}


void reverse_number(int n)
{
    int rev=0,remainder;
    while(n!=0)
    {
        remainder = n%10;
        rev = rev*10 + remainder;
        n=n/10;
        
    }
    
    printf("\nreverse is %d",rev);
    
}



void myatoi(char *str)
{
    int number=0;
    
    int sign = 1;
    int i=0;
    
    for(i=0;str[i];i++)
    {
        if(str[i] == ' ')
            continue;
        else if(str[i] == '-' || str[i] == '+')
        {
            if(str[i] == '-')
            {
                sign = -1;
            }
        }
        else
            break;
    }
    
    
    for(;str[i]!='\0';)
    {
        printf(" %c ",str[i]);
        
        if(str[i] >= '0' && str[i] <= '9')
        {
            number = number*10+(str[i]-'0');
            i++;
        }
        else{
            break;
        }
        
    }
    
    number=sign*number;
    
    printf("atoi number is %d",number);
    
}


int findSubstr(char src[], char pattern[])
{
    int i, j, firstOcc;
    i = 0, j = 0;
    
    while (src[i] != '\0') {
        
        while (src[i] != pattern[0] && src[i] != '\0')
            i++;
        
        if (src[i] == '\0')
            return (-1);
        
        firstOcc = i;
        
        while (src[i] == pattern[j] && src[i] != '\0' && pattern[j] != '\0') {
            i++;
            j++;
        }
        
        if (pattern[j] == '\0')
            return (firstOcc);
        if (src[i] == '\0')
            return (-1);
        
        i = firstOcc + 1;
        j = 0;
    }
    
    return -1;
}


int lengthOfLongestSubstring(char* s)
{
    // "nfvbiywbasfbu"
    
    int len = 0;
    int p=0 , q=0,  i;
    
    for(; q<strlen(s); q++)
    {
        for(i=p; i<q; i++)
        {
            if(s[q] == s[i])
            {
                if(q-p > len)
                {
                    len = q-p;
                }
                p = i+1;
                break;
            }
        }
    }
    len = (len > q-p )?len:q-p;
    return len;
}


int main()
{
    char str[] = "hello hey ssup";
    int length=strlen(str);

    reverse_string(str,length);
    
    reverse_words(str);
    
    char str2[]="512 35";
    length=strlen(str2);
    myatoi(str2);
    
    
    int num = 12345;
    reverse_number(num);
    
    
    char *src = "This is my sample program";
    char *pattern = "sample";
    int pos = findSubstr(src, pattern);
    
    if( pos > -1) {
        printf("Found the substring at position %d \n",pos);
    }
    else
    {
        printf("No match found \n");
    }
    

    length = lengthOfLongestSubstring("nfvbiywbasfbu");
    printf("\nlength of longestsbustring -> %d\n", length);


    
    char a_str[] = "hello1234";
    char *arr_ptr = &a_str;
    printf("\n length of string -> %d\n", strlen(arr_ptr));
    
    return 0;
}
