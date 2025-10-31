#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <iostream>
#include <regex>
#include <utility>
#include <string>
#include <vector>
#include <memory>
#include <optional>

// command structure
// -------------------------------------------------
// pptc [command] [subcommand] [options] [arguments]
class Command 
{
public:
    struct OptToArg {
        std::string opt, arg;
    };

    // factory method
    static std::optional<Command> parse(const std::string& cmd);
    
    // getters
    std::string invocation() const;
    std::string command() const;
    std::string subcommand() const;
    std::vector<OptToArg> optionsToArguments() const;

private:
    Command (
        const std::string& invoc,
        const std::string& cmd,
        const std::string& subcmd,
        const std::vector<OptToArg> optToArgs 
    );

    static std::vector<std::string> tokens(const std::string& cmd);

    // data
    std::string m_invoc;
    std::string m_cmd;
    std::string m_subcmd;
    std::vector<OptToArg> m_optToArgs;
};

#endif // COMMAND_HPP