#include <stdlib.h>
#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    int j=0;
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i] != nums[j])
        {
            j++;
            nums[j]=nums[i];
            
        }
    }
    
    for(int i=0;i<j+1;i++)
    {
        printf("%d",nums[i]);
    }
    return j+1;
}



int main(int argc, const char * argv[]) {
    int a[]={0,0,1,1,1,2,3,3,4};
    int size = 9;
    printf("\nsize of new array is :%d ",removeDuplicates(a,size));
    return 0;
}
