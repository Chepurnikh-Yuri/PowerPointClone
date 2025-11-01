#ifndef SLIDE_HPP
#define SLIDE_HPP

#include <iostream>
#include <vector>
#include <memory>
#include <utility>
#include <stdexcept>

#include "shape.hpp"

class Slide 
{
public:
    struct Sizes 
    {
        double width, height;

        Sizes(double width = double(), double height = double());

        Sizes(const Sizes& other);
        Sizes& operator=(const Sizes& other);
    };

    Slide(Sizes sizes);

    // copy operations
    Slide(const Slide& other);
    Slide& operator=(const Slide& other);
    
    // move operations
    Slide(Slide&& other) noexcept = delete;
    Slide& operator=(Slide&& other) noexcept = delete;

    ~Slide() = default;

    // getters 
    Sizes sizes() const;
    std::vector<Shape*> shapes() const;

    void addShape(size_t idx, const Shape& shape);
    void removeShape(size_t idx);
    Shape* getShape(size_t idx);

private:
    Sizes m_sizes;
    std::vector<std::unique_ptr<Shape>> m_shapes;
};

#endif // SLIDE_HPP