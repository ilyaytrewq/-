#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int key;
    int value;
    int height;
    struct Node* left, * right;
} Node;

Node* CreateNode(int key, int value)
{
    Node* node = (Node *)malloc(sizeof(Node));

    if (node == NULL)
    {
        printf("Error in creation\n");
        exit(-1);
    }

    node->key = key;
    node->value = value;
    node->height = 1;
    node->left = NULL;
    node->right = NULL;

    return node;
}

int height(Node* node)
{
    return (node == NULL ? 0 : node->height);
}

void update(Node* node)
{
    node->height = (height(node->left) > height(node->right) ? height(node->left) : height(node->right)) + 1;
}

int balance(Node* node)
{
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

Node* LeftRotation(Node* pred, Node* node)
{
    pred->right = node->left;
    node->left = pred;
    update(pred);
    update(node);
    return node;
}

Node* RightRotation(Node* pred, Node* node)
{
    pred->left = node->right;
    node->right = pred;
    update(pred);
    update(node);
    return node;
}

Node* RightZigZag(Node* pred, Node* node)
{
    node = LeftRotation(node, node->right);
    return RightRotation(pred, node);
}

Node* LeftZigZag(Node* pred, Node* node)
{
    node = RightRotation(node, node->left);
    return LeftRotation(pred, node);
}

Node* FindNode(Node* node, int key)
{
    if (node == NULL)
    {
        return node;
    }
    else if (node->key == key)
    {
        return node;
    }
    else if (node->key < key)
    {
        return FindNode(node->right, key);
    }
    else
    {
        return FindNode(node->left, key);
    }
    return NULL;
}

Node* MakeBalanced(Node* node)
{

    if (node == NULL)
        return node;

    update(node);

    if (balance(node) == 2)
    {
        if (balance(node->left) >= 0)
        {
            node = RightRotation(node, node->left);
        }
        else
        {
            node = RightZigZag(node, node->left);
        }
    }
    else if (balance(node) == -2)
    {
        if (balance(node->right) <= 0)
        {
            node = LeftRotation(node, node->right);
        }
        else
        {
            node = LeftZigZag(node, node->right);
        }
    }

    update(node);
    return node;
}

Node* InsertNode(Node* node, int key, int value)
{
    if (node == NULL)
    {
        return CreateNode(key, value);
    }

    if (node->key == key)
    {
        node->value = value;
        return node;
    }

    if (node->key < key)
    {
        node->right = InsertNode(node->right, key, value);
    }
    else
    {
        node->left = InsertNode(node->left, key, value);
    }

    node = MakeBalanced(node);

    return node;
}

Node* GetMin(Node* node)
{
    return (node->left ? GetMin(node->left) : node);
}

Node* DeleteNode(Node* node, int key)
{
    if (node == NULL)
    {
        return node;
    }
    if (node->key < key)
    {
        node->right = DeleteNode(node->right, key);
        return MakeBalanced(node);
    }
    else if (node->key > key)
    {
        node->left = DeleteNode(node->left, key);
        return MakeBalanced(node);
    }
    else
    {
        Node* tmp = NULL;
        if ((node->left == NULL) || (node->right == NULL))
        {
            tmp = (node->left ? node->left : node->right);
        }
        else
        {
            Node* mn = GetMin(node->right);

            tmp = CreateNode(mn->key, mn->value);
            tmp->right = DeleteNode(node->right, tmp->key);
            tmp->left = node->left;
        }
        free(node);
        tmp = MakeBalanced(tmp);
        return tmp;
    }
}

void FreeTree(Node* node)
{
    if (node == NULL)
        return;
    FreeTree(node->left);
    FreeTree(node->right);
    free(node);
}

int main(int argc, char const* argv[])
{
    char op = '-';
    Node* root = NULL;
    while (op != 'F')
    {
        do
        {
            scanf("%c", &op);
        } while (op == '\n');

        if (op == 'A')
        {
            int key, value;
            scanf("%d %d", &key, &value);
            root = InsertNode(root, key, value);
        }
        else if (op == 'S')
        {
            int key;
            scanf("%d", &key);
            Node* node = FindNode(root, key);

            if (node != NULL)
            {
                printf("%d %d\n", node->key, node->value);
            }
        }
        else if (op == 'D')
        {
            int key;
            scanf("%d", &key);
            if (FindNode(root, key) != NULL)
                root = DeleteNode(root, key);
        }
    }
    FreeTree(root);
    return 0;
}
