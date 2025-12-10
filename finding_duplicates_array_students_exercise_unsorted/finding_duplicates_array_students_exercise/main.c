#include <stdlib.h>
#include <stdio.h>


//126. Student Challenge : Finding Duplicates in a Unsorted Array

void find_duplicate(int *a,int numsize)
{
    int count;
    for(int i=1;i<numsize;i++)
    {
        count =1;       //for every element, count= 1 then find duplicate & then count++
        if(a[i] != -1)
        {
            for(int j=i+1;j<numsize;j++)
            {
                if(a[i]==a[j])
                {
                    count++;
                    a[j] = -1;
                }
            }
        }
        if(count>1) printf("%d \n",a[i]);
    }
}

int main(int argc, const char * argv[]) {
    int arr[]={2,3,2,4,4,2,2,1,5,6,7,3,6};
    int arrsize = sizeof(arr)/sizeof(int);
    find_duplicate(arr, arrsize);
    return 0;
}
