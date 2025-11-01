#ifndef CLIVIEW_HPP
#define CLIVIEW_HPP

#include <iostream>
#include <string>

// class-functor
class CLIView
{
public:
    std::string operator()() const;
};

#endif // CLIVIEW_HPP