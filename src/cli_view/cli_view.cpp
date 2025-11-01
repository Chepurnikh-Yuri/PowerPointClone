#include "cli_view.hpp"

std::string CLIView::operator()() const {
    std::cout << "PowerPointClone CLI" << std::endl;
    std::cout << "-------------------" << std::endl;
    std::cout << ">>> ";

    std::string input;
    std::getline(std::cin, input);

    return input;
}