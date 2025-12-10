#include <stdlib.h>
#include <stdio.h>

struct Array
{
    int A[10];
    int length;
    int size;
};

void display(struct Array A)
{
    for(int i=0;i<A.length;i++)
    {
        printf("%d ",A.A[i]);
    }
    printf("\n");
}

void append(struct Array *Arr,int value)
{
    if(Arr->length<Arr->size)
    {
        Arr->A[Arr->length++]=value;
    }
}

void insert(struct Array *Arr, int index, int value)
{
    if(index >= 0 && index <= Arr->length)
    {
        for(int i=Arr->length;i>index;i--)
        {
            Arr->A[i]=Arr->A[i-1];
            
        }
        Arr->A[index]=value;
        Arr->length++;
    }
}

void delete(struct Array *arr, int index)
{
    if(index >= 0 && index < arr->length)  //make sure this is properly defined
    {
        for(int i=index;i<arr->length-1;i++)
        {
            arr->A[i]=arr->A[i+1];
        }
        arr->length--;
    }
}

int LinearSearch(struct Array *arr, int key)
{
    for(int i=0;i<arr->length;i++)
    {
        if(key==arr->A[i])
        {
            return i;
        }
    }
    return -1;
}


void swap(int *p,int *q)
{
    int temp;
    temp = *p;
    *p = *q;  //initial mistake was p = q; changes the local pointer p to point to the same location as q, but this does not affect the actual pointer p passed to the function.
    *q= temp;
}

int ImprovedLinearSearch(struct Array *arr, int key)
{
    for(int i=0;i<arr->length;i++)
    {
        if(key==arr->A[i])
        {
            swap(&arr->A[i],&arr->A[0]);   //this first to head improvement method.
            //can use trasnposition method where ,swap(&arr->A[i],&arr->A[i-1]).
            return i;
        }
    }
    return -1;
}

int BinarySearch(struct Array arr,int key)
{
    int low = 0;
    int high = arr.length-1;
    int mid;
    
    while(low<=high)
    {
        mid = (high + low)/2;
        if(key == arr.A[mid])
            return mid;
        else if(key < arr.A[mid])
            high = mid-1;
        else if(key > arr.A[mid])
            low = mid+1;
        else{
            printf("element not found");
        }
    }
    
    
    //printf("%d",high);
    return 0;
}

int get(struct Array arr, int key)
{
    for(int i=0;i<=arr.length;i++)
    {
        if(key==arr.A[i])
            return i;
    }
    return -1;
}

int set(struct Array *arr, int index, int key)
{
    if(index >= 0 || index <arr->length)
    {
        for(int i=0;i<=arr->length;i++)
        {
            if(i==index)
            {
                return arr->A[i]=key;
            }
        }
    }
    return -1;
}

int max(struct Array arr)
{
    int m = arr.A[0];
    for(int i=0;i<arr.length;i++)
    {
        if(arr.A[i]>m)
        {
            m=arr.A[i];
        }
    }
    return m;
}

int sum(struct Array arr)
{
    int sum = 0;
    for(int i=0;i<arr.length;i++)
    {
        sum += arr.A[i];
    }
    return sum;
}

void Reverse(struct Array *arr)     //Reverse using auxiliary/extra array
{
    printf("\n Reversing the array\n");
    int *b;
    int i,j;
    
    b =(int *)malloc(arr->length*sizeof(int));
    
    for(i=arr->length-1,j=0;i>=0;i--,j++)
    {
        b[j]=arr->A[i];
    }
    
    for(i=0;i<arr->length;i++)
    {
        arr->A[i]=b[i];
    }
}

void Reverse2(struct Array *arr)
{
    printf("\n Reversing the array\n");
    int i,j;
    for(i=0,j=arr->length-1;i<j;i++,j--)
    {
        swap(&arr->A[i],&arr->A[j]);
    }
}

void nextline(void)
{
    printf("\n\n");
}

// This needs to be still fixed insert_sortedarray
void insert_sortedarray(struct Array *arr, int key)
{
    int i= arr->length-1;
    if(arr->length==arr->size)
        return;
    while (i >= 0 && arr->A[i] > key) {
           arr->A[i + 1] = arr->A[i];
           i--;
       }
    arr->A[i+1]=key;
    arr->length++;
}

int isSorted(struct Array arr)
{
    for(int i = 0; i < arr.length - 1; i++)  // Iterate from index 0 to the second-to-last index
    {
        if(arr.A[i] > arr.A[i+1])  // If the current element is greater than the next element
            return 0;  // Return 0, meaning the array is **not sorted**
    }
    return 1;  // Return 1, meaning the array is **sorted** in ascending order
}

 
//This function rearranges negative and positive value in an array
void Rearrange(struct Array *arr)
{
    int i = 0;  // Start index from the left of the array
    int j = arr->length - 1;  // Start index from the right of the array
    
    while (i < j)  // Continue looping as long as i is less than j
    {
        // Find the first positive number from the left side
        while (arr->A[i] < 0) i++;  // Move i to the right until you find a non-negative number
        
        // Find the first negative number from the right side
        while (arr->A[j] >= 0) j--;  // Move j to the left until you find a negative number
        
        // If i < j, swap the elements at i and j
        if (i < j) {
            swap(&arr->A[i], &arr->A[j]);  // Swap the negative and positive elements
        }
    }
}

struct Array * Merge(struct Array arr,struct Array arr1)
{
    int i,k,j;
    i=k=j=0;
    struct Array *arr3;
    arr3 = (struct Array *)malloc(sizeof(struct Array));
    
    while(i<arr.length && j<arr1.length)
    {
        if(arr.A[i]<arr.A[j])
            arr3->A[k++]=arr.A[i++];
        else
            arr3->A[k++]=arr1.A[j++];
    }
    
    for(;i<arr.length;i++)
        arr3->A[k++]=arr.A[i];
    for(;i<arr1.length;i++)
        arr3->A[k++]=arr1.A[i];
    
    arr3->length = arr.length+arr1.length;
    arr3->size=10;
    return arr3;
}

int main(int argc, const char * argv[]) {
    
    struct Array A1 = {{2,4,3,2},4,10};
    //append(A1,3,22);
    //append(&A1,66);
    insert(&A1, 3, 23);         //OP: 2 4 3 23 2
    append(&A1,66);             //OP: 2 4 3 23 2 66
    insert(&A1,7 , 23);         //OP: invalid, as the length of array is small
    display(A1);
    printf("\n");
    delete(&A1, 5);
    display(A1);
    printf("\n");
    printf("the index it is found at %d",ImprovedLinearSearch(&A1,23));
    printf("\n");
    display(A1);
    printf("\n");
    printf("the index it is found at %d",LinearSearch(&A1,23));
     
    //Binary Search
    struct Array A2 = {{11,22,33,44,55,66,77,88,99,222},10,10};
    printf("Element found at index %d ",BinarySearch(A2, 22));
    
    printf("element index is %d\n",get(A2, 55));
    
    set(&A2,4,555);
    display(A2);
    
    
    printf("\nmax element is %d\n",max(A2));
    
    printf("sum element is %d\n",sum(A2));
    
    
    Reverse(&A2);
    display(A2);
    
    Reverse2(&A2);
    display(A2);
    
    nextline();
    
    struct Array A3 = {{1,22,33,24,55,66,77,88,99,222},10,16};
    //insert_sortedarray(&A3,102);
    //this is giving garbage value after insertion needs to be looked into
    //display(A3);
    
    //Checking if array is sorted or not
    printf("sorted %d \n",isSorted(A3));
    
    
    //Rearraning array into positive and negative
    struct Array A4 = {{1,-9,3,6,-8},5,7};
    Rearrange(&A4);
    display(A4);
    
    
    //Merging of array
    struct Array arr5={{2,9,21,28,35},5,10};
    struct Array arr6={{2,3,16,18,28},5,10};
    struct Array *arr33;
    arr33=Merge(arr5,arr6);
    display(*arr33);
    return 0;}
