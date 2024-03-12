#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left_node;
    struct Node *right_node;
};

struct BST
{
    struct Node *root_node;
};

struct BST *create_BST()
{
    struct BST *binary_search_tree = (struct BST*)malloc(sizeof(struct BST));
    binary_search_tree -> root_node = NULL;
    return (binary_search_tree);
}

int bst_insert(struct BST *obj, int val)
{
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node -> data = val;
    new_node -> right_node= NULL;
    new_node -> left_node = NULL;

    if (obj -> root_node == NULL)
    {
        obj -> root_node = new_node;
        return (1);
    }

    struct Node *controller = obj -> root_node;
    while (1)
    {
        if (val < (controller -> data))
        {
            if (!controller -> left_node)
            {
                controller -> left_node = new_node;
                return (1);
            }
            controller = controller -> left_node;
        }
        else if (val > (controller -> data))
        {
            if (!controller -> right_node)
            {
                controller -> right_node = new_node;
                return (1);
            }
            controller = controller -> right_node;
        }
        else
            return (-999);
    }
}

int bst_contains(struct BST *obj, int val)
{
    struct Node *controller = obj -> root_node;
    while (controller)
    {
        if (val > controller -> data)
            controller = controller -> right_node;
        else if (val < controller -> data)
            controller = controller -> left_node;
        else
            return (1);
    }
    return (0);
}

int bst_minimum(struct BST *obj)
{
    while (obj -> root_node)
    {
        struct Node *controller = obj -> root_node;
        while (controller -> left_node)
            controller = controller -> left_node;
        return (controller -> data);
    }
    return (-999);
}

int bst_maximum(struct BST *obj)
{
    while (obj -> root_node)
    {
        struct Node *controller = obj -> root_node;
        while (controller -> right_node)
            controller = controller -> right_node;
        return (controller -> data);
    }
    return (-999);
}
