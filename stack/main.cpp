#include "stack.h"
#include <string.h>
#define TEMP 2000
using namespace std;

#define STACK_SIZE 500
#define WORD_LEN 1000
#define MIN_ASCII 33
#define MAX_ASCII 126
#define MAX_ITER 1000 /*Stands for iterations*/

//Test the stack
bool lite_stack_test(void);
//Deep test the stack
bool deep_stack_test(void);
//Make a random word
char * random_word(int max = WORD_LEN);
//Test push/pop
bool test_pop(stack<char> & test_stack);
bool test_push(stack<char> & test_stack);

bool test_node(void);

int main(int argc, char * argv[])
{
    if( deep_stack_test() )
        cout << "Deep stack test succeeded" << endl;
    else
        cout << "Deep stack test failed" << endl;

    //lite_stack_test();
    //test_node();
    return 0;
}

//Test the stack
bool lite_stack_test(void)
{
    stack<char> test_stack(10);
    char temp;
    char word[TEMP];

    cin.get(word, TEMP, '\n');
    cin.ignore(TEMP,'\n');

    size_t len = strlen(word);
    for(int i = 0; i < len; ++i)
        test_stack.push( word[i] );

    //Test our copy constructor here
    stack<char> test_stack2( test_stack );
    while( !test_stack2.is_empty() )
    {
        if( test_stack2.pop( temp ) )
            cout << temp;
    }
    cout << endl;
    return true;
}


//Deep test the stack.
bool deep_stack_test(void)
{
    srand( clock() );
    stack<char> test_stack(STACK_SIZE);
    stack<char> test_copy(STACK_SIZE);
    unsigned int iter = (unsigned int) rand() % MAX_ITER;
    for(unsigned int i = 0; i < iter; ++i)
    {
        if( !test_push( test_stack ) )
        {
            cerr << "deep_stack_test: test_push FAILED" << endl;
            return false;
        }

        //TODO implement assignment op
        test_copy = test_stack;
        if( !test_pop( test_copy ) )
        {
            cerr << "deep_stack_test: test_pop FAILED" << endl;
            return false;
        }
    }
    return true;
}

//Test the push function. This will push as many chars as the random word gen
//made.
bool test_push(stack<char> & test_stack)
{
    char * chars = random_word();
    char * current = chars;
    while( *current )
    {
        if( !test_stack.push( *current ) )
        {
            cerr << "test_push: PUSH FAILED FOR: " << *current << endl;
            return false;
        }
        ++current;
    }
    delete [] chars;
    return true;
}

//Test the pop function. This will pop until there are no more chars in the 
//stack.
bool test_pop(stack<char> & test_stack)
{
    char temp = ' ';

    while( !test_stack.is_empty() )
        test_stack.pop(temp);
    return true;
}

//This just makes a random word.
char * random_word(int max)
{
    srand( clock() );
    unsigned int len = (unsigned int) rand() % max;
    char * new_word = new char[len+1];
    char * current = new_word;

    for(unsigned int i = 0; i < len; ++i, ++current)
        *current = (rand() % (MAX_ASCII - MIN_ASCII)) + MIN_ASCII;

    *current = '\0';
    return new_word;
}

//Test the node used by the stack
bool test_node(void)
{
    node_stack<char> test_node(1000);
    node_stack<char> test_node2(10);
    char temp_char = ' ';
    char * chars = random_word();
    char * current_chars = chars;

    while( *current_chars && !test_node.is_full() )
    {
        test_node.push(*current_chars);
        ++current_chars;
    }

    test_node2 = test_node;
    cout << "Before: " << chars << endl
         << "After:  ";
    while( !test_node2.is_empty() )
    {
        test_node2.pop( temp_char );
        cout << temp_char;
    }
    cout << endl;

    delete chars;
    return true;
}
