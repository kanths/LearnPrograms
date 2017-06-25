#include <stdio.h>
#include <string.h>

int main(void) {
    // your code goes here
    
/* get range */
  

char str[]="hellok";

printf("string is %s",str);

int length=strlen(str);
int i =0;
int j;
j = length - 1;
char temp;

while(i<length/2)
{
  temp=str[i];
  str[i]=str[j];
  str[j]=temp;
  i++;
  j--;
}

printf(" \n string is %s",str);
    
}
