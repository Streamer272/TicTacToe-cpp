#include <iostream> // module for console writing and reading
#include <ctime> // module for generate_random_number function


// specifies namespace
using namespace std;


// file definition
#ifndef TICTACTOE_INNERSYSTEM_H
#define TICTACTOE_INNERSYSTEM_H
#endif //TICTACTOE_INNERSYSTEM_H


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
