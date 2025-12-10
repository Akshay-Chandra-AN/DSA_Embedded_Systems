#include <stdlib.h>
#include <stdio.h>

/* hash here is an array, filled with zero
 the max element of the original array, will be the last index of hash
 if element found at the hash, increment it, if duplicate found, increment it
 
*/

int main(int argc, const char * argv[]) {
    int a[]={2,5,1,4,4,1,2,4,5,6,8,9,3};
    int a_size = sizeof(a)/sizeof(int);
    
    //find max of array
    int m=a[0];
    for(int i=0;i<a_size;i++)
    {
        if(a[i]>m)
        {
            m=a[i];
        }
    }
    //printf("%d",m);
    
    int hash_length = m;
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
