#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <unordered_map>
#include <memory>

#include "presentation.hpp"
#include "cli_view.hpp"
#include "command.hpp"
#include "commands.hpp"

class CLIController
{
public:
    CLIController (
        std::shared_ptr<Presentation> presentation,
        CLIView& view
    );

    void run();

private:
    CLIView& m_cliView;
    std::shared_ptr<Presentation> m_presentation;

    std::unordered_map < 
        std::string, std::unordered_map <
            std::string, std::unique_ptr <Commands::ACommand>
        >
    > m_commands;
};

#endif // CONTROLLER_HPP