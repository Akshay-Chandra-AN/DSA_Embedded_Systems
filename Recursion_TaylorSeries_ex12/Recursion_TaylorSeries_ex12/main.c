#include <stdio.h>
#include <stdlib.h>

//analogy 1
double e(int x,int n)
{
    static double p=1,f=1;
    double r;       //to store result
    
    if(n==0)
    {
        return 1;
    }
    else
    {
        r = e(x,n-1);
        p=p*x;
        f=f*n;
        return r+p/f;
    }
}

//loop (analogy 1)
double e3(int x,int n)
{
    static double s=1;
    int i;
    double num=1;
    double den=1;
    
    for(i=1;i<=n;i++)
    {
        num *= x;
        den *= i;
        s+=num/den;
    }
    return s;
}


//analogy 2 horners rule
double e1(int x,int n)
{
    static double s=1;
    if(n==0)
        return s;
    else
        s= 1+ x*s/n;
    return e1(x,n-1);
}


//using loop horners rule
double e2(int x,int n)
{
    double s1=1;
    for(;n>0;n--)
    {
        s1=1+s1*x/n;
    }
    return s1;
}

//using loop

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("%lf \n",e(1,10));
    printf("%lf \n",e3(1,10));
    printf("%lf \n",e1(1,10));
    printf("%lf \n",e2(1,10));
    return 0;
}
