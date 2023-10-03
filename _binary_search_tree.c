#include <stdio.h>
#include <malloc.h>
// not understand (dry run )
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *createnode(int data)
{
    struct node *n;                                 // creating a node pointer
    n = (struct node *)malloc(sizeof(struct node)); // allocating memeory in the heap
    n->data = data;                                 // setting the data
    n->left = NULL;                                 // setting the left and right children to null
    n->right = NULL;
    return n; // finally returning the creted node
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d  ", root->data);
        inorder(root->right);
    }
}
// not unde
int isBST(struct node *root)
{
    static struct node*prev= NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0; // return false
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0; // return false
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;//return true 
    }
}

int main()
{
    // constructing the root node using function
    struct node *p = createnode(5);
    struct node *p1 = createnode(3 );
    struct node *p2 = createnode(6);
    struct node *p3 = createnode(1);
    struct node *p4 = createnode(4);
    // finally the tree look like this
    //        5
    //       / |
    //       3  6
    //      / |
    //      1 4

    // linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    inorder(p);
    printf("\n");
    //printf("%d",isBST(p));
    if (isBST(p))
    {
        printf("this is a BST");
    }
    
    return 0;
}