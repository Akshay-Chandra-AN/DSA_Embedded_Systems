#include <stdio.h>

void fun1(int n)
{
    if(n>0)
    {
        printf("%d \n",n);
        fun1(n-1);
    }
}


int fun2 (int n)
{
    if(n>0)
    {
        return fun2(n-1)+n;
    }
    return 0;
}

int fun3 (int n)
{
    static int x=0;
    if(n>0)
    {
        x++;
        return fun3(n-1)+x;
    }
    return 0;
}

void fun4 (int n)
{
    if(n>0)
    {
        printf("%d ",n);
        fun4(n-1);
        fun4(n-1);
    }
}
void funB (int n );
void funA(int n)
{
    if(n>0)
    {
        printf("%d ",n);
        funB(n-1);
    }
}


void funB (int n )
{
    if(n>1)
    {
        printf("%d ",n);
        funA(n/2);
    }
}



int main(int argc, const char * argv[]) {
    //int x=3;
    // fun1(x);                      //example 1- tail recursion
    //printf("%d \n",fun2(5));       //example 3- head recursion
    //printf("%d \n",fun3(5));       //ex 4 static variables in recurs
    //fun4(3);                       //tree recursion example 5
    funA(20);                      //indirect recursion ex 6
    return 0;
}
