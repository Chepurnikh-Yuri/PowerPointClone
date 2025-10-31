#include <iostream>
#include "./include/command.hpp"

int main()
{
    std::string cmd = "pptc slide add --opt1 arg1 --opt2 arg2";

    if (Command::parse(cmd)) {
        auto res = Command::parse(cmd);
    
        std::cout << "invocation: " << res->invocation() << std::endl;
        std::cout << "command: " << res->command() << std::endl;
        std::cout << "subcommand: " << res->subcommand() << std::endl;

        for (const auto& [opt, arg] : res->optionsToArguments())
            std::cout << opt << " " << arg << std::endl;
    }
}