#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[13]; //this is in stack now   for array in heap --> int *A;
    int size;
    int length;
};

void display(struct Array arr)
{
    int i;
    printf("\nElements are \n");
    for(i = 0;i<arr.length;i++)
        printf("%d ",arr.A[i]);
}

void append(struct Array *arr, int x) //call by address -> to modify array
{
    //check space is there r not
    if(arr->length < arr->size)
        arr->A[arr->length++]= x;
}

void insert(struct Array *arr, int index, int x)
{
    if(index >= 0 && index <=arr->length)
    {
        for(int i=arr->length;i>index;i--)
            arr->A[i]=arr->A[i-1];
        
        arr->A[index]=x;
        arr->length++;
    }
    else
        printf("cant insert at index");
}

int delete(struct Array *arr, int index)
{
    int x=0;
    if(index >= 0 && index <=arr->length)
    {
        x=arr->A[index];
        for(int i=index;i<arr->length-1;i++)
        {
            arr->A[i]=arr->A[i+1];
        }
        arr->length--;
        return x;
    }
    return 0;
}

int LinearSearch(struct Array arr,int key)  //pass by value, as you just need to find  and not modify
{
    int i;
    for(i=0;i<arr.length;i++)
    {
        if(key==arr.A[i])
            return i;
    }
    return -1;
}

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int ImprovedLinearSearch(struct Array *arr,int key)  //pass by value, as you just need to find  and not modify
{
    int i;
    for(i=0;i<arr->length;i++)
    {
        if(key==arr->A[i])
        {
            //swap(&arr->A[i],&arr->A[i-1]);      //option 1 : swap values and bring to front by 1 index
            swap(&arr->A[i],&arr->A[0]);          //option 2 : swap and bring to index 0
            return i;
        }
    }
    return -1;
}

int BinarySearch(struct Array arr,int key)
{
    int h,l,mid;
    l = 0;
    h = arr.length -1;
    
    
    while(l<=h)
    {
        mid = (l+h)/2;
        if(key==arr.A[mid])
            return mid;
        else if (key < arr.A[mid])         ////when key is on left side of mid, make high just before mid
            h= mid-1;
        else
            l = mid+1;                     ////when key is on right side of mid, make low just after mid
    }
    return -1;
}

int RecursiveBinary(int a[],int l, int h, int key)      //recursive way if binary search
{
    int mid;
    
    if(l<=h)
    {
        mid = (l+h)/2;
        if(key==a[mid])
            return mid;
        else if (key < a[mid])
            RecursiveBinary(a,l,mid-1,key);
        else
            RecursiveBinary(a,mid+1,h,key);
    }
    return -1;
}

void reverse(struct Array *arr)
{
    int *B;
    int i,j;
    
    B=(int *)malloc(arr->length*sizeof(int));
    for(i=arr->length-1,j=0;i>=0;i--,j++)
        B[j]=arr->A[i];
    for(i=0;i<arr->length;i++)
        arr->A[i]=B[i];
}

void reverse2(struct Array *arr)
{
    int j;
    for(int i=0,j=arr->length-1;i<j;i++,j--)
    {
        swap(&arr->A[i],&arr->A[j]);
    }
}

void insertsort(struct Array *arr, int x)
{
    if(arr->length==arr->size)
        return;
    int i=arr->length-1;
    while(i>=0 && arr->A[i]>x)
    {
        arr->A[i+1]=arr->A[i];
        i--;
    }
    arr->A[i+1]=x;
    arr->length++;
}

int isSorted(struct Array arr)
{
    int i;
    for(i=0;i<arr.length-1;i++)
    {
        if(arr.A[i]>arr.A[i+1])
            return 0;
    }
    return 1;
}

void rearrange(struct Array *arr)
{
    int i,j;
    i=0;
    j=arr->length-1;
    
    while (i<j)
    {
        while(arr->A[i]<0) i++;
        while(arr->A[j]>=0) j--;
        if(i<j) swap(&arr->A[i],&arr->A[j]);
    }
}

struct Array* sortedMerge(struct Array *arr1, struct Array *arr2)
{
    int i,j,k;
    i=k=j=0;
    
    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));
    //arr3->A = (int *)malloc(arr3->size * sizeof(int));
    while (i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
        else
            arr3->A[k++]=arr2->A[j++];
    }
    
    for(;i<arr1->length;i++)
        arr3->A[k++]=arr1->A[i];
    for(;j<arr2->length;j++)
        arr3->A[k++]=arr2->A[j];
    arr3->length=arr1->length+arr2->length;
    arr3->size=200;
    return arr3;
}

int main(int argc, const char * argv[]) {
    struct Array arr1;
    
    //******this part of code is array in heap****************
    //note : in struct make int *A, instead of int A[20]
//    printf("enter size of an array");
//    scanf("%d",&arr1.size);
//    arr1.A=(int *)malloc(arr1.size * sizeof(int));
//    arr1.length = 0;
    
    //*******Input the array property************
//    int n,i;
//    printf("Enter number of num \n");    //this is the length of actual array
//    scanf("%d",&n);
//    
//    printf("enter all elements \n");     //Entering the elements of array
//    for(i=0;i<n;i++)
//        scanf("%d",&arr1.A[i]);
//    arr1.length = n;
//    display(arr1);                        //Display the elements of array
    
    
    //***********Array in stack*******************
    struct Array arr= {{2,3,4,5,77,555},10,6};
//    append(&arr, 10);
//    insert(&arr,3,321);               //insert at right index
//    insert(&arr,9,121);               //inserting at wrong index
//    delete(&arr, 0);                    //Deleting at given index
//    printf("Search result %d\n",ImprovedLinearSearch(&arr, 4));           //Linear Search
//    printf("Search result %d\n",ImprovedLinearSearch(&arr, 4));           //Improved Linear Search
//    printf("Search result %d\n",BinarySearch(arr, 5));                      //Binary Search
//    printf("Search result %d\n",RecursiveBinary(arr.A,0,arr.length, 99));   //Recursive Binary Search
//    display(arr);
    
    //Reversing an array 2 methods
//    reverse(&arr);
//    reverse2(&arr);
//    display(arr);
    
    //Insert Sort
//    insertsort(&arr, 2.4);
//    display(arr);
    
    //Array is sorted or not
//    printf("%d\n",isSorted(arr));
    
    //-ve of lhs rearrange
//    struct Array arr2= {{2,3,-4,5,77,-555},10,6};
//    rearrange(&arr2);
//    display(arr2);
    
    //Merge 2 sorted array
//    struct Array arr3= {{2,3,4,5,77,555},10,6};
//    struct Array arr4= {{4,6,8,10,177,255},10,6};
//    struct Array *arr5 = sortedMerge(&arr3, &arr4);
//    display(*arr5);
    return 0;
}
