#include <stdio.h>
int removeElement(int* nums, int numsSize, int val)
{
    int j=0;
    for(int i=0;i<numsSize;i++)
    {
        if(val != nums[i])
        {
            nums[j]=nums[i];
            j++;
        }
    }
    
    return j;   //this is now the size of the new array
}
/* take an example : how it works
 Initial State:
 nums = {3, 2, 2, 3}
 numsSize = 4
 val = 3
 
 j = 0 (starts from the beginning of the array)
 First Iteration (i = 0):
 nums[0] = 3, which is equal to val.
 No assignment is made. i moves to the next element.
 
 Second Iteration (i = 1):
 nums[1] = 2, which is not equal to val.
 We copy nums[1] to nums[0] (i.e., nums[0] = 2).
 Increment j to 1.
 Now, nums = {2, 2, 2, 3} (no visible change yet), and j = 1.
 
 Third Iteration (i = 2):
 nums[2] = 2, which is not equal to val.
 We copy nums[2] to nums[1] (i.e., nums[1] = 2).
 Increment j to 2.
 Now, nums = {2, 2, 2, 3}, and j = 2. and so on.
 
 j acts as slow pointer.
 */
int main(int argc, const char * argv[]) {
    int A[]={2,4,3,2,5,6,3,2};
    int size = sizeof(A)/sizeof(A[0]);
    
    size = removeElement(A, size, 2);
    
    for(int i=0;i<size;i++)
    {
        printf("%d",A[i]);
    }
        return 0;
}
