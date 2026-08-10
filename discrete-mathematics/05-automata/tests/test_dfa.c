#include <stdio.h>

#include "dfa.h"


int passed = 0;
int failed = 0;


void assert_test(
    int condition,
    const char* name
)
{
    if(condition)
    {
        printf(
            "[PASS] %s\n",
            name
        );

        passed++;
    }
    else
    {
        printf(
            "[FAIL] %s\n",
            name
        );

        failed++;
    }
}


static DFA build_dfa(void)
{
    /*
    DFA recognises:

        strings containing an even
        number of 1s.

    State 0:
        even number of 1s

    State 1:
        odd number of 1s
    */

    DFA dfa =
        create_dfa(
            2,
            2
        );


    set_symbol(
        &dfa,
        0,
        '0'
    );

    set_symbol(
        &dfa,
        1,
        '1'
    );


    /*
    State 0

    0 -> 0
    1 -> 1
    */

    set_transition(
        &dfa,
        0,
        0,
        0
    );

    set_transition(
        &dfa,
        0,
        1,
        1
    );


    /*
    State 1

    0 -> 1
    1 -> 0
    */

    set_transition(
        &dfa,
        1,
        0,
        1
    );

    set_transition(
        &dfa,
        1,
        1,
        0
    );


    set_start_state(
        &dfa,
        0
    );


    /*
    Only state 0 is accepting.

    Therefore:

        even number of 1s
        -> accepted
    */

    set_accepting(
        &dfa,
        0,
        1
    );


    return dfa;
}


int main(void)
{
    DFA dfa =
        build_dfa();


    printf(
        "Automata Theory Test Suite\n"
    );

    printf(
        "==========================\n\n"
    );


    assert_test(
        accepts(
            &dfa,
            ""
        ) == 1,

        "Empty string accepted"
    );


    assert_test(
        accepts(
            &dfa,
            "0"
        ) == 1,

        "Zero ones"
    );


    assert_test(
        accepts(
            &dfa,
            "1"
        ) == 0,

        "One one rejected"
    );


    assert_test(
        accepts(
            &dfa,
            "11"
        ) == 1,

        "Two ones accepted"
    );


    assert_test(
        accepts(
            &dfa,
            "101"
        ) == 1,

        "Two ones with zeros"
    );


    assert_test(
        accepts(
            &dfa,
            "1011"
        ) == 0,

        "Three ones rejected"
    );


    assert_test(
        accepts(
            &dfa,
            "1100"
        ) == 1,

        "Two ones with zeros"
    );


    assert_test(
        accepts(
            &dfa,
            "1111"
        ) == 1,

        "Four ones accepted"
    );


    assert_test(
        accepts(
            &dfa,
            "abc"
        ) == 0,

        "Invalid alphabet rejected"
    );


    printf(
        "\nPassed: %d\n",
        passed
    );

    printf(
        "Failed: %d\n",
        failed
    );


    if(failed == 0)
    {
        printf(
            "\nAll automata tests passed.\n"
        );
    }


    return failed == 0 ? 0 : 1;
}