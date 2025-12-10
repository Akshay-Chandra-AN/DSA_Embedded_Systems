/*
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Example 1:
Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 */
 
#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int size = 3;
    int nums[] = {3,2,3};
    int candidate=0;
    int count = 0;
    
    for(int i=0;i<size;i++)
    {
        if(count == 0)
        {
            candidate = nums[i];
        }
        
        if(candidate == nums[i])
        {
            count++;
        }
        else{
            count--;
        }
    }
    
    
    printf("%d\n",candidate);
    return 0;
}
