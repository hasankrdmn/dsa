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
    array *queue;
}queue;

queue *createQueue()
{
    queue *qu = malloc(sizeof(queue));
    qu -> queue = createArray();
    return (qu);
}

array *createArray()
{
    array *arr = malloc(sizeof(array));
    arr -> front = NULL;
    arr -> rear = NULL;
    return (arr);
}

void myQueue_enqueue(queue *obj, int data)
{
    node *new_node = malloc(sizeof(node));
    new_node -> data = data;
    new_node -> previous = obj -> queue -> rear;
    new_node -> next = NULL;

    if (obj -> queue -> rear == NULL)
    {
        new_node -> previous = NULL;
        obj -> queue -> front = new_node;
        obj -> queue -> rear = new_node;
        return;
    }
    obj -> queue -> rear -> next = new_node;
    obj -> queue -> rear = new_node;
}

int myQueue_dequeue(queue *obj)
{
    if (obj -> queue -> rear == NULL)
    {
        return (-999);
    }
    int val = obj -> queue -> front -> data;
    node *tmp = obj -> queue -> front;
    obj -> queue -> front = obj -> queue -> front -> next ;
    obj -> queue -> front -> previous = NULL;
    free(tmp);
    return (val);
}

void myQueue_show(queue *obj)
{
    if (obj -> queue -> front == NULL)
    {
        return;
    }
    node *tmp = obj -> queue -> front;
    while (obj -> queue -> front != NULL)
    {
        printf("%d\n", obj -> queue -> front -> data);
        obj -> queue -> front = obj -> queue -> front -> next;
    }
    obj -> queue -> front = tmp;
}

void myQueue_free(queue *obj)
{
    if (obj == NULL)
    {
        return;
    }
    node *cur = obj -> queue -> front;
    while (cur != NULL)
    {
        node *tmp = cur;
        cur = cur -> next;
        free(tmp);
    }
    free(obj -> queue);
    free(obj);
}
