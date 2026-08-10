#ifndef DFA_H
#define DFA_H


#define MAX_STATES 16
#define MAX_SYMBOLS 16


typedef struct
{
    int state_count;
    int alphabet_size;

    char alphabet[MAX_SYMBOLS];

    int transition[MAX_STATES][MAX_SYMBOLS];

    int start_state;

    int accepting[MAX_STATES];

} DFA;


/* Construction */

DFA create_dfa(
    int state_count,
    int alphabet_size
);


void set_symbol(
    DFA* dfa,
    int index,
    char symbol
);


void set_transition(
    DFA* dfa,
    int state,
    int symbol_index,
    int next_state
);


void set_start_state(
    DFA* dfa,
    int state
);


void set_accepting(
    DFA* dfa,
    int state,
    int accepting
);


/* Execution */

int symbol_index(
    const DFA* dfa,
    char symbol
);


int accepts(
    const DFA* dfa,
    const char* input
);


#endif