// specifies namespace
using namespace std;


// file definition
#ifndef TICTACTOE_FIELDBASE_H
#define TICTACTOE_FIELDBASE_H
#endif


// field variable base, includes base positions, base symbols variables, base update_position and get functions
class FieldBase {
public:
    // base symbols variables
    string start_symbol = " "; // every position is set to this symbol when program starts
    string player_symbol = "X"; // symbol that player uses
    string robot_symbol = "O"; // symbol that robot uses

    // base positions to write and read
    string positions[9] = {
            start_symbol,
            start_symbol,
            start_symbol,
            start_symbol,
            start_symbol,
            start_symbol,
            start_symbol,
            start_symbol,
            start_symbol
    };

    // length of positions
    int length = sizeof(positions) / sizeof(positions[0]);

    // sets position on index to specified string
    void update_position(int index, const string& new_string);

    // reads positions
    string on_index(int index);
};
