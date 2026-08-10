#include <stdio.h>

#include "../include/set_theory.h"


int passed = 0;
int failed = 0;


void assert_test(
    int condition,
    const char* name
)
{
    if (condition)
    {
        printf("[PASS] %s\n", name);
        passed++;
    }
    else
    {
        printf("[FAIL] %s\n", name);
        failed++;
    }
}


IntSet make_set_a(void)
{
    IntSet set = create_set();

    add_element(&set, 1);
    add_element(&set, 2);
    add_element(&set, 3);

    return set;
}


IntSet make_set_b(void)
{
    IntSet set = create_set();

    add_element(&set, 3);
    add_element(&set, 4);
    add_element(&set, 5);

    return set;
}


void test_membership(void)
{
    IntSet set = make_set_a();

    assert_test(
        contains(&set, 2),
        "Membership"
    );

    assert_test(
        !contains(&set, 10),
        "Non-membership"
    );
}


void test_subset(void)
{
    IntSet a = make_set_a();

    IntSet subset = create_set();

    add_element(&subset, 1);
    add_element(&subset, 2);

    assert_test(
        is_subset(&subset, &a),
        "Subset"
    );
}


void test_union(void)
{
    IntSet a = make_set_a();
    IntSet b = make_set_b();

    IntSet result =
        set_union(&a, &b);

    assert_test(
        result.size == 5,
        "Union cardinality"
    );

    assert_test(
        contains(&result, 5),
        "Union contains elements"
    );
}


void test_intersection(void)
{
    IntSet a = make_set_a();
    IntSet b = make_set_b();

    IntSet result =
        set_intersection(&a, &b);

    assert_test(
        result.size == 1,
        "Intersection cardinality"
    );

    assert_test(
        contains(&result, 3),
        "Intersection contains common element"
    );
}


void test_difference(void)
{
    IntSet a = make_set_a();
    IntSet b = make_set_b();

    IntSet result =
        set_difference(&a, &b);

    assert_test(
        result.size == 2,
        "Difference cardinality"
    );

    assert_test(
        contains(&result, 1) &&
        contains(&result, 2),
        "Difference contains A minus B"
    );
}


void test_cartesian_product(void)
{
    IntSet a = create_set();
    IntSet b = create_set();

    add_element(&a, 1);
    add_element(&a, 2);

    add_element(&b, 10);
    add_element(&b, 20);
    add_element(&b, 30);

    CartesianProduct product =
        cartesian_product(
            &a,
            &b
        );

    assert_test(
        product.size == 6,
        "Cartesian product cardinality"
    );
}


void test_power_set(void)
{
    IntSet set = create_set();

    add_element(&set, 1);
    add_element(&set, 2);
    add_element(&set, 3);

    assert_test(
        power_set_size(&set) == 8,
        "Power set cardinality"
    );
}


int main(void)
{
    printf(
        "\nTopic 2 — Set Theory Tests\n"
    );

    printf(
        "==========================\n\n"
    );

    test_membership();
    test_subset();
    test_union();
    test_intersection();
    test_difference();
    test_cartesian_product();
    test_power_set();

    printf(
        "\nResults\n"
    );

    printf(
        "----------------\n"
    );

    printf(
        "Passed: %d\n",
        passed
    );

    printf(
        "Failed: %d\n",
        failed
    );

    if (failed == 0)
    {
        printf(
            "\nAll Topic 2 tests passed.\n"
        );

        return 0;
    }

    return 1;
}