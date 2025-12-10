#include <stdio.h>
static int count=0;
void TOH(int n, int A, int B, int C)
{
    
    if(n>0)
    {
        TOH(n-1, A, C, B);
        printf("%d->%d\n",A,C);
        count++;
        TOH(n-1, B, A, C);
    }
}



int main(int argc, const char * argv[]) {
    // insert code here...
    TOH(3,1,2,3);
    printf("%d ",count);    //just to see the overall recursive calling count
    return 0;
}
