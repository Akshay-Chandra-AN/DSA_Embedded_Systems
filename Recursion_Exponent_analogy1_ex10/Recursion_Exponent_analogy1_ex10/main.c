#include <stdio.h>
int pow1(int m,int n)
{
    if(n==0)
        return 1;
    return pow1(m,n-1)*m;
}

int pow2(int m, int n)
{
    if(n==0)
        return 1;
    if(n%2 == 0)
    {
        return pow1(m*m, n/2);
    }
    else
        return pow2(m*m,(n-1)/2)*m;    //abdul bari way
}

int pow3(int m, int n)
{
    if(n==0)
        return 1;
    if(n%2 == 0)
    {
        return pow1(m*m, n/2);
    }
    else
        return pow2(m,(n-1))*m;    //chatgpt way
}



int main(int argc, const char * argv[]) {
    // insert code here...
    printf("%d\n",pow1(3,3));
    printf("%d\n",pow2(3,3));
    printf("%d\n",pow3(3,3));
    return 0;
}
    
