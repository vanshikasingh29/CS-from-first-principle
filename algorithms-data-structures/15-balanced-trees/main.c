#include <stdio.h>

#include "balanced_tree.h"


int main(void)
{
    printf("\n");
    printf("========================================\n");
    printf(" Balanced Binary Search Tree Demo\n");
    printf("========================================\n");


    AVLNode *root = NULL;


    /*
     * Inserting these values would produce a highly
     * unbalanced ordinary BST without rotations.
     */
    int values[] =
    {
        30,
        20,
        10,
        25,
        40,
        50,
        45
    };


    int count =
        sizeof(values) /
        sizeof(values[0]);


    printf("\nInserting:\n");


    for (int i = 0; i < count; i++)
    {
        printf(
            "%d ",
            values[i]
        );


        root =
            avl_insert(
                root,
                values[i]
            );
    }


    printf("\n");


    printf("\nIn-order traversal:\n");

    avl_inorder(root);

    printf("\n");


    printf(
        "\nTree height: %d\n",
        avl_height(root)
    );


    printf(
        "Tree balanced: %s\n",
        avl_is_balanced(root)
            ? "yes"
            : "no"
    );


    /*
     * Search.
     */
    printf("\nSearching for 25:\n");


    AVLNode *found =
        avl_search(
            root,
            25
        );


    printf(
        "Result: %s\n",
        found != NULL
            ? "found"
            : "not found"
    );


    /*
     * Delete a node.
     */
    printf("\nDeleting 20...\n");


    root =
        avl_delete(
            root,
            20
        );


    printf(
        "In-order traversal: "
    );

    avl_inorder(root);

    printf("\n");


    printf(
        "Tree height: %d\n",
        avl_height(root)
    );


    printf(
        "Tree balanced: %s\n",
        avl_is_balanced(root)
            ? "yes"
            : "no"
    );


    avl_free(root);


    printf(
        "\nBalanced tree demonstration complete.\n"
    );


    return 0;
}