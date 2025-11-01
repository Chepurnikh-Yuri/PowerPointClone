#include <iostream>
#include "cli_view.hpp"

int main()
{
    CLIView view;
    std::string cmd = view();

    std::cout << "The entered command is: " << cmd;
}