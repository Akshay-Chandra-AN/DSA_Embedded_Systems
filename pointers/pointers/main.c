#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a=5;
    int *p;
    int **pp;
    p=&a;
    pp=&p;
    printf("a = %d\n",a);
    printf("address of a = %d\n",&a);
    printf("address of p = %d\n",&p);
    printf("address of pp = %d\n",&pp);
    printf("a = %d\n",*p);
    printf("a = %d\n",**pp);
    printf("address of a = %d\n",*pp);
    printf("value of pp / address of p = %d\n",pp);
    //printf("p = %d\n",);

    return 0;
}


/*
 How?
 value of a = a,    p*, *ppa,   5
 addrs of a = &a,   p,  *ppa,   2000
 value of p = &a,   p,  *ppa,   2000
 addr of  p =       &p, ppa,    2001
 value of pp=       &P, ppa,    2001
 addr of pp =           &ppa,   2002
 
 
 
 */
