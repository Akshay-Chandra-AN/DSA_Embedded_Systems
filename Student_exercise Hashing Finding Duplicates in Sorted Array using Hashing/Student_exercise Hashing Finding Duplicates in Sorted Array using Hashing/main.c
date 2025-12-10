#include <stdlib.h>
#include <stdio.h>

/* hash here is an array, filled with zero
 the last element of the original array, will be the last index of hash
 if element found at the hash, increment it, if duplicate found, increment it
*/

int main(int argc, const char * argv[]) {
    int a[]={1,2,3,3,4,5,5,5,6};
    int a_size = sizeof(a)/sizeof(int);
    int hash_length = a[a_size-1];
    int hash[hash_length];
    for(int i=0;i<=hash_length;i++)  hash[i]=0;
    
    for(int j=0;j<a_size;j++)
    {
        hash[a[j]]++;
    }
    
    for(int k=0;k<=hash_length;k++)
    {
        if(hash[k]>1)
            printf("the element is %d and count is %d \n",k,hash[k]);
    }
    return 0;
}
