#include "commands.hpp"
using namespace Commands;

ACommand::ACommand (
    std::shared_ptr<Presentation> presentationModel,
    CLIView& view
) :
    presentationModel(presentationModel), 
    view(view)
{ }

SlideCommand::SlideCommand (
    std::shared_ptr<Presentation> presentationModel,
    CLIView& view,
    size_t idx
) : 
    ACommand(presentationModel, view), slideIdx(idx)
{ }

ShapeCommand::ShapeCommand (
    std::shared_ptr<Presentation> presentationModel,
    CLIView& view,
    size_t slideIdx, 
    size_t shapeIdx
) :
    ACommand(presentationModel, view),
    slideIdx(slideIdx),
    shapeIdx(shapeIdx)
{ }

Presentation& CreatePresentationCommand::execute() {  
    presentationModel = std::make_shared<Presentation>();
    return *presentationModel;
}

Presentation& AddSlideCommand::execute() {
    presentationModel->addSlide(slideIdx);
    std::cout << "add slide by index: " << slideIdx << std::endl;
    return *presentationModel;
}

Presentation& RemoveSlideCommand::execute() {
    presentationModel->removeSlide(slideIdx);
    std::cout << "remove slide by index: " << slideIdx << std::endl;
    return *presentationModel;
}

Presentation& ShowSlideCommand::execute() {
    presentationModel->showSlide(slideIdx);
    return *presentationModel;
}

// Presentation& AddShapeCommand::execute() {
//     presentationModel.getSlide(slideIdx)->addShape(shapeIdx, );
//     return presentationModel;
// }

// Presentation& RemoveShapeCommand::execute() {
//     presentationModel.getSlide(slideIdx)->removeShape(shapeIdx);
//     return presentationModel;
// }