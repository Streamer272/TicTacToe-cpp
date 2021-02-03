#include "FieldBase.h"
#include <string>


// specifies namespace
using namespace std;


// file definition
#ifndef TICTACTOE_FIELDBASE_CPP
#define TICTACTOE_FIELDBASE_CPP
#endif


// sets position on index to specified string
void FieldBase::update_position(int index, const string& new_string) {
    positions[index] = new_string;
}

// reads positions
string FieldBase::on_index(int index) {
    return positions[index];
}
