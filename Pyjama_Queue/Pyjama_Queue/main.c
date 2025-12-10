#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    struct node *next;
    int data;
}node;

node *head;
node *tail;

void init(int adata)
{
    head = malloc(sizeof(node));
    head->next = NULL;
    head->data = adata;
    tail = head;
}

int add_end(int bdata)
{
    node *n;
    n = malloc(sizeof(node));
    
    n->data= bdata;
    n->next = NULL;
    
    node *cursor=head;
    for(cursor = head;
        cursor->next != NULL;
        cursor = cursor->next)
    {
        
    }
    cursor->next = n;
    return 0;
}

int queue(int bdata)
{
    node *n;
    n = malloc(sizeof(node));
    
    n->data= bdata;
    n->next = NULL;
    
    tail->next = n;
    tail = n;
    return 0;
}

int fetch()
{
    if(!head)
    {
        return -1;
    }
    
    int first;
    node *delete;
    first = head->data;
    delete = head;
    head = head->next;
    free(delete);
    printf("%d ", first);
    return 0;
}

void traverse(void)
{
    for(node *cursor = head;
        cursor != NULL;
        cursor = cursor->next)
    {
        printf("traversal : %d ",cursor->data);
    }
}

int main(int argc, const char * argv[]) {
    init(10);
    queue(55);
    queue(552);
    traverse();
    fetch();
    fetch();
  
    traverse();
    return 0;
}
