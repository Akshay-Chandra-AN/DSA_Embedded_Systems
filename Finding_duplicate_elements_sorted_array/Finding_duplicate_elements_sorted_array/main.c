
#include <stdio.h>

void removeDuplicates(int* nums, int numsSize) {
    
    int duplicate = 0;
    //int counter = 0;
    
    for(int i=0;i<numsSize; i++)
    {
        if(nums[i]==nums[i+1] && nums[i]!=duplicate)
        {printf("%d,",nums[i]);
            duplicate = nums[i];
            //printf("duplicate %d\n",duplicate);
            //counter++;
        }
    }
}

void counting_the_duplicate(int* nums, int numsSize) {
    
    int j=0;
    
    for(int i=0;i<numsSize-1; i++)
    {
        if(nums[i]==nums[i+1])
        {
            j=i+1;
            while(nums[j]==nums[i])j++;
            printf("%d is appearing %d times \n",nums[i],j-i);
            //printf("i is \n%d",i);
            i=j-1;
            //printf("%d \n",i);

        }
    }
}

int main(int argc, const char * argv[]) {
    int num[] = {1,1,1,2,2,3,4,4,4};
    int numsize = sizeof(num)/sizeof(num[0]);
    
    removeDuplicates(num, numsize);
    printf("\n");
    counting_the_duplicate(num, numsize);
    return 0;
}
