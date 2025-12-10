#include <stdio.h>

int fun(int n)
{
    if(n==0)
    {
        return 1;
    }
    else
        return fun(n-1)*n;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("%d\n",fun(6));
    return 0;
}
