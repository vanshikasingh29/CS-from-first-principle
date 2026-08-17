#ifndef BALANCED_TREE_H
#define BALANCED_TREE_H

/*
 * AVL tree node.
 */
typedef struct AVLNode
{
    int key;

    int height;

    struct AVLNode *left;
    struct AVLNode *right;

} AVLNode;


/*
 * Insert a key into the AVL tree.
 *
 * Returns the new root.
 */
AVLNode *avl_insert(
    AVLNode *root,
    int key
);


/*
 * Search for a key.
 *
 * Returns the node if found.
 * Returns NULL otherwise.
 */
AVLNode *avl_search(
    AVLNode *root,
    int key
);


/*
 * Delete a key from the AVL tree.
 *
 * Returns the new root.
 */
AVLNode *avl_delete(
    AVLNode *root,
    int key
);


/*
 * Print keys using in-order traversal.
 */
void avl_inorder(
    const AVLNode *root
);


/*
 * Return the height of a tree.
 */
int avl_height(
    const AVLNode *root
);


/*
 * Check whether the AVL invariant holds.
 */
int avl_is_balanced(
    const AVLNode *root
);


/*
 * Release all allocated nodes.
 */
void avl_free(
    AVLNode *root
);

#endif