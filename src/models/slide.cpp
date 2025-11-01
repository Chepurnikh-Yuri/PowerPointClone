#include "slide.hpp"

Slide::Sizes::Sizes(double width, double height) :
    width(width), height(height) { } 

Slide::Sizes::Sizes(const Slide::Sizes& other) :
    width(other.width), height(other.height) { }

Slide::Sizes& Slide::Sizes::operator=(const Slide::Sizes& other) {
    if (this != &other) {
        this->width = other.width;
        this->height = other.height;
    }
    return *this;
}

Slide::Slide(Sizes sizes) : m_sizes(std::move(sizes)) { }

Slide::Slide(const Slide& other) : m_sizes(other.m_sizes) {
    for (size_t i = 0; i < m_shapes.size(); ++i)
        m_shapes[i] = std::make_unique<Shape>(*other.m_shapes[i]);
}

Slide& Slide::operator=(const Slide& other) {
    if (this != &other) {
        m_sizes = other.m_sizes;

        for (size_t i = 0; i < m_shapes.size(); ++i)
            m_shapes[i] = std::make_unique<Shape>(*other.m_shapes[i]);
    }

    return *this;
}

Slide::Sizes Slide::sizes() const { return m_sizes; }

std::vector<Shape*> Slide::shapes() const {
    std::vector<Shape*> shapes;

    for (const auto& s : m_shapes)
        shapes.push_back(s.get());

    return shapes; 
}

void Slide::addShape(size_t idx, const Shape& shape) {
    if (idx > m_shapes.size())
        return;

    try {
        auto it = m_shapes.begin() + idx;
        m_shapes.insert(it, std::make_unique<Shape>(shape));
    }
    catch(const std::bad_alloc& e)
    {
        std::cerr << "Error: Memory allocation failed " << e.what() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void Slide::removeShape(size_t idx) {
    if (idx >= m_shapes.size())
        return;

    auto it = m_shapes.begin() + idx;
    m_shapes.erase(it);
}

Shape* Slide::getShape(size_t idx) {
    if (idx >= m_shapes.size())
        return nullptr;

    return m_shapes[idx].get();
}