#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <string>
#include <utility>
#include <memory>

class Shape
{
public:
    struct Pos
    {
        double x, y;
    };

    struct Sizes
    {
        double width, height;
    };

    Shape (
        const Pos& p,
        const Sizes& sz,
        const std::string& text = std::string()
    );

    // copy operations
    Shape(const Shape& other) = delete;
    Shape& operator=(const Shape& other) = delete;

    // move operations
    Shape(Shape&& other) noexcept = delete;
    Shape& operator=(Shape&& other) noexcept = delete;

    ~Shape() = default;
    
    // setters 
    void setUpperLeftCornerPos(const Pos& pos);
    void setSizes(const Sizes& sz);
    void setText(const std::string& text);

    // getters
    Pos upperLeftCornerPos() const;
    Sizes sizes() const;
    std::string text() const;
    
private:
    Pos m_upperLeftCornerPos;
    Sizes m_sizes;
    std::string m_text;
};

#endif // SHAPE_HPP