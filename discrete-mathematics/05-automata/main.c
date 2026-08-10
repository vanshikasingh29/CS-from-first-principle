#include <stdio.h>
#include "dfa.h"


static DFA build_even_ones_dfa(void)
{
    /*
     * State 0:
     * even number of 1s
     *
     * State 1:
     * odd number of 1s
     */

    DFA dfa =
        create_dfa(2, 2);


    set_symbol(&dfa, 0, '0');
    set_symbol(&dfa, 1, '1');


    /*
     * State 0 = EVEN
     * State 1 = ODD
     *
     * Reading 0 preserves parity.
     * Reading 1 switches parity.
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


    set_accepting(
        &dfa,
        0,
        1
    );


    set_accepting(
        &dfa,
        1,
        0
    );


    return dfa;
}


int main(void)
{
    DFA dfa =
        build_even_ones_dfa();


    const char* inputs[] =
    {
        "",
        "0",
        "1",
        "11",
        "101",
        "1011",
        "1100"
    };


    printf(
        "Automata Theory Lab\n"
    );

    printf(
        "===================\n\n"
    );


    for(int i = 0;
        i < 7;
        i++)
    {
        printf(
            "\"%s\" -> %s\n",
            inputs[i],
            accepts(
                &dfa,
                inputs[i]
            )
                ? "ACCEPT"
                : "REJECT"
        );
    }


    return 0;
}