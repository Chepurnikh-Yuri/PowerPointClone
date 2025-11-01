#ifndef SLIDE_HPP
#define SLIDE_HPP

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
    };

    Slide(Size sizes);

    // copy operations
    Slide(const Slide& other) = delete;
    Slide& operator=(const Slide& other) = delete;
    
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