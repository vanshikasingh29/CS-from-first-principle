#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "vector_space.h"


static int tests_passed = 0;
static int tests_failed = 0;


static void assert_test(
    int condition,
    const char *name
)
{
    if (condition)
    {
        printf("[PASS] %s\n", name);
        tests_passed++;
    }
    else
    {
        printf("[FAIL] %s\n", name);
        tests_failed++;
    }
}


static int approximately_equal(
    double a,
    double b
)
{
    return fabs(a - b) < 1e-9;
}


static void test_addition(void)
{
    double a_values[] = {1, 2, 3};
    double b_values[] = {4, 5, 6};

    Vector a = vector_create(a_values, 3);
    Vector b = vector_create(b_values, 3);

    Vector result =
        vector_add(&a, &b);

    int passed =
        result.size == 3 &&
        approximately_equal(result.data[0], 5) &&
        approximately_equal(result.data[1], 7) &&
        approximately_equal(result.data[2], 9);

    assert_test(
        passed,
        "Vector addition"
    );

    vector_destroy(&a);
    vector_destroy(&b);
    vector_destroy(&result);
}


static void test_scaling(void)
{
    double values[] = {1, 2, 3};

    Vector vector =
        vector_create(values, 3);

    Vector result =
        vector_scale(&vector, 2.0);

    int passed =
        approximately_equal(result.data[0], 2) &&
        approximately_equal(result.data[1], 4) &&
        approximately_equal(result.data[2], 6);

    assert_test(
        passed,
        "Scalar multiplication"
    );

    vector_destroy(&vector);
    vector_destroy(&result);
}


static void test_dot_product(void)
{
    double a_values[] = {2, 3};
    double b_values[] = {4, 5};

    Vector a = vector_create(a_values, 2);
    Vector b = vector_create(b_values, 2);

    double result =
        vector_dot(&a, &b);

    assert_test(
        approximately_equal(result, 23),
        "Dot product"
    );

    vector_destroy(&a);
    vector_destroy(&b);
}


static void test_norm(void)
{
    double values[] = {3, 4};

    Vector vector =
        vector_create(values, 2);

    double result =
        vector_norm(&vector);

    assert_test(
        approximately_equal(result, 5),
        "Euclidean norm"
    );

    vector_destroy(&vector);
}


int main(void)
{
    printf("\n");
    printf("=====================================\n");
    printf(" Vector Space Test Suite\n");
    printf("=====================================\n\n");

    test_addition();
    test_scaling();
    test_dot_product();
    test_norm();

    printf("\n");
    printf("Passed: %d\n", tests_passed);
    printf("Failed: %d\n", tests_failed);

    if (tests_failed == 0)
    {
        printf("\nAll vector-space tests passed.\n");
        return EXIT_SUCCESS;
    }

    return EXIT_FAILURE;
}