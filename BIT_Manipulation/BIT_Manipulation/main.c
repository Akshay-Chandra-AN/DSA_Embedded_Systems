#include <stdlib.h>
#include <stdio.h>
/*
 how do you set, clear and toggle a bit?
  set : x|=(1<<n);  //basically you make nth bit as 1 and rest 0 and then | making nth bit OR to set it.
clear : x&=~(1<<n); //set bit at n position, reverse it, making it 0 and rest 1. and then and.
toggle: x^=(1<<n);  //XOR to toggle the bits
 */

void bit_set(int x,int n)
{
    if(x & (1<<n))
    {
        printf("bit set");
    }
}

void count_set_bit(int x)
{
    int count = 0;
    while(x)
    {
        x &= (x-1);
        count ++;
    }
    printf("%d\n",count);
}

unsigned int reverse(unsigned int n)
{
    unsigned int rev = 0;
    for(int i=0;i<32;i++)
    {
        rev <<= 1;
        rev |= (n&1);
        n>>=1;
    }
    return rev;
}

unsigned int swap(unsigned int x,int p1,int p2)
{
    int bit1 = (1<<p1);
    int bit2 = (1<<p2);
    if(bit1 ^ bit2)
        x^=(1<<p1)|(1<<p2);
    return x;
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    //bit_set(46, 0);
    count_set_bit(25);
    //printf("%d",reverse(2));
   // printf("%d",swap(23, 3, 2));
    return EXIT_SUCCESS;
}
