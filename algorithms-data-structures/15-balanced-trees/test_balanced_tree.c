#include <stdio.h>
#include <stdlib.h>

#include "balanced_tree.h"


static int tests_passed = 0;
static int tests_failed = 0;


static void assert_test(
    int condition,
    const char *name
)
{
    if (condition)
    {
        printf(
            "[PASS] %s\n",
            name
        );

        tests_passed++;
    }
    else
    {
        printf(
            "[FAIL] %s\n",
            name
        );

        tests_failed++;
    }
}


/*
 * ============================================================
 * Test AVL insertion and balancing
 * ============================================================
 */

static void test_insertion_balance(void)
{
    AVLNode *root = NULL;


    root =
        avl_insert(
            root,
            30
        );

    root =
        avl_insert(
            root,
            20
        );

    root =
        avl_insert(
            root,
            10
        );


    /*
     * 30 -> 20 -> 10 would normally be a chain.
     *
     * AVL rotation should produce:
     *
     *       20
     *      /  \
     *    10    30
     */
    assert_test(
        root != NULL &&
        root->key == 20 &&
        avl_is_balanced(root),
        "AVL insertion and rotation"
    );


    avl_free(root);
}


/*
 * ============================================================
 * Test search
 * ============================================================
 */

static void test_search(void)
{
    AVLNode *root = NULL;


    root =
        avl_insert(
            root,
            20
        );

    root =
        avl_insert(
            root,
            10
        );

    root =
        avl_insert(
            root,
            30
        );


    assert_test(
        avl_search(
            root,
            30
        ) != NULL,
        "Successful AVL search"
    );


    assert_test(
        avl_search(
            root,
            99
        ) == NULL,
        "Unsuccessful AVL search"
    );


    avl_free(root);
}


/*
 * ============================================================
 * Test deletion
 * ============================================================
 */

static void test_deletion(void)
{
    AVLNode *root = NULL;


    int values[] =
    {
        50,
        30,
        70,
        20,
        40,
        60,
        80
    };


    for (
        size_t i = 0;
        i < sizeof(values) / sizeof(values[0]);
        i++
    )
    {
        root =
            avl_insert(
                root,
                values[i]
            );
    }


    root =
        avl_delete(
            root,
            30
        );


    assert_test(
        avl_search(
            root,
            30
        ) == NULL,
        "AVL deletion"
    );


    assert_test(
        avl_is_balanced(root),
        "AVL remains balanced after deletion"
    );


    avl_free(root);
}


/*
 * ============================================================
 * Test duplicate handling
 * ============================================================
 */

static void test_duplicates(void)
{
    AVLNode *root = NULL;


    root =
        avl_insert(
            root,
            10
        );

    root =
        avl_insert(
            root,
            10
        );


    assert_test(
        root != NULL &&
        root->left == NULL &&
        root->right == NULL,
        "Duplicate keys ignored"
    );


    avl_free(root);
}


/*
 * ============================================================
 * Test empty tree
 * ============================================================
 */

static void test_empty_tree(void)
{
    AVLNode *root = NULL;


    assert_test(
        avl_height(root) == 0,
        "Empty tree height"
    );


    assert_test(
        avl_search(root, 10) == NULL,
        "Empty tree search"
    );


    assert_test(
        avl_is_balanced(root),
        "Empty tree balance"
    );
}


/*
 * ============================================================
 * Main
 * ============================================================
 */

int main(void)
{
    printf("\n");
    printf("========================================\n");
    printf(" Balanced Tree Test Suite\n");
    printf("========================================\n\n");


    test_insertion_balance();

    test_search();

    test_deletion();

    test_duplicates();

    test_empty_tree();


    printf("\n");
    printf("Results\n");
    printf("--------------------\n");


    printf(
        "Passed: %d\n",
        tests_passed
    );


    printf(
        "Failed: %d\n",
        tests_failed
    );


    if (tests_failed == 0)
    {
        printf(
            "\nAll balanced tree tests passed.\n"
        );

        return EXIT_SUCCESS;
    }


    printf(
        "\nSome balanced tree tests failed.\n"
    );


    return EXIT_FAILURE;
}