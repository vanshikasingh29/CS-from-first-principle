#include <string.h>
#include "dfa.h"


DFA create_dfa(
    int state_count,
    int alphabet_size
)
{
    DFA dfa = {0};

    if(state_count < 0 ||
       state_count > MAX_STATES)
    {
        return dfa;
    }

    if(alphabet_size < 0 ||
       alphabet_size > MAX_SYMBOLS)
    {
        return dfa;
    }

    dfa.state_count = state_count;
    dfa.alphabet_size = alphabet_size;

    dfa.start_state = 0;


    for(int state = 0;
        state < MAX_STATES;
        state++)
    {
        for(int symbol = 0;
             symbol < MAX_SYMBOLS;
             symbol++)
        {
            dfa.transition[state][symbol] = -1;
        }
    }


    return dfa;
}


void set_symbol(
    DFA* dfa,
    int index,
    char symbol
)
{
    if(dfa == NULL)
    {
        return;
    }

    if(index < 0 ||
       index >= dfa->alphabet_size)
    {
        return;
    }

    dfa->alphabet[index] = symbol;
}


void set_transition(
    DFA* dfa,
    int state,
    int symbol_index_value,
    int next_state
)
{
    if(dfa == NULL)
    {
        return;
    }

    if(state < 0 ||
       state >= dfa->state_count)
    {
        return;
    }

    if(symbol_index_value < 0 ||
       symbol_index_value >= dfa->alphabet_size)
    {
        return;
    }

    if(next_state < 0 ||
       next_state >= dfa->state_count)
    {
        return;
    }

    dfa->transition[state][symbol_index_value]
        = next_state;
}


void set_start_state(
    DFA* dfa,
    int state
)
{
    if(dfa == NULL)
    {
        return;
    }

    if(state < 0 ||
       state >= dfa->state_count)
    {
        return;
    }

    dfa->start_state = state;
}


void set_accepting(
    DFA* dfa,
    int state,
    int accepting_value
)
{
    if(dfa == NULL)
    {
        return;
    }

    if(state < 0 ||
       state >= dfa->state_count)
    {
        return;
    }

    dfa->accepting[state] =
        accepting_value ? 1 : 0;
}


int symbol_index(
    const DFA* dfa,
    char symbol
)
{
    if(dfa == NULL)
    {
        return -1;
    }

    for(int i = 0;
        i < dfa->alphabet_size;
        i++)
    {
        if(dfa->alphabet[i] == symbol)
        {
            return i;
        }
    }

    return -1;
}


int accepts(
    const DFA* dfa,
    const char* input
)
{
    if(dfa == NULL ||
       input == NULL)
    {
        return 0;
    }

    int current_state =
        dfa->start_state;


    for(size_t i = 0;
        i < strlen(input);
        i++)
    {
        int index =
            symbol_index(
                dfa,
                input[i]
            );


        if(index == -1)
        {
            return 0;
        }


        int next_state =
            dfa->transition
                [current_state][index];


        if(next_state == -1)
        {
            return 0;
        }


        current_state =
            next_state;
    }


    return dfa->accepting[current_state];
}