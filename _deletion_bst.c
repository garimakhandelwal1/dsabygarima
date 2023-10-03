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
    static struct node *prev = NULL;
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
        return 1; // return true
    }
}
void insert(struct node *root, int key)
{
    struct node *prev = NULL;
    struct node *ptr; // follow root
    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            printf("cannot insert %d already in bst", key);
            return;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    // here previous pointer holds a value before the updation of root pointer  which is previous value
    // when root is at 3 prev at 5 when root is null ,prev at 1,and then we use prev to see whether to insert node on lhs or rhs
    struct node *new = createnode(key);
    if (key < prev->data)
    {
        prev->left = new;
    }
    else
    {
        prev->right = new;
    }
    // bcoz root is null and we have to link on prev left and right
}
// delete node function
// it returns node because
struct node *inorderpredecessor(struct node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        // jaise hi yeh condition false ho gyi matlab we reach at leaf node and return root
        root = root->right;
    }
    return root;
}

struct node *deletenode(struct node *root, int value)
{
    struct node *ipre;
    // this whole process runs recursively so we have to writ termination con
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        // means this is a leaf node free that memory location
        free(root);
        return NULL;
    }

    // search for the node to be deleted
    if (value < root->data)
    {
        root->left = deletenode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deletenode(root->right, value);
    }
    // deletion strategy(we found the node)
    else
    {
        ipre = inorderpredecessor(root);
        // this root value updates
        root->data = ipre->data;
        // here inorderpre ki value ko utha ke vha rakh diya jiski value ko delete krna tha
        root->left = deletenode(root->left, ipre->data);
        // so we delete that node jha pe inorderpre tha
        // here we say iss parti (root->left)wale tree me se(ipre->dta)wali value ko delete krdo
        // so we return updtae version of that tree
    }
    return root;
    // return krde denge vhi node jiske liye run ho rha h
}
int main()
{
    // constructing the root node using function
    struct node *p = createnode(5);
    struct node *p1 = createnode(3);
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
    deletenode(p, 1);
    printf("\n");
    // printf("|data is %d|",p->data);
    printf("\n");
    inorder(p);
    return 0;
}