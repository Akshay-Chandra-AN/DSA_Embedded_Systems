#include <stdio.h>
void rotate(int* nums, int numsSize, int k) {
    k = k % numsSize;
    int left = 0;
    int right = numsSize-1;
    int temp = 0;
    while(left<right)
    {
        temp = nums[left];
        nums[left]= nums[right];
        nums[right] = temp;
        left++;
        right--;
    }
    
    left = 0;
    right = k-1;
    while(left<right)
    {
        temp = nums[left];
        nums[left]= nums[right];
        nums[right] = temp;
        left++;
        right--;
    }
    
     left = k;
    right = numsSize-1;
    while(left<right)
    {
        temp = nums[left];
        nums[left]= nums[right];
        nums[right] = temp;
        left++;
        right--;
    }
    
    
    
    for(int i=0;i<numsSize;i++)
    {
        printf("%d",nums[i]);
    }
}



int main(int argc, const char * argv[]) {
    int nums[] = {1,2,3,4,5,6,7};
    int k = 3;
    int numssize = 7;
    rotate(nums,numssize,k);
    return 0;
}
