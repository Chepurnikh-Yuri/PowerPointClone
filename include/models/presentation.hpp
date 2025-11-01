#ifndef PRESENTATION_HPP
#define PRESENTATION_HPP

#include <vector>
#include <memory>
#include <iostream>

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

    void showSlide(size_t idx);
    void addSlide(size_t idx);
    void removeSlide(size_t idx);
    Slide* getSlide(size_t idx);

private:
    std::vector<std::unique_ptr<Slide>> m_slides;
};

#endif // PRESENTATION_HPP