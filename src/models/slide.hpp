#include "slide.hpp"

Slide::Slide(Size sizes) : m_sizes(std::move(sizes)) { }

Sizes Slide::sizes() const { return m_sizes; }

std::vector<Shape*> Slide::shapes() const { return m_shapes; }

void Shape::addShape(size_t idx, const Shape& shape) {
    if (idx > m_shapes.size())
        return;

    try {
        auto it = m_shapes.begin() + idx;
        m_shapes.insert(it, shape);
    }
    catch(const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void Shape::removeShape(size_t idx) {
    if (idx >= m_shapes.size())
        return;

    auto it = m_shapes.begin() + idx;
    m_shapes.erase(it);
}

Shape* Shape::getShape(size_t idx) {
    if (idx >= m_shapes.size())
        return;

    return m_shapes[idx];
}