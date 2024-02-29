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
}stack;

typedef struct {
    stack *stack;
}mystack;

stack *createStack();
void myStack_push(stack *obj, int data);
int myStack_pop(stack *obj);
void myStack_show(stack *obj);
void myStack_free(stack *obj);

// int main()
// {
//     stack *mystack = createStack();
//     myStack_push(mystack, 1);
//     myStack_push(mystack, 2);
//     myStack_pop(mystack);
//     myStack_push(mystack, 3);
//     myStack_push(mystack, 4);
//     myStack_pop(mystack);
//     myStack_push(mystack, 5);
//     myStack_show(mystack);
//     myStack_free(mystack);
// }

stack *createStack()
{
    stack *s = malloc(sizeof(stack));
    s -> front = NULL;
    s -> rear = NULL;
    return (s);
}

void myStack_push(stack *obj, int data)
{
    node *new_node = malloc(sizeof(node));
    new_node -> data = data;
    new_node -> previous = obj -> rear;
    new_node -> next = NULL;

    if (obj -> rear == NULL)
    {
        new_node -> previous = NULL;
        obj -> front = new_node;
        obj -> rear = new_node;
        return;
    }
    obj -> rear -> next = new_node;
    obj -> rear = new_node;
}

int myStack_pop(stack *obj)
{
    if (obj -> rear == NULL)
    {
        return (-999);
    }
    int val = obj -> rear -> data;
    node *tmp = obj -> rear;
    obj -> rear = obj -> rear -> previous;
    obj -> rear -> next = NULL;
    free(tmp);
    return (val);
}

void myStack_show(stack *obj)
{
    if (obj -> front == NULL)
    {
        return;
    }
    node *tmp = obj -> front;
    while (obj -> front != NULL)
    {
        printf("%d\n", obj->front->data);
        obj -> front = obj -> front -> next;
    }
    obj -> front = tmp;
}

void myStack_free(stack *obj)
{
    free(obj);
}
