#include <stdlib.h>

#include <stdio.h>


int main()
{
    /*
    int a[5]={1,2,3,4,5};       //array in stack
    int *p;
    //p=&a;     this is invalid when pointing to an array
    p=a;        //this is valid
    for(int i=0;i<5;i++)
    {
        //cout<<a[i]<<endl;
        printf("%d",a[i]);
    }
     */
    
    int a=10;
    int &r=a;
    printf("%d %d",a,r);
    return 0;
}
