#ifndef PRESENTATION_HPP
#define PRESENTATION_HPP

#include <vector>
#include <memory>

#include "slide.hpp"

class Presentation
{
public:
    Presentation() = default;

    // copy operations
    Presentation(const Presentation& other) = delete;
    Presentation& operator=(const Presentation& other) = delete;
    
    // move operations
    Presentation(Presentation&& other) noexcept = delete;
    Presentation& operator=(Presentation&& other) noexcept = delete;

    ~Presentation() = default;

    std::vector<Slide*> slides() const;

    void addSlide(size_t idx, const Shape& shape);
    void removeSlide(size_t idx);
    Shape* getSlide(size_t idx);

private:
    std::vector<std::unique_ptr<Slide>> m_slides;
};

#endif // PRESENTATION_HPP