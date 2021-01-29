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
    // create random seed on base of time for rand() function
    static void generate_init()
    {
        srand(time(nullptr));
    }

    // generates random number between min and max
    static int generate_random_number(int min, int max) {
        return min + rand() % ((max + 1) - min);
    }

    // clears console on base of os
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
