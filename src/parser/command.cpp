#include "command.hpp"
#include "validation.hpp"
using namespace Validation;

std::vector<std::string> Command::tokens(const std::string& cmd)
{
    if (cmd.empty())
        return {};

    std::regex split("\\s+");

    std::vector<std::string> toks;
    std::sregex_token_iterator it (cmd.begin(), cmd.end(), split, -1);
    std::sregex_token_iterator end;

    while (it != end)
    {
        toks.push_back(*it);
        ++it;
    }

    return toks;
}

std::optional<Command> Command::parse(const std::string& cmd) 
{
    std::vector<std::string> toks = Command::tokens(cmd);

    auto notEmpty = std::make_shared<NotEmptyValidator>();
    auto invoc = std::make_shared<InvocationNameValidator>();
    auto cmdName = std::make_shared<CommandNameValidator>();
    auto subcmdName = std::make_shared<SubCommandNameValidator>();
    auto optArg = std::make_shared<OptArgValidator>();

    notEmpty->setNext(invoc);
    invoc->setNext(cmdName);
    cmdName->setNext(subcmdName);
    subcmdName->setNext(optArg);

    if (!notEmpty->validate(toks, 0).success) {
        std::cout << notEmpty->validate(toks, 0).message << std::endl;
        return std::nullopt;
    }

    size_t i = 0;
    auto invoc_ = toks[i++];
    auto cmd_ = toks[i++];
    auto subcmd_ = toks[i++];

    std::vector<OptToArg> optToArgs_;

    while (i < toks.size())
    {
        optToArgs_.push_back({toks[i], toks[i + 1]});
        i += 2;
    }

    return Command(invoc_, cmd_, subcmd_, optToArgs_);
}

Command::Command (
    const std::string& invoc,
    const std::string& cmd,
    const std::string& subcmd,
    const std::vector<OptToArg> optToArgs 
) :
    m_invoc(std::move(invoc)),
    m_cmd(std::move(cmd)), 
    m_subcmd(std::move(subcmd)),
    m_optToArgs(std::move(optToArgs))
{ }

std::string Command::invocation() const { return m_invoc; }

std::string Command::command() const { return m_cmd; }

std::string Command::subcommand() const { return m_subcmd; }

std::vector<Command::OptToArg> Command::optionsToArguments() const { return m_optToArgs; }