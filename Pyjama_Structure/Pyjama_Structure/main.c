#include <stdio.h>

typedef struct _abc{
    int a;
    int b;
    char f;
}  __attribute__((packed)) abc;

typedef struct _ewq{
    int a;
    int b;
    char f;
}  ewq;

struct xyz
{
    int q;
    abc t;
    float w;
};

int main(int argc, const char * argv[]) {
    
    printf("sizeof abc (structure padding) : %lu\n",sizeof(abc));
    printf("sizeof abc (structure padding) : %lu\n",sizeof(ewq));
    ewq a; //same as struct _ewq a;
    a.a = 10;
    printf("%d\n",a.a);
    
    struct xyz q;
    q.t.b = 144;
    printf("sizeof xyz (structure padding) : %lu\n",sizeof(struct xyz));
    printf("accessing nested struct %d\n",q.t.b);
    //creation of struct array
    struct xyz struct1[10];
    printf("%p\n",&struct1[6].t.b);
    printf("%p\n",&struct1[6].t);
    
    
    return 0;
}
