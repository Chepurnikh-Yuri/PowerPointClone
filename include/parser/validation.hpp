#ifndef VALIDATION_HPP
#define VALIDATION_HPP

#include <string>
#include <memory>
#include <vector>

// chain of responsibility
namespace Validation
{
    // for simplicity ValidationResult is aggregate
    struct ValidationResult
    {
        bool success;
        std::string message;
    };

    class CommandValidator 
    {
    public:
        void incrIdx();
        void setNext(std::shared_ptr<CommandValidator> next);
        virtual ValidationResult validate(const std::vector<std::string>& cmd, size_t idx);
        virtual ~CommandValidator() = default;

    protected:
        std::shared_ptr<CommandValidator> next = nullptr;
    };

    class NotEmptyValidator : public CommandValidator
    {
    public:
        ValidationResult validate(const std::vector<std::string>& cmd, size_t idx) override;
    };

    class InvocationNameValidator : public CommandValidator
    {
    public:
        ValidationResult validate(const std::vector<std::string>& cmd, size_t idx) override;
    };

    class CommandNameValidator : public CommandValidator
    {
    public:
        ValidationResult validate(const std::vector<std::string>& cmd, size_t idx) override;
    };

    class SubCommandNameValidator : public CommandValidator
    {
    public:
        ValidationResult validate(const std::vector<std::string>& cmd, size_t idx) override;
    };

    class OptArgValidator : public CommandValidator
    {
    public:
        ValidationResult validate(const std::vector<std::string>& cmd, size_t idx) override;
    };
}

#endif // VALIDATION_HPP