#include "controller.hpp"

// command examples:
// pptc presentation create --name some_name
CLIController::CLIController (
    std::shared_ptr<Presentation> presentation,
    CLIView& view
) :
    m_presentation(presentation), 
    m_cliView(view)
{
    m_commands["presentation"]["create"] = std::make_unique<Commands::CreatePresentationCommand>(m_presentation, m_cliView);
    m_commands["slide"]["add"] = std::make_unique<Commands::AddSlideCommand>(m_presentation, m_cliView, -1);
    m_commands["slide"]["remove"] = std::make_unique<Commands::RemoveSlideCommand>(m_presentation, m_cliView, -1);
    m_commands["slide"]["show"] = std::make_unique<Commands::ShowSlideCommand>(m_presentation, m_cliView, -1);
}

void CLIController::run() {
    while (true) {
        std::string input = m_cliView();

        auto cmd = Command::parse(input).value();

        auto it = m_commands.find(cmd.command());

        if (it != m_commands.end()) {
            auto& subMap = it->second;
            auto cmdIt = subMap.find(cmd.subcommand());

            if (cmdIt != subMap.end()) {
                cmdIt->second->execute();
            } else {
                std::cout << "Error" << std::endl;
            }
        } else 
        {
            std::cout << "Error" << std::endl;
        }
    }
}