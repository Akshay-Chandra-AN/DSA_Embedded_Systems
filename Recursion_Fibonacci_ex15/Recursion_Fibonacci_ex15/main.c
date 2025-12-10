#include <stdio.h>

//analogy 1
int fib(int n)
{
    if(n<=1)
        return n;
    return fib(n-2)+fib(n-1);
}

//analogy2 : memoization
int F[10];
int fib2(int n)
{
    if(n<=1)
    {
        F[n]=n;
        return n;
    }
    else
    {
        if(F[n-2]== -1)
            F[n-2]=fib2(n-2);
        if(F[n-1]== -1)
            F[n-1]=fib2(n-1);
        F[n]=F[n-2]+F[n-1];
        return F[n];
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("fib %d\n",fib(8));
    
    //this for loop is for analogy 2
    for(int i=0;i<10;i++)
        F[i]=-1;
    printf("fib %d\n",fib2(8));
    return 0;
}
