#include <iostream> // module for console writing and reading
#include <ctime> // module for generate_random_number function
#include <unistd.h> // module for sleep function


// specifies namepace
using namespace std;


// os name finding and definition
#if defined(_WIN32)
#define os_name "windows"
#elif defined(__linux__)
#define os_name "linux"
#endif


// class for everything else used in field that isn't field
class InnerSystem
{
public:
    // generates generate_random_number number between min and max
    static int generate_random_number(bool first, int min, int max) {
        if (first) {
            srand(time(nullptr));
        }

        return min + rand() % ((max + 1) - min);
    }

    // clears console
    static void clear_console()
    {
        if (os_name == "linux")
        {
            system("clear");
        }
        else if (os_name == "windows")
        {
            system("cls");
        }
    }
};


// field variable base, includes base positions, base symbols variables, base update_position and get functions
class FieldBase
{
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
    void update_position(int index, const string& new_string)
    {
        positions[index] = new_string;
    }

    // reads positions
    string on_index(int index)
    {
        return positions[index];
    }
};


// function that controls FieldBase and has multiple complex functions to make tic-tac-toe work
class Field
{
public:
    FieldBase field; // defines base field as field
    bool first_time_random_generation = true; // first_time_random_generation time generate_random_number number generation variable

    // checks if index is last in row, true if index is last in row, false if isn't
    static bool is_index_last_in_row(int index)
    {
        return index == 2 || index == 5 || index == 8;
    }

    // asks player for position pick, repeat until pick isn't valid
    string ask_player()
    {
        string human_position_pick;

        do
        {
            do
            {
                cout << ">> ";
                cin >> human_position_pick;
            }
            while (get_position_by_string(human_position_pick) == -1);

        }
        while (is_position_occupied(get_position_by_string(human_position_pick)));

        return human_position_pick;
    }

    // picks generate_random_number position, repeat until pick isn't valid
    int ask_robot()
    {
        int robot_position_pick;

        do
        {
            robot_position_pick = InnerSystem::generate_random_number(first_time_random_generation, 0, 8);
            first_time_random_generation = false;
        }
        while (is_position_occupied(robot_position_pick));

        return robot_position_pick;
    }

    // parses numpad input to position index
    static int get_position_by_string(const string& to_find)
    {
        if (to_find == "1")
        {
            return 6;
        }
        else if (to_find == "2")
        {
            return 7;
        }
        else if (to_find == "3")
        {
            return 8;
        }
        else if (to_find == "4")
        {
            return 3;
        }
        else if (to_find == "5")
        {
            return 4;
        }
        else if (to_find == "6")
        {
            return 5;
        }
        else if (to_find == "7")
        {
            return 0;
        }
        else if (to_find == "8")
        {
            return 1;
        }
        else if (to_find == "9")
        {
            return 2;
        }

        return -1;
    }

    // checks if position is occupied by anyone, true if is occupied, false is isn't
    bool is_position_occupied(int position_index)
    {
        return field.on_index(position_index) != field.start_symbol;
    }

    // checks if positions on indexes are same, true if they are same, false if they aren't
    bool do_check(int index1, int index2, int index3)
    {
        if (field.on_index(index1) == field.on_index(index2) && field.on_index(index2) ==
                                                                field.on_index(index3) && field.on_index(index3) != field.start_symbol)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // checks every possible combination(calls do_check), "" if no one is winner, else if someone is winner
    string check_winner()
    {
        if (do_check(get_position_by_string("7"), get_position_by_string("8"),
                     get_position_by_string("9")))
        {
            return field.on_index(get_position_by_string("7"));
        }
        else if (do_check(get_position_by_string("4"), get_position_by_string("5"),
                          get_position_by_string("6")))
        {
            return field.on_index(get_position_by_string("4"));
        }
        else if (do_check(get_position_by_string("1"), get_position_by_string("2"),
                          get_position_by_string("3")))
        {
            return field.on_index(get_position_by_string("1"));
        }
        else if (do_check(get_position_by_string("7"), get_position_by_string("4"),
                          get_position_by_string("1")))
        {
            return field.on_index(get_position_by_string("7"));
        }
        else if (do_check(get_position_by_string("8"), get_position_by_string("5"),
                          get_position_by_string("2")))
        {
            return field.on_index(get_position_by_string("8"));
        }
        else if (do_check(get_position_by_string("9"), get_position_by_string("6"),
                          get_position_by_string("3")))
        {
            return field.on_index(get_position_by_string("9"));
        }
        else if (do_check(get_position_by_string("7"), get_position_by_string("5"),
                          get_position_by_string("3")))
        {
            return field.on_index(get_position_by_string("7"));
        }
        else if (do_check(get_position_by_string("9"), get_position_by_string("5"),
                          get_position_by_string("1")))
        {
            return field.on_index(get_position_by_string("9"));
        }

        return "";
    }

    bool is_field_full()
    {
        int positions_not_equal_to_start_symbol = 0;

        for (int index = 0; index < field.length; index++)
        {
            if (field.on_index(index) != field.start_symbol)
            {
                positions_not_equal_to_start_symbol++;
            }
        }

        return positions_not_equal_to_start_symbol != field.length;
    }

    // clears console and writes field positions in console
    void write_positions()
    {
        InnerSystem::clear_console();

        for (int index = 0; index < field.length; index++)
        {
            cout << field.on_index(index);

            if (is_index_last_in_row(index))
            {
                cout << endl;
            }
            else
            {
                cout << "|";
            }
        }
    }

    // asks player to pick position, parses pick, updates field positions and updates console
    void player_turn()
    {
        int position_picked = get_position_by_string(ask_player());
        field.update_position(position_picked, field.player_symbol);
        write_positions();
    }

    // asks robot to pick position, updates field positions and updates console
    void robot_turn()
    {
        int position_pick = ask_robot();
        field.update_position(position_pick, field.robot_symbol);
        write_positions();
    }

    // repeat calling player turn and robot turn until someone wins
    [[noreturn]] void main()
    {
        write_positions();

        int index = 0;

        do
        {
            if (index % 2 == 0)
            {
                player_turn();
            }
            else
            {
                robot_turn();
            }

            index++;
        }
        while (check_winner().empty() && is_field_full());

        if (!check_winner().empty())
        {
            cout << "And the winner is " << check_winner() << "!" << endl;
        }
        else
        {
            cout << "No one is winner! Field is full" << endl;
        }

        while (true)
        {
            sleep(5);
        }
    }
};


// starts the whole code
int main()
{
    Field master;
    master.main();
}

#pragma clang diagnostic pop
