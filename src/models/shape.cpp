#include "shape.hpp"

Shape::Shape (
    const Shape::Pos& p,
    const Shape::Sizes& sz,
    const std::string& text
) :
    m_upperLeftCornerPos(std::move(p)),
    m_sizes(std::move(sz)),
    m_text(std::move(text)) { } 

void Shape::setUpperLeftCornerPos(const Shape::Pos& pos) { m_upperLeftCornerPos = pos; }

void Shape::setSizes(const Shape::Sizes& sz) { m_sizes = sz; }

void Shape::setText(const std::string& text) { m_text = text; }

Shape::Pos Shape::upperLeftCornerPos() const { return m_upperLeftCornerPos; }

Shape::Sizes Shape::sizes() const { return m_sizes; }

std::string Shape::text() const { return m_text; }