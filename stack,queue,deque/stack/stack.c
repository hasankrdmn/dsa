#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *previous;
}node;

typedef struct {
    node *front;
    node *rear;
}array;

typedef struct {
    array *stack;
}stack;

stack *createStack();
array *createArray();
void myStack_push(stack *obj, int data);
int myStack_pop(stack *obj);
void myStack_show(stack *obj);
void myStack_free(stack *obj);

int main()
{
    stack *mystack = createStack();
    myStack_push(mystack, 1);
    myStack_push(mystack, 2);
    myStack_pop(mystack);
    myStack_push(mystack, 3);
    myStack_push(mystack, 4);
    myStack_pop(mystack);
    myStack_push(mystack, 5);
    myStack_show(mystack);
    myStack_free(mystack);
}

stack *createStack()
{
    stack *st = malloc(sizeof(stack));
    st -> stack = createArray();
    return (st);
}

array *createArray()
{
    array *arr = malloc(sizeof(array));
    arr -> front = NULL;
    arr -> rear = NULL;
    return (arr);
}

void myStack_push(stack *obj, int data)
{
    node *new_node = malloc(sizeof(node));
    new_node -> data = data;
    new_node -> previous = obj -> stack -> rear;
    new_node -> next = NULL;

    if (obj -> stack -> rear == NULL)
    {
        new_node -> previous = NULL;
        obj -> stack -> front = new_node;
        obj -> stack -> rear = new_node;
        return;
    }
    obj -> stack -> rear -> next = new_node;
    obj -> stack -> rear = new_node;
}

int myStack_pop(stack *obj)
{
    if (obj -> stack -> rear == NULL)
    {
        return (-999);
    }
    int val = obj -> stack -> rear -> data;
    node *tmp = obj -> stack -> rear;
    obj -> stack -> rear = obj -> stack -> rear -> previous;
    obj -> stack -> rear -> next = NULL;
    free(tmp);
    return (val);
}

void myStack_show(stack *obj)
{
    if (obj -> stack -> front == NULL)
    {
        return;
    }
    node *tmp = obj -> stack -> front;
    while (obj -> stack -> front != NULL)
    {
        printf("%d\n", obj -> stack -> front -> data);
        obj -> stack -> front = obj -> stack -> front -> next;
    }
    obj -> stack -> front = tmp;
}

void myStack_free(stack *obj)
{
    free(obj);
}