#include "balanced_tree.h"

#include <stdio.h>
#include <stdlib.h>


/*
 * ============================================================
 * Utility Functions
 * ============================================================
 */

static int max(
    int a,
    int b
)
{
    return a > b ? a : b;
}


int avl_height(
    const AVLNode *root
)
{
    if (root == NULL)
    {
        return 0;
    }

    return root->height;
}


static void update_height(
    AVLNode *node
)
{
    if (node == NULL)
    {
        return;
    }

    node->height =
        1 +
        max(
            avl_height(node->left),
            avl_height(node->right)
        );
}


static int balance_factor(
    const AVLNode *node
)
{
    if (node == NULL)
    {
        return 0;
    }

    return
        avl_height(node->left) -
        avl_height(node->right);
}


/*
 * ============================================================
 * Rotations
 * ============================================================
 *
 * Right rotation:
 *
 *          y                 x
 *         / \               / \
 *        x   T3    -->      T1  y
 *       / \                   / \
 *      T1 T2                 T2 T3
 *
 * Left rotation:
 *
 *        x                     y
 *       / \                   / \
 *      T1  y       -->       x  T3
 *         / \               / \
 *        T2 T3             T1 T2
 *
 * Rotations preserve the BST ordering property while changing
 * the tree's shape.
 * ============================================================
 */

static AVLNode *rotate_right(
    AVLNode *y
)
{
    AVLNode *x =
        y->left;

    AVLNode *subtree =
        x->right;


    x->right = y;

    y->left = subtree;


    update_height(y);

    update_height(x);


    return x;
}


static AVLNode *rotate_left(
    AVLNode *x
)
{
    AVLNode *y =
        x->right;

    AVLNode *subtree =
        y->left;


    y->left = x;

    x->right = subtree;


    update_height(x);

    update_height(y);


    return y;
}


/*
 * ============================================================
 * Node Creation
 * ============================================================
 */

static AVLNode *create_node(
    int key
)
{
    AVLNode *node =
        malloc(
            sizeof(AVLNode)
        );


    if (node == NULL)
    {
        return NULL;
    }


    node->key = key;

    node->height = 1;

    node->left = NULL;

    node->right = NULL;


    return node;
}


/*
 * ============================================================
 * Rebalancing
 * ============================================================
 */

static AVLNode *rebalance(
    AVLNode *node
)
{
    if (node == NULL)
    {
        return NULL;
    }


    update_height(node);


    int balance =
        balance_factor(node);


    /*
     * Left-heavy tree.
     */
    if (balance > 1)
    {
        /*
         * Left-Right case.
         */
        if (
            balance_factor(node->left) < 0
        )
        {
            node->left =
                rotate_left(
                    node->left
                );
        }


        /*
         * Left-Left case.
         */
        return rotate_right(node);
    }


    /*
     * Right-heavy tree.
     */
    if (balance < -1)
    {
        /*
         * Right-Left case.
         */
        if (
            balance_factor(node->right) > 0
        )
        {
            node->right =
                rotate_right(
                    node->right
                );
        }


        /*
         * Right-Right case.
         */
        return rotate_left(node);
    }


    return node;
}


/*
 * ============================================================
 * AVL Insertion
 * ============================================================
 */

AVLNode *avl_insert(
    AVLNode *root,
    int key
)
{
    if (root == NULL)
    {
        return create_node(key);
    }


    if (key < root->key)
    {
        root->left =
            avl_insert(
                root->left,
                key
            );
    }
    else if (key > root->key)
    {
        root->right =
            avl_insert(
                root->right,
                key
            );
    }
    else
    {
        /*
         * Ignore duplicate keys.
         */
        return root;
    }


    return rebalance(root);
}


/*
 * ============================================================
 * Search
 * ============================================================
 */

AVLNode *avl_search(
    AVLNode *root,
    int key
)
{
    if (
        root == NULL ||
        root->key == key
    )
    {
        return root;
    }


    if (key < root->key)
    {
        return avl_search(
            root->left,
            key
        );
    }


    return avl_search(
        root->right,
        key
    );
}


/*
 * ============================================================
 * Find Minimum Node
 * ============================================================
 */

static AVLNode *find_min(
    AVLNode *root
)
{
    AVLNode *current = root;


    while (
        current != NULL &&
        current->left != NULL
    )
    {
        current =
            current->left;
    }


    return current;
}


/*
 * ============================================================
 * AVL Deletion
 * ============================================================
 */

AVLNode *avl_delete(
    AVLNode *root,
    int key
)
{
    if (root == NULL)
    {
        return NULL;
    }


    if (key < root->key)
    {
        root->left =
            avl_delete(
                root->left,
                key
            );
    }
    else if (key > root->key)
    {
        root->right =
            avl_delete(
                root->right,
                key
            );
    }
    else
    {
        /*
         * Node has at most one child.
         */
        if (
            root->left == NULL ||
            root->right == NULL
        )
        {
            AVLNode *child =
                root->left != NULL
                    ? root->left
                    : root->right;


            /*
             * No children.
             */
            if (child == NULL)
            {
                free(root);

                return NULL;
            }


            /*
             * One child.
             */
            *root = *child;

            free(child);
        }
        else
        {
            /*
             * Two children:
             *
             * Replace with the smallest node from
             * the right subtree.
             */
            AVLNode *successor =
                find_min(
                    root->right
                );


            root->key =
                successor->key;


            root->right =
                avl_delete(
                    root->right,
                    successor->key
                );
        }
    }


    return rebalance(root);
}


/*
 * ============================================================
 * In-order Traversal
 * ============================================================
 *
 * Produces sorted output for a valid BST.
 * ============================================================
 */

void avl_inorder(
    const AVLNode *root
)
{
    if (root == NULL)
    {
        return;
    }


    avl_inorder(root->left);

    printf(
        "%d ",
        root->key
    );

    avl_inorder(root->right);
}


/*
 * ============================================================
 * Balance Validation
 * ============================================================
 */

int avl_is_balanced(
    const AVLNode *root
)
{
    if (root == NULL)
    {
        return 1;
    }


    int balance =
        balance_factor(root);


    if (
        balance > 1 ||
        balance < -1
    )
    {
        return 0;
    }


    return
        avl_is_balanced(root->left) &&
        avl_is_balanced(root->right);
}


/*
 * ============================================================
 * Memory Cleanup
 * ============================================================
 */

void avl_free(
    AVLNode *root
)
{
    if (root == NULL)
    {
        return;
    }


    avl_free(root->left);

    avl_free(root->right);

    free(root);
}