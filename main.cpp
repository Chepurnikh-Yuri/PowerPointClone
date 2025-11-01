#include "cli_view.hpp"
#include "presentation.hpp"
#include "controller.hpp"
#include "command.hpp"

int main()
{
    auto presentation = std::make_shared<Presentation>();
    CLIView view;
    CLIController controller(presentation, view);

    controller.run();
}