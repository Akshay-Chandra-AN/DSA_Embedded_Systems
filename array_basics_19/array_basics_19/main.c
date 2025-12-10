#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {

/****Declaration***/
    int a[5];                               //declare to 5 array size
    int a1[]={1,2,3,4,5,6};                 //size is the total length
    int a2[5]={3,5};                        //the rest are filled with zero
    int a3[5]={0};                          //all elements are zero
    
//Accessing elements
    //1st method
    
    printf("a1[3] is %d\n",a1[3]);
    printf("the elements in a1 are: ");
    for(int i=0;i<=5;i++)
        printf("%d ",a1[i]);
    printf("\n");
    
    //2nd method
    printf("2[a1] is %d \n",2[a1]);                  //2[a1] is similar to a1[2]
    
    //using pointer arithmetic
    printf("*(a1+2) is %d \n",*(a1+2));                //base address + 2
    
    //dynamic array ie array in heap        ex 18
    int *p;
    p=(int *)malloc(5*sizeof(int));
    p[2] = 55;
    
    printf("dynamic array p[2])  : %d \n",p[2]);
    printf("dynamic array *(p+2) : %d \n",*(p+2));
    //free(p);      you need to free it, not doing this now as p is used in next code section
    
    //Increasing array in heap, stack cannot be resized
    int *q;
    q=(int *)malloc(10*sizeof(int));
    for(int i=0;i<5;i++)
        q[i]=p[i];
    free(p);
    p=q;
    q = NULL;
    p[7]=777;
    printf("p[7] (now p size is increased) : %d \n",p[7]);
    
    
    /************************************************2D ARRAY*******************************************************************/
    
    /****Declaration***/
    //method 1
    int b[3][4]={{1,2,3,4},{5,6,7,8},{11,22,33,44}};
    //Note for 2 d array ,printf("%d \n",b[5]);, this doesnt work.
    
    //accessing elements
    printf("array elements for 2d array are : ");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
            printf("8 %d ",b[i][j]);
    }
    
    //method 2
    int *ptr1[4];                       //ptr in stack and array in heap
    ptr1[0] = (int *)malloc(4*sizeof(int));
    ptr1[1] = (int *)malloc(4*sizeof(int));
    ptr1[2] = (int *)malloc(4*sizeof(int));
    ptr1[3] = (int *)malloc(4*sizeof(int));
    
    ptr1[0][1]=110;
    ptr1[1][1]=210;
    
    //accessing elements
    printf("\n2d array : method 2 %d ",ptr1[0][1]);
    printf("\n2d array : method 2 %d ",ptr1[1][1]);
    
    //method 3                          //ptr and array in heap
    int **ptr2;
    ptr2 = (int **)malloc(4*sizeof(int *));     //ptr in heap
    
    ptr2[0] = (int *)malloc(4*sizeof(int));     //array in heap
    ptr2[1] = (int *)malloc(4*sizeof(int));
    ptr2[2] = (int *)malloc(4*sizeof(int));
    ptr2[3] = (int *)malloc(4*sizeof(int));
    
    ptr2[0][1]=110;
    ptr2[1][1]=210;
    
    //accessing elements
    printf("\n2d array : method 3 %d",ptr2[0][1]);
    printf("\n2d array : method 3 %d",ptr2[1][1]);
   
    
    
    
    return 0;
}
