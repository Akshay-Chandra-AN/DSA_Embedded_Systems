#include <stdlib.h>
#include <stdio.h>

struct Array
{
    int A[10];
    int length;
    int size;
};

int missing_sorted_natural(struct Array arr)
{
    int m=(arr.size*(arr.size+1)/2);
    int sum=0;
    for(int i=0;i<arr.length;i++)
    {
        sum=sum+arr.A[i];
    }
        sum=m-sum;
        return sum;
}


int main(int argc, const char * argv[]) {
    struct Array a={{1,2,3,4,6,7,8,9,10},9,10};
    printf("%d\n",missing_sorted_natural(a));
}
