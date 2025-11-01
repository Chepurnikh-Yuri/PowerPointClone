#include "validation.hpp"

#include <cassert>

using namespace Validation;

void CommandValidator::setNext(std::shared_ptr<CommandValidator> next)
{
    this->next = next;
}

ValidationResult CommandValidator::validate(const std::vector<std::string>& cmd, size_t idx)
{
    if (next)
        return next->validate(cmd, idx);

    return { true, "The command was successfully parsed" };
}

ValidationResult NotEmptyValidator::validate(const std::vector<std::string>& cmd, size_t idx)
{
    if (cmd.empty()) {
        return { false, "Error: The command is empty" };
    }

    return CommandValidator::validate(cmd, idx);
}

ValidationResult InvocationNameValidator::validate(const std::vector<std::string>& cmd, size_t idx)
{
    assert(idx < cmd.size() && "The index out of range");

    if (cmd[idx] == "pptc") {
        ++idx;
        return CommandValidator::validate(cmd, idx);
    }

    return { false, "Error: Unexpected invocation" };
}

ValidationResult CommandNameValidator::validate(const std::vector<std::string>& cmd, size_t idx)
{
    assert(idx < cmd.size() && "The index out of range");

    std::vector<std::string> names = {
        "presentation", "slide", "shape"
    };

    for (const auto& name : names) {
        if (name == cmd[idx]) {
            ++idx;
            return CommandValidator::validate(cmd, idx);
        }
    }

    return { false, "Error: Unexpected command" };
}

ValidationResult SubCommandNameValidator::validate(const std::vector<std::string>& cmd, size_t idx)
{
    assert(idx < cmd.size() && "The idx out of range");

    std::vector<std::string> subnames = {
        "create", "add", "remove", "show"
    };

    for (const auto& name : subnames) {
        if (name == cmd[idx]) {
            ++idx;
            return CommandValidator::validate(cmd, idx);
        }
    }

    return { false, "Error: Unexpected subcommand" };
}

ValidationResult OptArgValidator::validate(const std::vector<std::string>& cmd, size_t idx)
{
    while (idx < cmd.size()) 
    {
        if (cmd[idx].substr(0, 2) != "--") 
            return { false, "Error: Invalid option syntax" };         
        ++idx;

        if (idx >= cmd.size() || cmd[idx].substr(0, 2) == "--") 
            return { false, "Error: Argument not specified" };
        ++idx;
    }

    return CommandValidator::validate(cmd, idx);
}
