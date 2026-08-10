#include <stdio.h>

#include "../include/logic.h"


/*
============================================================
Simple Test Framework
============================================================
*/

static int tests_passed = 0;
static int tests_failed = 0;


static void assert_test(
    int condition,
    const char* name
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
============================================================
Predicates
============================================================
*/


static int greater_than_80(int value)
{
    return value > 80;
}


static int even(int value)
{
    return value % 2 == 0;
}


/*
============================================================
PROPOSITIONAL LOGIC TESTS
============================================================
*/


static void test_propositional_logic(void)
{
    assert_test(
        logical_not(1) == 0,
        "NOT"
    );


    assert_test(
        logical_not(0) == 1,
        "NOT false"
    );


    assert_test(
        logical_and(1, 1) == 1,
        "AND true/true"
    );


    assert_test(
        logical_and(1, 0) == 0,
        "AND true/false"
    );


    assert_test(
        logical_or(0, 1) == 1,
        "OR"
    );


    assert_test(
        logical_or(0, 0) == 0,
        "OR false/false"
    );


    assert_test(
        logical_implies(1, 0) == 0,
        "Implication false case"
    );


    assert_test(
        logical_implies(0, 0) == 1,
        "Implication true case"
    );


    assert_test(
        logical_implies(0, 1) == 1,
        "Implication antecedent false"
    );


    assert_test(
        logical_equivalent(1, 1) == 1,
        "Logical equivalence true"
    );


    assert_test(
        logical_equivalent(1, 0) == 0,
        "Logical equivalence false"
    );
}


/*
============================================================
PREDICATE LOGIC TESTS
============================================================
*/


static void test_predicates(void)
{
    int domain[] =
    {
        95,
        72,
        88,
        91
    };


    assert_test(
        count_satisfying(
            greater_than_80,
            domain,
            4
        ) == 3,
        "Predicate satisfaction count"
    );


    assert_test(
        evaluate_predicate(
            greater_than_80,
            domain,
            4
        ) == 0,
        "Universal predicate evaluation"
    );


    int even_domain[] =
    {
        2,
        4,
        6,
        8
    };


    assert_test(
        evaluate_predicate(
            even,
            even_domain,
            4
        ) == 1,
        "Universal predicate true"
    );
}


/*
============================================================
RELATIONAL ALGEBRA — RELATION CREATION
============================================================
*/


static void test_relation_creation(void)
{
    Relation relation =
        create_relation();


    assert_test(
        relation.size == 0,
        "Empty relation creation"
    );
}


/*
============================================================
RELATIONAL ALGEBRA — TUPLE INSERTION
============================================================
*/


static void test_tuple_insertion(void)
{
    Relation relation =
        create_relation();


    add_tuple(
        &relation,
        1,
        95
    );


    add_tuple(
        &relation,
        2,
        72
    );


    assert_test(
        relation.size == 2,
        "Tuple insertion"
    );


    assert_test(
        relation.tuples[0].id == 1 &&
        relation.tuples[0].value == 95,
        "Tuple contents"
    );
}


/*
============================================================
RELATIONAL ALGEBRA — SELECTION
============================================================

    σ grade>80(Student)
============================================================
*/


static void test_selection(void)
{
    Relation relation =
        create_relation();


    add_tuple(
        &relation,
        1,
        95
    );


    add_tuple(
        &relation,
        2,
        72
    );


    add_tuple(
        &relation,
        3,
        88
    );


    Relation result =
        selection(
            &relation,
            greater_than_80
        );


    assert_test(
        result.size == 2,
        "Relational selection cardinality"
    );


    assert_test(
        result.tuples[0].id == 1 &&
        result.tuples[1].id == 3,
        "Relational selection contents"
    );
}


/*
============================================================
RELATIONAL ALGEBRA — PROJECTION
============================================================

    πid(R)
============================================================
*/


static void test_projection(void)
{
    Relation relation =
        create_relation();


    add_tuple(
        &relation,
        1,
        95
    );


    add_tuple(
        &relation,
        2,
        72
    );


    Relation result =
        projection_id(
            &relation
        );


    assert_test(
        result.size == 2,
        "Relational projection cardinality"
    );


    assert_test(
        result.tuples[0].id == 1 &&
        result.tuples[1].id == 2,
        "Projection preserves identifiers"
    );


    assert_test(
        result.tuples[0].value == 0 &&
        result.tuples[1].value == 0,
        "Projection removes value attribute"
    );
}


/*
============================================================
MAIN TEST RUNNER
============================================================
*/


int main(void)
{
    printf(
        "\n"
        "Topic 1 — Logic & Relational Algebra Tests\n"
    );


    printf(
        "===========================================\n\n"
    );


    test_propositional_logic();

    test_predicates();

    test_relation_creation();

    test_tuple_insertion();

    test_selection();

    test_projection();


    printf(
        "\nResults\n"
    );


    printf(
        "----------------\n"
    );


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
            "\nAll Topic 1 tests passed.\n"
        );

        return 0;
    }


    printf(
        "\nSome Topic 1 tests failed.\n"
    );


    return 1;
}