#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include <memory>

#include "presentation.hpp"
#include "slide.hpp"
#include "shape.hpp"
#include "cli_view.hpp"

namespace Commands
{
    class ACommand
    {
    public:
        ACommand (
            std::shared_ptr<Presentation> presentationModel,
            CLIView& view
        );
        virtual Presentation& execute() = 0;
        virtual ~ACommand() = default;

    protected:
        std::shared_ptr<Presentation> presentationModel;
        CLIView& view;
    };

    class SlideCommand : public ACommand 
    {
    public: 
        SlideCommand (
            std::shared_ptr<Presentation> presentationModel,
            CLIView& view,
            size_t idx
        );

    protected:
        size_t slideIdx;
    };

    class ShapeCommand : public ACommand 
    {
    public:
        ShapeCommand (
            std::shared_ptr<Presentation> presentationModel,
            CLIView& view,
            size_t slideIdx, 
            size_t shapeIdx
        );

    protected:
        size_t slideIdx;
        size_t shapeIdx;
    };

    class CreatePresentationCommand : public ACommand
    {
    public:
        CreatePresentationCommand (
            std::shared_ptr<Presentation> presentationModel,
            CLIView& view
        ) : ACommand(presentationModel, view) { }

        Presentation& execute() override;
    };

    class AddSlideCommand : public SlideCommand
    {
    public:
        AddSlideCommand (
            std::shared_ptr<Presentation> presentationModel,
            CLIView& view,
            size_t idx
        ) : SlideCommand(presentationModel, view, idx) { }

        Presentation& execute() override;
    };

    class RemoveSlideCommand : public SlideCommand
    {
    public:
        RemoveSlideCommand (
            std::shared_ptr<Presentation> presentationModel,
            CLIView& view,
            size_t idx
        ) : SlideCommand(presentationModel, view, idx) { }

        Presentation& execute() override;
    };

    class ShowSlideCommand : public SlideCommand 
    {
    public:
        ShowSlideCommand (
            std::shared_ptr<Presentation> presentationModel,
            CLIView& view,
            size_t idx
        ) : SlideCommand(presentationModel, view, idx) { }

        Presentation& execute() override;
    };

    // class AddShapeCommand : public ShapeCommand
    // {
    // public:
    //     Presentation& execute() override;
    // };

    // class RemoveShapeCommand : public ShapeCommand
    // {
    // public:
    //     Presentation& execute() override;
    // };
}

#endif // COMMANDS_HPP